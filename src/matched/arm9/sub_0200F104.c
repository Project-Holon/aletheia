/*
 * function: NET_DEVICE_TABLE_GetFreeSlot
 * address:  0x0200F104
 * packet:   pkt_0200F104
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Scans a run of fixed-stride slots for the first one whose leading word
 * has bit 0 clear (a free-slot search); ctx+4 is the slot count (halfword)
 * and ctx+0x18 is the base pointer, stride 0x100 bytes. Returns the slot
 * pointer, or NULL if every slot up to the count is occupied. The loop
 * enters unconditionally and only checks the count after the first slot
 * has already been tested, so it is written as an infinite loop with two
 * breaks rather than a pre-tested while. The pointer argument is reused
 * in place for the slot cursor, which is what keeps it in r0 through to
 * the return and lets the found-slot path fall straight into the shared
 * epilogue with no register shuffle.
 *
 * EXACT* because the 34 compiled bytes fall two bytes short of the
 * disasm.py extent: a trailing "movs r0, r0" filler halfword between this
 * function and the next label, the ordinary inter-function padding, not a
 * byte difference (see "the two missing labels" in docs/MATCHING.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_GetFreeSlot.c \
 *       --func NET_DEVICE_TABLE_GetFreeSlot --addr 0x0200F104 --cc 1.1p1
 */
#include "../include/Obj00192.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void *NET_DEVICE_TABLE_GetFreeSlot(void *ctx)
{
    u16 count = *(u16 *)&((struct Obj00192 *)ctx)->f4;
    int i = 0;

    ctx = ((struct Obj00192 *)ctx)->f18;

    for (;;) {
        if ((((struct Obj00192 *)ctx)->f0 & 1) == 0) {
            break;
        }
        i++;
        ctx = (u8 *)ctx + 0x100;
        if (i >= count) {
            ctx = 0;
            break;
        }
    }
    return ctx;
}
