/*
 * function: func_021B682C
 * address:  0x021B682C
 * packet:   pkt_021B682C
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020515B4  0x020515B4  arm
 */

extern int func_020515B4(void *p, int b, int c);

void func_021B682C(int *p, int a)
{
    int buf[3] = {0, 0, 0};

    func_020515B4(*(void **)((char *)p + 0x2c), a, (int)buf);
}
