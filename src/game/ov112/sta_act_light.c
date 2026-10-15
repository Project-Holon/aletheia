/*
 * file:     sta_act_light.c
 * unit:     yes
 * function: func_021F6BC0, func_021F6BD8, func_021F6C7C, func_021F6CB0, func_021F6CE0, func_021F6D68, func_021F6E74, func_021F6E78, func_021F6EE4, func_021F6EF4, func_021F6F04, func_021F6F14, func_021F6F1C, func_021F6F24, func_021F6F4C, func_021F6F64, func_021F6F8C, func_021F6FB0, func_021F7048, func_021F7098, func_021F709C, func_021F7120, func_021F7160, func_021F718C, func_021F7204, func_021F732C, func_021F75A0, func_021F75D8, func_021F75DC, func_021F760C, func_021F77A0, func_021F77EC, func_021F79A8, func_021F7A98, func_021F7AEC, func_021F7BA8, func_021F7C90, func_021F7D30, func_021F7E2C, func_021F7ECC, func_021F7FA8, func_021F7FAC, func_021F8044, func_021F8054, func_021F8068, func_021F8084, func_021F80A0, func_021F80B0, func_021F80D4, func_021F8120, func_021F812C, func_021F8140, STA_ACT_LIGHT_SetElemValue
 * address:  0x021F6BC0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   func_02030734 0x02030734 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021F8408 0x021F8408 data a4
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_GetSelection 0x021F9E18 thumb ov132
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   d_021F8454 0x021F8454 data a1
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   d_021F8430 0x021F8430 data a4
 *   d_021F8418 0x021F8418 data a4
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   d_021F8464 0x021F8464 data a1
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 *   func_021F9E44 0x021F9E44 thumb ov132
 *   func_021F4990 0x021F4990 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   MTX_MultVec33 0x0207B51C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   func_021F5350 0x021F5350 thumb ov112
 *   func_021F5368 0x021F5368 thumb ov112
 *   func_021F535C 0x021F535C thumb ov112
 *   func_021F5424 0x021F5424 thumb ov112
 *   func_020056EC 0x020056EC thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   table 0x020A1B38 data a2
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4B30 0x021F4B30 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   _fadd 0x0209C95C arm
 *   func_021F5204 0x021F5204 thumb ov112
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B88 0x021F4B88 thumb ov112
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4B4C 0x021F4B4C thumb ov112
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F514C 0x021F514C thumb ov112
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   d_021F832C 0x021F832C data a4
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   func_021F9EDC 0x021F9EDC thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F9FD0 0x021F9FD0 thumb ov132
 *   func_021F9FB4 0x021F9FB4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   _ll_mul 0x0209C054 arm
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F539C 0x021F539C thumb ov112
 *   func_021F53B4 0x021F53B4 thumb ov112
 *   func_021F53CC 0x021F53CC thumb ov112
 *   func_021F5374 0x021F5374 thumb ov112
 *   func_021F5388 0x021F5388 thumb ov112
 *   func_021F5414 0x021F5414 thumb ov112
 */
#include "../../matched/include/Obj22554.h"
#include "../../matched/include/Obj08024.h"
#include "../../matched/include/Obj00771.h"
#include "../../matched/include/Obj05317.h"
#include "../../matched/include/Obj13836.h"
#include "../../matched/include/Obj05318.h"
#include "../../matched/include/Obj08025.h"
#include "../../matched/include/Obj08026.h"
#include "../../matched/include/Obj00670.h"
#include "../../matched/include/Obj13837.h"
#include "../../matched/include/Obj13838.h"
#include "../../matched/include/Obj22556.h"
#include "../../matched/include/Obj13839.h"
#include "../../matched/include/Obj10318.h"
#include "../../matched/include/Obj00904.h"
#include "../../matched/include/Obj00723.h"
#include "../../matched/include/Obj02824.h"
#include "../../matched/include/Obj03762.h"
#include "../../matched/include/Obj10319.h"
#include "../../matched/include/Obj10320.h"
#include "../../matched/include/Obj10321.h"
#include "../../matched/include/Obj02169.h"
#include "../../matched/include/Obj03248.h"
#include "../../matched/include/Obj13841.h"
#include "../../matched/include/Obj22558.h"
#include "../../matched/include/Obj13842.h"
#include "../../matched/include/Obj22559.h"
#include "../../matched/include/Obj08027.h"
#include "../../matched/include/Obj13843.h"
#include "../../matched/include/Obj22561.h"
#include "../../matched/include/Obj06409.h"
#include "../../matched/include/Obj08028.h"
#include "../../matched/include/Obj22562.h"
#include "../../matched/include/Obj06410.h"
#include "../../matched/include/Obj08029.h"
#include "../../matched/include/Obj22563.h"
#include "../../matched/include/Obj06411.h"
#include "../../matched/include/Obj08031.h"
#include "../../matched/include/Obj22564.h"
#include "../../matched/include/Obj04463.h"
#include "../../matched/include/Obj22565.h"
#include "../../matched/include/Obj10324.h"
#include "../../matched/include/Obj22566.h"
#include "../../matched/include/Obj08033.h"
#include "../../matched/include/Obj13844.h"
#include "../../matched/include/Obj13845.h"
#include "../../matched/include/Obj13846.h"
#include "../../matched/include/Obj22568.h"
#include "../../matched/include/Obj10327.h"

#define E (*(u8 **)(q + off + 0x84))
#define EA (*(u8 **)(q + off + 0xA8))
#define FXR(x) ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct Bank;
struct Obj;
struct Vec2;
struct Arg;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Tagged;
struct Desc;
struct Trip;
struct Personal;
struct Board;
struct Vec3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_021F6BD8;

typedef struct { u16 heap,pad; void *a; u32 entries[4][8]; u32 other[8]; void *bank; u32 x,y,z; } Object;

typedef struct { short x, y; } Point_021F6CE0;

typedef struct { short x,y; } Point_021F6D68;

typedef struct { Point_021F6D68 pos; u16 x,y,z; u8 a,b; } Desc;

typedef struct { int x,y,z; } Vec_021F6D68;

typedef short s16_021F6BC0;

typedef signed char s8;

typedef int s32_021F6E74;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef struct {int x,y,z;} Vec_021F6F04;

typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;

typedef int s32;

typedef struct { int pad[5]; int flag; } Record;

typedef struct { int x,y,z; } Vec_021F6F64;

typedef struct { int m[9]; } Mtx;

