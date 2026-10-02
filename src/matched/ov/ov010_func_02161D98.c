/*
 * function: func_02161D98
 * address: 0x02161D98
 * packet: pkt_ov010_02161D98
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02161E78 0x02161E78 thumb ov010
 */
typedef unsigned short u16;
extern void func_02161E78(unsigned char *);
void func_02161D98(char *p)
{
    int i;
    char *b;
    char *a;
    *(u16 *)p = 0;
    *(u16 *)(p + 2) = 2;
    a = p + 8;
    b = p + 0xF8;
    for (i = 0; i < 10; i++) {
        func_02161E78((unsigned char *)(a + i * 24));
        func_02161E78((unsigned char *)(b + i * 24));
    }
}
