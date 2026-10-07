/*
 * file:     unit_021D7CEC_p03.c
 * unit:     yes
 * function: func_021D80E0, func_021D824C
 * address:  0x021D80E0
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F590 0x0215F590 arm ov009
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   func_0215F4DC 0x0215F4DC arm ov009
 *   d_021D9E40b 0x021D9E40 data a4
 *   d_021DA18C 0x021DA18C data a4 ov125
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_020855BC 0x020855BC arm
 */
#include "../../matched/include/G_Clear.h"

typedef unsigned int u32;

typedef unsigned long long u64;

typedef unsigned char u8;

extern u64 OS_GetTick(void);
extern int func_0215F590(int, void *, int, int);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern int func_0215F4DC(int, void *, int, int);
extern void func_020853C0(void *, void (*)(void *), int, void *, int, unsigned);
extern void func_02085868(void *);
extern void func_020855BC(void *);
int func_021D80E0(void);
void func_021D81EC(void *a0);
int func_021D824C(void);
extern struct Clear d_021D9E40;
extern struct Clear d_021D9E40b;
extern char d_021DA18C[];

int func_021D80E0(void)
{
    int start, count = 0, length, result;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        length = ((u32 *)&d_021D9E40)[0x254/4] - count;
        if (length > (int)((u32 *)&d_021D9E40)[0x254/4]) length = ((u32 *)&d_021D9E40)[0x254/4];
        result = func_0215F590(((u32 *)&d_021D9E40)[0x26c/4], (char *)((u32 *)&d_021D9E40)[0x258/4] + count, length, 0);
        if (result != -6) {
            if (result < 0) {
                ((u32 *)&d_021D9E40)[0x250/4] = 11;
                return 0;
            }
            count += result;
            if (count == ((u32 *)&d_021D9E40)[0x254/4]) break;
        }
        if (((u32 *)&d_021D9E40)[0x248/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&d_021D9E40)[0x248/4]) {
            ((u32 *)&d_021D9E40)[0x250/4] = 11;
            return 0;
        }
        func_021D7CAC();
        if (((u32 *)&d_021D9E40)[0x268/4] == 1) {
            ((u32 *)&d_021D9E40)[0x250/4] = 13;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    return 1;
}

void func_021D81EC(void *a0)
{
    int count;
    for (;;) {
        count = ((u32 *)&d_021D9E40)[0x410/4];
        func_021D7CAC();
        if (!((u32 *)&d_021D9E40)[0x414/4]) {
            ((u32 *)&d_021D9E40)[0x40c/4] = func_0215F4DC(((u32 *)&d_021D9E40)[0x26c/4], (char *)((u32 *)&d_021D9E40)[0x260/4] + count, ((u32 *)&d_021D9E40)[0x25c/4] - count, 0);
            ((u32 *)&d_021D9E40)[0x414/4] = 1;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}

int func_021D824C(void)
{
    u32 count = 0;
    int zero = 0;
    u32 word = -1;
    int start;
    int r;
    u64 t0;
    int ret = 0;

    t0 = OS_GetTick();
    func_020853C0(d_021DA18C, func_021D81EC, 0, ((u8 *)&d_021D9E40b), 0x800, ((u32 *)&d_021D9E40)[0x270 / 4]);
    ((u32 *)&d_021D9E40)[0x40C / 4] = -6;
    ((u32 *)&d_021D9E40)[0x410 / 4] = 0;
    ((u32 *)&d_021D9E40)[0x414 / 4] = 0;
    func_02085868(d_021DA18C);
    start = t0 / 0x7fd88;
    for (;;) {
        if (((u32 *)&d_021D9E40)[0x24C / 4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)((u32 *)&d_021D9E40)[0x24C / 4]) {
            ((u32 *)&d_021D9E40)[0x250 / 4] = 12;
            func_020855BC(d_021DA18C);
            return ret;
        }
        if (((u32 *)&d_021D9E40)[0x414 / 4] == 0) {
            continue;
        }
        r = ((u32 *)&d_021D9E40)[0x40C / 4];
        if (r != -6) {
            if (r <= 0) {
                ((u32 *)&d_021D9E40)[0x250 / 4] = 9;
                func_020855BC(d_021DA18C);
                return 0;
            }
            count += r;
            if (count >= 4 && word == -1) {
                u8 *h = (u8 *)&word;
                u8 *q = (u8 *)((u32 *)&d_021D9E40)[0x260 / 4];
                h[0] = q[0]; h[1] = q[1]; h[2] = q[2]; h[3] = q[3];
            }
            if (count == word) {
                if (word != -1) {
                    ((u32 *)&d_021D9E40)[0x25C / 4] = word - 4;
                    break;
                }
            }
            ((u32 *)&d_021D9E40)[0x410 / 4] = count;
        }
        func_021D7CAC();
        if (((u32 *)&d_021D9E40)[0x268 / 4] == 1) {
            ((u32 *)&d_021D9E40)[0x250 / 4] = 13;
            func_021D7CC0();
            func_020855BC(d_021DA18C);
            return 0;
        }
        func_021D7CC0();
        ((u32 *)&d_021D9E40)[0x414 / 4] = zero;
        func_021D8438(1);
    }
    func_020855BC(d_021DA18C);
    return 1;
}
