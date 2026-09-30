/*
 * function: func_021D5188
 * address: 0x021D5188
 * packet: pkt_ov120_021D5188
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8358 0x021D8358 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D6FD8 0x021D6FD8 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D50C4 0x021D50C4 thumb ov120
 */
typedef unsigned char u8;
extern int func_021D7AF4(void *);
extern void *func_021D6988(void *);
extern void func_021B6558(void *, int, int);
extern void *func_021D8358(void *, int);
extern void func_021D63F4(void *, int, int);
extern void func_021D6FD8(void *, int);
extern void func_021D4244(int, int, int);
extern void func_021D50C4(void);
void func_021D5188(u8 *p)
{
    if (func_021D7AF4(*(void **)(p + 0x40))) {
        func_021B6558(func_021D6988(*(void **)(p + 0x3c)), 1, 0);
        *(void **)(p + 0x38) = func_021D8358(*(void **)(p + 0x40), 1);
        func_021D63F4(*(void **)(p + 0x3c), 1, 1);
        func_021D6FD8(*(void **)(p + 0x3c), 0);
        func_021D4244((int)p, (int)func_021D50C4, 0x634);
    }
}
