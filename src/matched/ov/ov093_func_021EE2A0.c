/*
 * unit:     yes
 * function: BTLV_SCU_UpdateBallWindowOpen, BTLV_SCU_StartBallWindowRefresh
 * address:  0x021EE2A0
 * packet:   pkt_ov093_021EE2A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_StepBallWindowRefresh  0x021EE4B4  thumb  ov093
 */

typedef unsigned char u8;

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

struct C;
extern int BTLV_SCU_StepBallWindowRefresh(int *st, struct C *c);

int BTLV_SCU_UpdateBallWindowOpen(struct O *o)
{
    if (o->fe0 != 0) {
        if (o->fe0(&o->fec, o->fe8) != 0) {
            o->fe0 = 0;
            o->fec = 0;
        }
        return 0;
    }
    if (o->fe4 != 0) {
        if (o->fe4(&o->fec, o->fe8) != 0) {
            o->fe4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

void BTLV_SCU_StartBallWindowRefresh(struct O *o)
{
    o->fe0 = 0;
    o->fe4 = (int (*)(void *, void *))BTLV_SCU_StepBallWindowRefresh;
    o->fe8 = o;
    o->fec = 0;
}
