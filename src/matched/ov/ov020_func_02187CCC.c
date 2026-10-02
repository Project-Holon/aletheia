/*
 * function: func_02187CCC
 * address: 0x02187CCC
 * packet: pkt_ov020_02187CCC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02187BBC 0x02187BBC thumb ov020
 *   func_02187C20 0x02187C20 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02187BBC(char *, int);
extern void func_02187C20(char *, int *, int);
void func_02187CCC(char *p, int *s)
{
    int st;
    st = func_02187BBC(p, *s);
    if (*s != st) func_02187C20(p, s, st);
}
