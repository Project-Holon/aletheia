/*
 * function: EVENT_TRAINER_EYE_FindTrainer
 * address:  0x021AE1FC
 * packet:   pkt_ov021_021AE1FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetSightDistance  0x021AE288  thumb  ov021
 *   EVENT_TRAINER_EYE_IsTrainerDefeated  0x021AE890  thumb  ov021
 *   EVENT_TRAINER_EYE_FillHit  0x021AE8B4  thumb  ov021
 */

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetEncount(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
struct S;
extern int EVENT_TRAINER_EYE_GetSightDistance(int a, int b, int c, u16 *d);
extern int EVENT_TRAINER_EYE_IsTrainerDefeated(u32 a, u32 b);
extern void EVENT_TRAINER_EYE_FillHit(struct S *s, u32 a, u32 b, u32 c);

int EVENT_TRAINER_EYE_FindTrainer(int a, void *b, int c)
{
    int s0, s4, s8;
    u16 sc;
    void *s14;
    int s10;
    void *r4;
    void *r7;

    s0 = c;
    s4 = FIELDMAP_GetEncount((void *)a);
    r4 = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)a));
    r7 = FIELDMAP_GetMmdlSys((void *)a);
    s14 = 0;
    s10 = 0;
    while (FLDMMDL_SysSearchUseMmdl(r7, (struct Rec **)(&s14), (u32 *)(&s10)) == 1) {
        if (s14 != r4 && (b == 0 || b != s14)) {
            s8 = EVENT_TRAINER_EYE_GetSightDistance(s4, (int)s14, (int)r4, &sc);
            if (s8 != -1 && EVENT_TRAINER_EYE_IsTrainerDefeated((u32)((void *)a), (u32)s14) == 0) {
                EVENT_TRAINER_EYE_FillHit((struct S *)s0, (u32)s14, s8, sc);
                return 1;
            }
        }
    }
    return 0;
}
