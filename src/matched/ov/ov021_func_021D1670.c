/*
 * function: func_021D1670
 * address:  0x021D1670
 * packet:   pkt_ov021_021D1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02012F8C (arm9 Thumb leaf) is filed as src/matched/arm9/func_02012F8C.c
 * to give the witness.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012F8C  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012F8C(u32 *p);
struct Sub02009210Obj;
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 func_020092D8(const struct Sub02009210Obj *obj);

int func_021D1670(u32 a, u32 b)
{
    void *r7;
    u32 r6;
    u16 *r4;
    u32 r5;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r7 = func_0215A5E4((void *)b);
    r6 = func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    func_02159B10((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    r5 = func_02012F8C(r7);
    if (r6 == 0) {
        if (func_020092EC((const struct Sub02009210Obj *)r5) == 1 && func_020092D8((const struct Sub02009210Obj *)r5) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
    }
    return 0;
}
