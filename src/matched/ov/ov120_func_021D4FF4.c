/*
 * function: func_021D4FF4
 * address: 0x021D4FF4
 * packet: pkt_ov120_021D4FF4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8664 0x021D8664 thumb ov120
 *   func_020435F4 0x020435F4 arm
 *   func_021D7EC4 0x021D7EC4 thumb ov120
 *   func_021D68C4 0x021D68C4 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_021D6D94 0x021D6D94 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4FD0 0x021D4FD0 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D8664(u8 *p);
extern void func_020435F4(u32 planes);
extern void func_021D7EC4(u8 *p);
extern void func_021D68C4(u8 *p);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_02041B6C(u32 bit);
extern void func_02040588(u32, u32);
extern void func_021D6D94(u8 *p);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4FD0(u8 *p);
void func_021D4FF4(u8 *p)
{
    if (func_021D8664(*(void **)(p + 0x40))) {
        func_020435F4(8);
        func_021D7EC4(*(void **)(p + 0x40));
        func_021D68C4(*(void **)(p + 0x3c));
        func_021D63F4(*(void **)(p + 0x3c), 0, 0);
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
        func_02041B6C(5);
        if (*(int *)(p + 0x138) == 1) {
            func_02040588(4, 0);
            func_021D6D94(*(void **)(p + 0x3c));
        }
        func_021D4244((int)p, (void (*)(int))func_021D4FD0, 0x5dd);
    }
}