typedef struct { int x, y, z; } Vec_021F732C;

typedef int s32_021F75D8;

typedef signed int     s32_021F760C;

typedef struct { int pad[24]; int value; int pad2[8]; int other; } Slot_021F6BC0;

typedef struct { u16 count, pad; int index; } Tail_021F6F64;

typedef struct { short count, pad; int index, a, b; } Tail_021F7AEC;

typedef struct { int x,y,z; } Vec_021F7BA8;

typedef struct { u16 count,pad; int index,a,b; } Tail_021F6BC0;

typedef struct { int x, y, z; } Vec_021F7C90;

typedef struct { short count, pad; int index, a, b; } Tail_021F7C90;

typedef signed short   s16_021F7C90;

typedef long long s64;

typedef struct { int x,y,z; } Vec_021F7D30;

typedef struct { u16 count,pad; int index,a,b; } Tail_021F7D30;

typedef struct { int x,y,z; } Vec_021F7ECC;

typedef struct { u16 count,pad; int index,a,b; } Tail_021F7ECC;

typedef struct { short y,x; } Scale;

typedef signed short   s16_021F7ECC;

typedef short s16_021F7FAC;

typedef struct { u16 count, pad; int index; } Tail_021F7FAC;

typedef struct { u8 pad0[0x4c]; int zero; u8 pad50[8]; int target; } Obj;

typedef struct { int pad[33]; int a; int pad2[17]; int b; } Slot_021F7C90;

extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern signed int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021F6BD8 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021F6BD8 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_DeleteUnit(void *);
extern void func_020307B0(void *);
extern u16 STA_ACTING_GetCameraTarget(u8 *p);
extern int STA_ACTING_GetSelection(char *p);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_DeleteActor(struct Obj *p);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);
extern void MTX_Identity33_(void *);
extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void G3D_SYSTEM_DeleteObject(struct Rec *p);
extern void G3D_SYSTEM_DeleteAnime(struct Rec *p);
extern void G3D_SYSTEM_DeleteRender(struct Rec *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern u32 BILLBOARD_AddImageFromArchive(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
extern void BILLBOARD_DeleteImage(u8 *a0, int i);
extern u32 func_021F9E44(u8 *p);
extern void func_021F4990(int);
extern u8 *func_021F545C(u8 *);
extern char *func_021F5464(char *);
extern void VEC_Add(const Vec_021F6F64 *,const Vec_021F6F64 *,Vec_021F6F64 *);
extern void func_0207AF38(Mtx *,int,int);
extern void MTX_MultVec33(const Vec_021F6F64 *,const Mtx *,Vec_021F6F64 *);
extern void VEC_Subtract(const Vec_021F6F64 *,const Vec_021F6F64 *,Vec_021F6F64 *);
extern void func_021F5350(int *p, int *q);
extern void func_021F5368(int *,u16);
extern void func_021F535C(int *p, int *q);
extern void func_021F5424(int,int);
extern u32 func_020056EC(u32);
extern u8 *func_021F5450(u8 *, int);
extern int func_021F4B30(u8 *);
extern int func_021F4B24(u8 *);
extern void func_021F4E8C(u32, u8 *, const Vec_021F732C *);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021F4EB4(u32 unused, u32 p, s16_021F6BC0 a, s16_021F6BC0 b);
extern void func_021F4E6C(u8 *, u8 *, u32);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern u8 *func_021F5204(void *,u8 *,u32);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *);
extern void *func_021F4B3C(int type);
extern void *func_021F4B88(void *,int,u32,int *);
extern s32_021F760C BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_FreeElem(void *p, u32 idx);
extern void func_021F4D40(u8 *p, u8 *e);
extern void func_021F4B4C(struct Tagged *a0);
extern void func_021F5330(int, int);
extern u32 func_021F4F10(u8 *);
extern unsigned char func_021F514C(void *p, int i);
extern void GFL_USE_PlaySeInSlot(void *,int);
extern void GFL_USE_StopSeSlot(int);
extern void *STA_ACTING_GetAnimHandle(void *p);
extern char *func_021F9EDC(char *p, u32 a);
extern void func_021F9F74(int, int, Vec_021F6F64 *);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern void func_021F9FD0(char *,int,int);
extern void func_021F9FB4(char *,int);
extern void func_021F9F58(u8 *unused, u8 *p);
extern void func_021F4EC4(u32 unused, u32 p, s16_021F7ECC *a, s16_021F7ECC *b);
extern void func_021F539C(void **p);
extern void func_021F53B4(int);
extern void func_021F53CC(int, unsigned int);
extern void func_021F5374(int *p, int b);
extern int func_021F5388(u8 **p);
extern void func_021F5414(int a, int b);
void func_021F6BC0(char *p,u32 *q,u32 flag);
Object *func_021F6BD8(u16 heap,void *a);
void func_021F6C7C(char *p);
void func_021F6CB0(char *p);
void func_021F6CE0(char *p, char *q);
void func_021F6D68(char *p);
void func_021F6E74(void);
u8 *func_021F6E78(u8 *p, int v);
void func_021F6EE4(void *unused,u8 *p);
void func_021F6EF4(void *unused,u32 *p,const u32 *q);
void func_021F6F04(void *ctx,char *p,Vec_021F6F04 *out);
void func_021F6F14(void *a,char *p,u16 b,u8 c);
void func_021F6F1C(void *a,char *p,u32 b,u32 c);
u8 *func_021F6F24(u32 heap,u32 v);
void func_021F6F4C(u8 *p);
void func_021F6F64(u8 *p);
void func_021F6F8C(u8 *p);
void func_021F6FB0(Cleanup *p, char *q);
void func_021F7048(Cleanup *p);
void func_021F7098(u8 *p, u16 v);
u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
void func_021F7120(char *p);
void func_021F7160(u8 *p);
void func_021F718C(char *p);
void func_021F7204(u8 *p,u8 *q);
void func_021F732C(u8 *self, u8 *q);
void func_021F75A0(u8 *p);
void func_021F75D8(u8 *a0, u8 *a1);
void func_021F75DC(u8 *p, u16 v);
void func_021F760C(u8 *p,u8 *input);
void func_021F77A0(char *p, char *q);
void func_021F77EC(u32 unused, u8 *p, u32 v);
void func_021F79A8(char *p,char *q,int index);
int func_021F7A80(char *p,char *q);
void func_021F7A94(char *p,char *q);
void func_021F7A98(char *p, char *q);
void func_021F7AEC(char *p, char *q);
void func_021F7BA8(u8 *p,u8 *q);
void func_021F7C90(char *p, char *q);
void func_021F7D30(u8 *p,u8 *q);
void func_021F7E2C(char *p, char *q);
void func_021F7ECC(char *p,char *q);
void func_021F7FA8(char *a0, char *a1);
void func_021F7FAC(char *p, char *q);
void func_021F8044(void *unused,u32 *p,u32 *q);
void func_021F8054(void *unused,u32 *p,const u32 *q);
void func_021F8068(int self, char *p, u16 v);
void func_021F8084(void *unused,u32 *p,const u32 *q);
void func_021F80A0(int a,u8 *p);
void func_021F80B0(int a, Obj *b);
void func_021F80C8(int a, Obj *b, unsigned int c);
void func_021F80D4(char *p, char *q, int v);
int func_021F8120(int a,u8 *p);
int func_021F812C(int unused, int *p, int flag);
void func_021F8140(int a,u8 *p,int b);
extern const char d_021F8408[];
extern const char d_021F8454[];
extern u32 d_021F8430[];
extern struct Arg d_021F8418;
extern char d_021F8464[];
extern s16_021F6BC0 table[];
extern void *d_021F832C[];




/*
 * note: True entry includes push {r0-r3}; handed 021F6BC2 is an interior prologue label.
 */
void func_021F6BC0(char *p,u32 *q,u32 flag) {BILLBOARD_SetElemVisible(((struct Obj22554 *)p)->f4,q[6],&flag);}




Object *func_021F6BD8(u16 heap,void *a)
{
    u8 i;
    Object *p;
    void *q;
    i=0;
    p=func_02030734(heap,184,0,d_021F8408,87);
    p->heap=heap; p->a=a;
    for(;i<4;i++) p->entries[i][0]=0;
    p->other[0]=0;
    p->bank=CLACT_CreateUnit(5,0,p->heap);
    CLACT_SetUnitDefaultRenderer(p->bank);
    q=func_020490F4((unsigned int)47,p->heap);
    p->x=CLACT_RegisterPalette((void *)q,4,0,0,p->heap);
    p->y=CLACT_RegisterCharacter((void *)((u32)q),10,0,0,p->heap);
    p->z=CLACT_RegisterCellAnim((void *)((u32)q),20,23,p->heap);
    ARC_TOOL_DeleteHandle(q);
    return p;
}




/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void func_021F6C7C(char *p) {CLACT_ReleasePalette(((struct Obj08024 *)p)->fAC);CLACT_ReleaseCharacter(((struct Obj08024 *)p)->fB0);CLACT_ReleaseCellAnim(((struct Obj08024 *)p)->fB4);CLACT_DeleteUnit(((struct Obj08024 *)p)->fA8);func_020307B0(p);}




void func_021F6CB0(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) func_021F6CE0(p,p+8+i*32); if(*(int *)&((struct Obj00771 *)p)->f4) func_021F6D68(p); }




