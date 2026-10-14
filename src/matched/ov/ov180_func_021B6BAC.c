/*
 * function: HALL_OF_FAME_StateMonSequence
 * address: 0x021B6BAC
 * packet: pkt_ov180_021B6BAC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword alignment padding at 0x021B6F32.
 * Bound: original stack allocation 24 bytes is six output coordinate pairs, each two signed halfwords.
 * Caller evidence: 021B74B4's forwarded r0 is consumed; 021B7268 and 021B723C return their verified state values.
 * symbols:
 *   HALL_OF_FAME_BeginCountdown 0x021B7268 thumb ov180
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   HALL_OF_FAME_LoadMonInfo 0x021B654C thumb ov180
 *   HALL_OF_FAME_PrepareMonVoice 0x021B65A0 thumb ov180
 *   HALL_OF_FAME_CreateMonParticle 0x021B6778 thumb ov180
 *   HALL_OF_FAME_CreateBackdropParticle 0x021B67EC thumb ov180
 *   HALL_OF_FAME_LoadMonActors 0x021B761C thumb ov180
 *   HALL_OF_FAME_PrintMonInfo 0x021B78E0 thumb ov180
 *   HALL_OF_FAME_UpdatePlatePositions 0x021B7C08 thumb ov180
 *   HALL_OF_FAME_LoadUiPalette 0x021B7750 thumb ov180
 *   HALL_OF_FAME_BeginFadeIn 0x021B7210 thumb ov180
 *   HALL_OF_FAME_MoveActorRelative 0x021B7438 thumb ov180
 *   HALL_OF_FAME_StartMonParticle 0x021B67C4 thumb ov180
 *   HALL_OF_FAME_StartBackdropParticle 0x021B682C thumb ov180
 *   HALL_OF_FAME_GetActorPos 0x021B7408 thumb ov180
 *   HALL_OF_FAME_RandomizeJitter 0x021B727C thumb ov180
 *   HALL_OF_FAME_ApplyJitterStep 0x021B72B0 thumb ov180
 *   PM_VOICE_Start 0x02006A64 thumb
 *   HALL_OF_FAME_SetActorVisible 0x021B746C thumb ov180
 *   HALL_OF_FAME_PlayActorAnim 0x021B7488 thumb ov180
 *   PM_VOICE_IsActive 0x02006BD0 thumb
 *   HALL_OF_FAME_IsActorAnimActive 0x021B74B4 thumb ov180
 *   HALL_OF_FAME_BeginFadeOut 0x021B723C thumb ov180
 *   HALL_OF_FAME_DeleteBackdropParticle 0x021B681C thumb ov180
 *   HALL_OF_FAME_DeleteMonParticle 0x021B67B4 thumb ov180
 */
