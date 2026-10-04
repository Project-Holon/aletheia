/*
 * function: func_021BEDEC
 * address: 0x021BEDEC
 * packet: pkt_ov110_021BEDEC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF1C4 0x021BF1C4 thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BF1C4(u8 *,void *);
extern int func_021B9C90(unsigned int a, int b);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,void *);
int func_021BEDEC(u8 *p,u32 *q) {
    switch(*q) {
    case 0: func_021BF1C4(p,q); break;
    case 1: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) *q=0; break;
    case 2: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),20)) { func_021B9BEC(((struct Obj00012 *)p)->f14,19); *q=0; } break;
    case 3: if(func_021B9C90((unsigned int)(((struct Obj00012 *)p)->f14),31)) *q=0; break;
    case 4: if(func_021B9C74((unsigned int)(((struct Obj00012 *)p)->f14))) { func_021BD7A0(p,((struct Obj00012 *)p)->f28); *q=0; } break;
    }
    return 0;
}
