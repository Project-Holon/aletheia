/*
 * unit: yes
 * function: func_021D80E0, func_021D81EC
 * address: 0x021D80E0
 * packet: pkt_ov125_021D80E0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F590 0x0215F590 arm ov009
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   func_0215F4DC 0x0215F4DC arm ov009
 */
typedef unsigned int u32;
typedef unsigned long long u64;
extern u32 d_021D9E40[];
extern u64 OS_GetTick(void);
extern int func_0215F590(int, void *, int, int);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern int func_0215F4DC(int, void *, int, int);
int func_021D80E0(void)
{
    int start, count = 0, length, result;
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        length = d_021D9E40[0x254/4] - count;
        if (length > (int)d_021D9E40[0x254/4]) length = d_021D9E40[0x254/4];
        result = func_0215F590(d_021D9E40[0x26c/4], (char *)d_021D9E40[0x258/4] + count, length, 0);
        if (result != -6) {
            if (result < 0) {
                d_021D9E40[0x250/4] = 11;
                return 0;
            }
            count += result;
            if (count == d_021D9E40[0x254/4]) break;
        }
        if (d_021D9E40[0x248/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)d_021D9E40[0x248/4]) {
            d_021D9E40[0x250/4] = 11;
            return 0;
        }
        func_021D7CAC();
        if (d_021D9E40[0x268/4] == 1) {
            d_021D9E40[0x250/4] = 13;
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
        count = d_021D9E40[0x410/4];
        func_021D7CAC();
        if (!d_021D9E40[0x414/4]) {
            d_021D9E40[0x40c/4] = func_0215F4DC(d_021D9E40[0x26c/4], (char *)d_021D9E40[0x260/4] + count, d_021D9E40[0x25c/4] - count, 0);
            d_021D9E40[0x414/4] = 1;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}
