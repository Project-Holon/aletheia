/*
 * function: func_02067AC0
 * address:  0x02067AC0
 * packet:   pkt_02067AC0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sOamSoftEmuContext   0x02148B48  data
 *
 * Seeds the multi-cell renderer's working block from the caller's parameter
 * record: the record pointer at +0x2C, six of its words copied to +0x40..+0x50
 * and +0x64/+0x68, the four state words at +0x48..+0x5C zeroed, the blend
 * word at +0x60 set to 0x1000, and the shadow of the +0x34 field refreshed at
 * +0x6C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067AC0.c \
 *       --func func_02067AC0 --addr 0x02067AC0 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Src02067AC0 {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

struct Work02067AC0 {
    u8  pad_00[0x2c];
    u32 unk_2c;
    u8  pad_30[4];
    u32 unk_34;
    u8  pad_38[8];
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5c;
    u32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 unk_6c;
};

extern struct Work02067AC0 *sOamSoftEmuContext;

void func_02067AC0(struct Src02067AC0 *src)
{
    struct Work02067AC0 *w = sOamSoftEmuContext;

    w->unk_2c = (u32)src;
    w->unk_40 = src->unk_00;
    w->unk_44 = src->unk_04;
    w->unk_48 = 0;
    w->unk_4c = src->unk_08;
    w->unk_50 = src->unk_0c;
    w->unk_54 = 0;
    w->unk_58 = 0;
    w->unk_5c = 0;
    w->unk_60 = 0x1000;
    w->unk_64 = src->unk_10;
    w->unk_68 = src->unk_14;
    w->unk_6c = w->unk_34;
}
