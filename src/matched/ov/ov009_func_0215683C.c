/*
 * function: func_0215683C
 * address: 0x0215683C
 * packet: pkt_ov009_0215683C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021A1C5C 0x021A1C5C data ov009 a1
 *   func_02034714 0x02034714 arm
 *   func_021688FC 0x021688FC arm ov009
 */
extern char d_021A1C5C[];
extern void func_02034714(char *, int, char *);
extern int func_021688FC(char *, unsigned long);
int func_0215683C(char *a, int b)
{
    if (b > 32)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    return func_021688FC(a, b);
}