void func_021F6CE0(char *p, char *q) {
    u16 n;
    int tmp;
    Point_021F6CE0 point;
    if (*(int *)&((struct Obj00771 *)p)->f4 == 0) tmp = 0x80;
    else tmp = STA_ACTING_GetCameraTarget((u8 *)(*(int *)&((struct Obj00771 *)p)->f4));
    n = tmp;
    if (((struct Obj05317 *)q)->f0 == 1) {
        point.x = (short)((float)((struct Obj05317 *)q)->f8 / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)((struct Obj05317 *)q)->fC / 4096.0f);
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05317 *)q)->f1C), (const struct Vec2 *)(&point), 0);
        if (*(int *)&((struct Obj00771 *)p)->f4 != 0 && STA_ACTING_GetSelection((char *)(*(int *)&((struct Obj00771 *)p)->f4)) != 4) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj05317 *)q)->f1C, 0);
            return;
        }
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj05317 *)q)->f1C, 1);
    }
}




/*
 * ABI: B294 leaves live r0 which the original stores and passes to B3DC despite its legacy void declaration.
 */
void func_021F6D68(char *p)
{
    Vec_021F6D68 v;
    Desc d;
    void *a;
    char *ctx;
    char *model;
    u16 n;
    if(((struct Obj00771 *)p)->f88==0 && STA_ACTING_GetSelection(*(char * *)&((struct Obj00771 *)p)->f4)!=4) {
        ((struct Obj00771 *)p)->f88=1;
        d.x=128;
        d.y=96;
        d.z=0;
        d.a=0;
        d.b=2;
        a=CLACT_CreateActor((void *)((struct Obj00771 *)p)->fA8,((struct Obj00771 *)p)->fB0,((struct Obj00771 *)p)->fAC,((struct Obj00771 *)p)->fB4,&d.x,0,((struct Obj00771 *)p)->f0);
        ((struct Obj00771 *)p)->fA4=a;
        CLACT_SetActorDrawEnable(a,1);
    }
    if(((struct Obj00771 *)p)->f88==1) {
        if(STA_ACTING_GetSelection(*(char * *)&((struct Obj00771 *)p)->f4)==4) {
            CLACT_DeleteActor(((struct Obj00771 *)p)->fA4);
            ((struct Obj00771 *)p)->f88=0;
            return;
        }
        ctx=STA_ACTING_GetActorSystem(((struct Obj00771 *)p)->f4);
        model=STA_ACTING_GetActor(((struct Obj00771 *)p)->f4,STA_ACTING_GetSelection(*(char * *)&((struct Obj00771 *)p)->f4));
        n=STA_ACTING_GetCameraTarget(((struct Obj00771 *)p)->f4);
        func_021F8044(ctx,(u32 *)model,(u32 *)(&v));
        d.pos.x=(short)((float)v.x/4096.0f-(float)(unsigned)n);
        d.pos.y=(short)((float)v.y/4096.0f-32.0f);
        CLACT_AddActorSurfacePos(((struct Obj00771 *)p)->fA4,(const struct Vec2 *)(&d.pos),0);
    }
}





void func_021F6E74(void) { }




