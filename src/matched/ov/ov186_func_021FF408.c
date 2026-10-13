/*
 * function: func_021FF408
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
 *   func_021D6660 0x021D6660 thumb ov125
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GDS_PROFILE_Create 0x0200D59C thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   func_021FFB14 0x021FFB14 thumb ov186
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   func_021FFACC 0x021FFACC thumb ov186
 *   func_021FFAD8 0x021FFAD8 thumb ov186
 *   func_021FFAE4 0x021FFAE4 thumb ov186
 *   func_021FFAF0 0x021FFAF0 thumb ov186
 *   func_021FFAFC 0x021FFAFC thumb ov186
 *   func_021FFB08 0x021FFB08 thumb ov186
 *   func_021FF8E0 0x021FF8E0 thumb ov186
 *   func_021FFB80 0x021FFB80 thumb ov186
 *   d_02200D8C 0x02200D8C data a1
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
extern int func_021D6660(char *p, char *a);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct GdsProfile *GDS_PROFILE_Create(u32 heap);
extern void GDS_PROFILE_Init(struct GdsProfile *p, void *sys);
extern char *func_021FFB14(void *p, int f, unsigned heap);
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
extern void func_021FFACC(char *),func_021FFAD8(char *),func_021FFAE4(char *),func_021FFAF0(char *),func_021FFAFC(char *),func_021FFB08(char *);
extern void func_021FF8E0(void);
extern int func_021FFB80(char *,int,int,int);
extern const char d_02200D8C[];
extern char ov125_id[];
char *func_021FF408(void *owner,void *arg,u32 heap)
{
    char *p;
    Config cfg;
    func_02034AC4((int)ov125_id);
    p=func_02030734(heap,0x5E4,0,d_02200D8C,0x97);
    MI_CpuFill8(p,0,0x5E4);
    ((struct Obj06637 *)p)->f5E0=owner;
    MI_CpuFill8(&cfg,0,0x2C);
    cfg.owner=owner;
    cfg.value=func_0200853C((const struct Sub0200852CObj *)func_02012944(owner));
    cfg.arg=arg;
    cfg.context=p;
    cfg.a=func_021FFACC;cfg.b=func_021FFAD8;cfg.c=func_021FFAE4;
    cfg.d=func_021FFAF0;cfg.e=func_021FFAFC;cfg.f=func_021FFB08;
    func_021D6660(p,(char *)(&cfg));
    ((struct Obj06637 *)p)->f5A4=1;
    GAME_DATA_GetSaveControl(owner);
    ((struct Obj06637 *)p)->f5A8=GDS_PROFILE_Create(heap);
    GDS_PROFILE_Init(((struct Obj06637 *)p)->f5A8,owner);
    ((struct Obj06637 *)p)->f5AC=func_021FFB14(p,(int)((void *)func_021FF8E0),heap);
    DWC_RAP_SetErrorHookCallback((int)((void *)func_021FFB80),(int)p);
    return p;
}
