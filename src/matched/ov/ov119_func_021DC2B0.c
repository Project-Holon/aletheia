/*
 * function: func_021DC2B0
 * address: 0x021DC2B0
 * packet: pkt_ov119_021DC2B0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8C6C 0x021D8C6C thumb ov119
 *   func_021DB198 0x021DB198 thumb ov119
 *   func_021DB45C 0x021DB45C thumb ov119
 *   func_021DF5D8 0x021DF5D8 thumb ov119
 *   func_021D9E54 0x021D9E54 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
struct S;
extern void TOUCHBAR_Update(struct S *p);extern int TOUCHBAR_GetPressedButtonIdIfDone(int);extern void func_021D8E84(void *,int);extern int func_021D8AA8(void *);extern int func_021DD2F4(void *);extern void func_021B6558(int,int,int);extern void func_021D8C6C(void *);extern void func_021DB198(void);extern void func_021DB45C(void);extern void func_021DF5D8(void);extern void func_021D9E54(void);extern void func_021DBE70(void);
void func_021DC2B0(char *p){TOUCHBAR_Update((struct S *)(*(int *)&((struct Obj00001 *)p)->f9C0));switch(TOUCHBAR_GetPressedButtonIdIfDone(*(int *)&((struct Obj00001 *)p)->f9C0)) {case 1:func_021D8E84(p,(int)func_021DB198);return;case 7:func_021D8E84(p,(int)func_021DB45C);return;case 8:if(func_021D8AA8(p)){if(func_021DD2F4(p)){func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,7,0);func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);func_021D8C6C(p);func_021D8E84(p,(int)func_021DF5D8);return;}else{func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,7,1);func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);}}else{if(((struct Obj00001 *)p)->fF84==-1){func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,7,1);func_021B6558(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);}else{func_021D8E84(p,(int)func_021D9E54);return;}}func_021D8E84(p,(int)func_021DBE70);return;}}
