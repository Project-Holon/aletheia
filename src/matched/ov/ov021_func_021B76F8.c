/*
 * function: func_021B76F8
 * address:  0x021B76F8
 * packet:   pkt_ov021_021B76F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201292C  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct BigObj;
struct Sub02009210Obj;
extern void *func_0201292C(const struct BigObj *p);
extern void *func_02009310(void *p, u32 i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *ctx, void *a, int b, int key);

int func_021B76F8(void *p, int key, void *q)
{
    void *ctx;
    u32 i;
    int n;
    void *a;
    int b;

    ctx = func_0201292C(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0)
                n++;
        }
    }
    return n;
}
