/*
 * function: NNSi_G2dOamSoftEmuEnd
 * address:  0x02067CB0
 * packet:   pkt_02067BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sOamSoftEmuContext  0x02148B48  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Struct02067CB0_Inner {
    u8 pad[0x14];
    u32 unk14;
};

struct Struct02067CB0 {
    struct Struct02067CB0_Inner *inner; /* 0x00 */
    u8 pad_04[0x0c];
    u32 unk10;                            /* 0x10 */
    u8 pad_14[0x14];
    u32 unk28;                            /* 0x28 */
    u32 unk2c;                            /* 0x2c */
};

extern struct Struct02067CB0 *sOamSoftEmuContext;

void NNSi_G2dOamSoftEmuEnd(void)
{
    struct Struct02067CB0 *p = sOamSoftEmuContext;

    if (p->inner->unk14 == 0) {
        volatile u32 *reg = (volatile u32 *)0x04000440;
        reg[0] = 0;
        reg[2] = 1;
        reg[0] = 1;
    } else {
        p->unk10 = 0;
        sOamSoftEmuContext->unk2c = 0;
        sOamSoftEmuContext->unk28 = 0;
    }
    sOamSoftEmuContext = 0;
}
