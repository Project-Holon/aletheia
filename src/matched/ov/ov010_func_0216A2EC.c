/*
 * function: func_0216A2EC
 * address:  0x0216A2EC
 * packet:   pkt_ov010_0216A2EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011400  0x02011400  thumb
 *   func_0216A298  0x0216A298  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 func_02011400(int row, int col);
extern void func_0216A298(void *a, void *list);

int func_0216A2EC(int a0, int a1, int a2, int *a3, int a4)
{
    int r6;
    int r0;
    int r1;
    int t;

    r6 = func_02011400(a4, 3);
    r0 = func_02011400(a4, 0);
    r1 = a3[0];
    if (!((u32)r1 < (u32)r6 && (u32)r1 >= (u32)r0)) {
        t = r1;
        if (t < r0) {
            t += 24;
        }
        t = t - r6;
        if (a3[1] + t * 60 < a2 + 1) {
            func_0216A298((void *)a0, (void *)a1);
            return 1;
        }
        return 0;
    }
    t = r1 - r0;
    if (a3[1] + t * 60 < a2) {
        func_0216A298((void *)a0, (void *)a1);
        return 1;
    }
    return 0;
}
