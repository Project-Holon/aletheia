/*
 * function: func_021BE4B4
 * address: 0x021BE4B4
 * packet: pkt_ov203_021BE4B4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov203
 *   func_021BE158 0x021BE158 thumb ov203
 *   func_0200566C 0x0200566C thumb
 *   func_0204EA0C 0x0204EA0C arm
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03354.h"
typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
struct Rec;
extern void func_021BF810(char *p);
extern void func_021BE158(void *);
extern void func_0200566C(void);
extern int func_0204EA0C(void);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern void G3D_UTIL_Delete(struct Rec *p);
extern u32 func_020307B0(void *p);
void func_021BE4B4(char *ctx, int b, int c, u32 d)
{
    unsigned i;
    func_021BF810(((struct Obj03354 *)ctx)->f6C);
    func_021BE158(((struct Obj03354 *)ctx)->f20);
    if (((struct Obj03354 *)ctx)->f10) {
        func_0200566C();
        func_0204EA0C();
    }
    ICA_ANIME_Delete(((struct Obj03354 *)ctx)->f18);
    for (i = 0; i < ((struct Obj03354 *)ctx)->f2C; i++) {
        G3D_UTIL_RemoveUnit(((struct Obj03354 *)ctx)->f1C, (*(unsigned short **)(ctx + 0x70))[i]);
    }
    G3D_UTIL_Delete(((struct Obj03354 *)ctx)->f1C);
    func_020307B0(((struct Obj03354 *)ctx)->f70);
    func_020307B0(ctx);
}
