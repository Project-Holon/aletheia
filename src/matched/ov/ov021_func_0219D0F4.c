/*
 * function: func_0219D0F4
 * address:  0x0219D0F4
 * packet:   pkt_ov021_0219D0F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219D064  0x0219D064  thumb  ov021
 *   func_0219D1F8  0x0219D1F8  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_0216D4F0(void *p);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern void func_0219D064(int *, int *);
extern void func_0219D1F8(int *);

void func_0219D0F4(int *obj)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short sp[2];

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && *((unsigned char *)p + 0xd) == 1) {
            if (func_0219CBD4((u32)obj, *(unsigned short *)(p + 2), (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                func_0219D064(obj, p);
                func_0219D1F8(p);
            }
        }
    }
}
