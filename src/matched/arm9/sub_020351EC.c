/*
 * function: UI_SetIntrData
 * address:  0x020351EC
 * packet:   pkt_02035080
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A plain two-field setter, same shape as UI_SetSuspendHook/UI_SetResumeHook: "str
 * r1,[r0,#8]; str r2,[r0,#0xc]; bx lr", twelve bytes, no relocations. No lr
 * push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_SetIntrData.c \
 *       --func UI_SetIntrData --addr 0x020351EC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj020351EC {
    unsigned char pad[8];
    u32 unk08;
    u32 unk0C;
};

void UI_SetIntrData(struct Obj020351EC *p, u32 a, u32 b)
{
    p->unk08 = a;
    p->unk0C = b;
}
