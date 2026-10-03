/*
 * function: func_021B9118
 * address: 0x021B9118
 * packet: pkt_ov133_021B9118
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4B10 0x021F4B10 thumb ov112
 *   func_021F4AFC 0x021F4AFC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021F4B10(u8 *p, int index, int mode);
extern int func_021F4AFC(u8 *p, int index, int mode);
u16 func_021B9118(u8 *p, u8 *q, int v)
{
    int a = func_021F4B10(*(void **)(p + 0x1884), *(u16 *)q, v);
    int b = func_021F4AFC(*(void **)(p + 0x1884), *(u16 *)q, v);
    int n;
    if (a == 1) {
        if (*(int *)(q + 16) == 1) n = 6000;
        else n = 5000;
    } else if (b == 1) {
        if (*(int *)(q + 16) == 1) n = 4000;
        else n = 3000;
    } else {
        if (*(int *)(q + 16) == 1) n = 2000;
        else n = 1000;
    }
    return n + (999 - *(u16 *)q);
}
