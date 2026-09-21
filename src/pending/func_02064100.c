/*
 * function: func_02064100
 * address:  0x02064100
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (15 concrete bytes out)
 */

typedef unsigned short u16;
typedef short s16;

typedef struct Struct02064100 {
    int unk0;
    s16 unk4;
    s16 unk6;
    int unk8;
    int unkC;
    s16 unk10;
    u16 unk12;
} Struct02064100;

void func_02064100(Struct02064100 *r0, s16 r1)
{
    if (r0->unk0 == 1) {
        r0->unk12 |= 4;
        r0->unk10 = r1;
    }
}