u8 *func_021F6E78(u8 *p, int v)
{
    u8 i = 0;
    u8 *q;
    Pos pos;
    struct Obj *o;
    do {
        if (*(u32 *)(p + i * 32 + 8) == 0) break;
        i++;
    } while (i < 4);
    *(u32 *)(p + 8 + i * 32) = v;
    q = p + 8 + i * 32;
    pos.x = 0x80;
    pos.y = 0x60;
    pos.z = 0;
    pos.a = 0;
    pos.b = 2;
    o = CLACT_CreateActor(*(void **)(p + 0xa8), *(u32 *)(p + 0xb0), *(u32 *)(p + 0xac), *(u32 *)(p + 0xb4), &pos, 0, *(u16 *)p);
    *(struct Obj **)(q + 0x1c) = o;
    CLACT_SetActorDrawEnable(o, 1);
    return q;
}




void func_021F6EE4(void *unused,u8 *p) { CLACT_DeleteActor(*(struct Obj * *)&((struct Obj13836 *)p)->f1C); ((struct Obj13836 *)p)->f0=0; }




/*
 * extent: two zero padding bytes then existing ov112_func_021F6F04, 021F6F14, 021F6F1C sources and shards.
 */
void func_021F6EF4(void *unused,u32 *p,const u32 *q) { p[2]=q[0]; p[3]=q[1]; p[4]=q[2]; }




/*
 * extent: trailing zero halfword at 021F6F12 is alignment padding.
 */
void func_021F6F04(void *ctx,char *p,Vec_021F6F04 *out)
{
    out->x=*(int *)&((struct Obj05318 *)p)->f8;
    out->y=*(int *)&((struct Obj05318 *)p)->fC;
    out->z=*(int *)&((struct Obj05318 *)p)->f10;
}




void func_021F6F14(void *a,char *p,u16 b,u8 c)
{
    ((struct Obj08025 *)p)->f4=b;
    ((struct Obj08025 *)p)->f6=c;
}




void func_021F6F1C(void *a,char *p,u32 b,u32 c)
{
    ((struct Obj08025 *)p)->f14=b;
    ((struct Obj08025 *)p)->f18=c;
}




u8 *func_021F6F24(u32 heap,u32 v) { u8 *p; p=func_02030734(heap,64,0,d_021F8454,81); ((struct Obj08026 *)p)->f0=heap; ((struct Obj08026 *)p)->f4=v; ((struct Obj08026 *)p)->f8=0; ((struct Obj08026 *)p)->f1C=0; return p; }




/*
 * extent: two zero alignment bytes follow code.
 */
void func_021F6F4C(u8 *p) { if(*(u32 *)&((struct Obj00670 *)p)->f1C) func_021F7048((Cleanup *)p); func_020307B0(p); }








void func_021F6F64(u8 *p) { u8 i; if(((struct Obj13837 *)p)->f1C) { for(i=0;i<3;i++) G3D_SYSTEM_LoopObjectAnimeFrame(((struct Obj13837 *)p)->f3C,i,4096); } }








void func_021F6F8C(u8 *p) { if(((struct Obj13838 *)p)->f1C) { MTX_Identity33_(d_021F8430); G3D_SYSTEM_DrawObject(((struct Obj13838 *)p)->f3C,&d_021F8418); } }








/*
 * extent: two-byte zero padding before 021F7048.
 */
void func_021F6FB0(Cleanup *p, char *q) {
    u8 i, j;
    if (p->single != 0) func_021F7048(p);
    p->single = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x1e));
    p->a[0] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x24));
    p->a[1] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x2e));
    p->a[2] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x29));
    if (G3D_SYSTEM_TransVramTexture((int *)p->single) != 0) {
        p->b = (int)G3D_SYSTEM_CreateRender((void *)p->single, 0, (void *)p->single);
        for (i = 0; i < 3; i++) p->c[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p->b, (const struct G3dOwner *)p->a[i], 0);
        p->d = (int)G3D_SYSTEM_CreateObject(p->b, (u32 *)p->c, 3);
        for (j = 0; j < 3; j++) G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->d, j);
    }
}








void func_021F7048(Cleanup *p) {
    u8 i;
    G3D_SYSTEM_DeleteObject((struct Rec *)p->d);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteAnime((struct Rec *)p->c[i]);
    G3D_SYSTEM_DeleteRender((struct Rec *)p->b);
    for (i = 0; i < 3; i++) G3D_SYSTEM_DeleteResource((struct Tagged *)p->a[i]);
    G3D_SYSTEM_FreeVramTexture((u32 *)p->single);
    G3D_SYSTEM_DeleteResource((struct Tagged *)p->single);
    p->single = 0;
}









void func_021F7098(u8 *p, u16 v) { ((struct Obj22556 *)p)->f8 = v; }








u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e)
{
    u8 i = 0;
    u8 *p;
    p = func_02030734(heap, 0x440, 0, d_021F8464, 0x93);
    *(u16 *)p = heap;
    *(u32 *)(p + 4) = b;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = d;
    *(u16 *)(p + 0x434) = i;
    *(u32 *)(p + 8) = e;
    *(u8 *)(p + 0x43c) = i;
    for (i = 0; i < 4; i++) {
        u8 *q = p + i * 0x108;
        *(u32 *)(q + 0x14) = 0;
        *(u32 *)(q + 0x18) = 0;
    }
    *(u32 *)(p + 0x438) = BILLBOARD_AddImageFromArchive((struct Desc *)(*(u32 *)(p + 8)), 0x2f, 0x1d, 3, 0x33, 0x40, 0x40);
    return p;
}








void func_021F7120(char *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1)
            func_021F77A0((char *)((int)p), (char *)((int)(p + 0x14 + i * 0x108)));
    }
    BILLBOARD_DeleteImage((u8 *)(((struct Obj13839 *)p)->f8), ((struct Obj13839 *)p)->f438);
    func_020307B0((void *)((int)p));
}








void func_021F7160(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) func_021F7204(p,p+20+i*264); }








/*
 * extent: two-byte zero padding before 021F7204.
 */
