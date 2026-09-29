/*
 * function: func_021BB910
 * address:  0x021BB910
 * packet:   pkt_ov091_021BB910
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02005DE4(int a);
extern void func_02005E64(void);
extern void func_02005D90(int a, int b);
extern void func_020061E4(int a);
extern int func_02005F38(void);
extern void func_02005E9C(void);
extern int func_02006238(void);

int func_021BB910(int k)
{
    switch (k) {
    case 2:
        func_02005DE4(1);
        func_02005E64();
        func_02005D90(0x515, 0xffff);
        break;
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            return 0;
        }
        return 1;
    case 6:
        return func_02006238();
    }
    return 0;
}
