/*
 * function: func_021D824C
 * address: 0x021D824C
 * packet: pkt_ov125_021D824C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * 2026-10-04 wave D3 lane 18: DIFF, compiled 500 bytes vs 492. Download thread supervisor, sibling of func_021D80E0 (same d_021D9E40 struct, same OS_GetTick()/0x7fd88 timeout).
 * Matched so far: OS_GetTick called first into a u64 t0 and divided after the wakeup (start = t0 / 0x7fd88 in sl), count is u32 in sb (blo), word = -1 in [sp+8], the 4-byte copy as a u8[4] struct copy, the loop and error codes 12, 9, 13.
 * Residue: original keeps three zero copies (sb = count, r7 for the f414 store, fp for the second division high word and the timeout return); it holds &word in r8 after the thread pointer register is freed (add r8, sp, #8). Compiled puts the zero in r8 and the constant 1 in fp. Thread pointer 0x021DA18C is reloaded from the pool at each use in the original. Stack top arg r3 uses a second extern name for 0x021D9E40 (duplicate pool word, d_021D9E40b).
 * Unresolved: d_021DA18C has no witness outside this function (pool word), so even a perfect body would be MATCH.
 * func_020855BC (thread destroy or exit, takes the thread pointer) is unnamed in the tree.
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D9E40b 0x021D9E40 data a4
 *   d_021DA18C 0x021DA18C data a4 ov125
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_020853C0 0x020853C0 arm
 *   func_02085868 0x02085868 arm
 *   func_020855BC 0x020855BC arm
 *   func_021D81EC 0x021D81EC arm ov125
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;
typedef struct { u8 b[4]; } W4;
extern u32 d_021D9E40[];
extern u8 d_021D9E40b[];
extern char d_021DA18C[];
extern u64 OS_GetTick(void);
extern void func_020853C0(void *, void (*)(void *), int, void *, int, unsigned);
extern void func_02085868(void *);
extern void func_020855BC(void *);
extern void func_021D81EC(void *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
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
    func_020853C0(d_021DA18C, func_021D81EC, 0, d_021D9E40b, 0x800, d_021D9E40[0x270 / 4]);
    d_021D9E40[0x40C / 4] = -6;
    d_021D9E40[0x410 / 4] = 0;
    d_021D9E40[0x414 / 4] = 0;
    func_02085868(d_021DA18C);
    start = t0 / 0x7fd88;
    for (;;) {
        if (d_021D9E40[0x24C / 4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)d_021D9E40[0x24C / 4]) {
            d_021D9E40[0x250 / 4] = 12;
            func_020855BC(d_021DA18C);
            return ret;
        }
        if (d_021D9E40[0x414 / 4] == 0) {
            continue;
        }
        r = d_021D9E40[0x40C / 4];
        if (r != -6) {
            if (r <= 0) {
                d_021D9E40[0x250 / 4] = 9;
                func_020855BC(d_021DA18C);
                return 0;
            }
            count += r;
            if (count >= 4 && word == -1) {
                *(W4 *)&word = *(W4 *)d_021D9E40[0x260 / 4];
            }
            if (count == word) {
                if (word != -1) {
                    d_021D9E40[0x25C / 4] = word - 4;
                    func_020855BC(d_021DA18C);
                    return 1;
                }
            }
            d_021D9E40[0x410 / 4] = count;
        }
        func_021D7CAC();
        if (d_021D9E40[0x268 / 4] == 1) {
            d_021D9E40[0x250 / 4] = 13;
            func_021D7CC0();
            func_020855BC(d_021DA18C);
            return 0;
        }
        func_021D7CC0();
        d_021D9E40[0x414 / 4] = zero;
        func_021D8438(1);
    }
}
