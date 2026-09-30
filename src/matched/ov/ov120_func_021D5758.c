/*
 * function: func_021D5758
 * address: 0x021D5758
 * packet: pkt_ov120_021D5758
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 */
typedef unsigned char u8;
extern int func_021D7AF4(void *);
extern void func_021D79F4(void *, int);
extern void *func_021D6988(void *);
extern void func_021B64D0(void *, int);
extern void func_021D4244(int, int, int);
extern void func_021D5AD4(void);
extern int func_020355C4(void);
extern void func_021D69F4(void *, void *, int);
void func_021D5758(u8 *p)
{
    if (func_021D7AF4(*(void **)(p + 0x40))) {
        if (--*(int *)(p + 0x14) <= 0) {
            func_021D79F4(*(void **)(p + 0x40), 0x20);
            func_021B64D0(func_021D6988(*(void **)(p + 0x3c)), 1);
            func_021D4244((int)p, (int)func_021D5AD4, 0x7c7);
            if (func_020355C4() == 0)
                func_021D69F4(*(void **)(p + 0x3c), 0, *(int *)(p + 0x15c));
        }
    }
}
