/*
 * function: func_0202BAF4
 * address:  0x0202BAF4
 * packet:   pkt_0202BAF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * iss_3ds_sys.c per-frame step: returns when +0x04 is zero, then runs the
 * four per-entry steps over every live entry of the 0x10-slot table.
 * The listing extent (84) runs into the 8-byte thunk at 0x0202BB40; the
 * function itself is 74 bytes.
 *
 * The kept `cmp r4, #0x10; bge` zero-trip guard (the four bytes that were
 * the whole residue in docs/notes/func_0202BAF4.c.txt) is an enum-typed
 * counter (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * the same lever as its sibling func_0202BA24.
 *
 * symbols:
 *   sub_0202BE24   0x0202BE24  thumb
 *   func_0202BB68  0x0202BB68  thumb
 *   func_0202BBB0  0x0202BBB0  thumb
 *   func_0202BC78  0x0202BC78  thumb
 *   func_0202BE00  0x0202BE00  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BAF4.c \
 *       --func func_0202BAF4 --addr 0x0202BAF4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

extern void sub_0202BE24(u8 *o);
extern void func_0202BB68(u8 *o, int i);
extern void func_0202BBB0(u8 *o, int i);
extern void func_0202BC78(u8 *o, int i);
extern void func_0202BE00(u8 *o, int i);

void func_0202BAF4(u8 *o)
{
    Slot i;

    if (*(u32 *)(o + 4) == 0) {
        return;
    }
    sub_0202BE24(o);
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)(o + i * 0x1c + 0x24) != 0) {
            func_0202BB68(o, i);
            func_0202BBB0(o, i);
            func_0202BC78(o, i);
            func_0202BE00(o, i);
        }
    }
}
