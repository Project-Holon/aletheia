/*
 * packet: pkt_ov115_021D5214
 * region: ov115
 * function: func_021D5214
 * address: 0x021D5214
 * isa: thumb
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * status: EXACT
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   sub_020409B4 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   d_021D6404 0x021D6404 data a4
 *   d_021D6344 0x021D6344 data a4
 *   d_021D64E4 0x021D64E4 data a4
 *   d_021D6504 0x021D6504 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
} BgTemplate;
extern const BgTemplate d_021D6404, d_021D6344, d_021D64E4, d_021D6504;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void sub_020409B4(u8);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void func_02041300(u8, int, int, int, u8, u8, u8);

void func_021D5214(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6404;
    BG_SYS_InitBgLayer((u8)base, &t0, 0);
    sub_02040588(base, 1);
    sub_020409B4(base);
    id1 = base + 1;
    t1 = d_021D6344;
    BG_SYS_InitBgLayer((u8)id1, &t1, 0);
    sub_02040588(id1, 1);
    BG_SYS_Init(id1, 0, 1, 0);
    func_02041300(id1, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id1);
    id2 = base + 2;
    t2 = d_021D64E4;
    BG_SYS_InitBgLayer((u8)id2, &t2, 0);
    sub_02040588(id2, 1);
    sub_020409B4(id2);
    id3 = base + 3;
    t3 = d_021D6504;
    BG_SYS_InitBgLayer((u8)id3, &t3, 0);
    sub_02040588(id3, 1);
    sub_020409B4(id3);
}
