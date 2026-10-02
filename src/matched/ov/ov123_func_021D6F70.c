/*
 * function: func_021D6F70
 * address:  0x021D6F70
 * packet:   pkt_ov123_021D6F70
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02012E08  0x02012E08  thumb
 *   func_021D8F58  0x021D8F58  thumb  ov123
 *   func_021D5D58  0x021D5D58  thumb  ov123
 *   func_021D6EE0  0x021D6EE0  thumb  ov123
 *   func_021D6F44  0x021D6F44  thumb  ov123
 */

typedef unsigned int u32;

extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02012E08(int);
extern void func_021D8F58(int);
extern int func_021D5D58(int);
extern void func_021D6EE0(int, int, int);
extern void func_021D6F44(void);

void func_021D6F70(int a)
{
    if (*(unsigned char *)(a + 0xab) != 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (*(unsigned char *)(a + 0xad) != 0) {
        func_02012E08(*(int *)(a + 0x2c));
        *(unsigned char *)(a + 0xad) = 0;
    }
    func_021D8F58(a);
    if (*(int *)(a + 8) != 0) {
        if (func_021D5D58(*(int *)(a + 8)) != 0)
            func_021D6EE0(a, (int)func_021D6F44, 0x191);
        func_021D6EE0(a, 0x021D706D, 0x193);
    } else {
        func_021D6EE0(a, 0x021D706D, 0x196);
    }
}
