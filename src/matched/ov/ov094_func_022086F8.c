/*
 * function: BTLV_GAUGE_UpdateLevelUp
 * address: 0x022086F8
 * packet: pkt_ov094_022086F8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BTLV_GAUGE_StepValue 0x02207F6C thumb ov094
 *   BTLV_GAUGE_DrawBar 0x022082FC thumb ov094
 *   BTLV_GAUGE_DrawHpNumbers 0x02208420 thumb ov094
 *   BTLV_GAUGE_DrawLevel 0x02208550 thumb ov094
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct E {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 b0:1, b1:1, b2:1, b3:1, phase:4, hi:24;
    char p74[12];
} E;
typedef struct { char p0[0x40]; E e[8]; } O;
typedef unsigned char  u8;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int BTLV_GAUGE_StepValue(int n, int target, int delta, int *cur, u8 x, int speed);
struct O;
extern void BTLV_GAUGE_DrawBar(struct O *o, int idx, int k);
extern void BTLV_GAUGE_DrawHpNumbers(O *, E *, int);
extern void BTLV_GAUGE_DrawLevel(O *, E *);
void BTLV_GAUGE_UpdateLevelUp(O *o, int i)
{
    E *e;
    e = &o->e[i];
    if (e->b1 == 0) {
        switch (e->phase) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x56e);
            e->phase++;
            break;
        case 1:
            e->phase++;
            break;
        case 2:
            e->f54 = 0;
            e->f58 = e->f5c;
            e->f64 = 0x80000000;
            e->f60 = 0;
            BTLV_GAUGE_StepValue(e->f4c, e->f48, 0, &e->f50, 6, 1);
            BTLV_GAUGE_StepValue(e->f58, e->f54, 0, &e->f64, 10, 1);
            BTLV_GAUGE_DrawBar((struct O *)o, i, 0);
            BTLV_GAUGE_DrawBar((struct O *)o, i, 1);
            BTLV_GAUGE_DrawHpNumbers(o, e, e->f48);
            BTLV_GAUGE_DrawLevel(o, e);
            e->b2 = 0;
            break;
        }
    }
}
