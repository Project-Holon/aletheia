/*
 * unit:     yes
 * function: func_021B9BA0, func_021B9BAC
 * address:  0x021B9BA0
 * packet:   pkt_ov071_021B9BA0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two thunks advancing a pointer by 8.
 *
 * symbols:
 *   func_021B6B38  0x021B6B38  thumb  ov071
 *   func_021B6B70  0x021B6B70  thumb  ov071
 */

void func_021B9BA0(void *p)
{
    void func_021B6B38(void *);
    func_021B6B38((char *)p + 8);
}

void func_021B9BAC(void *p, int a)
{
    void func_021B6B70(void *, int);
    func_021B6B70(p, a + 8);
}
