/*
 * function: EVENT_TRAINER_EYE_StepWaitPlayerFace
 * address:  0x021AE6E0
 * packet:   pkt_ov021_021AE6E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u8 pad[0x30]; u8 *f34; } S;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_CheckEndAcmd(void *a);
extern int FLDMMDL_EndAcmd(char *p);

int EVENT_TRAINER_EYE_StepWaitPlayerFace(S *s)
{
    void *t = FIELD_PLAYER_GetMmdl(s->f34);

    if (FLDMMDL_CheckEndAcmd(t) == 0)
        return 0;
    FLDMMDL_EndAcmd(t);
    s->f0 = 0x10;
    return 1;
}
