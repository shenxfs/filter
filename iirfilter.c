/**
 * @brief IIR Filter Function
 * @file iirfilter.c
 * @author shenxfs 380406785@@qq.com
 * @date 2017-07-30
 * @version V1.0.0
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.1 and the Signal Processing Toolbox 7.3.
 * Generated on: 29-Jul-2017 14:06:31
 * Discrete-Time IIR Filter (real and fixed point)
 * -------------------------------
 */
#include <stdint.h>
#include <stdio.h>
#include "iirfilter.h"

 /**
 * @brief Filter Structure(REAL) Data
 * Filter Structure    : Direct-Form II, Second-Order Sections
 * Number of Sections  : 4
 * Stable              : Yes
 * Linear Phase        : No
 * fs 1000Hz
 * fc 30Hz
 */
 fdata_t fd=
 {
   .a = {
     {-1.895289756537,   0.9294659022914},
     {-1.779339107215,    0.811424413678},
     {-1.699750237618,   0.7304003857905},
     {-1.659576201179,   0.6895019251732}
   },
   .b={
    {0.008544036438708,0.017088072877416,0.008544036438708},
    {0.008021326615853,0.016042653231706,0.008021326615853},
    {0.007662537043122,0.015325074086244,0.007662537043122},
    {0.007481430998498,0.014962861996996,0.007481430998498}
   },
   .g = 1.000011000121001,
   .wn={
     {0.0,0.0},
     {0.0,0.0},
     {0.0,0.0},
     {0.0,0.0}
   }
 };

 /**
 * @brief Filter Structure(Fixed Point) Data
 * Filter Structure    : Direct-Form II, Second-Order Sections
 * Number of Sections  : 4
 * Stable              : Yes
 * Linear Phase        : No
 * fs 1000Hz
 * fc 30Hz
 */
 fdfix_t fx=
 {
   .a = {
     {2035051880L,   -998006413L},
     {1910550818L,   -871260330L},
     {1825092920L,   -784261442L},
     {1781956377L,   -740347055L}
   },
   .b={
    {9174089L,18348179L,9174089L},
    {8612834L,17225668L,8612834L},
    {8227587L,16455173L,8227587L},
    {8033125L,16066251L,8033125L}
   },
   .g = 1074594469L,
   .wn={
     {0,0},
     {0,0},
     {0,0},
     {0,0}
   }
 };

/**
* @fn IIR Filter initialized(REAL)
* @param pfd
*/
void iir_filter_init(fdata_t *pfd)
{
  int8_t i,j;
  for(i = 0;i < NODE;i++)
  {
    for(j=0;j<3;j++)
    {
      pfd->wn[i][j] = 0.0;
    }
  }
}

/**
* @brief IIR Filter(REAL)
* @param x
* @param pfd
* @return Filter value
* Direct-Form II, Second-Order Sections \n
* wn(n) = x(n) - a1*wn(n-1) - a2*wn(n-2) \n
* y(n) = b0*wn(n-1) + b1*wn(n-1) + b2*Wn(n-2) \n
*/
double iir_filter(double x,fdata_t *pfd)
{
  int8_t i,j;
  double yn[NODE];
  double w0,y;
  y = x;
  for(j=0;j<NODE;j++)
  {
    w0 = y-pfd->a[j][0]*pfd->wn[j][0]-pfd->a[j][1]*pfd->wn[j][1];
    y = pfd->b[j][0]*w0+pfd->b[j][1]*pfd->wn[j][0]+pfd->b[j][2]*pfd->wn[j][1];
    printf("w[0]=%f,wn[1]=%f,wn[2]=%f,y%i=%f\n",w0,pfd->wn[j][0],pfd->wn[j][1],j,y);
    pfd->wn[j][1] = pfd->wn[j][0];
    pfd->wn[j][0] = w0;
  }
  return y*pfd->g;
}

/**
* @brief IIR Filter(Fixed Point)
* @param x Q=30
* @param pfd
* @return Filter value Q=30
* Direct-Form II, Second-Order Sections \n
* wn(n) = x(n) + (-a1)*wn(n-1) + (-a2)*wn(n-2) \n
* y(n) = b0*wn(n-1) + b1*wn(n-1) + b2*Wn(n-2) \n
* wn Q=24 \n
*/
int32_t fixiir_filter(int32_t x,fdfix_t *pfd)
{
  int8_t i;
  int32_t yn[NODE];
  int32_t w0,y;
  int64_t sum;
  y = x;
  for(i = 0;i < NODE;i++)
  {
    sum = (int64_t)y*16777216L;
    sum += (int64_t)pfd->a[i][0]*pfd->wn[i][0];
    sum += (int64_t)pfd->a[i][1]*pfd->wn[i][1];
    w0 = (int32_t)(sum/1073741824L);
    sum = (int64_t)pfd->b[i][0]*w0;
    sum += (int64_t)pfd->b[i][1]*pfd->wn[i][0];
    sum += (int64_t)pfd->b[i][2]*pfd->wn[i][1];
    y = (int32_t)(sum/16777216L);
    printf("w[0]=%08X,w[1]=%08X,[2]=%08X,y%i=%08X\n",w0,pfd->wn[i][0],pfd->wn[i][1],i,y);
    pfd->wn[i][1] = pfd->wn[i][0];
    pfd->wn[i][0] = w0;
  }
  return ((int64_t)y*pfd->g/1073741824L);
}

/**
* @fn IIR Filter initialized(Fixed Point)
* @param pfd
*/
void fixiir_filter_init(fdfix_t *pfd)
{
  int8_t i,j;
  for(i = 0;i < NODE;i++)
  {
    for(j=0;j<3;j++)
    {
      pfd->wn[i][j] = 0;
    }
  }
}