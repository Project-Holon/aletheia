/*
 * function: func_021BADE8
 * address: 0x021BADE8
 * packet: pkt_ov110_021BADE8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 */
#include "../include/Obj03239.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Descriptor;
struct Cfg;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_021BADE8(u8 *p) { struct Descriptor *q; if(((struct Obj03239 *)p)->f70!=0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(*(unsigned *)&((struct Obj03239 *)p)->f7C),(void *)((unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C)))==0) { q=*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C; BMP_WIN_TransferChars(q);BMP_WIN_MakeScreen((struct Cfg *)q);func_02041B6C(BMP_WIN_GetBgLayer(q));((struct Obj03239 *)p)->f70=0; } }
