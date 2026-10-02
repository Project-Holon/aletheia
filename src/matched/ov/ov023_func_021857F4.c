/*
 * function: func_021857F4
 * address: 0x021857F4
 * packet: pkt_ov023_021857F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
typedef unsigned char u8;
extern char *func_02184180(u8 *, u8);
extern void func_0201F02C(void *, int, char *);
void func_021857F4(char *p, int a, int i)
{
    char *v;
    v = func_02184180(**(u8 ***)(p + 4), (u8)i);
    if (v != 0)
        func_0201F02C(*(void **)(p + 0x10), a, v);
}
