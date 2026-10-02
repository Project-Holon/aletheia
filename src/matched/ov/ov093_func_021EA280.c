/*
 * function: func_021EA280
 * address:  0x021EA280
 * packet:   pkt_ov093_021EA280
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern int func_021B8D8C(void *p, void *a, u8 b);

void func_021EA280(char *ctx, u8 n, int b, const u8 *c, u16 e)
{
    u8 *t;
    u32 i;

    t = func_021E9100((u8 *)ctx, 0x14);
    *(int *)(t + 0xc) = b;
    t[6] = n;
    *(u16 *)(t + 0x10) = e;
    *(u16 *)(t + 8) = 0;
    for (i = 0; i < n; i++) {
        t[i] = func_021B8D8C(*(void **)ctx, *(void **)(ctx + 8), c[i]);
    }
}