#include "../include/Obj00299.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern int HALL_OF_FAME_BeginCountdown(char *,int);
extern int HALL_OF_FAME_BeginFadeOut(char *,int,int);
extern int HALL_OF_FAME_BeginFadeIn(char *,int);
extern int HALL_OF_FAME_ApplyJitterStep(char *,int);
extern int HALL_OF_FAME_IsActorAnimActive(int *p, int i);
extern void GFL_USE_PlaySeDefaultVolume(u32);
typedef signed short   s16;
extern int GFL_USE_IsSeqPlaying(u32);
extern int PM_VOICE_Start(u32);
extern u32 PM_VOICE_IsActive(u32 i);
extern void HALL_OF_FAME_LoadMonInfo(char *),HALL_OF_FAME_PrepareMonVoice(char *),HALL_OF_FAME_CreateMonParticle(char *),HALL_OF_FAME_CreateBackdropParticle(char *),HALL_OF_FAME_LoadMonActors(char *),HALL_OF_FAME_PrintMonInfo(char *),HALL_OF_FAME_UpdatePlatePositions(char *),HALL_OF_FAME_LoadUiPalette(char *),HALL_OF_FAME_RandomizeJitter(char *);
extern void HALL_OF_FAME_StartMonParticle(char *,int);
extern void HALL_OF_FAME_StartBackdropParticle(int *,int);
extern void HALL_OF_FAME_GetActorPos(u8 *p, int n, s16 *x, s16 *y);
extern void HALL_OF_FAME_MoveActorRelative(u8 *p, int n, int x, int y);
extern void HALL_OF_FAME_SetActorVisible(int *,int,int);
extern void HALL_OF_FAME_PlayActorAnim(u8 *p, int n, int v);
extern void HALL_OF_FAME_DeleteBackdropParticle(int *);
extern void HALL_OF_FAME_DeleteMonParticle(int *);
int HALL_OF_FAME_StateMonSequence(char *p) {
    short coords[12];
    int busy;
    switch(((struct Obj00299 *)p)->f9190){
    case 0: ++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,32);
    case 1: GFL_USE_PlaySeDefaultVolume(0x79B);++((struct Obj00299 *)p)->f9190;break;
    case 2: if(++((struct Obj00299 *)p)->f9188==48){GFL_USE_PlaySeDefaultVolume(0x79C);((struct Obj00299 *)p)->f9188=0;++((struct Obj00299 *)p)->f9190;}break;
    case 3: if(GFL_USE_IsSeqPlaying(0x79C)==0){
        GFL_USE_PlaySeDefaultVolume(0x79A);HALL_OF_FAME_LoadMonInfo(p);HALL_OF_FAME_PrepareMonVoice(p);HALL_OF_FAME_CreateMonParticle(p);HALL_OF_FAME_CreateBackdropParticle(p);HALL_OF_FAME_LoadMonActors(p);HALL_OF_FAME_PrintMonInfo(p);HALL_OF_FAME_UpdatePlatePositions(p);HALL_OF_FAME_LoadUiPalette(p);
        ++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginFadeIn(p,5);
    }break;
    case 4: if(((struct Obj00299 *)p)->f9188==22){++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,8);}else{HALL_OF_FAME_MoveActorRelative((u8 *)p,1,-16,0);++((struct Obj00299 *)p)->f9188;}break;
    case 5: HALL_OF_FAME_StartMonParticle(p,0);HALL_OF_FAME_StartMonParticle(p,1);++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,8);
    case 6: HALL_OF_FAME_StartBackdropParticle((int *)p,1);++((struct Obj00299 *)p)->f9190;
    case 7:
        HALL_OF_FAME_GetActorPos((u8 *)p,2,&coords[11],&coords[10]);
        if(coords[11]!=168)HALL_OF_FAME_MoveActorRelative((u8 *)p,2,16,0);
        else{GFL_USE_PlaySeDefaultVolume(0x57A);HALL_OF_FAME_RandomizeJitter(p);((struct Obj00299 *)p)->f9160=coords[11];((struct Obj00299 *)p)->f9162=coords[10];++((struct Obj00299 *)p)->f9190;}
        HALL_OF_FAME_UpdatePlatePositions(p);break;
    case 8: HALL_OF_FAME_StartBackdropParticle((int *)p,0);++((struct Obj00299 *)p)->f9190;
    case 9:
        busy=HALL_OF_FAME_ApplyJitterStep(p,2);HALL_OF_FAME_GetActorPos((u8 *)p,3,&coords[9],&coords[8]);
        if(coords[9]!=88)HALL_OF_FAME_MoveActorRelative((u8 *)p,3,-16,0);
        else if(busy==0){GFL_USE_PlaySeDefaultVolume(0x57A);HALL_OF_FAME_RandomizeJitter(p);((struct Obj00299 *)p)->f9160=coords[9];((struct Obj00299 *)p)->f9162=coords[8];++((struct Obj00299 *)p)->f9190;}
        HALL_OF_FAME_UpdatePlatePositions(p);break;
    case 10:
        busy=HALL_OF_FAME_ApplyJitterStep(p,3);HALL_OF_FAME_GetActorPos((u8 *)p,0,&coords[7],&coords[6]);
        if(coords[7]!=48)HALL_OF_FAME_MoveActorRelative((u8 *)p,0,16,0);
        else if(busy==0){GFL_USE_PlaySeDefaultVolume(0x57A);HALL_OF_FAME_RandomizeJitter(p);((struct Obj00299 *)p)->f9160=coords[7];((struct Obj00299 *)p)->f9162=coords[6];++((struct Obj00299 *)p)->f9190;}
        HALL_OF_FAME_UpdatePlatePositions(p);break;
    case 11: if(HALL_OF_FAME_ApplyJitterStep(p,0)==0){PM_VOICE_Start(((struct Obj00299 *)p)->f9184);HALL_OF_FAME_SetActorVisible((int *)p,4,1);HALL_OF_FAME_PlayActorAnim((u8 *)p,4,6);++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginCountdown(p,128);}break;
    case 12: if(PM_VOICE_IsActive(((struct Obj00299 *)p)->f9184)==0 && HALL_OF_FAME_IsActorAnimActive((int *)p,4)==0)++((struct Obj00299 *)p)->f9190;break;
    case 13: HALL_OF_FAME_GetActorPos((u8 *)p,0,&coords[5],&coords[4]);if(coords[5]!=-48)HALL_OF_FAME_MoveActorRelative((u8 *)p,0,-16,0);else ++((struct Obj00299 *)p)->f9190;break;
    case 14: HALL_OF_FAME_GetActorPos((u8 *)p,3,&coords[3],&coords[2]);if(coords[3]!=264)HALL_OF_FAME_MoveActorRelative((u8 *)p,3,16,0);else ++((struct Obj00299 *)p)->f9190;HALL_OF_FAME_UpdatePlatePositions(p);break;
    case 15: HALL_OF_FAME_GetActorPos((u8 *)p,2,&coords[1],&coords[0]);if(coords[1]!=-8){HALL_OF_FAME_MoveActorRelative((u8 *)p,2,-16,0);HALL_OF_FAME_UpdatePlatePositions(p);}else{++((struct Obj00299 *)p)->f9190;return HALL_OF_FAME_BeginFadeOut(p,5,6);}break;
    case 16: HALL_OF_FAME_DeleteBackdropParticle((int *)p);HALL_OF_FAME_DeleteMonParticle((int *)p);++((struct Obj00299 *)p)->f915D;if(((struct Obj00299 *)p)->f915D==((struct Obj00299 *)p)->f915E){((struct Obj00299 *)p)->f915D=0;((struct Obj00299 *)p)->f9190=0;return 6;}else ((struct Obj00299 *)p)->f9190=3;break;
    }
    return 5;
}
