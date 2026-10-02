/*
 * function: func_021DD26C
 * address: 0x021DD26C
 * packet: pkt_ov093_021DD26C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DD368 0x021DD368 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int);
extern u8 func_021DD368(void *, int);
extern void func_021DD044(void *, void *, int);
void func_021DD26C(void *a, void *b, int c)
{
    int v;
    if (c == func_021D775C(2)) {
        v = func_021D775C(0x2e);
        if (v != 2 && v != 0) return;
        if (func_021DD368(b, c) != 4)
            func_021DD044(a, b, c);
    }
}
