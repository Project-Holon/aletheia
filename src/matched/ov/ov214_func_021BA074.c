/*
 * unit: yes
 * function: func_021BA074, func_021BA0A4
 * address: 0x021BA074
 * packet: pkt_ov214_021BA074
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Parameter evidence: original narrows third input to u16 before func_0201F73C.
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 */
#include "../include/Obj10935.h"
#include "../include/Obj25724.h"
struct Descriptor;struct Cfg;
typedef unsigned int   u32;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_02041B6C(unsigned);
extern void func_0201F7A8(void *desc, u32 kind);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
void func_021BA074(int unused,char *p){struct Descriptor *d;func_0201F73C(((struct Obj10935 *)p)->f6C,1,(unsigned short)(((struct Obj10935 *)p)->f74),10);d=*(struct Descriptor * *)&((struct Obj10935 *)p)->f6C;BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);func_02041B6C(BMP_WIN_GetBgLayer(d));}
void func_021BA0A4(int unused,char *p){func_0201F7A8(((struct Obj25724 *)p)->f6C,(int)1);}
