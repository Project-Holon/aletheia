/*
 * function: IRCBATTLEMENU_IsMessageEnd
 * address:  0x021975D0
 * packet:   pkt_ov021_021975D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll of the object at +0x2B4; returns 1 when it is absent.
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ctx;
struct Rec;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void func_020061E4(u32 a);

int IRCBATTLEMENU_IsMessageEnd(u8 *p)
{
    if (((struct Obj00094 *)p)->f2B4 != 0) {
        if (((struct Obj00094 *)p)->f2B0 != 0)
            APP_KEYCURSOR_Update(((struct Obj00094 *)p)->f2A8, ((struct Obj00094 *)p)->f2B4, ((struct Obj00094 *)p)->f2B0);
        switch (func_0201CE30(((struct Obj00094 *)p)->f2B4)) {
        case 2:
            func_0201CE48(((struct Obj00094 *)p)->f2B4);
            ((struct Obj00094 *)p)->f2B4 = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg() != 0) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00094 *)p)->f2B4);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont() != 0)
                func_0201CE5C(((struct Obj00094 *)p)->f2B4, 0);
            break;
        }
        return 0;
    }
    return 1;
}
