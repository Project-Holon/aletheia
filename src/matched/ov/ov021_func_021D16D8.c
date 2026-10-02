/*
 * function: func_021D16D8
 * address:  0x021D16D8
 * packet:   pkt_ov021_021D16D8
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
 *   func_02009390  0x02009390  thumb
 *   func_020093D8  0x020093D8  thumb
 *   func_02009418  0x02009418  thumb
 *   func_02009428  0x02009428  thumb
 *   func_020093F0  0x020093F0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02012F8C(void *a);
extern u16 *func_02009390(u32 a, u32 b);
extern u32 func_020093D8(u32 a);
extern u32 func_02009418(u32 a);
extern void func_02009428(u32 a, u32 b);
extern void func_020093F0(u32 a, u32 b);

int func_021D16D8(u32 a, u32 b)
{
    void *r6;
    u32 r7;
    u32 k1;
    u16 *r4;
    u8 i;
    u16 *e;
    u32 id;

    func_0215A5F4((void *)b);
    func_0215A5DC((void *)b);
    r6 = func_0215A5E4((void *)b);
    r7 = func_02159B10(a, b);
    k1 = func_02159B10(a, b);
    func_02159B10(a, b);
    r4 = func_02159AE8((void *)a, (void *)b);
    id = func_02012F8C(r6);
    switch (r7) {
    case 0:
        *r4 = 1;
        for (i = 0; i < 5; i++) {
            e = func_02009390(id, i);
            if (e == 0) {
                *r4 = 0;
            } else if (e[0] == 0x7E || e[0] == 0) {
                *r4 = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8(id) == 0x7F) {
            *r4 = 0;
        } else {
            *r4 = 1;
        }
        break;
    case 2:
        if (func_02009418(id) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
        break;
    case 3:
        func_02009428(id, 0);
        break;
    case 4:
        func_020093F0(id, k1);
        break;
    }
    return 0;
}
