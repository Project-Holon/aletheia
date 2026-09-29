/*
 * function: func_021B91FC
 * address:  0x021B91FC
 * packet:   pkt_ov070_021B91FC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008550  0x02008550  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 */

extern int func_02008550(int);
extern int func_0204AC18(int, int, int, int, int, int, unsigned short);
extern int func_0204A6C8(int, int, int, int, unsigned short);
extern int func_0204AF28(int, int, int, unsigned short);

void func_021B91FC(char *p, int bg)
{
    int a, b, c, d;
    int r = func_02008550(*(int *)(p + 8));
    if (r == 0) {
        a = 0x10;
        b = 0xf;
        c = 0xe;
        d = 0xd;
    } else if (r == 1) {
        a = 0xc;
        b = 0xb;
        c = 0xa;
        d = 9;
    }
    *(int *)(p + 0x590) = func_0204AC18(bg, a, 0, 0xc0, 0, 4, *(unsigned short *)(p + 0x544));
    *(int *)(p + 0x594) = func_0204A6C8(bg, b, 0, 0, *(unsigned short *)(p + 0x544));
    *(int *)(p + 0x598) = func_0204AF28(bg, c, d, *(unsigned short *)(p + 0x544));
}
