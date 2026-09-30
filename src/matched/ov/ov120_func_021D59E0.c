/*
 * function: func_021D59E0
 * address: 0x021D59E0
 * packet: pkt_ov120_021D59E0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D44AC 0x021D44AC thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 */
typedef unsigned char u8;
extern int func_020279E8(void *);
extern u8 func_02027A04(const u8 *);
extern void func_021D8418(int);
extern void func_021D4244(int, int, int);
extern void func_021D44AC(void);
extern void func_021D79F4(void *, int);
extern u8 func_020355C4(void);
extern void func_021D69F4(void *, void *, int);
extern void *func_021D6988(void *);
extern void func_021B6558(void *, int, int);
extern void func_021D63F4(void *, int, int);
extern void func_021D5AD4(void);
void func_021D59E0(u8 *p)
{
    int state;
    if (func_020279E8(*(void **)(p + 0x38))) {
        state = func_02027A04(*(void **)(p + 0x38));
        func_021D8418(*(int *)(p + 0x38));
        *(int *)(p + 0x38) = 0;
        switch (state) {
        case 0:
            *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 1;
            *(int *)(p + 0x14) = 0;
            func_021D4244((int)p, (int)func_021D44AC, 0x8b5);
            return;
        case 1:
            if (*(int *)(p + 0x184) == 0)
                func_021D79F4(*(void **)(p + 0x40), 0x20);
            else
                func_021D79F4(*(void **)(p + 0x40), 0x2b);
            if (func_020355C4() == 0)
                func_021D69F4(*(void **)(p + 0x3c), 0, *(int *)(p + 0x15c));
            func_021B6558(func_021D6988(*(void **)(p + 0x3c)), 1, 1);
            func_021D63F4(*(void **)(p + 0x3c), 0, 0);
            func_021D4244((int)p, (int)func_021D5AD4, 0x8c3);
            break;
        }
    }
}
