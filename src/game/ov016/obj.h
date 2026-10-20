#ifndef GAME_OV016_OBJ_H
#define GAME_OV016_OBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of obj.c, prototypes copied from their definitions. */

union GXOamAttr;

void DWCi_OBJlInit(void);
void DWCi_OBJlEnd(void);
union GXOamAttr *DWCi_OBJlFormGx(unsigned int i);
void DWCi_OBJlDelete(unsigned int *obj);
char *DWCi_OBJlGetOam(unsigned int a, unsigned int b);
/* END mkheaders: generated region */

#endif
