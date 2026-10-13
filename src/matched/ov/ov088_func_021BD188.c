/*
 * function: STARTMENU_SaveEraseUpdateMessage
 * address:  0x021BD188
 * packet:   pkt_ov088_021BD188
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */
#include "../include/Obj00578.h"

typedef unsigned int u32;

struct Ctx;
struct Rec3;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);

int STARTMENU_SaveEraseUpdateMessage(char *p)
{
    TCBL_Main(((struct Obj00578 *)p)->f18);
    APP_KEYCURSOR_Update(((struct Obj00578 *)p)->f24, ((struct Obj00578 *)p)->f14, ((struct Obj00578 *)p)->f1C);
    switch (func_0201CE30(((struct Obj00578 *)p)->f14)) {
    case 0:
        ((struct Obj00578 *)p)->f28 = 0;
        break;
    case 1:
        if (((struct Obj00578 *)p)->f28 == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00578 *)p)->f14);
                ((struct Obj00578 *)p)->f28 = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(((struct Obj00578 *)p)->f14);
        ((struct Obj00578 *)p)->f28 = 0;
        return 0;
    }
    return 1;
}
