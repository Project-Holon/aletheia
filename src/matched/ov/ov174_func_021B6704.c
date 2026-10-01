/*
 * function: func_021B6704
 * address: 0x021B6704
 * packet: pkt_ov174_021B6704
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: assign the getter result to width before dividing it; the combined call/divide swaps table and stack-address registers. Named x/y alone stayed DIFF12; split-assign(width) reached EXACT.
 * symbols:
 *   func_021B7360 0x021B7360 thumb ov174
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021B7360(void *);
extern void func_0204B404(void *, u16 *, int);
extern void func_0204B3DC(void *, unsigned);
extern void func_0204B9A0(void *);
extern const u8 d_021B7380[][2];
void func_021B6704(u8 *p, int index)
{
    u16 point[2];
    unsigned width;
    unsigned x;
    unsigned y;
    width = func_021B7360(*((void **) ((p + 28) + (index * 4))));
    width = width / 2;
    x = ((d_021B7380[index][0] * 8) + 80) + width;
    point[0] = x;
    y = (d_021B7380[index][1] * 8) + 16;
    point[1] = y;
    func_0204B404(*((void **) (p + 84)), point, 0);
    func_0204B3DC(*((void **) (p + 84)), 1);
    func_0204B9A0(*((void **) (p + 84)));
}
