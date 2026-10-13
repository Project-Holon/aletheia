/*
 * file:     zenkoku_zukan_award_graphic.c
 * unit:     yes
 * function: func_021B9F10, func_021B9FB8, func_021BA014, func_021BA028, func_021BA034, func_021BA048, func_021BA0A8, func_021BA0E0, func_021BA0E4, func_021BA0EC, func_021BA12C, func_021BA148, func_021BA150, func_021BA15C
 * address:  0x021B9F10
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021BA390 0x021BA390 data a1
 *   d_021BA2CC 0x021BA2CC data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA1C8 0x021BA1C8 thumb ov222
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   config 0x021BA280 data a4
 *   records 0x021BA2FC data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_021B9E6C 0x021B9E6C thumb ov222
 *   dims 0x020A1EB8 data
 *   vec1 0x021BA268 data a4
 *   vec2 0x021BA25C data a4
 *   vec3 0x021BA274 data ov222
 */
#include "../../matched/include/Obj26083.h"
#include "../../matched/include/Obj26084.h"
#include "../../matched/include/Obj14785.h"
#include "../../matched/include/Obj26085.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

struct Record_021BA048 { u32 id; u8 template_data[32]; u32 type; u32 enabled; };

struct Record_021BA0A8 { u32 id;u8 template_data[32];u32 type;u32 enabled; };

typedef signed short s16;

struct Vec3 { u32 x,y,z; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void*,int,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void* func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_021BA1C8(u32 *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(u32);
extern void BMP_WIN_Init(u32);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_021B9E6C(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u32);
void* func_021B9F10(u32 swap,u32 heap);
void func_021B9FB8(char *p);
void func_021BA014(char *p);
u32 func_021BA028(char *p);
void func_021BA034(void *unused, char *p);
void func_021BA048(void *p,u32 heap);
void func_021BA0A8(void *p);
void func_021BA0E0(void *p);
void func_021BA0E4(void *p);
void func_021BA0EC(unsigned char *p, int a, int b);
void func_021BA12C(char *p);
void func_021BA148(void *p);
void func_021BA150(void *p);
u32 func_021BA158(const u32 *p);
void func_021BA15C(u32 **out,u32 heap);
extern char d_021BA390[];
extern u32 d_021BA2CC[];
extern u32 config[];
extern const struct Record_021BA048 records[];
extern const char dims[];
extern struct Vec3 vec1,vec2,vec3;

void* func_021B9F10(u32 swap,u32 heap)
{
 char*p;
 u32*g;
 p=func_02030734(heap,16,0,d_021BA390,0x1cc);
 MI_CpuFill8(p,0,16);
 *(volatile u16*)0x04000050=0;
 *(volatile u16*)0x04001050=0;
 *(volatile u32*)0x04000000 &= ~0xe000u;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 BG_SYS_ClearGraphicsMemory(0);
 g=d_021BA2CC;
 BG_SYS_SetVramBanks((const struct DispVram *)g);
 func_0204363C(swap);
 BG_SYS_ResetSubDisplay();
 BG_SYS_ClearMainPlanes();
 BG_SYS_ClearSubPlanes();
 func_0201DD60();
 func_021BA048(p,heap);
 func_021BA0EC((unsigned char*)p+4,(int)g,heap);
 func_021BA15C((u32**)(p+8),heap);
 *(void* *)&((struct Obj26083 *)p)->fC=func_020056A0((u32)func_021BA034,(u32)p,0);
 return p;
}

/*
 * volatile: BLDCNT stores 021B9FDE/021B9FE4; DISPCNT accesses 021B9FE6..021B9FF4
 * 1DD68 ignores incoming arguments and tails with fixed 1,2,0.
 */
void func_021B9FB8(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26084 *)p)->fC));
    func_021BA1C8((u32 *)(p+8));
    func_021BA12C(p+4);
    func_021BA0A8(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}


void func_021BA014(char *p)
{
    func_021BA148(p + 4);
    func_021BA0E0(p);
}

u32 func_021BA028(char *p) { return func_021BA158((const u32 *)(p+4)); }


void func_021BA034(void *unused, char *p)
{
    func_021BA0E4(p);
    func_021BA150(p + 4);
}

void func_021BA048(void *p,u32 heap)
{
    u32 i;
    MI_CpuFill8(p,0,4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config);
    for(i=0;i<2;i++) {
        const struct Record_021BA048 *r=&records[i];
        u32 id=r->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        func_020414AC(id);
        func_02040588(id,r->enabled);
    }
}

void func_021BA0A8(void *p) { u32 i;for(i=0;i<2;i++)func_020403F4((u8)records[i].id);BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4); }

void func_021BA0E0(void *p) { }

void func_021BA0E4(void *p) { func_020419E4(); }


void func_021BA0EC(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BA290, a, b);
    ((struct Obj14785 *)p)->f0 = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)((struct Obj14785 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BA12C(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26085 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void func_021BA148(void *p) { CLACT_DrawSystem(); }

void func_021BA150(void *p) { CLACT_VBlankSystem(); }

u32 func_021BA158(const u32 *p) { return *p; }

void func_021BA15C(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021B9E6C);
    *out=G3D_CAMERA_Create(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,&vec1,&vec2,&vec3,heap);
}
