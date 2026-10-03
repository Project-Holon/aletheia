/*
 * function: func_021B6554
 * address:  0x021B6554
 * packet:   pkt_ov070_021B6554
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_0203633C  0x0203633C  arm
 *   func_021B6300  0x021B6300  thumb  ov070
 *   func_021B6374  0x021B6374  thumb  ov070
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Obj;
extern int func_021B61C8(u8 *p);
extern unsigned int func_0203633C(void);
extern int func_021B6300(struct Obj *o, int n, int k);
extern int func_021B6374(struct Obj *o, int n, int k);

int func_021B6554(void *o)
{
    int res = 0;
    int k;
    u32 cnt;

    k = func_021B61C8(o);
    if (func_0203633C() & 0x80) {
        res = func_021B6300(o, k, 1);
    } else if (func_0203633C() & 0x40) {
        res = func_021B6374(o, k, 1);
    } else if (func_0203633C() & 0x100) {
        cnt = res;
        do {
            if (func_021B6300(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (func_0203633C() & 0x200) {
        cnt = res;
        do {
            if (func_021B6374(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    return res;
}
