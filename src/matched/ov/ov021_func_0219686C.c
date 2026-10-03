/*
 * function: func_0219686C
 * address:  0x0219686C
 * packet:   pkt_ov021_0219686C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02155A94  0x02155A94  thumb  ov010
 *   func_0200873C  0x0200873C  thumb
 *   func_02008428  0x02008428  thumb
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 *   func_02197700  0x02197700  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_02155A94(u32 a);
extern u32 func_0200873C(u32 h);
extern u32 func_02008428(unsigned short *p);
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_02196804(u8 *p);
extern void func_02197700(u8 *a);
extern void func_02196A60(u8 *p);

void func_0219686C(u8 *p)
{
    if (*(u32 *)(p + 8) == 0xC) {
        func_02196034(p, (void *)func_02196804, 0x38C);
        return;
    }
    if (func_02008428((unsigned short *)func_0200873C(func_02155A94(*(u32 *)(p + 0x2E4)))) == 1) {
        func_02196034(p, (void *)func_02197700, 0x38F);
        return;
    }
    if (*(u32 *)(p + 8) - 6 <= 2) {
        func_02196034(p, (void *)func_02196804, 0x394);
        return;
    }
    func_02196034(p, (void *)func_02196A60, 0x397);
}
