/*
 * function: FIELD_GIMMICK_SOUND_OBJS_B_Exit
 * address: 0x021F3704
 * packet: pkt_ov054_021F3704
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   ISS_3DS_SYS_SetVolume 0x0202B914 thumb
 *   FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames 0x021F38B0 thumb ov054
 *   SOUND_OBJ_Delete 0x021C4DA8 thumb ov021
 */
#include "../include/Obj20572.h"

extern int *FIELDMAP_GetCommonWork(char *,int);
extern void FIELDMAP_FreeCommonWork(unsigned char *,int);
typedef unsigned int   u32;
struct Obj;
extern void ISS_3DS_SYS_SetVolume(struct Obj *o, u32 v);
extern void FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(char *,int);
extern int SOUND_OBJ_Delete(void *a);
void FIELD_GIMMICK_SOUND_OBJS_B_Exit(char *a) { int i=0; char *p=(char *)FIELDMAP_GetCommonWork(a,0); ISS_3DS_SYS_SetVolume((struct Obj *)(((struct Obj20572 *)p)->f4),0); FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(p,(int)a); for(;i<2;i++) SOUND_OBJ_Delete((void *)(*(void **)(p+8+4*i))); FIELDMAP_FreeCommonWork((unsigned char *)a,0); }
