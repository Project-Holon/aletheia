/*
 * function: func_021EF2D4
 * address:  0x021EF2D4
 * packet:   pkt_ov025_021EF2D4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the m chain has no final else (the original leaves r5 as it was
 *           when r % 100 >= 100, a path that cannot run).
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21C8  0x021A21C8  thumb  ov021
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern u32 func_020056EC(u32 v);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern int *func_021A21B8(int *p);
extern void *func_021A21C8(void *p, int a1);
extern unsigned char *func_021A2630(unsigned char *o);
extern unsigned int func_021A2638(unsigned char *o);
extern void func_021A2654(int obj, unsigned short *src);

void func_021EF2D4(int a, int n, int idx)
{
    int i;
    int obj;
    int *e;
    int h;
    u32 r;
    u32 t;
    int m;
    int k;
    Pt pt;

    func_021A21B8((int *)a);
    for (i = 0; i < n; i++) {
        obj = (int)func_021A21C8((void *)a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630((unsigned char *)obj);
        h = func_021A2638((unsigned char *)obj);
        r = func_020056EC(0);
        e[0] = 0;
        t = r % 100;
        if (t < 30) {
            m = 0;
        } else if (t < 95) {
            m = 1;
        } else if (t < 100) {
            m = 2;
        }
        CLACT_SetActorAnimIndex(h, (u16)(2 - m));
        k = r % 23;
        e[2] = k + (m + 1) * 10;
        if (m == 2) {
            e[2] += 3;
        }
        e[4] = k / 4 + (m + 1) * 4;
        if (m == 2) {
            e[4] -= 2;
        }
        e[3] = 0;
        e[1] = (r & 3) + 1;
        pt.x = r % 270 + (m * 15 - 0x40);
        pt.y = (r & 0xF) - 8;
        func_021A2654(obj, (short unsigned int *)(&pt));
        e[6] = r;
    }
}
