/*
 * function: sub_0204AFD8
 * address:  0x0204AFD8
 * packet:   pkt_0204ACEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *   sub_020307B0 0x020307B0  arm
 *
 * Tear down one entry of the 0x14-byte table hanging off +0x114 of the
 * singleton at 0x02146A74: free the two payload pointers at +0 and +4 if
 * they are set, NULL them, and mark the slot free with 1 at +0x10.
 *
 * The entry address is bound to a named local (r4) and survives both
 * calls, so neither the global nor the index multiply is recomputed after
 * the first store, unlike sub_0204ADA4 next door
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The first load reads through the register-offset form `ldr r0,[r2,r1]`
 * before the `add` that materialises the cursor; that is scheduling, not
 * a second addressing mode in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204AFD8.c \
 *       --func sub_0204AFD8 --addr 0x0204AFD8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Slot {
    void *unk_00;
    void *unk_04;
    u8    pad_08[8];
    u32   unk_10;
};

struct Sys {
    u8           pad_000[0x114];
    struct Slot *slots;
};

extern struct Sys *g_02146A74;
extern u32 sub_020307B0(void *p);

void sub_0204AFD8(u32 i)
{
    struct Slot *s = &g_02146A74->slots[i];

    if (s->unk_00 != 0) {
        sub_020307B0(s->unk_00);
        s->unk_00 = 0;
    }
    if (s->unk_04 != 0) {
        sub_020307B0(s->unk_04);
        s->unk_04 = 0;
    }
    s->unk_10 = 1;
}
