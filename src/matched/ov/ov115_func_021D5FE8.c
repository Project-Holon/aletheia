/*
 * function: func_021D5FE8
 * address: 0x021D5FE8
 * packet: pkt_ov115_021D5FE8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D6544 0x021D6544 data a2
 *   func_0201FDA0 0x0201FDA0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 a, b, c, d; u16 e; } Record;
extern const Record d_021D6544;
extern void *func_0201FDA0(const Record *, u16, u8, u8, u16);
void func_021D5FE8(u8 *p, int mode, int n) {
    Record r = d_021D6544;
    r.e = *(int *)p;
    switch (mode) {
    case 0: r.b = 24; r.c = 13; break;
    case 1: r.b = 24; r.c = 19; break;
    }
    func_0201FDA0(&r, r.e, 12, n, *(u16 *)(p + 0x4c));
}
