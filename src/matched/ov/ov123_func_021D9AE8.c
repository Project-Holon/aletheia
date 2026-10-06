/*
 * function: func_021D9AE8
 * address:  0x021D9AE8
 * packet:   pkt_ov123_021D9AE8
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BG-layer init, same shape as func_021D6100 (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 * symbols:
 *   d_021DA8A8      0x021DA8A8  data
 *   func_0203FCA0   0x0203FCA0  arm
 *   func_020409B4   0x020409B4  arm
 *   func_02040588   0x02040588  arm
 *   func_02040C14   0x02040C14  arm
 *   func_02041300   0x02041300  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern const struct BgTemplate d_021DA8A8[8];
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);

void func_021D9AE8(void *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021DA8A8[1];
    func_0203FCA0(0, &b[7], 0);
    func_02040588(0, 1);
    func_020409B4(0);

    b[6] = d_021DA8A8[4];
    func_0203FCA0(1, &b[6], 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021DA8A8[3];
    func_0203FCA0(2, &b[5], 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021DA8A8[7];
    func_0203FCA0(3, &b[4], 0);
    func_02040588(3, 1);
    func_02040C14(3, 0, 1, 0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021DA8A8[5];
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021DA8A8[0];
    func_0203FCA0(5, &b[2], 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021DA8A8[6];
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021DA8A8[2];
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_02040C14(7, 0, 1, 0);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(7);
}
