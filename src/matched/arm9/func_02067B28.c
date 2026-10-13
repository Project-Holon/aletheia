/*
 * function: NNS_G2dSetRndCoreCurrentMtx2D
 * address:  0x02067B28
 * packet:   pkt_02067AC0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sRndCoreInstance       0x02148B48  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S02067B28 {
    u8  pad[0x28];
    u32 unk28;
    u32 unk2c;
};

extern struct S02067B28 *sRndCoreInstance;

void NNS_G2dSetRndCoreCurrentMtx2D(u32 a, u32 b)
{
    struct S02067B28 *p = sRndCoreInstance;

    p->unk2c = a;
    p->unk28 = b;
}
