/*
 * function: GIMMICK53_Exit
 * address:  0x021F3734
 * packet:   pkt_ov053_021F3734
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021; site +0008 now
 * resolves via `matched`. Site +0030 (SOUND_OBJ_Delete) resolves via label.
 *
 * symbols:
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 *   GIMMICK53_SaveAnimeFrames  0x021F39D0  thumb  ov053
 *   SOUND_OBJ_Delete  0x021C4DA8  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb
 */
#include "../include/Obj13115.h"

extern void *FIELDMAP_GetCommonWork(int, int);
struct Obj;
extern void ISS_3DS_SYS_SetVolume(struct Obj *o, unsigned int v);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);
extern void GIMMICK53_SaveAnimeFrames(char *a, int b);
extern int SOUND_OBJ_Delete(void *a);
extern void FIELDMAP_FreeCommonWork(int, int);

void GIMMICK53_Exit(int a)
{
    int i;
    char *p = (char *)FIELDMAP_GetCommonWork(a, 0);
    ISS_3DS_SYS_SetVolume((struct Obj *)(((struct Obj13115 *)p)->f4), 0);
    GFL_USE_SetBgmTrackVolume(((struct Obj13115 *)p)->f58, 0);
    GIMMICK53_SaveAnimeFrames(p, a);
    for (i = 0; i < 5; i++)
        SOUND_OBJ_Delete((void *)(*(int *)(p + i * 4 + 8)));
    FIELDMAP_FreeCommonWork(a, 0);
}
