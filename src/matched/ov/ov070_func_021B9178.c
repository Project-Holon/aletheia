/*
 * function: func_021B9178
 * address:  0x021B9178
 * packet:   pkt_ov070_021B9178
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 */

extern int func_02008550(int);
extern void func_02049B68(int, int, int, int, int, unsigned short);
extern int func_02049740(int, int, int, int, int, unsigned short);
extern void func_02049990(int, int, int, int, unsigned short, int, int, unsigned short);

void func_021B9178(char *p, int bg)
{
    int a, b, c, t;
    int r = func_02008550(*(int *)(p + 8));
    if (r == 0) {
        a = 4;
        b = 3;
        c = 5;
    } else if (r == 1) {
        a = 1;
        b = 0;
        c = 2;
    }
    func_02049B68(bg, a, 0, 0, 0x20, *(unsigned short *)(p + 0x544));
    t = func_02049740(bg, b, 0, 0, 0, *(unsigned short *)(p + 0x544));
    *(int *)(p + 0x7F8) = t;
    func_02049990(bg, c, 0, 0, (unsigned short)t, 0, 0, *(unsigned short *)(p + 0x544));
}
