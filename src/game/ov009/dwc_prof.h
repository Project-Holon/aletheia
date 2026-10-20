#ifndef GAME_OV009_DWC_PROF_H
#define GAME_OV009_DWC_PROF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_prof.c, prototypes copied from their definitions. */

int DWCi_CheckProfanityAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, char *region);
int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
int DWC_CheckProfanityProcess(void);
int DWCi_Prof_ParseResponse(void);
/* END mkheaders: generated region */

#endif
