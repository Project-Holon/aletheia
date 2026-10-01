/*
 * function: func_021C2EDC
 * address:  0x021C2EDC
 * packet:   pkt_ov021_021C2EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a request block and dispatches func_021C2EBC on success (EXACT*: pad).
 *
 * symbols:
 *   func_021C2F50  0x021C2F50  thumb  ov021
 *   func_021C2EBC  0x021C2EBC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

extern void func_021C2F50(T *t);
extern int func_0206E62C(void *a, T *t);
extern int func_021C2EBC(u32 a, u32 b);

int func_021C2EDC(u8 *p)
{
    T t;
    int r;

    func_021C2F50(&t);
    if (p != 0)
        r = func_0206E62C(p + 0x3C, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2EBC((u32)p, r);
}
