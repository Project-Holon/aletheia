/*
 * function: ISS_3DS_SYS_UpdateImpl
 * address:  0x0202BAF4
 * packet:   pkt_0202BAF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * iss_3ds_sys.c per-frame step: returns when +0x04 is zero, then runs the
 * four per-entry steps over every live entry of the 0x10-slot table.
 * The listing extent (84) runs into the 8-byte thunk at 0x0202BB40; the
 * function itself is 74 bytes.
 *
 * The kept `cmp r4, #0x10; bge` zero-trip guard (the four bytes that were
 * the whole residue in docs/notes/ISS_3DS_SYS_UpdateImpl.c.txt) is an enum-typed
 * counter (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * the same lever as its sibling ISS_3DS_SYS_ResetSources.
 *
 * symbols:
 *   sub_0202BE24   0x0202BE24  thumb
 *   ISS_3DS_SYS_StepSourceVolume  0x0202BB68  thumb
 *   ISS_3DS_SYS_StepSourcePan  0x0202BBB0  thumb
 *   ISS_3DS_SYS_ApplySourceVolume  0x0202BC78  thumb
 *   ISS_3DS_SYS_ApplySourcePan  0x0202BE00  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_UpdateImpl.c \
 *       --func ISS_3DS_SYS_UpdateImpl --addr 0x0202BAF4 --thumb --cc 1.1p1
 */
#include "../include/Obj05797.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

struct Obj0202BE24;
extern void sub_0202BE24(struct Obj0202BE24 *p);
extern void ISS_3DS_SYS_StepSourceVolume(u8 *o, int i);
extern void ISS_3DS_SYS_StepSourcePan(u8 *o, int i);
extern int ISS_3DS_SYS_ApplySourceVolume(int a0, int a1);
extern void ISS_3DS_SYS_ApplySourcePan(u8 *p, u32 i);

void ISS_3DS_SYS_UpdateImpl(u8 *o)
{
    Slot i;

    if (((struct Obj05797 *)o)->f4 == 0) {
        return;
    }
    sub_0202BE24((struct Obj0202BE24 *)o);
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)(o + i * 0x1c + 0x24) != 0) {
            ISS_3DS_SYS_StepSourceVolume(o, i);
            ISS_3DS_SYS_StepSourcePan(o, i);
            ISS_3DS_SYS_ApplySourceVolume((int)o, i);
            ISS_3DS_SYS_ApplySourcePan(o, i);
        }
    }
}
