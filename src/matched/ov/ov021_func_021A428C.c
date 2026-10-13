/*
 * function: FIELD_PLAYER_GRID_PlayTileSound
 * address:  0x021A428C
 * packet:   pkt_ov021_021A428C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a sound id from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter at +0x1a.
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_GRID_HasFlag  0x021A5318  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   gFieldPlayerGridAttrSounds     0x021D8A00  data  ov021  a4
 *   gFieldPlayerGridAttrSoundsAhead     0x021D8A0C  data  ov021  a4
 *   gFieldPlayerGridCallbackSounds     0x021D89F4  data  ov021  a4
 *   gFieldPlayerGridCallbackSoundsAhead     0x021D8A2C  data  a4
 * Addresses are Black-image addresses.
 * gFieldPlayerGridCallbackSoundsAhead carries no ov021 token: with it the hint reads as contested.
 */
#include "../include/Obj00656.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 mask; int val; s16 a; s16 b; } T1;
typedef struct { int (*fn)(u16); u16 val; s8 a; s8 b; u8 kind; } T2;

extern T1 gFieldPlayerGridAttrSounds[];
extern T1 gFieldPlayerGridAttrSoundsAhead[];
extern T2 gFieldPlayerGridCallbackSounds[];
extern T2 gFieldPlayerGridCallbackSoundsAhead[];

extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_GRID_HasFlag(u32 *p, u32 m);
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern int FLDMMDL_MOVE_GetMapAttr(void *, int, u32 *);
extern u16 MAP_ATTR_GetFlags(u32);
extern void func_020061E4(u32 a);

int FIELD_PLAYER_GRID_PlayTileSound(u8 *o, int unused, int c, int flag, int kind)
{
    int lim;
    int sel;
    u32 id;
    int mode;
    T1 *t;
    T2 *u;
    u32 bits;

    sel = 0x546;
    lim = 0;
    mode = 0;
    if (FIELD_PLAYER_CORE_GetFormCode((u8 *)(*(u32 *)&((struct Obj00656 *)o)->fC)) == 1) {
        mode = 2;
    } else if (FIELD_PLAYER_GRID_HasFlag((u32 *)o, 0x20) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        ((struct Obj00656 *)o)->f18 = 0x546;
        ((struct Obj00656 *)o)->f1A = 0;
    }
    if (FLDMMDL_MOVE_GetMapAttr(FIELD_PLAYER_CORE_GetMmdl(((struct Obj00656 *)o)->fC), c, &id) == 1) {
        bits = MAP_ATTR_GetFlags(id);
        if (flag == 0) {
            t = gFieldPlayerGridAttrSounds;
        } else {
            t = gFieldPlayerGridAttrSoundsAhead;
        }
        for (; t->mask != 0; t++) {
            if (t->mask & bits) {
                sel = t->val;
                if (mode == 1) {
                    lim = t->a;
                } else if (mode == 2) {
                    lim = t->b;
                }
                break;
            }
        }
        if (sel == 0x546) {
            u = gFieldPlayerGridCallbackSounds;
            if (flag != 0) {
                u = gFieldPlayerGridCallbackSoundsAhead;
            }
            for (; u->fn != 0; u++) {
                if (u->fn((u16)id) == 1 && (u->kind == 4 || u->kind == kind)) {
                    sel = u->val;
                    if (mode == 1) {
                        lim = u->a;
                    } else if (mode == 2) {
                        lim = u->b;
                    }
                    break;
                }
            }
        }
        if (sel == 0x546) {
            if (flag == 1) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
        } else if (mode != 0) {
            if (((struct Obj00656 *)o)->f18 != sel) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            if (((struct Obj00656 *)o)->f1A != 0 && ((struct Obj00656 *)o)->f1A < lim) {
                sel = 0x546;
            }
            if (((struct Obj00656 *)o)->f1A >= lim) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            ((struct Obj00656 *)o)->f18 = sel;
            ((struct Obj00656 *)o)->f1A = ((struct Obj00656 *)o)->f1A + 1;
        }
        if (sel != 0x546) {
            func_020061E4(sel);
            return 1;
        }
    }
    return 0;
}
