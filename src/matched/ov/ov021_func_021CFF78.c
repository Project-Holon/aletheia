/*
 * function: func_021CFF78
 * address:  0x021CFF78
 * packet:   pkt_ov021_021CFF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_021CFCF4  0x021CFCF4  thumb  ov021
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009634  0x02009634  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
struct Big;
struct Ctx;
struct Sub02009470Obj;
struct Tbl021CFCF4;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F38(int base);
extern u8 func_021CFCF4(struct Tbl021CFCF4 *p, u32 i);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);

int func_021CFF78(u32 a, u32 b)
{
    u32 h, p, k, r;
    u16 *out;

    func_0215A5F4((void *)b);
    h = (u32)func_020120F4(func_0215A5DC((void *)b));
    p = func_02012F38(h);
    k = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    *out = 0;
    r = func_021CFCF4((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        if ((u8)func_02009634(func_02009470(func_02012EBC((struct Big *)h)), r, 5)) {
            *out = 1;
        }
    }
    return 0;
}
