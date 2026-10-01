/*
 * function: func_021FFB20
 * address: 0x021FFB20
 * packet: pkt_ov135_021FFB20
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed offset locals b then a, with two literal assignments each,
 * reproduce the dead stack stores; compound updates reverse the first pair.
 * symbols:
 *   func_021FFC8C 0x021FFC8C thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FFC8C(void *, void *, int, int, int);
extern void func_0204B878(u32, u16);
extern void func_0204B3DC(u32, int);
extern void func_020061E4(int);
void func_021FFB20(u8 *p, int count, int flag)
{
    int i;
    int b, a;
    if (count != 0 && flag == 1) func_020061E4(0x676);
    a = 0xE5C;
    a = 0xEA0;
    b = 0x302;
    b = 0x32E;
    for (i = 0; i < 7; i++) {
        if (i < count) {
            func_021FFC8C(p + 0xE5C, *(void **)(p + a), i, *(u8 *)(p + i * 0x128 + b), *(u8 *)(p + i * 0x128 + 0x302));
            if (flag != 0) func_0204B878(*(u32 *)(p + i * 4 + 0xD10), i * 4 + 14);
            else func_0204B878(*(u32 *)(p + i * 4 + 0xD10), i * 4 + 17);
            func_0204B3DC(*(u32 *)(p + i * 4 + 0xD10), 1);
        } else {
            func_0204B3DC(*(u32 *)(p + i * 4 + 0xD10), 0);
        }
    }
}
