/*
 * function: func_0217CA1C
 * address: 0x0217CA1C
 * packet: pkt_ov018_0217CA1C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217BED4 0x0217BED4 thumb ov018
 *   func_02185588 0x02185588 thumb ov020
 */
typedef struct { int x, y, z; } V12;
extern int func_0217BED4(int, V12 *);
extern void *func_02185588(void *, int, V12 *);
void *func_0217CA1C(void *p)
{
    V12 v;
    func_0217BED4(0x117, &v);
    return func_02185588(p, 0x117, &v);
}
