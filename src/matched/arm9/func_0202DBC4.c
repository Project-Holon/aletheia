/*
 * unit:     no
 * function: PMS_DRAW_Main
 * address:  0x0202DBC4
 * packet:   pkt_0202DAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks the selected entry of the 0x28-byte element array hung off +0xc:
 * the selection at +0x28 is primed to 1, then every element whose +0x18
 * bit 0 is set is offered to PMS_DRAW_UpdateElem along with the two cursor
 * words at +8 and +0x2c; the first one that answers non-zero resets the
 * selection to 0.  The count at +0x30 is a signed char and is re-read at
 * the top of every iteration (the call may change it), which is what
 * keeps the `adds r0, r5, #0x30; ldrb` pair inside the loop -- 0x30 is
 * past the Thumb `ldrb` immediate reach of +31.
 *
 * symbols:
 *   PMS_DRAW_UpdateElem  0x0202E0E0  thumb
 */
#include "../include/Obj04744.h"

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Ent { u32 pad[6]; u32 bit0 : 1; };

struct Obj0202E0E0;
extern int PMS_DRAW_UpdateElem(struct Obj0202E0E0 *a0, void *a1, int a2);

void PMS_DRAW_Main(u8 *p)
{
    s32 i;

    ((struct Obj04744 *)p)->f28 = 1;
    for (i = 0; i < (s32)((struct Obj04744 *)p)->f30; i++) {
        u8 *e = *(u8 * *)&((struct Obj04744 *)p)->fC + i * 0x28;
        if (((struct Ent *)e)->bit0 != 0) {
            if (PMS_DRAW_UpdateElem((struct Obj0202E0E0 *)e, ((struct Obj04744 *)p)->f8, ((struct Obj04744 *)p)->f2C) != 0) {
                ((struct Obj04744 *)p)->f28 = 0;
            }
        }
    }
}
