/*
 * function: func_02183C3C
 * address:  0x02183C3C
 * packet:   pkt_ov022_02183C3C
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0203D378  0x0203D378  arm
 *   func_02183EE0  0x02183EE0  thumb  ov022
 *   func_02183D34  0x02183D34  thumb  ov022
 *   func_02183CC0  0x02183CC0  thumb  ov022
 *   func_02183D4C  0x02183D4C  thumb  ov022
 *   func_02183D94  0x02183D94  thumb  ov022
 *   func_02183DAC  0x02183DAC  thumb  ov022
 *   func_02183DDC  0x02183DDC  thumb  ov022
 *   func_02183E48  0x02183E48  thumb  ov022
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern void func_02172D38(u8 *p);
extern int func_02172D68(u8 *p);
extern u32 func_0203D378(void);
extern void func_02183EE0(u8 *s, u8 *c);
extern void func_02183D34(u8 *s);
extern void func_02183CC0(u8 *s);
extern void func_02183D4C(u8 *s);
extern void func_02183D94(u8 *s);
extern void func_02183DAC(u8 *s);
extern void func_02183DDC(u8 *s);
extern void func_02183E48(u8 *s, u8 *c);

void func_02183C3C(u8 *s, u8 *c)
{
    if (func_0200FB24() != 0) {
        return;
    }
    if (*(int *)(s + 0x28) == 1) {
        return;
    }
    if (*(int *)(s + 0x20) == 1) {
        func_02172D38(c);
        *(int *)(s + 0x20) = 0;
        *(int *)(s + 0x24) = 1;
        return;
    }
    if (*(int *)(s + 0x24) == 1) {
        if (func_02172D68(c) == 0) {
            *(int *)(s + 0x24) = 0;
            *(int *)(s + 0x28) = 1;
        }
        return;
    }
    if (func_0203D378() == 1) {
        func_02183EE0(s, c);
        func_02183D34(s);
        func_02183CC0(s);
        func_02183D4C(s);
        func_02183D94(s);
    }
    func_02183DAC(s);
    func_02183DDC(s);
    func_02183E48(s, c);
}
