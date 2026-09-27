/*
 * function: func_021D8D4C
 * address:  0x021D8D4C
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned short u16;

extern int func_02007A18(int a, int b, int c);
extern int func_0201747C(int a, int b);
extern int func_0201AA18(int m);
extern void *func_0201AB28(int m, int c);
extern void *func_020173F0(unsigned int species, unsigned int level,
                           unsigned long long id, unsigned int heap);
extern int func_020173EC(void);
extern void func_02082D44(void *dst, const void *src, int n);

int func_021D8D4C(int a, int b, int c, char *p)
{
    int n, res = 0;

    if (b == -1)
        goto out;
    n = *(int *)(p + 0x630);
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = func_0201747C(func_02007A18(a, b, c), *(u16 *)(p + 0x5f4));
    } else {
        int m = *(int *)(p + 0x838);
        if (c >= func_0201AA18(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = func_020173F0(1, 1, 1, *(u16 *)(p + 0x5f4));
            int sz = func_020173EC();
            func_02082D44(func_0201AB28(m, c), mon, sz);
            res = (int)mon;
        }
    }
out:
    return res;
}
