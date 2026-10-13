/*
 * function: GIMMICK54_Update
 * address:  0x021F373C
 * packet:   pkt_ov054_021F373C
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 2026-10-05 (wave D5 lane 02): arm9 ISS_3DS_SYS_SetCamera re-verified EXACT (Thumb) and filed as src/matched/arm9/ISS_3DS_SYS_SetCamera.c; unresolved site clears once labelled.
 * 2026-10-05 (wD4 lane19): still MATCH*. Blocked by arm9 0x0202B93C (parked MATCH in src/pending/arm9, no label).
 *
 * 2026-10-04 (wave D2 lane 14): re-checked, still MATCH. ISS_3DS_SYS_SetCamera is parked as MATCH in
 * src/pending/arm9/ISS_3DS_SYS_SetCamera.c; its callee ISS_3DS_SYS_SetCameraImpl (Thumb, 30 bytes, copies two 3-word
 * vectors to p+0xC and p+0x18) is now EXACT in src/matched/arm9/ISS_3DS_SYS_SetCameraImpl.c. The remaining
 * unresolved site (+0034) needs 0x0202B93C and 0x0202BA9C to be labelled or in a shard.
 *
 * Blocker (older note): ISS_3DS_SYS_SetCamera (arm9, unlabelled tail-call stub, the integrator's) has no
 * witness.  Its verified C (MATCH, 8 bytes):
 *   extern void ISS_3DS_SYS_SetCameraImpl(int, void *, void *);
 *   void ISS_3DS_SYS_SetCamera(int a, void *b, void *c) { ISS_3DS_SYS_SetCameraImpl(a, b, c); }
 *   symbols: ISS_3DS_SYS_SetCameraImpl 0x0202BA9C thumb
 * Callee 0x021F3918 (ov054, 36 B) is unmatched but resolves sole-ref/code.
 *
 * symbols:
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   G3D_CAMERA_GetUp  0x02048B30  arm
 *   ISS_3DS_SYS_SetCamera  0x0202B93C  thumb
 *   SOUND_OBJ_AdvanceAnime  0x021C4DE4  thumb  ov021
 *   GIMMICK54_RestartAnime  0x021F393C  thumb  ov054
 *   GIMMICK54_StartWait  0x021F3918  thumb  ov054
 */

extern void *FIELDMAP_GetCommonWork(int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void G3D_CAMERA_GetEye(void *, void *);
extern void G3D_CAMERA_GetUp(void *, void *);
extern void ISS_3DS_SYS_SetCamera(int, void *, void *);
extern int SOUND_OBJ_AdvanceAnime(int, int);
extern int GIMMICK54_RestartAnime(char *, int);
extern void GIMMICK54_StartWait(char *, int);

void GIMMICK54_Update(int a)
{
    int i;
    char *p;
    void *cam;
    int v[3];
    int w[3];

    p = (char *)FIELDMAP_GetCommonWork(a, 0);
    cam = (void *)FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera((void *)a));
    G3D_CAMERA_GetEye(cam, v);
    G3D_CAMERA_GetUp(cam, w);
    ISS_3DS_SYS_SetCamera(*(int *)(p + 4), v, w);
    for (i = 0; i < 2; i++) {
        int *e = (int *)(p + i * 4);
        if (e[4] > 0) {
            e[4]--;
            if (e[4] <= 0)
                GIMMICK54_RestartAnime(p, i);
        } else if (SOUND_OBJ_AdvanceAnime(e[2], 0x1000)) {
            GIMMICK54_StartWait(p, i);
        }
    }
}
