#ifndef GAME_OV009_DWC_NASFUNC_H
#define GAME_OV009_DWC_NASFUNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_nasfunc.c, prototypes copied from their definitions. */

int DWC_GetDateTime(void *date, void *time);
int DWC_SVLGetTokenAsync(char *svl, void *result);
int DWC_SVLProcess(void);
int DWC_NASLoginAsync(void);
int DWC_NASLoginProcess(void);
/* END mkheaders: generated region */

#endif
