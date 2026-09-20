/*
 * function: func_02071EAC
 * address:  0x02071EAC
 * packet:   pkt_02071DD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Struct02071EAC_Arg {
    s32 unk00;
    u32 unk04;
    u32 pad08[2];
    u32 unk10;
    s32 unk14;
    u32 pad18;
    s32 unk18;
    s32 unk1c;
    u32 pad20[3];
    u16 unk2c;
    u16 unk2e;
    s32 unk30;
    s32 unk34;
};

void func_02071EAC(struct Struct02071EAC_Arg *dst, const struct Struct02071EAC_Arg *src)
{
    s32 v18 = src->unk18;
    s32 v1c = src->unk1c;
    dst->unk00 = v18;
    dst->unk14 = v1c;
    dst->unk04 = 0;
    dst->unk30 = (0x1000 - v18) * src->unk2c << 3;
    dst->unk34 = (0x1000 - v1c) * src->unk2e << 3;
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
