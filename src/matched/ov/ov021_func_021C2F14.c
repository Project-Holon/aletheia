/*
 * function: func_021C2F14
 * address:  0x021C2F14
 * packet:   pkt_ov021_021C2F14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a request block and dispatches func_021C2ECC on success (EXACT*: pad).
 *
 * symbols:
 *   func_021C2F50  0x021C2F50  thumb  ov021
 *   func_021C2ECC  0x021C2ECC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

extern void func_021C2F50(char *dst, const char *src);
extern int func_0206E62C(void *a, T *t);
extern int func_021C2ECC(u32 a, u32 b);

int func_021C2F14(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0 && *(u16 *)(p + 0x34) != 0)
        r = func_0206E62C(p + *(u16 *)(p + 0x34), &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2ECC((u32)p, r);
}
