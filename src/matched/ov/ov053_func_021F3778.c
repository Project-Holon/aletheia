/*
 * function: FIELD_GIMMICK_SOUND_OBJS_Update
 * address:  0x021F3778
 * packet:   pkt_ov053_021F3778
 * region:   ov053
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb  ov021
 *   FIELD_CAMERA_GetTargetRaw  0x0218ECB4  thumb  ov021
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   FIELD_GIMMICK_SOUND_OBJS_RestartAnime  0x021F3A5C  thumb  ov053
 *   SOUND_OBJ_AdvanceAnime  0x021C4DE4  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_StartWait  0x021F3A38  thumb  ov053
 *   FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade  0x021F3A7C  thumb  ov053
 *   FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume  0x021F3A6C  thumb  ov053
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe  0x021F3B40  thumb  ov053
 */

typedef unsigned char  u8;
struct Obj;
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *p);
extern void FIELD_CAMERA_GetEyeRaw(int, int *);
extern void FIELD_CAMERA_GetTargetRaw(int, int *);
extern void ISS_3DS_SYS_SetCamera(int a, void *b, void *c);
extern int FIELD_GIMMICK_SOUND_OBJS_RestartAnime(char *p, int i);
extern int SOUND_OBJ_AdvanceAnime(int, int);
extern void FIELD_GIMMICK_SOUND_OBJS_StartWait(char *a, int i);
extern void FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(char *p, int a);
extern void FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(int *);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_UpdateAnimes(int);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(struct Obj *o, int h, u8 *a2);

void FIELD_GIMMICK_SOUND_OBJS_Update(int a)
{
    int i;
    int h;
    int *p;
    int v1[3];
    int v2[3];

    i = 0;
    p = FIELDMAP_GetCommonWork((char *)a, 0);
    h = (int)FIELDMAP_GetCamera((void *)a);
    FIELD_CAMERA_GetEyeRaw(h, v1);
    FIELD_CAMERA_GetTargetRaw(h, v2);
    ISS_3DS_SYS_SetCamera(p[1], v1, v2);
    for (i = 0; i < 5; i++) {
        int *q = p + i;
        if (q[7] > 0) {
            if (--q[7] <= 0) {
                FIELD_GIMMICK_SOUND_OBJS_RestartAnime((char *)p, i);
                switch (i) {
                case 0:
                    p[8] = 1;
                    break;
                case 2:
                    p[10] = 1;
                    break;
                }
            }
        } else if (SOUND_OBJ_AdvanceAnime(q[2], 0x1000)) {
            FIELD_GIMMICK_SOUND_OBJS_StartWait((char *)p, i);
        }
    }
    FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade((char *)p, a);
    FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(p);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj((int *)a));
    FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe((struct Obj *)(p + 0x1a), h, (u8 *)FIELDMAP_GetFieldPlayer((struct Obj00020 *)a));
}
