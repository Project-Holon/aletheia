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
#include "../include/Obj08050.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(void *a, u32 b);
extern u32 func_0201AA18(void *m);
extern void *func_0201AB28(void *m, u32 c);
extern void *func_020173F0(u16 species, u16 level, unsigned long long id, u16 heap);
extern u32 func_020173EC(void);
extern void func_02082D44(void *dst, const void *src, int n);

void *func_021D8D4C(void **a, int b, int c, char *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = ((struct Obj08050 *)p)->f630;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = func_0201747C(func_02007A18(a, b, c), ((struct Obj08050 *)p)->f5F4);
    } else {
        void *m = ((struct Obj08050 *)p)->f838;
        if (c >= (int)func_0201AA18(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = func_020173F0(1, 1, 1, ((struct Obj08050 *)p)->f5F4);
            int sz = func_020173EC();
            func_02082D44(func_0201AB28(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}
