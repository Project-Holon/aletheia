/*
 * function: func_021B6338
 * address:  0x021B6338
 * packet:   pkt_ov179_021B6338
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049F78  0x02049F78  arm
 *   func_02082A90  0x02082A90  arm
 *   func_020307B0  0x020307B0  arm
 */

extern int func_02049F78(int, int, void *, int);
extern void func_02082A90(int, int, int);
extern void func_020307B0(int);

void func_021B6338(void *obj, int a, int b)
{
    void *ptr;
    int t;
    char *p;

    t = func_02049F78(*(int *)((char *)obj + 4), b, &ptr, 0x807f);
    p = (char *)obj + 8 + a * 0x2004;
    *(int *)(p + 0x2000) = *(int *)((char *)ptr + 8);
    func_02082A90(*(int *)((char *)ptr + 0xc), (int)p, *(int *)(p + 0x2000));
    func_020307B0(t);
}
