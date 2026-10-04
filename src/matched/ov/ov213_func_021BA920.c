/*
 * function: func_021BA920
 * address: 0x021BA920
 * packet: pkt_ov213_021BA920
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   func_02047788 0x02047788 arm
 *   func_02047554 0x02047554 arm
 *   func_0204755C 0x0204755C arm
 *   func_02047250 0x02047250 arm
 *   func_0206A67C 0x0206A67C arm
 *   func_0206A5B4 0x0206A5B4 arm
 */
#include "../include/Obj25711.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_02047788(int *),func_02047554(int *),func_0204755C(int *);
extern int func_02047250(char *);
extern void func_0206A67C(char *);
extern int func_0206A5B4(char *,char *,u32,u32);
int func_021BA920(int *p,u32 b,u32 c) { int *q; char *a,*h,*r; q=(int *)func_02047788(p); a=(char *)func_02047554(q); h=*(char * *)&((struct Obj25711 *)((char *)func_0204755C(q)))->f4; r=(char *)func_02047250(a); func_0206A67C(h); return func_0206A5B4(h,r,b,c)&1; }
