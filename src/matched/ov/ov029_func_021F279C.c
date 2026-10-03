/*
 * function: func_021F279C
 * address: 0x021F279C
 * packet: pkt_ov029_021F279C
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021F251C 0x021F251C thumb ov029
 *   d_021F3554 0x021F3554 data a4
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int d_021F3554;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, unsigned short tag);
extern void func_021F251C(u8 *, int, int, int, int);
void *func_021F279C(int a, int b, int c, int d)
{
    u8 *p;
    p = func_02030734(0x70, 0x468, 1, (const char *)&d_021F3554, 0x1147);
    func_021F251C(p, a, b, c, d);
    return p;
}
