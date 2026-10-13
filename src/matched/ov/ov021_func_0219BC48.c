/*
 * function: FLDMMDL_MOVE_UpdateFellowTracking
 * address:  0x0219BC48
 * packet:   pkt_ov021_0219BC48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   EVENT_TRAINER_EYE_GetTrainerId  0x021AE884  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_MOVE_StartFellowTracking  0x0219BCC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;
struct Ctx;
struct Rec;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u16 FLDMMDL_GetZoneId(void *p);
extern int EVENT_TRAINER_EYE_GetTrainerId(u32 a);
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_MOVE_StartFellowTracking(int a, u8 *b, int c);

int FLDMMDL_MOVE_UpdateFellowTracking(int a, u8 *b)
{
    u32 iter;
    int out;
    int r7;
    int r6;
    int t;

    t = (int)FLDMMDL_GetMmdlSys((void *)a);
    iter = 0;
    r7 = FLDMMDL_GetZoneId((void *)a);
    r6 = EVENT_TRAINER_EYE_GetTrainerId(a);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)t, (struct Rec **)(&out), &iter) == 1) {
        if (a != out && r7 == FLDMMDL_GetZoneId((void *)out) && r6 == EVENT_TRAINER_EYE_GetTrainerId(out)) {
            if (b[1] == 0) {
                FLDMMDL_MOVE_StartFellowTracking(a, b, out);
            }
            return 1;
        }
    }
    b[1] = 0;
    return 0;
}
