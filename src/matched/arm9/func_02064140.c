/*
 * function: NNSi_G2dSrtcInitControl
 * address:  0x02064140
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dSrtcResetSrtData    0x02064150  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct O02064140 {
    u32 unk0;
};

extern int NNSi_G2dSrtcResetSrtData(int a0);

void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a)
{
    o->unk0 = a;
    NNSi_G2dSrtcResetSrtData((int)o);
}
