/*
 * function: func_021E0BC4
 * address: 0x021E0BC4
 * packet: pkt_ov119_021E0BC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0BE8 0x021E0BE8 thumb ov119
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned func_02039CB4(struct Link *, unsigned, unsigned);
extern void func_021D8E84(void *, int);
extern void func_021E0BE8(char *p);
void func_021E0BC4(void *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, 8)) {
        func_021D8E84(p, (int)func_021E0BE8);
    }
}
