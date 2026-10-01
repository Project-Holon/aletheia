/*
 * function: func_021FB91C
 * address:  0x021FB91C
 * packet:   pkt_ov094_021FB91C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F81B4  0x021F81B4  thumb  ov094
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8198  0x021F8198  thumb  ov094
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_022079C0  0x022079C0  thumb  ov094
 *
 * 2026-10-01: 6 bytes left. The original keeps the second-branch case 4
 * argument as a fresh `add r2, sp, #0x10` while the loops use r6 = p = ids;
 * this source CSEs the call argument into r6, and schedules `add r6` after
 * the `str r1, [sp]` spill instead of before it. Tried: &ids[0], (int *)&ids,
 * u32 *p, declaration orders, p assigned later. `pt.x *= -1` (not `* -1`)
 * and `Pt pt = {0, 0};` in the loop block are required for the rest.
 */
typedef unsigned int u32;

typedef struct {
    char pad[0xdc];
    int fdc;            /* 0xdc */
    char pade0[0x23c - 0xe0];
    int ret;            /* 0x23c */
} State;

typedef struct { short x, y; } Pt;

extern u32 func_0201134C(void *p);
extern void func_021F81B4(u32 a, u32 b);
extern int func_021FCA04(State *s, int id, int *out);
extern void func_021F8198(u32 a, u32 b);
extern int func_021F7F1C(int i);
extern void *func_021F86B4(void);
extern void func_022079C0(char *p, int i, Pt *pt);

int func_021FB91C(void *r, State *s)
{
    int ids2[8];
    int ids[8];
    int *p;
    u32 a;
    u32 b;
    int n;
    int i;

    p = ids;
    a = func_0201134C(r);
    b = func_0201134C(r);
    if (a <= 1) {
        switch (b) {
        case 3:
            func_021F81B4(a, s->fdc);
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids2);
            if (n != 0) {
                for (i = 0; i < n; i++)
                    func_021F81B4(a, ids2[n]);
            }
            break;
        default:
            func_021F8198(a, b);
            break;
        }
    } else {
        n = 0;
        switch (b) {
        case 0:
            for (i = 0; i < 8; i += 2) {
                if (func_021F7F1C(i))
                    {
                    p[n] = i;
                    n++;
                }
            }
            break;
        case 1:
            for (i = 1; i < 8; i += 2) {
                if (func_021F7F1C(i))
                    {
                    p[n] = i;
                    n++;
                }
            }
            break;
        case 2:
            for (i = 0; i < 8; i++) {
                if (func_021F7F1C(i))
                    {
                    p[n] = i;
                    n++;
                }
            }
            break;
        case 3:
            n = 1;
            ids[0] = s->fdc;
            break;
        case 4:
            n = func_021FCA04(s, 0x10, ids);
            break;
        }
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Pt pt = {0, 0};

                pt.x = (a == 2) ? 0x80 : -0x10;
                if (p[i] & 1)
                    pt.x *= -1;
                func_022079C0(func_021F86B4(), p[i], &pt);
            }
        }
    }
    return s->ret;
}
