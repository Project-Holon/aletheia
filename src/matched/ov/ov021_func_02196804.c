/*
 * function: func_02196804
 * address:  0x02196804
 * packet:   pkt_ov021_02196804
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_021967BC  0x021967BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02155A90(u32 a);
extern void func_02012138();
extern u32 func_02026454();
extern void func_02026400();
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_021967BC();

void func_02196804(u8 *p)
{
    p[0x306] = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, *(u16 *)(p + 0x10));
    if (*(u32 *)(p + 8) != 0xC) {
        func_02155A90(*(u32 *)(p + 0x2E4));
        func_02012138();
        if (func_02026454() != 0) {
            func_02155A90(*(u32 *)(p + 0x2E4));
            func_02012138();
            func_02026400();
        }
    }
    func_02196034(p, (void *)func_021967BC, 0x37C);
}
