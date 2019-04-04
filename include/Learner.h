//
//  Learner.h
//  TLD
//
//  Created by 陈裕昕 on 14/11/7.
//  Copyright (c) 2014年 Fudan. All rights reserved.
//

#ifndef __TLD__Learner__
#define __TLD__Learner__

#include <iostream>
#include <opencv2/opencv.hpp>

#include "TLDSystemStruct.h"
#include "Detector.h"

class Detector;

using namespace std;
using namespace cv;

class Learner
{
private:
    Detector *detector;
    PatchGenerator patchGenerator;
    
public:
    Learner(){}
    void init(Detector *detector);
    
    ~Learner();
    
    void learn(const Mat &img, const Mat &imgB, const Mat &img32F, const TYPE_BBOX &ret);
};

#endif /* defined(__TLD__Learner__) */
