/*
 * function: FLDMMDL_MOVE_FindFellow
 * address:  0x0219BBA4
 * packet:   pkt_ov021_0219BBA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetTrainerId  0x021AE884  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
struct Rec;
extern u16 FLDMMDL_GetEventType(u8 *p);
extern u16 FLDMMDL_GetZoneId(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int EVENT_TRAINER_EYE_GetTrainerId(u32 a);
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);

int FLDMMDL_MOVE_FindFellow(int a)
{
    int out;
    u32 iter;
    u32 kind;
    int r7;
    int r6;
    int r5;

    iter = 0;
    kind = FLDMMDL_GetEventType((u8 *)a);
    r7 = FLDMMDL_GetZoneId((void *)a);
    r6 = (int)FLDMMDL_GetMmdlSys((void *)a);
    r5 = EVENT_TRAINER_EYE_GetTrainerId(a);
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)r6, (struct Rec **)(&out), &iter) == 1) {
            if (a != out && r7 == FLDMMDL_GetZoneId((void *)out) && r5 == EVENT_TRAINER_EYE_GetTrainerId(out)) {
                return out;
            }
        }
        break;
    }
    return 0;
}
