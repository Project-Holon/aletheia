/*
 * function: func_021B687C
 * address: 0x021B687C
 * packet: pkt_ov174_021B687C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_021B7364 0x021B7364 thumb ov174
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
#include "../include/Obj00152.h"
typedef unsigned char u8;
typedef signed int     s32;
typedef unsigned int   u32;
struct Blk;
struct Ctx;
struct PrintSys;
struct Rec3;
struct Tcbl;
struct U16Vec;
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern unsigned func_0201CE30(void *);
extern void func_021B7364(char *p, int v);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 func_0201C4E4(struct PrintSys *ps);
void func_021B687C(u8 *p)
{
    func_020310C4(((struct Obj00152 *)p)->f58);
    if(((struct Obj00152 *)p)->f64) {
        func_020286C4(((struct Obj00152 *)p)->f7C,((struct Obj00152 *)p)->f64,((struct Obj00152 *)p)->f5C);
        if(func_0201CE30(((struct Obj00152 *)p)->f64)!=0) func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),0);
        else func_021B7364(*(void **)(p+28+((struct Obj00152 *)p)->f88*4),1);
        if(func_02028484((struct Blk *)(p+128),((struct Obj00152 *)p)->f64)==1) {
            func_0201CE48(((struct Obj00152 *)p)->f64);
            ((struct Obj00152 *)p)->f64=0;
            func_02045808(((struct Obj00152 *)p)->f70);
            ((struct Obj00152 *)p)->f70=0;
        }
    }
    func_0201C4E4(((struct Obj00152 *)p)->f78);
}
