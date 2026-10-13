/*
 * function: EVENT_TRAINER_EYE_FindPartner
 * address:  0x021AE8D4
 * packet:   pkt_ov021_021AE8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetSightType  0x021AE79C  thumb  ov021
 *   EVENT_TRAINER_EYE_GetTrainerId  0x021AE884  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *FLDMMDL_GetMmdlSys(void *a0);
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int EVENT_TRAINER_EYE_GetSightType(u32 a);
extern int EVENT_TRAINER_EYE_GetTrainerId(u32 a);

u32 EVENT_TRAINER_EYE_FindPartner(u32 a, u16 b)
{
    u32 out;
    u32 iter;
    u32 h;

    iter = 0;
    h = (u32)FLDMMDL_GetMmdlSys((void *)a);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)h, (struct Rec **)(&out), &iter) == 1) {
        if (out != a && (u16)(EVENT_TRAINER_EYE_GetSightType(out) + 0xFFFF) <= 1 && b == EVENT_TRAINER_EYE_GetTrainerId(out)) {
            return out;
        }
    }
    return 0;
}
