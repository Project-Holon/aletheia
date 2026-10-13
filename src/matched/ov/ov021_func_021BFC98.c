/*
 * function: EVENT_APPEAR_RunMoveAnime
 * address:  0x021BFC98
 * packet:   pkt_ov021_021BFC98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera 0x02188C58 thumb ov021
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetMmdl 0x021A3074 thumb ov021
 *   FIELD_CAMERA_GetMode 0x0218E138 thumb ov021
 *   FIELD_CAMERA_SetMode 0x0218E13C thumb ov021
 *   FLDMMDL_SetAcmd 0x0216D410 thumb ov010
 *   FLDMMDL_CheckEndAcmd 0x0216D454 thumb ov010
 *   FLDMMDL_EndAcmd 0x0216D480 thumb ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn 0x021BE92C thumb ov021
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
typedef unsigned short u16;
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_CheckEndAcmd(void *);
extern int FLDMMDL_EndAcmd(char *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_APPEAR_RunMoveAnime(int a, int *s, int *q)
{
    int h = (int)FIELDMAP_GetCamera((void *)q[1]);
    void *t;

    t = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)q[1]));
    switch (s[0]) {
    case 0:
        q[2] = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        FLDMMDL_SetAcmd(t, 0x44);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)q[0], q[1], 0, 1, 1, 0, 0));
        s[0] = s[0] + 1;
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(t) == 1) {
            FLDMMDL_EndAcmd(t);
            s[0] = s[0] + 1;
        }
        break;
    case 2:
        FIELD_CAMERA_SetMode((u8 *)h, q[2]);
        s[0] = s[0] + 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}
