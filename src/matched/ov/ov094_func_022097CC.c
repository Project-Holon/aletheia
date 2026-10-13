/*
 * function: BTLV_BG_StartScroll
 * address:  0x022097CC
 * packet:   pkt_ov094_022097CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   BTLV_BG_StartScrollJob  0x0220986C  thumb  ov094
 *   BTLV_BG_ScrollTask  0x022099E8  thumb  ov094
 */

typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct {
    void *f0;
    u32 b0 : 1;
    u32 rest : 31;
} O;

extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern void BTLV_BG_StartScrollJob(O *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                          void (*f1)(void *, void *));
extern void BTLV_BG_ScrollTask(void *, void *);

void BTLV_BG_StartScroll(O *o, int a, u32 mode, int x, int y, int s1, int s2, int s3)
{
    Vec w;
    Vec v;

    v.x = x << 12;
    v.y = y << 12;
    v.z = 0;
    w.x = func_020407E8(3) << 12;
    w.y = func_02040804(3) << 12;
    w.z = 0;
    if (mode == 4 && (a & 1))
        v.x *= -1;
    if (mode == 1) {
        v.x += w.x;
        v.y += w.y;
        v.z += w.z;
    }
    BTLV_BG_StartScrollJob(o, mode, &w, &v, s1, s2, s3, BTLV_BG_ScrollTask);
    o->b0 = 1;
}
