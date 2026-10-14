/*
 * function: BR_NET_Create
 * address: 0x021FF408
 * packet: pkt_ov186_021FF408
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Layout: original fills 0x2c bytes of local config and allocates 0x5e4-byte context. Callback table occupies its final seven words.
 * symbols:
 *   ov125_id 0x0000007D data
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02012944 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   GDS_RAP_Init 0x021D6660 thumb ov125
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GDS_PROFILE_Create 0x0200D59C thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   BR_NET_CreateTask 0x021FFB14 thumb ov186
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   BR_NET_OnUploadEntry 0x021FFACC thumb ov186
 *   BR_NET_OnDownloadEntries 0x021FFAD8 thumb ov186
 *   BR_NET_OnUploadVideo 0x021FFAE4 thumb ov186
 *   BR_NET_OnSearchVideos 0x021FFAF0 thumb ov186
 *   BR_NET_OnGetVideo 0x021FFAFC thumb ov186
 *   BR_NET_OnMarkVideo 0x021FFB08 thumb ov186
 *   BR_NET_StepIdle 0x021FF8E0 thumb ov186
 *   BR_NET_OnRapError 0x021FFB80 thumb ov186
 *   gBrNetSourceFile 0x02200D8C data a1
 */
#include "../include/Obj06637.h"
typedef unsigned long u32;
typedef unsigned short u16;
typedef struct {u32 value;u32 unused;void *owner;void *arg;void *context;void (*a)(char *);void (*b)(char *);void (*c)(char *);void (*d)(char *);void (*e)(char *);void (*f)(char *);} Config;
extern int func_02034AC4(int);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
extern void MI_CpuFill8(void *,u32,u32);
typedef unsigned char  u8;
struct Big;
struct GdsProfile;
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern int GDS_RAP_Init(char *p, char *a);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct GdsProfile *GDS_PROFILE_Create(u32 heap);
extern void GDS_PROFILE_Init(struct GdsProfile *p, void *sys);
extern char *BR_NET_CreateTask(void *p, int f, unsigned heap);
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
extern void BR_NET_OnUploadEntry(char *),BR_NET_OnDownloadEntries(char *),BR_NET_OnUploadVideo(char *),BR_NET_OnSearchVideos(char *),BR_NET_OnGetVideo(char *),BR_NET_OnMarkVideo(char *);
extern void BR_NET_StepIdle(void);
extern int BR_NET_OnRapError(char *,int,int,int);
extern const char gBrNetSourceFile[];
extern char ov125_id[];
char *BR_NET_Create(void *owner,void *arg,u32 heap)
{
    char *p;
    Config cfg;
    func_02034AC4((int)ov125_id);
    p=func_02030734(heap,0x5E4,0,gBrNetSourceFile,0x97);
    MI_CpuFill8(p,0,0x5E4);
    ((struct Obj06637 *)p)->f5E0=owner;
    MI_CpuFill8(&cfg,0,0x2C);
    cfg.owner=owner;
    cfg.value=func_0200853C((const struct Sub0200852CObj *)func_02012944(owner));
    cfg.arg=arg;
    cfg.context=p;
    cfg.a=BR_NET_OnUploadEntry;cfg.b=BR_NET_OnDownloadEntries;cfg.c=BR_NET_OnUploadVideo;
    cfg.d=BR_NET_OnSearchVideos;cfg.e=BR_NET_OnGetVideo;cfg.f=BR_NET_OnMarkVideo;
    GDS_RAP_Init(p,(char *)(&cfg));
    ((struct Obj06637 *)p)->f5A4=1;
    GAME_DATA_GetSaveControl(owner);
    ((struct Obj06637 *)p)->f5A8=GDS_PROFILE_Create(heap);
    GDS_PROFILE_Init(((struct Obj06637 *)p)->f5A8,owner);
    ((struct Obj06637 *)p)->f5AC=BR_NET_CreateTask(p,(int)((void *)BR_NET_StepIdle),heap);
    DWC_RAP_SetErrorHookCallback((int)((void *)BR_NET_OnRapError),(int)p);
    return p;
}
