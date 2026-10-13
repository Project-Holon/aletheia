/*
 * function: func_021E12AC
 * address: 0x021E12AC
 * packet: pkt_ov119_021E12AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48 0x0201CE48 thumb
 */
#include "../include/Obj00001.h"
typedef signed int     s32;
struct Blk;
struct Ctx;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0201CE48(struct Rec3 *p);
int func_021E12AC(char *p) {int v=1;if(((struct Obj00001 *)p)->f72C) {if(*(int *)&((struct Obj00001 *)p)->f71C)APP_KEYCURSOR_Update((struct Ctx *)(*(int *)&((struct Obj00001 *)p)->f74C),(void *)(((struct Obj00001 *)p)->f72C),(void *)(*(int *)&((struct Obj00001 *)p)->f71C));v=func_02028484((struct Blk *)(p+0x11d4),(void *)(((struct Obj00001 *)p)->f72C));if(v) {if(((struct Obj00001 *)p)->f72C) {func_0201CE48((struct Rec3 *)(((struct Obj00001 *)p)->f72C));((struct Obj00001 *)p)->f72C=0;}}}return v;}
