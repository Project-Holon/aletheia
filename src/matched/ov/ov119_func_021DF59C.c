/*
 * function: func_021DF59C
 * address: 0x021DF59C
 * packet: pkt_ov119_021DF59C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76EC 0x021E76EC data a4
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021E131C 0x021E131C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF548 0x021DF548 thumb ov119
 */
typedef struct { int a, b; } Pair;
extern const Pair d_021E76EC;
extern int func_021E12AC(void *);
extern void func_021E131C(void *, int *, int, int, int);
extern void func_021D8E84(void *, int);
extern void func_021DF548(void *);
void func_021DF59C(void *p)
{
    Pair t;
    if (func_021E12AC(p)) {
        t = d_021E76EC;
        func_021E131C(p, (int *)&t, 2, 0x20, 0xc);
        func_021D8E84(p, (int)func_021DF548);
    }
}