void func_021F718C(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1) {
            func_021F732C((unsigned char *)p, (unsigned char *)(p + 0x14 + i * 0x108));
            if (((struct Obj10318 *)p)->f4 != 0) {
                for (j = 0; j < func_021F9E44((u8 *)(((struct Obj10318 *)p)->f4)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    func_021F4990(((struct Obj10318 *)p)->f10);
}








/*
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 */
void func_021F7204(u8 *p,u8 *q)
{
    Vec_021F6F64 pos;
    Vec_021F6F64 scale;
    Vec_021F6F64 delta;
    Mtx matrix;
    Vec_021F6F64 *a;
    Vec_021F6F64 *b;
    int angle;
    a=(Vec_021F6F64 *)func_021F545C(*(u8 * *)&((struct Obj00904 *)q)->f58);
    b=(Vec_021F6F64 *)func_021F5464(*(char * *)&((struct Obj00904 *)q)->f58);
    VEC_Add((const Vec_021F6F64 *)((Vec_021F6F64 *)(q+24)), (const Vec_021F6F64 *)((Vec_021F6F64 *)(q+48)), (Vec_021F6F64 *)&pos);
    angle=((struct Obj00904 *)q)->f48;
    delta.x=0;
    delta.y=b->y;
    func_0207AF38(&matrix,-table[(angle>>4)*2],table[(angle>>4)*2+1]);
    MTX_MultVec33((const Vec_021F6F64 *)&delta, &matrix, (Vec_021F6F64 *)(q+60));
    VEC_Subtract((const Vec_021F6F64 *)&delta, (const Vec_021F6F64 *)((Vec_021F6F64 *)(q+60)), (Vec_021F6F64 *)(q+60));
    pos.x=(pos.x-a->x-((struct Obj00904 *)q)->f3C)/16;
    pos.y=(0xc0000-(pos.y-a->y+((struct Obj00904 *)q)->f40))/16;
    func_021F5350(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&pos));
    func_021F5368(*(int * *)&((struct Obj00904 *)q)->f58,((struct Obj00904 *)q)->f48);
    scale.x=((struct Obj00904 *)q)->f24<<4;
    scale.y=((struct Obj00904 *)q)->f28<<4;
    scale.z=((struct Obj00904 *)q)->f2C<<4;
    if(((struct Obj00904 *)q)->f54==1) scale.x*=-1;
    func_021F535C(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&scale));
    ((struct Obj00904 *)q)->f4=0;
    if(((struct Obj00904 *)q)->f4C==1) {
        ((struct Obj00904 *)q)->f50+=(u16)func_020056EC(2);
        if(((struct Obj00904 *)q)->f50>120) func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,1);
        else func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,0);
        if(((struct Obj00904 *)q)->f50>125) ((struct Obj00904 *)q)->f50=func_020056EC(120)/3U;
    }
}








/*
 * note 2026-10-05 (wD7 lane15): closed. The else arm of func_021F4B24 writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
 */
void func_021F732C(u8 *self, u8 *q)
{
    Vec_021F732C v3;
    Mtx mtx;
    Vec_021F732C v2;
    Vec_021F732C v1;
    int i;
    int off;
    int k;
    int ang2;
    int z;
    int ang0;
    int neg;
    u8 *t;
    u16 h;

    for (i = 0; i < 9; i++) {
        k = i;
        if (*(int *)(q + 0x54) == 1) {
            if (i == 7) {
                k = 8;
            } else if (i == 8) {
                k = 7;
            } else if (i == 0) {
                k = 1;
            } else if (i == 1) {
                k = 0;
            }
        }
        off = i * 4;
        if (E != 0 && *(int *)(q + off + 0xCC) == 1) {
            if (*(int *)(q + 0xC) == 1 && *(int *)(q + 8) == 1) {
                t = func_021F5450(*(u8 **)(q + 0x58), k);
                if (*(int *)t == 1) {
                    neg = (*(int *)(t + 0x1C) < 0) ? 1 : 0;
                    ang0 = (u16)(0x10000 - *(u16 *)(t + 0x34));
                    ang2 = (u16)((0x10000 + *(u16 *)(t + 0x36) + *(s16_021F6BC0 *)(EA + 2)) % 0x10000);
                    func_021F545C(*(u8 **)(q + 0x58));
                    z = *(int *)(t + 0x1C);
                    func_0207AF38(&mtx, -table[(ang0 >> 4) * 2], table[(ang0 >> 4) * 2 + 1]);
                    MTX_MultVec33((const Vec_021F6F64 *)((Vec_021F732C *)(t + 0x10)), &mtx, (Vec_021F6F64 *)&v1);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (func_021F4B30(E) == 0 && neg == 1) {
                        z = -z;
                    }
                    MTX_MultVec33((const Vec_021F6F64 *)((Vec_021F732C *)(t + 0x28)), &mtx, (Vec_021F6F64 *)&v2);
                    VEC_Subtract((const Vec_021F6F64 *)((Vec_021F732C *)(t + 0x28)), (const Vec_021F6F64 *)&v2, (Vec_021F6F64 *)&v2);
                    h = *(u16 *)(self + 0x434);
                    v3.x = *(int *)(t + 4) + v1.x + 0x80000 + FXR(h);
                    v3.y = *(int *)(t + 8) + v1.y + 0x60000;
                    if (func_021F4B24(E) == 1) {
                        v3.z = *(int *)(q + 0x20) - 0x14000;
                    } else {
                        if (k - 7 <= 1u) {
                            v3.z = *(int *)(q + 0x20) + 0xA000 - (*(u8 *)(EA + 4) << 11);
                        } else {
                            v3.z = *(int *)(q + 0x20) + 0x5000 - (*(u8 *)(EA + 4) << 11);
                        }
                    }
                    func_021F4E8C(*(u32 *)(self + 0x10), E, (const Vec_021F732C *)&v3);
                    func_021F4ED4(*(u32 *)(self + 0x10), (u32)E, (u16)(ang2 - ang0));
                    func_021F4EB4(*(u32 *)(self + 0x10), (u32)E, (s16_021F6BC0)(z / 16 / 4), (s16_021F6BC0)(*(int *)(t + 0x20) / 16 / 4));
                    func_021F4E6C(*(u8 **)(self + 0x10), E, 1);
                }
            } else {
                func_021F4E6C(*(u8 **)(self + 0x10), E, 0);
            }
        }
    }
    func_021F545C(*(u8 **)(q + 0x58));
    v3.x = *(int *)(q + 0x18) / 16;
    v3.y = (0xC0000 - *(int *)(q + 0x1C)) / 16;
    v3.z = 0x32;
    BILLBOARD_SetElemPos(*(void **)(self + 8), *(u32 *)(q + 0x5C), (struct Trip *)(&v3));
}







void func_021F75A0(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(func_021F8120((int)p,p+20+i*264)==1) func_021F75D8(p,p+20+i*264); } }








void func_021F75D8(u8 *a0, u8 *a1) { }







