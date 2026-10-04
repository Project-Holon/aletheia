/*
 * function: func_021D4CC4
 * address: 0x021D4CC4
 * packet: pkt_ov120_021D4CC4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028230 0x02028230 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7550 0x021D7550 thumb ov120
 *   func_021D8520 0x021D8520 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4B48 0x021D4B48 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02028230(u8 *p);
extern void func_02028148(u8 *p);
extern void func_02041B6C(u32 bit);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_021D7550(u8 *p);
extern void func_021D8520(char *p, u16 n);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4B48(u8 *p);
void func_021D4CC4(u8 *p)
{
    if (func_02028230(*(void **)(p + 0x34))) {
        func_02028148(*(void **)(p + 0x34));
        *(int *)(p + 0x34) = 0;
        func_02041B6C(5);
        func_021D79F4(*(void **)(p + 0x40), 14);
        func_021D7550(*(void **)(p + 0x3c));
        func_021D8520(*(void **)(p + 0x40), 13);
        func_021D63F4(*(void **)(p + 0x3c), 1, 2);
        *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 2;
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
        func_021D4244((int)p, (void (*)(int))func_021D4B48, 0x460);
    }
}
