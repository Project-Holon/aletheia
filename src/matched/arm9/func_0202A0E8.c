/*
 * function: func_0202A0E8
 * address:  0x0202A0E8
 * packet:   pkt_0202A084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02029F8C  0x02029F8C  thumb
 *   func_0202A084  0x0202A084  thumb
 */

typedef unsigned int u32;

extern int func_02029F8C(void *p);
extern void func_0202A084(void *p, int a);

void func_0202A0E8(u32 *p)
{
    int r = func_02029F8C(p);

    switch (*(u32 *)p) {
    case 0:
        break;
    case 1:
        if (r == 0) {
            func_0202A084(p, 0);
        }
        break;
    case 2:
        break;
    case 3:
        if (r == 0) {
            func_0202A084(p, 2);
        }
        break;
    }
}
