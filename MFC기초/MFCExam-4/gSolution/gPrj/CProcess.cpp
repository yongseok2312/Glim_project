﻿// CProcess.cpp: 구현 파일
//

#include "stdafx.h"
#include "gPrj.h"
#include "CProcess.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

int CProcess::getStarinfo(CImage *pImage, int nth) {
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeight = pImage->GetHeight();
	int nPitch = pImage->GetPitch();

	int nSum = 0;
	for (int k = 0; k < nWidth * nHeight; k++) {
		if (fm[k] > 100)
			nSum++;
	}
	return nSum;

}

// CProcess 멤버 함수
