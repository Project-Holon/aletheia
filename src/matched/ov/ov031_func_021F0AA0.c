/*
 * function: func_021F0AA0
 * address:  0x021F0AA0
 * packet:   pkt_ov031_021F0AA0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0A04  0x021F0A04  thumb  ov031
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_021F07AC  0x021F07AC  thumb  ov031
 *   d_021F10D0     0x021F10D0  data  a4
 *
 * `long i` keeps `i = n` from being copy-propagated into the first loop's
 * entry guard (with `int i` the guard tests a spare copy of n, +2 bytes);
 * `j++`/`j--` in the loop body rather than the for header gives i r7 and j r5
 * (the comma form swaps them in both first loops).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021F0A04(void *a, u8 i, u8 j, char *b, int d);
extern void *func_021BBC2C(void *r, int i);
extern void func_02034714(const char *file, int line, const char *msg);
extern void func_021F07AC(void *a, void *b, u32 c);
extern const char d_021F10D0[];

void func_021F0AA0(void *a, char *b, int n)
{
    long i;
    int j;
    void *e;

    if (n > 0) {
        for (i = n, j = 0; i < 3; i++) {
            func_021F0A04(a, i, j, b, *(int *)(b + 0x440) - n);
            j++;
        }
        for (j = 3 - n; j < 3; j++) {
            e = func_021BBC2C(b, *(int *)(b + 0x440) - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    } else {
        for (i = n + 2, j = 2; i > -1; i--) {
            func_021F0A04(a, i, j, b, *(int *)(b + 0x440) - n);
            j--;
        }
        for (j = -1 - n; j > -1; j--) {
            e = func_021BBC2C(b, *(int *)(b + 0x440) - 2 + j);
            if (e == 0)
                func_02034714(d_021F10D0, 0, d_021F10D0);
            func_021F07AC(a, e, (u8)j);
        }
    }
}
