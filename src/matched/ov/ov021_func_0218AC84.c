/*
 * function: func_0218AC84
 * address:  0x0218AC84
 * packet:   pkt_ov021_0218AC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_021AA944 on the position's object; when it declines, calls
 * func_021AA80C and returns 0.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02188CE8  0x02188CE8  thumb
 *   func_021AA944  0x021AA944  thumb
 *   func_021AA80C  0x021AA80C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct Ctx;
struct Self;
extern void *func_02012EBC(struct Big *p);
extern u32 func_02188CE8(u8 *p);
extern int func_021AA944(struct Self *self);
extern void func_021AA80C(struct Ctx *ctx);

int func_0218AC84(u8 *pos, void *msg, void *sys)
{
    void *obj;
    int r;

    func_02012EBC(sys);
    obj = (void *)func_02188CE8(pos);
    r = func_021AA944(obj);
    if (r == 0) {
        func_021AA80C(obj);
        return 0;
    }
    return r;
}
