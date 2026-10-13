/*
 * function: G3D_SYSTEM_InitResourceByKind
 * address:  0x02046C9C
 * packet:   pkt_02046C9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Initialise a counted record: the mode picks the halfword written at +2
 * (2, 3 and 4 for modes 1, 2 and 3), then the caller's value goes into the
 * word at +4 and the constant 0x48BF into the halfword at +0.  Modes other
 * than one to three leave the +2 field alone entirely, which is why the
 * last arm stores inside its own arm and the first two meet at a shared
 * store: the comparison chain tests 1, 2 and 3 in that order and falls
 * through to the tail for everything else.
 *
 * The function saves no lr because it calls nothing, so disasm.py gives it
 * no label; 0x48BF is too wide for a `mov` and is the pool word at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_InitResourceByKind.c \
 *       --func G3D_SYSTEM_InitResourceByKind --addr 0x02046C9C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
};

void G3D_SYSTEM_InitResourceByKind(struct Rec *rec, u32 mode, u32 value)
{
    switch (mode) {
    case 1:
        rec->unk_02 = 2;
        break;
    case 2:
        rec->unk_02 = 3;
        break;
    case 3:
        rec->unk_02 = 4;
        break;
    }

    rec->unk_04 = value;
    rec->unk_00 = 0x48BF;
}
