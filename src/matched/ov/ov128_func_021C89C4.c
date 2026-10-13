/*
 * function: func_021C89C4
 * address: 0x021C89C4
 * packet: pkt_ov128_021C89C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding at 0x021C8A4E; next label 0x021C8A50.
 * symbols:
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 */
#include "../include/Obj03282.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C8A50(char *p, int unused);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32,int,u8,u8,u8,u8,u8);
static inline int ab(int v) {return v<0?-v:v;}
void func_021C89C4(char *p, void *q, void *a2) {
 void *v;
 func_021C8A50(p,(int)q);
 v=**(void ** *)&((struct Obj03282 *)p)->f8;BMP_WIN_ClearScreen(v);func_02041B6C(func_02045730(v));
 func_02041300(2,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(2);
 func_02041300(3,0,ab(((struct Obj03282 *)p)->f0),ab(((struct Obj03282 *)p)->f2),p[4],p[5],0);
 func_02041B6C(3);
}
