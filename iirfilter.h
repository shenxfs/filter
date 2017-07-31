/**
 * @brief IIR Filter Includer
 * @file iirfilter.h
 * @author shenxfs 380406785@@qq.com
 * @date 2017-08-01
 * @version V1.1.1
 *
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool \n
 * Generated by MATLAB(R) 9.1 and the Signal Processing Toolbox 7.3. \n
 * Generated on: 29-Jul-2017 14:06:31 \n
 * Discrete-Time IIR Filter (real and fixed point)
 * -------------------------------
 */
#ifndef IIR_FILTER_H
#define IIR_FILTER_H

/**
*@struct  Discrete-Time IIR Filter Structure(REAL)
*/
typedef struct _fdata
{
  int16_t node;        /**<Second-Order Sections */
  const double (*a)[2];/**<Second-Order Sections a Coefficients a[NODE][0]-->a1,a[NODE][1]-->a2*/
  const double (*b)[3];/**<Second-Order Sections b Coefficients b[NODE][0]-->b0,b[NODE][1]-->b1,b[NODE][2]-->b2*/
  const double g;         /**<Total gain Coefficients*/
  double (*wn)[2];     /**<Delay Variabler*/
}fdata_t;

/**
*@struct  Discrete-Time IIR Filter Structure(Fixed Point)
*/
typedef struct _fdfix
{
  int16_t node;          /**<Second-Order Sections */
  const int32_t (*a)[2];/**<Second-Order Sections a Coefficients a[NODE][0]-->-a1,a[NODE][1]-->-a2,Q=30*/
  const int32_t (*b)[3];/**<Second-Order Sections b Coefficients b[NODE][0]-->b0,b[NODE][1]-->b1,b[NODE][2]-->b2,Q=30*/
  const int32_t g;         /**<Total gain Coefficients,Q=30*/
  int32_t (*wn)[2];     /**<Delay Variabler,Q=24*/
}fdfix_t;
extern fdata_t fd;
extern fdfix_t fx;
double iir_filter(double x,fdata_t *pfd);
void iir_filter_init(fdata_t *pfd);
int32_t fixiir_filter(int32_t x,fdfix_t *pfd);
void fixiir_filter_init(fdfix_t *pfd);
#endif
