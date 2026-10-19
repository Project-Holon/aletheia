/*
 * function: ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled
 * address:  0x021BDC48
 * packet:   pkt_ov208_021BDC48
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_GetTouchEnable  0x021BD35C  thumb
 *   ZKND_TBAR_SetTouchEnable  0x021BD358  thumb
 */

typedef unsigned int u32;

struct Ov208Scene {
    u32 pad0[2];
    u32 f8;
    u32 pad0c[9];
    void *mgr;
    u32 f34;
};

extern int ZKND_TBAR_GetTouchEnable(char *p);
extern void ZKND_TBAR_SetTouchEnable(char *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (ZKND_TBAR_GetTouchEnable(p->mgr) == 0 && p->f8 == 2)
            ZKND_TBAR_SetTouchEnable(p->mgr, 1);
    } else {
        if (ZKND_TBAR_GetTouchEnable(p->mgr) != 0)
            ZKND_TBAR_SetTouchEnable(p->mgr, 0);
    }
}
