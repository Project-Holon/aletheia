/*
 * function: func_021D50C4
 * address: 0x021D50C4
 * packet: pkt_ov120_021D50C4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7550 0x021D7550 thumb ov120
 *   func_021D8520 0x021D8520 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4B48 0x021D4B48 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D6FD8 0x021D6FD8 thumb ov120
 *   func_021D50A0 0x021D50A0 thumb ov120
 */
typedef unsigned char u8;
extern int func_020279E8(void *);
extern u8 func_02027A04(const u8 *);
extern void func_021D8418(int);
extern void *func_021D6988(void *);
extern void func_021B6558(void *, int, int);
extern void func_021D79F4(void *, int);
extern void func_021D7550(void *);
extern void func_021D8520(void *, int);
extern void func_021D4244(int, int, int);
extern void func_021D4B48(void);
extern void func_021D63F4(void *, int, int);
extern u8 func_020355C4(void);
extern void func_021D69F4(void *, void *, int);
extern void func_021D6FD8(void *, int);
extern void func_021D50A0(void);
void func_021D50C4(u8 *p)
{
    int state;
    if (func_020279E8(*(void **)(p + 0x38))) {
        int zero;
        state = func_02027A04(*(void **)(p + 0x38));
        func_021D8418(*(int *)(p + 0x38));
        zero = 0;
        *(int *)(p + 0x38) = zero;
        func_021B6558(func_021D6988(*(void **)(p + 0x3c)), 1, 1);
        switch (state) {
        case 0:
            func_021D79F4(*(void **)(p + 0x40), 0xe);
            func_021D7550(*(void **)(p + 0x3c));
            func_021D8520(*(void **)(p + 0x40), 0xd);
            *(int *)(p + 0x144) = zero;
            *(int *)(p + 0x13c) = zero;
            *(int *)(p + 0x140) = zero;
            *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 3;
            func_021D4244((int)p, (int)func_021D4B48, 0x614);
            return;
        case 1:
            func_021D63F4(*(void **)(p + 0x3c), zero, zero);
            func_021D79F4(*(void **)(p + 0x40), 0x13);
            if (func_020355C4() == 0)
                func_021D69F4(*(void **)(p + 0x3c), 0, *(int *)(p + 0x164));
            else
                func_021D69F4(*(void **)(p + 0x3c), 0, 9);
            func_021D6FD8(*(void **)(p + 0x3c), 1);
            func_021D4244((int)p, (int)func_021D50A0, 0x620);
            break;
        }
    }
}
