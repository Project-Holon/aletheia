/*
 * packet: pkt_ov115_021D4FA4
 * region: ov115
 * function: func_021D4FA4
 * address: 0x021D4FA4
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * status: EXACT
 * ABI: base and unsigned-long indices are full 32-bit wrapping values;
 *   only BG calls with original lsls/lsrs pairs take u8.  Template copies
 *   follow index assignment; four distinct 32-byte locals preserve layout.
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   d_021D6464 0x021D6464 data a4
 *   d_021D6444 0x021D6444 data a4
 *   d_021D6424 0x021D6424 data a4
 *   d_021D6524 0x021D6524 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
} BgTemplate;
extern const BgTemplate d_021D6464, d_021D6444, d_021D6424, d_021D6524;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void sub_02040588(u8, u32);
extern void sub_020409B4(u8);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u8, int, int, int, u8, u8, u8);

void func_021D4FA4(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6464;
    func_0203FCA0((u8)base, &t0, 0);
    sub_02040588(base, 1);
    sub_020409B4(base);
    id1 = base + 1;
    t1 = d_021D6444;
    func_0203FCA0((u8)id1, &t1, 0);
    sub_02040588(id1, 1);
    sub_020409B4(id1);
    id2 = base + 2;
    t2 = d_021D6424;
    func_0203FCA0((u8)id2, &t2, 0);
    sub_02040588(id2, 1);
    sub_020409B4(id2);
    id3 = base + 3;
    t3 = d_021D6524;
    func_0203FCA0((u8)id3, &t3, 0);
    sub_02040588(id3, 1);
    func_02040C14(id3, 0, 1, 0);
    func_02041300(id3, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id3);
}
