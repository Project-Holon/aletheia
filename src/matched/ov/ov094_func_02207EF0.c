/*
 * function: BTLV_GAUGE_UpdateExpAnim
 * address:  0x02207EF0
 * packet:   pkt_ov094_02207EF0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_GAUGE_CalcPixelChange  0x022080B0  thumb  ov094
 *   BTLV_GAUGE_StepValue  0x02207F6C  thumb  ov094
 *   BTLV_GAUGE_DrawBar  0x022082FC  thumb  ov094
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct E {
    char p0[0x54];
    int f54;
    int f58;
    int p5c;
    int f60;
    int f64;
    char p68[8];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 hi : 30;
    char p74[12];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

extern int BTLV_GAUGE_CalcPixelChange(int a, int b, int c, unsigned int d);
typedef unsigned char  u8;
extern int BTLV_GAUGE_StepValue(int n, int target, int delta, int *cur, u8 x, int speed);
extern void BTLV_GAUGE_DrawBar(O *obj, int idx, int k);

void BTLV_GAUGE_UpdateExpAnim(O *obj, int idx)
{
    E *e;
    int k;
    int q;
    int r;

    e = &obj->e[idx];
    k = BTLV_GAUGE_CalcPixelChange(e->f54, e->f60, e->f58, 10);
    if (k == 0) {
        k = 1;
    }
    q = e->f60 / k;
    if (q < 0) {
        q = -q;
    }
    if (q == 0) {
        q = 1;
    }
    r = BTLV_GAUGE_StepValue(e->f58, e->f54, e->f60, &e->f64, (int)10, (u16)q);
    BTLV_GAUGE_DrawBar(obj, idx, 1);
    if (r == -1) {
        e->f54 = e->f54 - e->f60;
        e->b1 = 0;
        e->f64 = 0;
    }
}