void func_021F75DC(u8 *p, u16 v)
{
    u8 i;
    *(u16 *)(p + 0x434) = v;
    for (i = 0; i < 9; i++) {
        u8 *e = p + i * 0x108;
        if (*(u32 *)(e + 0x14) == 1) *(u32 *)(e + 0x18) = 1;
    }
}







/*
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 */
void func_021F760C(u8 *p,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    u8 *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    for(i=0;i<9;i++) {
        if(*(int *)(p+20+264*i)==0) break;
    }
    q=p+20+264*i;
    ((struct Obj00723 *)q)->f0=1;
    ((struct Obj00723 *)q)->f4=1;
    ((struct Obj00723 *)q)->f8=1;
    ((struct Obj00723 *)q)->fC=0;
    ((struct Obj00723 *)q)->f10=0;
    ((struct Obj00723 *)q)->f14=0;
    ((struct Obj00723 *)q)->f104=0;
    *(u8 * *)&((struct Obj00723 *)q)->f58=func_021F5204(((struct Obj03762 *)p)->fC,input,1);
    personal=POKE_PERSONAL_Create((u32)((struct Obj10319 *)input)->f8,(u32)input[11],(u32)((struct Obj03762 *)p)->f0);
    if(POKE_PERSONAL_GetParam(personal,16)==1) ((struct Obj00723 *)q)->f10=1;
    if(POKE_PERSONAL_GetParam(personal,34)==1) ((struct Obj00723 *)q)->f14=1;
    POKE_PERSONAL_Delete(personal);
    ((struct Obj00723 *)q)->f18=0;
    ((struct Obj00723 *)q)->f1C=0;
    ((struct Obj00723 *)q)->f20=0;
    ((struct Obj00723 *)q)->f30=0;
    ((struct Obj00723 *)q)->f34=0;
    ((struct Obj00723 *)q)->f38=0;
    ((struct Obj00723 *)q)->f24=4096;
    ((struct Obj00723 *)q)->f28=4096;
    ((struct Obj00723 *)q)->f2C=4096;
    func_021F77EC((u32)p,q,((struct Obj10319 *)input)->f8);
    ((struct Obj00723 *)q)->f48=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        *(u8 * *)&((struct Obj02824 *)row)->fA8=record;
        if(id!=255) {
            ((struct Obj02824 *)row)->fCC=1;
            ((struct Obj02824 *)row)->f60=(int)func_021F4B3C(id);
            ((struct Obj02824 *)row)->f84=func_021F4B88(((struct Obj03762 *)p)->f10,id,*(u32 *)&((struct Obj02824 *)row)->f60,(int *)(q+24));
            func_021F4EB4(*(int *)&((struct Obj03762 *)p)->f10,*(int *)&((struct Obj02824 *)row)->f84,scale,scale);
            func_021F4E6C((u8 *)(*(int *)&((struct Obj03762 *)p)->f10),(u8 *)(*(int *)&((struct Obj02824 *)row)->f84),0);
        } else {
            ((struct Obj02824 *)row)->fCC=0;
            ((struct Obj02824 *)row)->f60=0;
            *(int *)&((struct Obj02824 *)row)->f84=0;
        }
    }
    *(int *)&((struct Obj00723 *)q)->f5C=BILLBOARD_AddElem(((struct Obj03762 *)p)->f8,((struct Obj03762 *)p)->f438,1024,768,(struct Vec3 *)(q+24),30,0,0);
    flag=1;
    BILLBOARD_SetElemVisible(((struct Obj03762 *)p)->f8,((struct Obj00723 *)q)->f5C,&flag);
    ((struct Obj00723 *)q)->f50=func_020056EC(150)>>1;
    ((struct Obj00723 *)q)->f4C=1;
}







/*
 * extent: trailing two-byte zero padding before 021F77EC.
 */
void func_021F77A0(char *p, char *q) {
    u8 i;
    BILLBOARD_FreeElem((void *)(((struct Obj10320 *)p)->f8), ((struct Obj10321 *)q)->f5C);
    for (i = 0; i < 9; i++) {
        if (((Slot_021F6BC0 *)(q + i * 4))->other != 0) {
            func_021F4D40((u8 *)(((struct Obj10320 *)p)->f10), (u8 *)(((Slot_021F6BC0 *)(q + i * 4))->other));
            func_021F4B4C((struct Tagged *)(((Slot_021F6BC0 *)(q + i * 4))->value));
            ((Slot_021F6BC0 *)(q + i * 4))->value = 0;
            ((Slot_021F6BC0 *)(q + i * 4))->other = 0;
        }
    }
    func_021F5330(((struct Obj10320 *)p)->fC, ((struct Obj10321 *)q)->f58);
    ((struct Obj10321 *)q)->f0 = 0;
}







/*
 * Addresses are Black-image addresses.
 */
