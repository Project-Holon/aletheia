/*
 * function: CLACT_ReleaseCharacter
 * address:  0x0204A8D4
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   VMAN_IsHandleInvalid  0x02034640  arm
 *   VMAN_Free  0x020346B8  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *
 * Retire one slot of the 0x40-byte table at +0x10c of the singleton behind
 * 0x02146A74.  The two eight-byte sub-objects at +0x2c and +0x34 are returned
 * to their owners (+0x104 and +0x108) unless VMAN_IsHandleInvalid says they are
 * already detached, the payload at +0x24 is released, and the flag word at
 * +0x3c ends as "top bit set, everything else clear".
 *
 * Nothing is cached: every one of the eleven accesses reloads g_ClactSystem and
 * re-indexes, because each intervening store may alias the global pointer
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md read from
 * the other side, the same shape as src/matched/CLACT_ReleasePalette.c).  The payload
 * pointer is the one exception: it is bound to a local, which is why the `bl`
 * to GFL_HEAP_Free needs no load in front of it.
 *
 * +0x3c is a bitfield word, not a mask word.  The evidence is the guard:
 * `lsl #31` / `lsrs #31` to read bit 0, where a plain `x & 1` compiles to
 * `ands` (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 * The other two writes confirm the partition: `bic`+`orr` with 0x80000000 is
 * an assignment to the one-bit field at bit 31, and `and #0x80000001` is an
 * assignment of zero to the thirty-bit field between them.  Field order is
 * LSB first, as in CLACT_ReleasePalette.c.
 *
 * The release is the fall-through and the flag clear is the `else`, so the
 * guard is spelled `== 0` and the short arm is left to be if-converted into
 * `bicne`/`strne` (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ReleaseCharacter.c \
 *       --func CLACT_ReleaseCharacter --addr 0x0204A8D4 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Handle {
    u32 unk_00;
    u32 unk_04;
};

struct Slot {
    u8            pad_00[0x24];
    void         *unk_24;
    u32           unk_28;
    struct Handle unk_2c;
    struct Handle unk_34;
    u32           unk_3c_0  : 1;
    u32           unk_3c_1  : 30;
    u32           unk_3c_31 : 1;
};

extern struct Mgr *g_ClactSystem;

struct Sentinel;
extern int VMAN_IsHandleInvalid(struct Sentinel *p);
struct Owner;
extern void VMAN_Free(struct Owner *owner, struct Sentinel *p);
extern u32 GFL_HEAP_Free(void *p);

void CLACT_ReleaseCharacter(u32 i)
{
    void *payload;

    if (VMAN_IsHandleInvalid((struct Sentinel *)(&g_ClactSystem->owner_slots[i].unk_2c)) == 0) {
        VMAN_Free(g_ClactSystem->unk_104, (struct Sentinel *)(&g_ClactSystem->owner_slots[i].unk_2c));
    }

    if (VMAN_IsHandleInvalid((struct Sentinel *)(&g_ClactSystem->owner_slots[i].unk_34)) == 0) {
        VMAN_Free(g_ClactSystem->unk_108, (struct Sentinel *)(&g_ClactSystem->owner_slots[i].unk_34));
    }

    payload = g_ClactSystem->owner_slots[i].unk_24;
    if (payload != 0) {
        if (g_ClactSystem->owner_slots[i].unk_3c_0 == 0) {
            GFL_HEAP_Free(payload);
        } else {
            g_ClactSystem->owner_slots[i].unk_3c_0 = 0;
        }
        g_ClactSystem->owner_slots[i].unk_24 = 0;
    }

    g_ClactSystem->owner_slots[i].unk_3c_31 = 1;
    g_ClactSystem->owner_slots[i].unk_3c_1 = 0;
}
