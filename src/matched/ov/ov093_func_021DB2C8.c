/*
 * function: func_021DB2C8
 * address: 0x021DB2C8
 * packet: pkt_ov093_021DB2C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021DB318 0x021DB318 thumb ov093
 */
typedef unsigned short u16;
extern int func_021D775C(int);
extern u16 func_021D70A8(void *p);
extern void func_021DB318(int,void *,int);

void func_021DB2C8(void *a, void *b, int c)
{
    int v;
    if (c == func_021D775C(2)) {
        v = func_021D775C(16);
        if (v != func_021D70A8(a)) func_021DB318((int)a, b, c);
    }
}
