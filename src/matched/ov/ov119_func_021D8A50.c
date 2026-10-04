/*
 * function: func_021D8A50
 * address: 0x021D8A50
 * packet: pkt_ov119_021D8A50
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005E30 0x02005E30 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005DF8 0x02005DF8 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern void func_02005E30(u32 a);
extern void func_02005DE4(void *p);
extern void func_02005E64(void);
extern void func_02005D90(int,int);
extern void func_02005DF8(u32 a);
void func_021D8A50(void *p) {
 int v;
 if(((struct Obj00001 *)p)->f1094!=0) {
 v=++((struct Obj00001 *)p)->f1094;
 if(v==2) {func_02005E30(6); return;}
 if(v==8) {
 func_02005DE4((void *)1); func_02005E64();
 ++((struct Obj00001 *)p)->f11F8;
 func_02005D90(0x3f3,0xffff); func_02005DF8(1);
 ((struct Obj00001 *)p)->f1094=0;
 }
 }
}
