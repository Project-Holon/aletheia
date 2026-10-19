/*
 * function: UI_SetSoftResetInhibit
 * address:  0x0203515C
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The set half of a set/clear pair on the flag byte at +0x39, right after
 * the two tail-call veneers in the same block; no lr push, so disasm.py
 * never labels it. Twin of UI_ClearFlags39 (clear).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_SetSoftResetInhibit.c \
 *       --func UI_SetSoftResetInhibit --addr 0x0203515C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj0203515C {
    unsigned char pad[0x39];
    u8 unk39;
};

void UI_SetSoftResetInhibit(struct Obj0203515C *p, u8 mask)
{
    p->unk39 |= mask;
}
