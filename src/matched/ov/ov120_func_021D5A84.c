/*
 * function: func_021D5A84
 * address: 0x021D5A84
 * packet: pkt_ov120_021D5A84
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D7B60 0x021D7B60 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D59E0 0x021D59E0 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern int func_021D7AF4(char *p);
extern u32 func_021D6988(u8 *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void *func_021D7B60(char *p, int n);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D4244(int, int, int);
extern void func_021D59E0(u8 *p);
void func_021D5A84(u8 *p)
{
    if (func_021D7AF4(*(void **)(p + 0x40))) {
        func_021B6558((unsigned char *)func_021D6988(*(void **)(p + 0x3c)), 1, 0);
        *(void **)(p + 0x38) = func_021D7B60(*(void **)(p + 0x40), 1);
        func_021D63F4(*(void **)(p + 0x3c), 1, 0);
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
        func_021D4244((int)p, (int)func_021D59E0, 0x8d4);
    }
}
