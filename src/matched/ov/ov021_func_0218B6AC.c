/*
 * function: func_0218B6AC
 * address:  0x0218B6AC
 * packet:   pkt_ov021_0218B6AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_0218B6AC(void *ctx)
{
    void *list;
    void *e;
    int n;
    int i;
    int cnt;

    list = func_02012934(func_020120F4(ctx));
    n = func_0201AA18(list);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        e = func_0201AB28(list, i);
        if (func_02017E1C(e, 0x4C, 0) == 0 && func_02017E1C(e, 0xA0, 0) != 0)
            cnt++;
    }
    return cnt;
}
