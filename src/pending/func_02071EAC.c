/*
 * function: func_02071EAC
 * address:  0x02071EAC
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * note:     re-verified 2026-09-20: DIFF; see verify output
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Struct02071EAC_Arg {
    s32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1c;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u16 unk2c;
    u16 unk2e;
    s32 unk30;
    s32 unk34;
};

void func_02071EAC(struct Struct02071EAC_Arg *dst, struct Struct02071EAC_Arg *src)
{
    dst->unk00 = src->unk18;
    dst->unk14 = src->unk1c;
    dst->unk04 = 0;
    dst->unk30 = (0x1000 - src->unk18) * src->unk2c << 3;
    dst->unk34 = (0x1000 - src->unk1c) * src->unk2e << 3;
    dst->unk10 = 0;
}

void func_02071EFC(struct Struct02071EAC_Arg *dst)
{
    dst->unk00 = 0x1000;
    dst->unk04 = 0;
    dst->unk10 = 0;
    dst->unk14 = 0x1000;
    dst->unk30 = 0;
    dst->unk34 = 0;
}
