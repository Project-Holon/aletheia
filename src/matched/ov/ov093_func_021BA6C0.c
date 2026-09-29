/*
 * function: func_021BA6C0
 * address:  0x021BA6C0
 * packet:   pkt_ov093_021BA6C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B90F8  0x021B90F8  thumb  ov093
 *   func_021CD924  0x021CD924  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;

struct T {
    int w[6];
};

extern int func_021B90F8(char *);
extern void *func_021CD924(void *, int *);
extern void func_02082D44(void *, void *, int);

void func_021BA6C0(char *p)
{
    int n;
    void *src;

    if (func_021B90F8(p)) {
        src = func_021CD924(*(void **)(p + (u8)p[0x46c] * 4 + 0x10), &n);
        if (src) {
            func_02082D44(src, *(void **)(*(char **)p + 0x94), n);
            *(int *)(*(char **)p + 0x98) = n;
            *(struct T *)(*(char **)p + 0x9c) = *(struct T *)(p + 0x3f0);
        }
    }
}
