/*
 * function: PDW_POSTMAN_GetUnreceivableItem
 * address:  0x021B7740
 * packet:   pkt_ov021_021B7740
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
struct BigObj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
typedef unsigned short u16;
extern u16 func_02009310(const struct Sub02009210Obj *obj, int i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *ctx, void *a, int b, int key);

void *PDW_POSTMAN_GetUnreceivableItem(void *p, int key, void *q, int idx)
{
    void *ctx;
    int i;
    int n;
    void *a;
    int b;

    ctx = GAME_DATA_GetMyItem(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = (void *)func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0) {
                if (n == idx)
                    return a;
                n++;
            }
        }
    }
    return 0;
}
