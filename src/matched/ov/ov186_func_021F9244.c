/*
 * function: BR_PROC_SYS_Exit
 * address: 0x021F9244
 * packet: pkt_ov186_021F9244
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume 0x02028A58 thumb
 *   BR_NET_IsFatal 0x021FF8D4 thumb ov186
 *   BR_NET_Destroy 0x021FF4E4 thumb ov186
 *   ov125_id 0x0000007d data
 *   func_02034A5C 0x02034A5C arm
 *   BR_SIDEBAR_Destroy 0x021FEDC4 thumb ov186
 *   BR_FADE_Delete 0x021FE734 thumb ov186
 *   BR_PROC_SYS_Delete 0x021F9A6C thumb ov186
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BEACON_SetRecorderFlag 0x0200C3EC thumb
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_Delete 0x021FB92C thumb ov186
 *   BR_GRAPHIC_Destroy 0x021FC474 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct SoundSys;
extern void FIELD_SOUND_SYSTEM_FadeVolume(struct SoundSys *sys, u8 level, u16 frames);
extern int BR_NET_IsFatal(char *);
extern void BR_NET_Destroy(char *p);
extern char ov125_id[];
extern void func_02034A5C(int);
extern void BR_SIDEBAR_Destroy(char *p, char *ctx);
extern void BR_FADE_Delete(char *p);
extern void BR_PROC_SYS_Delete(int *);
extern void *GAME_DATA_GetMiscSave(int *p);
extern int BR_RES_GetPalSet(char *p);
typedef unsigned int   u32;
struct Blk34;
extern void BEACON_SetRecorderFlag(struct Blk34 *p, u32 v);
extern void BR_RES_ApplyBgSet(int,unsigned);
extern void BR_RES_Delete(char *p);
extern void BR_GRAPHIC_Destroy(char *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int BR_PROC_SYS_Exit(int sys,int unused,int unused2,int *p)
{
    int *nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) FIELD_SOUND_SYSTEM_FadeVolume((struct SoundSys *)GAME_DATA_GetBgmInfo((const struct BigObj *)nested[1]),0x7f,0);
    if(p[5]) {
        if(BR_NET_IsFatal((char *)p[5])) ((int *)((int *)p[6])[3])[3]=2;
        BR_NET_Destroy((char *)p[5]); p[5]=0;
    } else func_02034A5C((int)ov125_id);
    BR_SIDEBAR_Destroy((char *)p[4],(char *)p[1]);
    BR_FADE_Delete((char *)p[3]);
    BR_PROC_SYS_Delete((int *)p[2]);
    nested=(int *)((int *)p[6])[3];
    if(nested[0]==0) {
        int a=(int)GAME_DATA_GetMiscSave((int *)nested[1]);
        int b=BR_RES_GetPalSet((char *)p[1]);
        BEACON_SetRecorderFlag((struct Blk34 *)a,(unsigned char)b);
    }
    BR_RES_ApplyBgSet(p[1],0);
    BR_RES_ApplyBgSet(p[1],1);
    BR_RES_Delete((char *)p[1]);
    BR_GRAPHIC_Destroy((char *)p[0]);
    func_020315D4((struct S020315D4 *)sys);
    GFL_HEAP_DeleteChecked(0x5a);
    return 1;
}