void func_021F77EC(u32 unused, u8 *p, u32 v)
{
    if (v == 0xe8) { ((struct Obj02169 *)p)->f24 = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { ((struct Obj02169 *)p)->f24 = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { ((struct Obj02169 *)p)->f24 = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { ((struct Obj02169 *)p)->f24 = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        ((struct Obj02169 *)p)->f28 = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        ((struct Obj02169 *)p)->f28 = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { ((struct Obj02169 *)p)->f28 = 0xff3; return; }

    if (v == 0x1c1) {
        ((struct Obj02169 *)p)->f24 = 0x1040;
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        ((struct Obj02169 *)p)->f24 = 0xfc0;
        ((struct Obj02169 *)p)->f28 = 0xfcc;
        return;
    }
}






/*
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 */
void func_021F79A8(char *p,char *q,int index)
{
    u32 v;
    if(*(int *)(q+132+index*4)==0 || *(int *)&((struct Obj03248 *)q)->f104!=0) return;
    v=func_021F514C((void *)func_021F4F10((u8 *)((struct Obj13841 *)p)->f10),**(u16 **)(q+168+index*4));
    ((struct Obj03248 *)q)->fF0=0;
    ((struct Obj03248 *)q)->fF4=index;
    ((struct Obj03248 *)q)->fF8=0;
    GFL_USE_PlaySeInSlot(d_021F832C[v],2);
    ((struct Obj13841 *)p)->f43C+=1;
    switch(v) {
    case 0: func_021F7A94(p,q); *(void (**)(char *,char *))(q+260)=func_021F7A98; break;
    case 1: func_021F7AEC(p,q); *(void (**)(u8 *,u8 *))(q+260)=func_021F7BA8; break;
    case 2: func_021F7C90(p,q); *(void (**)(char *,char *))(q+260)=(void (*)(char *, char *))func_021F7D30; break;
    case 3: func_021F7E2C(p,q); *(void (**)(char *,char *))(q+260)=func_021F7ECC; break;
    case 4: func_021F7FA8(p,q); *(void (**)(char *,char *))(q+260)=func_021F7FAC; break;
    }
}






int func_021F7A80(char *p,char *q)
{
    if(((struct Obj22558 *)q)->f104!=0) return 1;
    return 0;
}






void func_021F7A94(char *p,char *q)
{
}






void func_021F7A98(char *p, char *q) {
    Tail_021F6F64 *tail = (Tail_021F6F64 *)(q + 0xf0);
    s16_021F6BC0 *v = *(s16_021F6BC0 **)(q + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        ((struct Obj22559 *)q)->f104 = 0;
        ((struct Obj13842 *)p)->f43C -= 1;
        if (((struct Obj13842 *)p)->f43C == 0) GFL_USE_StopSeSlot(2);
    }
}




/*
 * extent: two-byte zero padding before 021F7BA8.
 */
void func_021F7AEC(char *p, char *q) {
    Tail_021F7AEC *t = (Tail_021F7AEC *)(q + 0xf0);
    int a = (int)STA_ACTING_GetAnimHandle((void *)(((struct Obj13843 *)p)->f4));
    char *r = (char *)func_021F5450((u8 *)(*(char * *)&((struct Obj08027 *)q)->f58), ((struct Obj08027 *)q)->fF4);
    Vec_021F6F64 v;
    t->a = (int)func_021F9EDC((char *)a, 0x35);
    if (((struct Obj08027 *)q)->f8 == 1 && ((struct Obj22561 *)r)->f0 == 1) {
        func_021F4EA4(((struct Obj13843 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), (u32)(&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        VEC_Add((const Vec_021F6F64 *)((Vec_021F6F64 *)(q + 0x18)), (const Vec_021F6F64 *)((Vec_021F6F64 *)func_021F5464(*(char * *)&((struct Obj08027 *)q)->f58)), (Vec_021F6F64 *)&v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    func_021F9F74(t->a, 0, (Vec_021F6F64 *)&v);
}



void func_021F7BA8(u8 *p,u8 *q)
{
    Tail_021F6BC0 *t=(Tail_021F6BC0 *)(q+240);
    u8 *r=func_021F5450(*(u8 * *)&((struct Obj06409 *)q)->f58, ((struct Obj06409 *)q)->fF4);
    Vec_021F7BA8 v;
    int a;
    if(((struct Obj06409 *)q)->f8==1 && ((struct Obj22562 *)r)->f0==1) {
        func_021F4EA4(((struct Obj08028 *)p)->f10,*(int *)(q+132+t->index*4),(u32)(&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        VEC_Add((const Vec_021F6F64 *)((Vec_021F7BA8 *)(q+24)), (const Vec_021F6F64 *)((Vec_021F7BA8 *)func_021F5464(*(char * *)&((struct Obj06409 *)q)->f58)), (Vec_021F6F64 *)&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    func_021F9FD0((char *)t->a,0,(int)&v);
    t->count++;
    if(t->count>=180) {
        a=(int)STA_ACTING_GetAnimHandle((void *)(((struct Obj08028 *)p)->f4));
        func_021F9FB4((char *)t->a,0);
        func_021F9F58((void *)a,(void *)t->a);
        ((struct Obj06409 *)q)->f104=0;
        ((struct Obj08028 *)p)->f43C-=1;
        if(((struct Obj08028 *)p)->f43C==0) GFL_USE_StopSeSlot(2);
    }
}






void func_021F7C90(char *p, char *q) {
    Tail_021F7C90 *t = (Tail_021F7C90 *)(q + 0xf0);
    char *r = (char *)func_021F5450((u8 *)(*(char * *)&((struct Obj06410 *)q)->f58), ((struct Obj06410 *)q)->fF4);
    Vec_021F7C90 v;
    *(int *)(q + 0xcc + ((struct Obj06410 *)q)->fF4 * 4) = 0;
    if (((struct Obj06410 *)q)->f8 == 0 || ((struct Obj22563 *)r)->f0 == 0) {
        VEC_Add((Vec_021F6F64 *)((Vec_021F7C90 *)(q + 0x18)), (Vec_021F6F64 *)((Vec_021F7C90 *)func_021F5464(*(char * *)&((struct Obj06410 *)q)->f58)), (Vec_021F6F64 *)((Vec_021F7C90 *)&v));
        v.z -= 0x1c000;
        func_021F4E8C((u32)(((struct Obj08029 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), (Vec_021F732C *)((Vec_021F7C90 *)&v));
    }
    func_021F4E6C((u8 *)(((struct Obj08029 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), 1);
    func_021F4ED4(((struct Obj08029 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 0);
    func_021F4EB4(((struct Obj08029 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1024, 1024);
}






static inline long fxmul(long a,long b)
{
    return (long)(((s64)a*b+2048)>>12);
}






/*
 * lever: inline signed-long FX multiply takes the scaled time first;
 *   a direct cast expression changes register allocation and offset homing.
 */
void func_021F7D30(u8 *p,u8 *q)
{
    Tail_021F7D30 *t=(Tail_021F7D30 *)(q+0xf0);
    Vec_021F7D30 v;
    unsigned long offset;
    u16 time=t->count;
    int angle=(time<<9)%65536;
    long s=table[(angle>>4)*2];
    func_021F4EA4(*(u32 *)(p+0x10),*(u32 *)(q+0x84+t->index*4),(u32)&v);
    offset=205;
    v.x+=fxmul((time/3)*offset,s);
    v.y-=3072;
    func_021F4E8C((u32)(*(u32 *)(p+0x10)), (u8 *)((int)(*(void **)(q+0x84+t->index*4))), (Vec_021F732C *)((Vec_021F7C90 *)(&v.x)));
    func_021F4ED4(*(u32 *)(p+0x10),*(u32 *)(q+0x84+t->index*4),s>>1);
    t->count++;
    if(t->count>=180) {
        func_021F4E6C(*(u8 **)(p+0x10),*(u8 **)(q+0x84+t->index*4),0);
        offset+=55;
        *(int *)(q+offset)=0;
        *(u8 *)(p+0x43c)-=1;
        if(*(u8 *)(p+0x43c)==0) GFL_USE_StopSeSlot(2);
    }
}





void func_021F7E2C(char *p, char *q) {
    Tail_021F7C90 *t = (Tail_021F7C90 *)(q + 0xf0);
    char *r = (char *)func_021F5450((u8 *)(*(char * *)&((struct Obj06411 *)q)->f58), ((struct Obj06411 *)q)->fF4);
    Vec_021F7C90 v;
    *(int *)(q + 0xcc + ((struct Obj06411 *)q)->fF4 * 4) = 0;
    if (((struct Obj06411 *)q)->f8 == 0 || ((struct Obj22564 *)r)->f0 == 0) {
        VEC_Add((Vec_021F6F64 *)((Vec_021F7C90 *)((Vec_021F7C90 *)(q + 0x18))), (Vec_021F6F64 *)((Vec_021F7C90 *)((Vec_021F7C90 *)func_021F5464(*(char * *)&((struct Obj06411 *)q)->f58))), (Vec_021F6F64 *)((Vec_021F7C90 *)&v));
        func_021F4E8C((u32)(((struct Obj08031 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), (Vec_021F732C *)((Vec_021F7C90 *)&v));
    }
    t->b = -0x3000;
    func_021F4E6C((u8 *)(((struct Obj08031 *)p)->f10), (u8 *)(*(int *)(q + 0x84 + t->index * 4)), 1);
    func_021F4ED4(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 0);
    func_021F4EB4(((struct Obj08031 *)p)->f10, *(int *)(q + 0x84 + t->index * 4), 1024, 1024);
}





/*
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 */
void func_021F7ECC(char *p,char *q)
{
    Tail_021F7ECC *t=(Tail_021F7ECC *)(q+0xf0);
    Vec_021F7ECC v;
    Scale s;
    func_021F4EA4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),(unsigned int)(&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    func_021F4E8C((u32)(((struct Obj04463 *)p)->f10), (u8 *)(*(int *)(q+0x84+t->index*4)), (Vec_021F732C *)((Vec_021F7C90 *)&v));
    func_021F4EC4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    func_021F4EB4(((struct Obj04463 *)p)->f10,*(int *)(q+0x84+t->index*4),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        func_021F4E6C((u8 *)(((struct Obj04463 *)p)->f10),(u8 *)(*(int *)(q+0x84+t->index*4)),0);
        ((struct Obj22565 *)q)->f104=0;
        ((struct Obj04463 *)p)->f43C-=1;
        if(((struct Obj04463 *)p)->f43C==0) GFL_USE_StopSeSlot(2);
    }
}





void func_021F7FA8(char *a0, char *a1)
{
}





void func_021F7FAC(char *p, char *q) {
    Tail_021F7FAC *t = (Tail_021F7FAC *)(q + 0xf0);
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        ((struct Obj22566 *)q)->f104 = 0;
        ((struct Obj10324 *)p)->f43C -= 1;
        if (((struct Obj10324 *)p)->f43C == 0) GFL_USE_StopSeSlot(2);
        return;
    }
    func_021F4EB4(((struct Obj10324 *)p)->f10, *(int *)(q + 0x84 + t->index * 4),
                  table[(angle >> 4) * 2] / 8 + 1024,
                  table[(angle >> 4) * 2 + 1] / 8 + 1024);
}




void func_021F8044(void *unused,u32 *p,u32 *q) { q[0]=p[6]; q[1]=p[7]; q[2]=p[8]; }




void func_021F8054(void *unused,u32 *p,const u32 *q) { p[6]=q[0]; p[7]=q[1]; p[8]=q[2]; p[1]=1; }





/*
 * note: unlabelled leaf in ov112 (the listing emits it as a .word run), filed
 * to witness the bl from src/pending/ov132_func_021FBA14.c.  The first
 * argument is ignored; the original moves r1 into r0, so the pointer is the
 * second parameter.
 */
void func_021F8068(int self, char *p, u16 v)
{
    ((struct Obj08033 *)p)->f48 = v;
    if (((struct Obj08033 *)p)->f10 == 1)
        ((struct Obj08033 *)p)->f48 = 0;
    ((struct Obj08033 *)p)->f4 = 1;
}



void func_021F8084(void *unused,u32 *p,const u32 *q) { p[12]=q[0]; p[13]=q[1]; p[14]=q[2]; if(p[4]==1) p[13]=0; p[1]=1; }



void func_021F80A0(int a,u8 *p) { func_021F539C(((struct Obj13844 *)p)->f58); ((struct Obj13844 *)p)->f4C=1; }



/*
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 */
void func_021F80B0(int a, Obj *b)
{
    func_021F53B4(b->target);
    b->zero = 0;
    func_021F5424(b->target, 0);
}



void func_021F80C8(int a, Obj *b, unsigned int c)
{
    func_021F53CC(b->target, c);
}



/*
 * note: handed label 021F80D6 follows the parameter-home push.
 */
void func_021F80D4(char *p, char *q, int v) {
    int i;
    int value = v;
    func_021F5374((int *)(((struct Obj13846 *)q)->f58), value);
    for (i = 0; i < 9; i++) {
        if (((Slot_021F7C90 *)(q + i * 4))->a != 0 && ((Slot_021F7C90 *)(q + i * 4))->b == 1)
            func_021F4E6C((u8 *)(((struct Obj13845 *)p)->f10), (u8 *)(((Slot_021F7C90 *)(q + i * 4))->a), value);
    }
    BILLBOARD_SetElemVisible((void *)(((struct Obj13845 *)p)->f8), ((struct Obj13846 *)q)->f5C, (u32 *)(&v));
}



/*
 * extent: Existing matched follower ov112_func_021F812C.c follows.
 */
int func_021F8120(int a,u8 *p) { return func_021F5388(((struct Obj22568 *)p)->f58); }



/*
 * note: parent-coordinated blocker leaf for ov132 021FB258.
 */
int func_021F812C(int unused, int *p, int flag)
{
    if (p[5] == 1) p[21] = 0;
    else p[21] = flag;
    p[1] = 1;
    return 1;
}



void func_021F8140(int a,u8 *p,int b) { ((struct Obj10327 *)p)->f8=b; func_021F5414((int)(((struct Obj10327 *)p)->f58),b); ((struct Obj10327 *)p)->f4=1; }




/* Sets the light element's value word and marks the element updated. */
int STA_ACT_LIGHT_SetElemValue(int a0, int *a1, int a2)
{
    a1[3] = a2;
    a1[1] = 1;
    return 1;
}
