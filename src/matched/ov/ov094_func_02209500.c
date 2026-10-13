/*
 * function: BTLV_TIMER_IsExpired
 * address:  0x02209500
 * packet:   pkt_ov094_02209500
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
} W;

extern u64 func_020870D0(void);

int BTLV_TIMER_IsExpired(W *w, int i)
{
    u64 d;

    d = func_020870D0() - w->t[i];
    d = (d << 6) / 33514000ULL;
    return w->x4c[i] - (int)d <= 0;
}
