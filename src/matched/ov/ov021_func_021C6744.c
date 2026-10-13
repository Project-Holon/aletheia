/*
 * function: FIELD_G3DOBJ_SetAnimeFrame
 * address:  0x021C6744
 * packet:   pkt_ov021_021C6744
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * push {r0-r3} entry (0x021C6744); the fourth parameter's address is taken.
 *
 * symbols:
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09694.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 k : 2; } K;

typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

void FIELD_G3DOBJ_SetAnimeFrame(u32 *a, int idx, int mode, u32 val)
{
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + ((struct Obj09694 *)e)->f4 * 0x2c + 0x28);
        if (mode == 8) {
            i = 0;
            if (n > 0) {
                do {
                    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)i, (s32 *)(&val));
                    i++;
                } while (i < n);
            }
        } else if (mode < n) {
            G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)(((struct Obj09694 *)e)->f44), (u16)mode, (s32 *)(&val));
        }
    }
}
