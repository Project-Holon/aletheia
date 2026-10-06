/*
 * function: func_021BD7A0
 * address: 0x021BD7A0
 * packet: pkt_ov110_021BD7A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BD8A8 0x021BD8A8 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD8B8 0x021BD8B8 thumb ov110
 *   func_021BEDEC 0x021BEDEC thumb ov110
 *   func_021BD8C8 0x021BD8C8 thumb ov110
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef int (*Handler)(u8 *,void *);
extern int func_021BD894(u8 *,void *);
extern int func_021BE4C0(u8 *,void *);
extern int func_021BEDEC(u8 *,void *);
extern int func_021BD8A8(u8 *p);
extern int func_021BD8B8(u8 *p);
extern int func_021BD8C8(u8 *p);
extern void func_021BAE24(void *,u8 *,void *);
extern void func_021BAE94(u8 *p, u8 *q, void *a2);
extern void func_021BAED0(void *,u8 *,void *);
void func_021BD7A0(u8 *p,Handler fn) {
 *(Handler *)&((struct Obj00012 *)p)->f24=fn; ((struct Obj00012 *)p)->f20=0;
 if(fn==func_021BD894) { func_021BAE24(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8A8; }
 else if(fn==func_021BE4C0) { func_021BAE94(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8B8; }
 else if(fn==func_021BEDEC) { func_021BAED0(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8C8; }
 else *(Handler *)&((struct Obj00012 *)p)->f74=0;
}
