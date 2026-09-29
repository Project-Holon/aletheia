/*
 * function: func_021BB3F4
 * address:  0x021BB3F4
 * packet:   pkt_ov070_021BB3F4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB368  0x021BB368  thumb  ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_02012BF8  0x02012BF8  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202173C  0x0202173C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3F4  0x0204B3F4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int func_021BB368(int);
extern void func_021BB5A4(int);
extern void func_021BB580(int, int);
extern int func_02012BF8(int, int);
extern u32 func_020056BC(void);
extern int func_0202173C(int p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_020216D4(int slots, u32 bank, u32 off, u32 size);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0204B878(int, int);
extern int func_0204B3F4(int);

void func_021BB3F4(int p, int mode)
{
    int r;

    if (*(int *)(p + 0x858) == mode) {
        return;
    }
    *(int *)(p + 0x858) = mode;
    r = func_02012BF8(*(int *)p, func_021BB368(*(int *)(p + 0x80C)));
    if (mode == 1) {
        func_0202173C(*(int *)(p + 0x854), 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        func_0202173C(*(int *)(p + 0x854), 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        func_021BB5A4(p);
        func_0204B878(*(int *)(p + 0x710), 4);
        func_0204B878(*(int *)(p + 0x714), 5);
        func_0204B878(*(int *)(p + 0x71C), 0);
        if (r == 1) {
            func_0204B878(*(int *)(p + 0x718), 7);
        } else {
            func_0204B878(*(int *)(p + 0x718), 6);
        }
        func_021BB580(p, 1);
    } else {
        func_020216D4(*(int *)(p + 0x854), 2, 0, 0x200);
        func_0202173C(*(int *)(p + 0x854), 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        func_0202173C(*(int *)(p + 0x854), 1, 1, 0, 8, 8, 0, func_020056BC());
        if (*(int *)(p + 0x10) == 4 && func_0204B3F4(*(int *)(p + 0x710)) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        func_0204B878(*(int *)(p + 0x72C), 4);
        func_0204B878(*(int *)(p + 0x710), 0x12);
        func_0204B878(*(int *)(p + 0x714), 0x13);
        func_0204B878(*(int *)(p + 0x71C), 0xE);
        if (r == 1) {
            func_0204B878(*(int *)(p + 0x718), 0x16);
        } else {
            func_0204B878(*(int *)(p + 0x718), 0x15);
        }
    }
}
