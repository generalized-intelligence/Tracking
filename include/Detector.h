//
//  Detector.h
//  TLD
//
//  Created by 陈裕昕 on 11/5/14.
//  Copyright (c) 2014 Fudan. All rights reserved.
//

#ifndef __TLD__Detector__
#define __TLD__Detector__

#include <iostream>
#include <algorithm>
#include <opencv2/opencv.hpp>
//#include <opencv2/legacy/legacy.hpp>
#include "PatchGenerator.h"

#include "VarClassifier.h"
#include "RandomFernsClassifier.h"
#include "NNClassifier.h"
#include "Learner.h"

#include "TLDSystemStruct.h"

using namespace std;
using namespace cv;

class Detector
{
    friend class Learner;
private:
    RandomFernsClassifier rFClassifier;
    NNClassifier nNClassifier;
    
    Mat pattern;
    TYPE_BBOX patternBB;
    int imgW, imgH;
    float patternVar;
    PatchGenerator patchGenerator;
    TYPE_TRAIN_DATA_SET trainDataSetNN, trainDataSetRF;
    
    TYPE_DETECTOR_RET rfRet;
    
    vector<float> scales;
    
    float overlap(const TYPE_BBOX &bb1, const TYPE_BBOX &bb2);
    
    // scanning-window grid
    TYPE_DETECTOR_SCANBBS scanBBs;
    void genScanBB();
    
    void sortByOverlap(const TYPE_BBOX &bb, bool rand = false);
    
    void genPosData(const Mat &img, const Mat &imgB, const Mat &img32F, TYPE_TRAIN_DATA_SET &trainDataSetNN, TYPE_TRAIN_DATA_SET &trainDataSetRF);
    void genNegData(const Mat &img, const Mat &imgB, const Mat &img32F, TYPE_TRAIN_DATA_SET &trainDataSetNN, TYPE_TRAIN_DATA_SET &trainDataSetRF);
    
    void update();
    void initTrain(const Mat &img, const Mat &imgB, const Mat &img32F, const Rect &patternBB);
    
public:
    Detector(){}
    void init(const Mat &img, const Mat &imgB, const Mat &img32F, const Rect &patternBB);
    
    void dectect(const Mat &img, const Mat &imgB, const Mat &img32F, TYPE_DETECTOR_RET &ret);
    
    void updataNNPara(const Mat &img32F, TYPE_DETECTOR_SCANBB &sbb);
    float getNNThPos();
    
    ~Detector();
};

#endif /* defined(__TLD__Detector__) */
