/*
 * unit:     no
 * function: func_02039A2C
 * address:  0x02039A2C
 * packet:   pkt_020399B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

extern int func_02039338(void);
extern void *func_0203996C(int v);
void func_02039A2C(int a)
{
    char *q;
    if (func_02039338())
        return;
    q = (char *)func_0203996C(0xff) + a * 2;
    q[0x2c] = (char)a;
    q[0x2d] = 1;
}
