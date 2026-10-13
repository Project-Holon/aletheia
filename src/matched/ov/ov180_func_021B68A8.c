/*
 * function: func_021B68A8
 * address: 0x021B68A8
 * packet: pkt_ov180_021B68A8
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_021B8034 0x021B8034 data a4
 *   d_021B801C 0x021B801C data a4
 *   d_021B8028 0x021B8028 data a4
 */
#include "../include/Obj00547.h"
typedef unsigned int   u32;
extern void *MCSS_Init(u32 id, void *heap); extern void MCSS_SetTextureTransAdrs(void *,unsigned); extern void MCSS_SetOrthoMode(void *);
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,void *,void *,void *,unsigned short);
struct Light;
extern void func_02048AD0(struct Light *l);
extern unsigned d_021B8034[]; extern unsigned d_021B801C[]; extern unsigned d_021B8028[];
void func_021B68A8(char *p) {
 ((struct Obj00547 *)p)->f18=MCSS_Init(1,(void *)141); MCSS_SetTextureTransAdrs(((struct Obj00547 *)p)->f18,0); MCSS_SetOrthoMode(((struct Obj00547 *)p)->f18);
 ((struct Obj00547 *)p)->f20=func_02048A24(2,0x60000,0xFFFA0000,0xFFF80000,0x80000,0x1000,0x400000,0,d_021B8034,d_021B801C,d_021B8028,141);
 func_02048AD0(((struct Obj00547 *)p)->f20);
}
