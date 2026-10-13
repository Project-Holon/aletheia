/*
 * file:     btl_rec_sel_graphic.c
 * unit:     yes
 * function: func_021BB178, func_021BB220, func_021BB27C, func_021BB290, func_021BB29C, func_021BB2A8, func_021BB2B4, func_021BB2C8, func_021BB328, func_021BB360, func_021BB364, func_021BB36C, func_021BB3AC, func_021BB3C8, func_021BB3D0, func_021BB3DC, func_021BB448, func_021BB458
 * address:  0x021BB178
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 *   config2 0x021BB53C data ov214
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BB46C 0x021BB46C thumb ov214
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   records 0x021BB5B8 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_021BB0D4 0x021BB0D4 thumb ov214
 *   dims 0x020A1EB8 data
 *   vec1 0x021BB524 data a4
 *   vec2 0x021BB518 data ov214
 *   vec3 0x021BB530 data ov214
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm  arm9
 */
#include "../../matched/include/Obj25730.h"
#include "../../matched/include/Obj25731.h"
#include "../../matched/include/Obj14703.h"
#include "../../matched/include/Obj25732.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Light;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct Record { u32 id; u8 template_data[32]; u32 type; u32 enabled; };

typedef signed short s16;

struct Vec3 { u32 x,y,z; };

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,u32,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern u32 func_020056A0(void (*)(void *),void *,u32);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BB46C(void *);
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
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_021BB0D4(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u32);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
char *func_021BB178(u32 a,u32 heap);
void func_021BB220(char *p);
void func_021BB27C(u8 *p);
void func_021BB290(u8 *p);
void func_021BB29C(char *p);
u32 func_021BB2A8(u8 *p);
void func_021BB2B4(void *unused,u8 *p);
void func_021BB2C8(void *p,u32 heap);
void func_021BB328(void *p);
void func_021BB360(void *p);
void func_021BB364(void *p);
void func_021BB36C(unsigned char *p, int a, int b);
void func_021BB3AC(void *p);
void func_021BB3C8(void *p);
void func_021BB3D0(void *p);
u32 func_021BB3D8(u32 *p);
void func_021BB3DC(u32 **out,u32 heap);
void func_021BB448(int *p);
void func_021BB458(unsigned int *p);
extern const char site[];
extern const u32 config[];
extern const u32 config2[];
extern const struct Record records[];
extern const char dims[];
extern struct Vec3 vec1,vec2,vec3;





/*
 * volatile: MMIO accesses 021BB19E..021BB1B2
 */
char *func_021BB178(u32 a,u32 heap)
{
    char *p=func_02030734(heap,16,0,site,458);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)config);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BB2C8(p,heap);
    func_021BB36C((unsigned char *)p+4,(int)config,heap);
    func_021BB3DC((u32 **)(p+8),heap);
    ((struct Obj25730 *)p)->fC=func_020056A0((void (*)(void *))func_021BB2B4,p,0);
    return p;
}





void func_021BB220(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj25731 *)p)->fC));
    func_021BB448((int *)(p+8));
    func_021BB3AC(p+4);
    func_021BB328(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}





void func_021BB27C(u8 *p) { func_021BB3C8(p+4);func_021BB360(p); }





void func_021BB290(u8 *p) { func_021BB458((u32 *)(p+8)); }





void func_021BB29C(char *p) { func_021BB46C(p+8); }





u32 func_021BB2A8(u8 *p) { return func_021BB3D8((u32 *)(p+4)); }



void func_021BB2B4(void *unused,u8 *p) { func_021BB364(p);func_021BB3D0(p+4); }


/*
 * Caller explicitly narrows both BG identifiers and record fields to u8.
 * Heap externs widened: caller passes full r1 without a narrowing instruction.
 */
void func_021BB2C8(void *p,u32 heap)
{
    u32 i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)config2);
    for(i=0;i<3;i++) {
        const struct Record *r=&records[i];
        u32 id=r->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)r->template_data,(u8)r->type);
        func_020414AC(id);
        func_02040588(id,r->enabled);
    }
}


void func_021BB328(void *p) { u32 i;for(i=0;i<3;i++)func_020403F4((u8)records[i].id);BMP_WIN_Exit();func_0203F9B4();func_02082BCC(p,0,4); }




void func_021BB360(void *p) { }



void func_021BB364(void *p) { func_020419E4(); }




void func_021BB36C(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BB54C, a, b);
    ((struct Obj14703 *)p)->f0 = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14703 *)p)->f0);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void func_021BB3AC(void *p) { CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25732 *)p)->f0);CLACT_ExitSystem();func_02082BCC(p,0,4); }



void func_021BB3C8(void *p) { CLACT_DrawSystem(); }



void func_021BB3D0(void *p) { CLACT_VBlankSystem(); }



/*
 * follower: 021BB3D8 word getter, within handed extent.
 */
u32 func_021BB3D8(u32 *p) { return *p; }



void func_021BB3DC(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021BB0D4);
    *out=G3D_CAMERA_Create(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,&vec1,&vec2,&vec3,heap);
}




void func_021BB448(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}




void func_021BB458(unsigned int *p)
{
    func_02047964();
    func_02048AD0((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
