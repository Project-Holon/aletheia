/*
 * function: func_021F903C
 * address:  0x021F903C
 * packet:   pkt_ov094_021F903C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   d_0220AC70 0x0220AC70 data a4
 *   d_0220AC78 0x0220AC78 data a4
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021F7BEC 0x021F7BEC thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned int u32;
typedef unsigned long long u64;
extern char *d_0220AF20;
extern u32 d_0220AC70[];
extern u32 d_0220AC78[];
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021F7BEC(void);
extern void func_021F7998(u32);
extern int func_021F7EB4(void);
extern int func_021BA1A8(char **p, int m);
extern u32 func_0203F0A8(void);
#define WORD(k) (*(int *)(d_0220AF20 + (k)))

void func_021F903C(void)
{
    int a, b;
    u32 n, value;
    a = func_020362DC();
    b = TOUCHPANEL_GetTrg();
    if (WORD(0x238) == 0)
        return;
    if (WORD(0x238) != 2 && WORD(0x238) != 3 && (a != 0 || b != 0)) {
        func_021F7BEC();
        func_021F7998(0x252);
        WORD(0x23c) = 0;
        WORD(0x240) = 0;
    }
    switch (WORD(0x23c)) {
    case 0:
        if (WORD(0x240) < WORD(0x244)) {
            WORD(0x240)++;
            return;
        }
        WORD(0x23c) = 1;
    case 1:
        if (func_021F7EB4() == 0) {
            if (WORD(0x238) == 3 && func_021BA1A8(*(void **)(d_0220AF20 + 0x1e4), 0x400)) {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 2) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = d_0220AC70[WORD(0x248)];
            } else {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 6) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = d_0220AC78[WORD(0x248)];
            }
            func_021F7998(value);
            WORD(0x1e8) = 1;
        }
        break;
    }
}
