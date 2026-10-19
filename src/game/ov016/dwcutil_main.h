#ifndef GAME_OV016_DWCUTIL_MAIN_H
#define GAME_OV016_DWCUTIL_MAIN_H

/* Public functions of dwcutil_main.c, prototypes copied from their definitions. */

int DWC_StartUtility(void *work, int language, int param);
void initGraph(void);
void DWCi_ChangeScene(unsigned int v);
void DWCi_SetParam_(unsigned int stepParam, unsigned int buttonParam);
void DWCi_GetParam_(void **outStepParam, void **outButtonParam);
void DWCi_SetParam2_(unsigned int a, unsigned int b);
void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
unsigned char DWCi_Language(void);
unsigned int DWCi_Entry(void);
int DWCi_Flag(unsigned int v);
void DWCi_EndUtility(void);
unsigned char kDWCi_Language(void);

#endif
