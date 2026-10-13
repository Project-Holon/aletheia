/*
 * file:     egg_demo_view.c
 * unit:     yes
 * function: func_021F63CC, func_021F6474, func_021F64D0, func_021F64E4, func_021F64F0, func_021F64FC, func_021F6508, func_021F651C, func_021F657C, func_021F65B4, func_021F65B8, func_021F65C0, func_021F6600, func_021F661C, func_021F6624, func_021F6630, func_021F669C, func_021F66AC, func_021F66C8, func_021F6718, func_021F6720, func_021F67B0, func_021F67E0, func_021F6A24, func_021F6A3C, func_021F6A48, func_021F6A84, func_021F6A98, func_021F6AB4, func_021F6AB8, func_021F6AE0, func_021F6AEC, func_021F6CAC, func_021F6CC0, func_021F6CCC, func_021F6D0C, func_021F6D1C, func_021F6D58, func_021F6D7C, func_021F6D90, func_021F6DB4, func_021F6E4C, func_021F6E5C, func_021F6EE4, func_021F6EEC, func_021F6EF8, func_021F6F18, func_021F6F24, func_021F6F64, func_021F7028, func_021F7048, func_021F70F8, func_021F7100, func_021F7110
 * address:  0x021F63CC
 * region:   ov215
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
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021F73E0 0x021F73E0 data a4
 *   d_021F71C4 0x021F71C4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021F7178 0x021F7178 data a4
 *   d_021F71F4 0x021F71F4 data a4
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
 *   func_021F6328 0x021F6328 thumb ov215
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021F7160 0x021F7160 data a4
 *   d_021F7154 0x021F7154 data a4
 *   d_021F716C 0x021F716C data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   d_021F73F4 0x021F73F4 data a1
 *   func_02017E1C 0x02017E1C thumb
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 *   sub_02030EAC 0x02030EAC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02006238 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021F70F8 0x021F70F8 thumb ov215
 *   func_021F7100 0x021F7100 thumb ov215
 *   func_021F7110 0x021F7110 thumb ov215
 *   PM_VOICE_Play 0x02006984 thumb
 *   func_02006650 0x02006650 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   table_021F7384 0x021F7384 data a4
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_GetSizeY 0x02015F0C thumb
 *   MCSS_GetOfsY 0x02015F1C thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   func_02064CBC 0x02064CBC arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   func_02063000 0x02063000 arm
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_SetAlpha 0x02015FBC thumb
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021F7300 0x021F7300 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   d_021F73B4 0x021F73B4 data a4
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   d_021F7330 0x021F7330 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame    0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame    0x020478B8  arm
 */
#include "../../matched/include/Obj25749.h"
#include "../../matched/include/Obj25750.h"
#include "../../matched/include/Obj14709.h"
#include "../../matched/include/Obj25751.h"
#include "../../matched/include/Obj25752.h"
#include "../../matched/include/Obj25755.h"
#include "../../matched/include/Obj00317.h"
#include "../../matched/include/Obj04636.h"
#include "../../matched/include/Obj01083.h"
#include "../../matched/include/Obj06708.h"
#include "../../matched/include/Obj25756.h"
#include "../../matched/include/Obj25757.h"
#include "../../matched/include/Obj25758.h"
#include "../../matched/include/Obj14710.h"
#include "../../matched/include/Obj25759.h"
#include "../../matched/include/Obj25760.h"
#include "../../matched/include/Obj02262.h"
#include "../../matched/include/Obj10941.h"
#include "../../matched/include/Obj25761.h"
#include "../../matched/include/Obj06707.h"
#include "../../matched/include/Obj14711.h"
#include "../../matched/include/Obj05551.h"
#include "../../matched/include/Obj14712.h"
#include "../../matched/include/Obj25762.h"
#include "../../matched/include/Obj14713.h"
#include "../../matched/include/Obj03373.h"
#include "../../matched/include/Obj02263.h"
#include "../../matched/include/Obj25763.h"
#include "../../matched/include/Obj14714.h"
#include "../../matched/include/Obj06709.h"

#define W(o) (*(u32 *)(p+(o)))
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
struct DispVram;
struct Node;
struct DispConfig;
struct Cfg;
struct Bank;
struct Light;
struct McssSys;
struct McssFade;
struct Obj;
struct Data;
struct Util;
struct Rec;
struct Arg;
struct Setup;
struct Record;
struct G3dSys;
struct AnmCtl;
struct Ctx;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

struct BgTemplate { unsigned words[8]; };

struct BgConfig { unsigned layer; struct BgTemplate template; unsigned type,enable; };

typedef signed short s16;

struct Vec3 { unsigned x,y,z; };

typedef struct { int tag,x,y,z,sx,sy,sz,matrix[9],tail; } Record;

typedef signed int     s32;

typedef struct {int x,y,z;} Vec_021F63CC;

typedef struct {u32 species;float x,y;} Entry;

struct Pair { unsigned archive,member; };

typedef struct { int x,y,z; } Vec_021F6D7C;

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void (*)(int,char *),char *,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
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
extern void func_021F6328(void);
extern void G3D_SYSTEM_Init(unsigned,unsigned,unsigned,unsigned,u16,unsigned,void (*)(void));
extern void *G3D_CAMERA_Create(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,const struct Vec3 *,const struct Vec3 *,const struct Vec3 *,u16);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void func_0207ADC4(void *);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void sub_02030EAC(struct Node *);
extern void func_020061E4(u32);
extern int func_02006238(void);
extern int GFL_USE_IsSeSlotBusy(u32);
extern int GFL_USE_GetSeSlot(u32);
extern void func_0200616C(void *,int);
extern void func_020061F8(int);
extern void func_021F70F8(char *);
extern int func_021F7100(char *);
extern void func_021F7110(char *);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern int func_02006650(void);
extern void MCSS_Main(char *);
extern void MCSS_Draw(struct McssSys *);
extern void MCSS_SetVanishFlag(void *);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern int MCSS_CheckPaletteFade(void *);
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetOrthoMode(void *);
extern void MCSS_Exit(u8 *);
extern void *MCSS_TOOL_AddPokeMcss(void *,void *,u32,u32,u32,u32);
extern void MCSS_SetShadowVanishFlag(char *,int);
extern void MCSS_SetPosition(void *,u32 *);
extern void MCSS_SetScale(void *,u32 *);
extern u16 MCSS_GetSizeY(void *);
extern s16 MCSS_GetOfsY(void *);
extern s16 MCSS_GetOfsX(void *);
extern void MCSS_SetOfsPosition(void *,u32 *);
extern void MCSS_SetAnmStopFlag(void *);
extern void MCSS_Del(void *,void *);
/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void MCSS_SetAnimeIndex(void *,unsigned);
extern void *MCSS_GetAnimCtrl(void *);
extern void func_02064CBC(struct Obj *x);
extern void MCSS_ResetAnmStopFlag(void *);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern int MCSS_TOOL_SetAnimeStopCallback(int a0);
extern u8 MCSS_GetAlpha(struct Data *);
extern void MCSS_SetAlpha(char *,int);
extern void MCSS_ResetVanishFlag(void *);
extern void PARTICLE_InitManager(unsigned);
extern int PARTICLE_CreateSystemDefault(int,int,int,int);
extern int PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);
extern u16 BUTTON_MAN_GetResourceType(void *);
extern void PARTICLE_SetupSystem(void *,unsigned,unsigned,unsigned);
extern void PARTICLE_ExitManager(void);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillAllEffects(void *);
extern void PARTICLE_Main(void);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
extern struct Util *G3D_UTIL_Create(u16,u16,u16);
extern void G3D_UTIL_Delete(struct Rec *);
extern unsigned func_02048A18(unsigned char *,int);
extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);
extern unsigned func_020489F4(unsigned char *,int);
extern unsigned G3D_SYSTEM_EnableObjectAnime(struct G3dSys *,unsigned);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *p, int a, int b);
char *func_021F63CC(unsigned mode,u16 heap);
void func_021F6474(char *p);
void func_021F64D0(char *a);
void func_021F64E4(char *p);
void func_021F64F0(char *p);
int func_021F64FC(char *p);
void func_021F6508(int a, char *b);
void func_021F651C(void *out,unsigned heap);
void func_021F657C(void *p);
void func_021F65B4(void *a0);
void func_021F65B8(void *a0);
void func_021F65C0(unsigned char *p, int a, u32 b);
void func_021F6600(char *p);
void func_021F661C(void *a0);
void func_021F6624(void *a0);
int func_021F662C(void *p);
void func_021F6630(void **out,u16 heap);
void func_021F669C(int *p);
void func_021F66AC(void *p);
void func_021F66C0(void *p);
Record *func_021F66C8(unsigned heap,unsigned count);
void func_021F6718(void *p);
char *func_021F6720(unsigned heap,void *mon);
void func_021F67B0(char *p);
void func_021F67E0(char *p);
void func_021F6A24(char *p);
void func_021F6A3C(char *p);
int func_021F6A44(char *p);
void func_021F6A48(char *p,int a);
int func_021F6A84(char *p);
void func_021F6A98(char *p);
int func_021F6AA4(char *p);
void func_021F6AB4(void);
void func_021F6AB8(char *p);
void func_021F6AE0(char *p);
void func_021F6AEC(char *p);
void func_021F6CAC(char *p);
void func_021F6CC0(char *p);
void func_021F6CCC(char *p,unsigned flag,int enable);
int func_021F6D0C(char *a);
void func_021F6D1C(char *p);
void func_021F6D58(char *p);
int func_021F6D7C(char *p);
void func_021F6D90(char *p);
char *func_021F6DB4(unsigned heap,unsigned count,const void *table);
void func_021F6E4C(char *a);
void func_021F6E5C(char *p);
void func_021F6EE4(char *p);
void func_021F6EEC(char *p);
void func_021F6EF8(char *p);
void func_021F6F18(char *p);
void func_021F6F24(char *p);
void func_021F6F64(char *p);
void func_021F7028(char *p);
void func_021F7048(char *p);
extern const char d_021F73E0[];
extern const unsigned d_021F71C4[];
extern const unsigned d_021F7178[];
extern const struct BgConfig d_021F71F4[];
extern const s16 d_020A1EB8[];
extern const struct Vec3 d_021F7160,d_021F7154,d_021F716C;
extern const char d_021F73F4[];
extern const unsigned d_021F7340[],d_021F7314[];
extern const Entry table_021F7384[];
extern const unsigned long long d_021F7300;
extern const Vec_021F6D7C d_021F73B4;
extern const struct Setup d_021F7330;







/*
 * volatile: hardware 021F63F2,63F4,63F8,6400,6402,6406.
 */
char *func_021F63CC(unsigned mode,u16 heap)
{
    char *p;
    p=func_02030734(heap,16,0,d_021F73E0,466);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &=0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021F71C4);
    func_0204363C(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021F651C(p,heap);
    func_021F65C0((unsigned char *)(p+4),(int)d_021F71C4,heap);
    func_021F6630((void **)(p+8),heap);
    ((struct Obj25749 *)p)->fC=func_020056A0(func_021F6508,p,0);
    return p;
}







void func_021F6474(char *p)
{
    func_02030EAC(((struct Obj25750 *)p)->fC);
    func_021F669C((int *)(p+8));
    func_021F6600(p+4);
    func_021F657C(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}








void func_021F64D0(char *a)
{
    func_021F661C(a + 4);
    func_021F65B4(a);
}







void func_021F64E4(char *p){func_021F66AC(p+8);}







void func_021F64F0(char *p){func_021F66C0(p+8);}







int func_021F64FC(char *p){return func_021F662C(p+4);}








void func_021F6508(int a, char *b)
{
    func_021F65B8(b);
    func_021F6624(b + 4);
}







void func_021F651C(void *out,unsigned heap)
{
    unsigned i;
    func_02082BCC(out,0,4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021F7178);
    for(i=0;i<6;i++) {
        func_0203FCA0((u8)d_021F71F4[i].layer,&d_021F71F4[i].template,(u8)d_021F71F4[i].type);
        func_020414AC(d_021F71F4[i].layer);
        func_02040588(d_021F71F4[i].layer,d_021F71F4[i].enable);
    }
}







/*
 * evidence: the caller truncates the 020403F4 argument with lsl/lsr #24,
 * so its extern is u8 although the callee's own source uses a word.
 * lever: a named unsigned byte-address base keeps the table in r4 and
 * index in r5; the inline address swaps them, and word indexing adds lsl #2.
 */
void func_021F657C(void *p){unsigned base=(unsigned)d_021F71F4;unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();func_0203F9B4();func_02082BCC(p,0,4);}







/*
 * extent: two-byte alignment padding follows the body.
 */
void func_021F65B4(void *a0){}







void func_021F65B8(void *a0){func_020419E4();}








void func_021F65C0(unsigned char *p, int a, u32 b)
{
    func_02082BCC(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021F7188, a, b);
    ((struct Obj14709 *)p)->f0 = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14709 *)p)->f0);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}







void func_021F6600(char *p){CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25751 *)p)->f0);CLACT_ExitSystem();func_02082BCC(p,0,4);}







void func_021F661C(void *a0){CLACT_DrawSystem();}







/*
 * extent: includes cleared tiny follower func_021F662C; no further code included.
 */
void func_021F6624(void *a0){CLACT_VBlankSystem();}







int func_021F662C(void *p){return ((struct Obj25752 *)p)->f0;}







/*
 * evidence: 46440 heap extern widened; original stores full r1 at sp+4.
 */
void func_021F6630(void **out,u16 heap)
{
    G3D_SYSTEM_Init(0,2,0,1,0,heap,func_021F6328);
    *out=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,4194304,0,&d_021F7160,&d_021F7154,&d_021F716C,heap);
}








void func_021F669C(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}







/*
 * extent: includes cleared tiny follower func_021F66C0; no further code included.
 */
void func_021F66AC(void *p){func_02047964();func_02048AD0(*(struct Light * *)&((struct Obj25755 *)p)->f0);G3D_SYSTEM_ApplyLookAt();}







void func_021F66C0(void *p){G3D_SYSTEM_DrawEnd();}







Record *func_021F66C8(unsigned heap,unsigned count)
{
    Record *p;
    u16 i;
    p=func_02030734(heap,68*count,1,d_021F73F4,283);
    for(i=0;i<count;i++) {
        p[i].x=0;p[i].y=0;p[i].z=0;
        p[i].sx=4096;p[i].sy=4096;p[i].sz=4096;
        func_0207ADC4(p[i].matrix);
    }
    return p;
}







void func_021F6718(void *p){func_020307B0(p);}







/*
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 */
char *func_021F6720(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    ((struct Obj00317 *)p)->f0=heap;
    ((struct Obj00317 *)p)->f4=mon;
    ((struct Obj00317 *)p)->f8=func_02017E1C(mon,5,0);
    ((struct Obj00317 *)p)->fC=0;
    ((struct Obj00317 *)p)->f10=0;
    ((struct Obj00317 *)p)->f14=0;
    ((struct Obj00317 *)p)->f18=0;
    ((struct Obj00317 *)p)->f1C=0;
    ((struct Obj00317 *)p)->f24=0;
    ((struct Obj00317 *)p)->f28=0;
    ((struct Obj00317 *)p)->f2C=func_020056A0((void ( *)(int,char *))func_021F6AB4, (char *)p, 1);
    func_021F6AB8(p);
    func_021F6AEC(p);
    if(((struct Obj00317 *)p)->f8==490)
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,5,d_021F7340);
    else
        ((struct Obj00317 *)p)->f44=func_021F6DB4(((struct Obj00317 *)p)->f0,3,d_021F7314);
    func_021F6EF8(p);
    func_021F6F64(p);
    return p;
}







/*
 * trailing: zero halfword at 021F67DE is alignment padding.
 */
void func_021F67B0(char *p){func_021F7028(p);func_021F6F18(p);func_021F6E4C(*(char * *)&((struct Obj04636 *)p)->f44);func_021F6CAC(p);func_021F6AE0(p);sub_02030EAC(*(struct Node * *)&((struct Obj04636 *)p)->f2C);func_020307B0(p);}







void func_021F67E0(char *p)
{
    u32 limit,a,b;
    switch(W(12)) {
    case 0:
        if(W(16)) {
            W(12)=1;W(24)=0;
            func_021F6CCC(p,1,1);
            func_021F6EEC(*(char * *)&((struct Obj01083 *)p)->f44);
        }
        break;
    case 1:
        if(((struct Obj01083 *)p)->f8==490)limit=300;else limit=380;
        W(24)++;
        if(((struct Obj01083 *)p)->f8==490) {
            switch(W(40)) {
            case 0: if(W(24)==10){func_020061E4(1955);W(40)=1;}break;
            case 1: if(!func_02006238()){func_020061E4(1960);W(40)=2;}break;
            case 2: if(!func_02006238())W(40)=3;break;
            case 3:break;
            }
        }else{
            if(W(24)==20)func_020061E4(1954);
            else if(W(24)==109)func_020061E4(1954);
            else if(W(24)==218)func_020061E4(1488);
            if(W(24)==10)func_020061E4(1968);
            else if(W(24)==15)func_020061E4(1968);
            else if(W(24)==85)func_020061E4(1968);
            else if(W(24)==90)func_020061E4(1968);
            if(W(28)&&!GFL_USE_IsSeSlotBusy(W(32))) {
                W(28)=0;
                if(W(24)>=150&&W(24)<309)W(36)=20;
                else if(W(24)>309)W(36)=0;
            }
            if(W(24)>=150&&W(24)<limit) {
                if(!W(28)) {
                    if(!W(36)) {
                        W(32)=GFL_USE_GetSeSlot(1967);
                        func_0200616C((void *)1967,W(32));
                        W(28)=1;
                    }else W(36)--;
                }
            }else if(W(24)==limit&&W(28)&&GFL_USE_IsSeSlotBusy(W(32))) {
                func_020061F8(W(32));W(28)=0;
            }
        }
        if(W(24)==limit) {
            func_021F6D58(p);func_021F70F8(p);func_020061E4(1935);W(12)=2;
        }
        break;
    case 2:if(func_021F6D7C(p))W(12)=3;break;
    case 3:if(func_021F7100(p)){func_021F6CC0(p);W(20)=1;W(12)=4;}break;
    case 4:W(20)=0;break;
    case 6:
        if(++W(24)>=120){func_021F6D90(p);func_021F7110(p);W(12)=7;W(24)=0;}
        break;
    case 7:
        if(++W(24)>=65) {
            W(12)=8;
            a=func_02017E1C(((struct Obj01083 *)p)->f4,5,0);
            b=func_02017E1C(((struct Obj01083 *)p)->f4,111,0);
            PM_VOICE_Play(a,b,64,0,0,0,0,0);
        }
        break;
    case 8:if(!func_02006650())W(12)=9;break;
    case 9:break;
    }
    func_021F6D1C(p);
    MCSS_Main(*(char * *)&((struct Obj01083 *)p)->f30);
    func_021F6E5C(*(char * *)&((struct Obj01083 *)p)->f44);
    func_021F7048(p);
}







void func_021F6A24(char *p){MCSS_Draw(*(struct McssSys * *)&((struct Obj06708 *)p)->f30);func_021F6F24(p);func_021F6EE4(*(char * *)&((struct Obj06708 *)p)->f44);}







/*
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter, two alignment bytes, four-byte getter; twelve bytes total.
 */
void func_021F6A3C(char *p){((struct Obj25756 *)p)->f10=1;}







int func_021F6A44(char *p){return ((struct Obj25757 *)p)->f14;}






void func_021F6A48(char *p,int a)
{
    func_021F6CAC(p);
    *(int *)(p + 4) = a;
    func_021F6AEC(p);
    func_021F6CCC(p,0,0);
    MCSS_SetVanishFlag(*(void **)(p + 0x34));
    MCSS_SetPaletteFade(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}






/*
 * trailing: existing followers 021F6A98/6AA4 unit and 021F6AB4 shard.
 */
int func_021F6A84(char *p){if(MCSS_CheckPaletteFade(((struct Obj25758 *)p)->f34)==0)return 1;return 0;}






void func_021F6A98(char *p){((struct Obj14710 *)p)->fC=6;((struct Obj14710 *)p)->f18=0;}






int func_021F6AA4(char *p){if(((struct Obj25759 *)p)->fC>=9)return 1;return 0;}






/*
 * evidence: sole callback blocker of 021F6720; parent SDK/ownership audit.
 * extent: bx lr at 021F6AB4, zero padding at 6AB6; 6AB8 begins next function.
 */
void func_021F6AB4(void)
{
}






void func_021F6AB8(char *p)
{
    *(void **)(p + 0x30) = MCSS_Init(1, (void *)(*(unsigned short *)p));
    MCSS_SetTextureTransAdrs(*(void **)(p + 0x30), 3 << 16);
    MCSS_SetOrthoMode(*(void **)(p + 0x30));
    *(unsigned int *)(p + 0x3c) = 0;
    *(unsigned char *)(p + 0x40) = 0;
}






void func_021F6AE0(char *p){MCSS_Exit(*(u8 * *)&((struct Obj25760 *)p)->f30);}






/*
 * lever: FX float rounding macro; translation z shares the constructor's -50<<16 literal.
 */
void func_021F6AEC(char *p)
{
    Vec_021F63CC trans,scale,delta;
    u32 species;
    u8 i=0;
    float angle,y,x;
    ((struct Obj02262 *)p)->f34=MCSS_TOOL_AddPokeMcss(((struct Obj02262 *)p)->f30,((struct Obj02262 *)p)->f4,0,0,0xfff42000,0xffce0000);
    MCSS_SetShadowVanishFlag(*(char * *)&((struct Obj02262 *)p)->f34,1);
    species=func_02017E1C(((struct Obj02262 *)p)->f4,171,0);
    if(species!=650){
        for(;i<4;i++){
            if(species==table_021F7384[i].species){
                trans.x=FIX(table_021F7384[i].x);
                trans.y=FIX(table_021F7384[i].y);
                trans.z=0xffce0000;
                MCSS_SetPosition(((struct Obj02262 *)p)->f34,(u32 *)&trans);
                break;
            }
        }
    }
    scale.x=65536;scale.y=65536;scale.z=4096;
    MCSS_SetScale(((struct Obj02262 *)p)->f34,(u32 *)&scale);
    angle=(float)MCSS_GetSizeY(((struct Obj02262 *)p)->f34);
    y=(float)MCSS_GetOfsY(((struct Obj02262 *)p)->f34);
    x=(float)MCSS_GetOfsX(((struct Obj02262 *)p)->f34);
    if(angle>96.0f)angle=96.0f;
    y=(96.0f-angle)/2.0f+y;
    x=0.0f-x;
    delta.x=FIX(x);delta.y=FIX(y);delta.z=0;
    MCSS_SetOfsPosition(((struct Obj02262 *)p)->f34,(u32 *)&delta);
    MCSS_SetAnmStopFlag(((struct Obj02262 *)p)->f34);
}






/*
 * trailing: existing follower 021F6CC0 in its own matched shard.
 */
void func_021F6CAC(char *p){MCSS_SetVanishFlag(((struct Obj10941 *)p)->f34);MCSS_Del(((struct Obj10941 *)p)->f30,((struct Obj10941 *)p)->f34);}






/*
 * leaf: sole overlay blocker of 021F67E0; tail-call pool ends at 021F6CCC.
 */
void func_021F6CC0(char *p){MCSS_SetVanishFlag(((struct Obj25761 *)p)->f34);}






void func_021F6CCC(char *p,unsigned flag,int enable)
{
    void *obj;
    MCSS_SetAnimeIndex(((struct Obj06707 *)p)->f34,flag);
    obj=MCSS_GetAnimCtrl(((struct Obj06707 *)p)->f34);
    func_02064CBC(obj);
    MCSS_ResetAnmStopFlag(((struct Obj06707 *)p)->f34);
    if(enable) {
        func_02063000((int)obj,1,(int)p,(int)func_021F6D0C);
        ((struct Obj06707 *)p)->f38=0;
    } else MCSS_TOOL_SetAnimeStopCallback((int)(((struct Obj06707 *)p)->f34));
}







/*
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
int func_021F6D0C(char *a)
{
    MCSS_SetAnmStopFlag((void *)(((struct Obj14711 *)a)->f34));
    ((struct Obj14711 *)a)->f38 = 1;
    return 1;
}






void func_021F6D1C(char *p){u8 n;if(((struct Obj05551 *)p)->f3C){n=MCSS_GetAlpha(*(struct Data * *)&((struct Obj05551 *)p)->f34);if(n>((struct Obj05551 *)p)->f40)n--;else n++;MCSS_SetAlpha(*(char * *)&((struct Obj05551 *)p)->f34,n);if(n==((struct Obj05551 *)p)->f40)((struct Obj05551 *)p)->f3C=0;}}






void func_021F6D58(char *p){MCSS_SetAnmStopFlag(((struct Obj14712 *)p)->f34);MCSS_SetPaletteFade(*(struct McssFade * *)&((struct Obj14712 *)p)->f34,0,16,0,32767);}





int func_021F6D7C(char *p){if(MCSS_CheckPaletteFade(((struct Obj25762 *)p)->f34)==0)return 1;return 0;}





void func_021F6D90(char *p){MCSS_ResetVanishFlag(((struct Obj14713 *)p)->f34);MCSS_SetPaletteFade(*(struct McssFade * *)&((struct Obj14713 *)p)->f34,16,0,2,32767);}





char *func_021F6DB4(unsigned heap,unsigned count,const void *table)
{
    char *p;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    p=func_02030734(heap,0x481C,1,d_021F73F4,0x502);
    ((struct Obj03373 *)p)->f0=0;
    ((struct Obj03373 *)p)->f2=0;
    ((struct Obj03373 *)p)->f4=count;
    *(const void * *)&((struct Obj03373 *)p)->f8=table;
    ((struct Obj03373 *)p)->f4814=0;
    ((struct Obj03373 *)p)->f4818=-1;
    PARTICLE_InitManager(heap);
    *(int *)&((struct Obj03373 *)p)->f480C=PARTICLE_CreateSystemDefault((int)(p+12),0x4800,1,heap);
    config=d_021F7300;
    resource=PARTICLE_LoadArchiveMember((unsigned)config,(unsigned)(config>>32),heap);
    ((struct Obj03373 *)p)->f4810=BUTTON_MAN_GetResourceType((void *)resource);
    PARTICLE_SetupSystem(((struct Obj03373 *)p)->f480C,resource,1,0);
    return p;
}






void func_021F6E4C(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}





/*
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 */
void func_021F6E5C(char *p)
{
    if (((struct Obj02263 *)p)->f4814) {
        Vec_021F6D7C v=d_021F73B4;
        while (((struct Obj02263 *)p)->f2<((struct Obj02263 *)p)->f4) {
            const char *table=*(const char * *)&((struct Obj02263 *)p)->f8;
            unsigned index=((struct Obj02263 *)p)->f2;
            u16 frame=((struct Obj02263 *)p)->f0;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            PARTICLE_StartEffect(*(void **)(p+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),(int)(&v));
            (((struct Obj02263 *)p)->f2)++;
        }
        (((struct Obj02263 *)p)->f0)++;
    }
    if (((struct Obj02263 *)p)->f4818>=0) {
        if (((struct Obj02263 *)p)->f4818==0) PARTICLE_KillAllEffects(((struct Obj02263 *)p)->f480C);
        (((struct Obj02263 *)p)->f4818)--;
    }
}





void func_021F6EE4(char *p){PARTICLE_Main();}




/*
 * leaf: sole overlay blocker of 021F67E0; store and return, pool ends 021F6EF8.
 */
void func_021F6EEC(char *p){((struct Obj25763 *)p)->f4814=1;}




void func_021F6EF8(char *p){unsigned z=0;G3D_SYSTEM_SetSwapBuffersMode(1,z);*(struct Util * *)&((struct Obj00317 *)p)->f48=G3D_UTIL_Create(4,1,((struct Obj00317 *)p)->f0);((struct Obj00317 *)p)->f50=z;}




void func_021F6F18(char *p){G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj04636 *)p)->f48);}



void func_021F6F24(char *p)
{
    unsigned short i;
    for(i=0;i<((struct Obj06708 *)p)->f50;i++) {
        char *entry=*(char * *)&((struct Obj06708 *)p)->f54+i*0x44;
        if(((struct Obj14714 *)entry)->f40)
            G3D_SYSTEM_DrawObject((void *)func_02048A18(*(unsigned char * *)&((struct Obj06708 *)p)->f48,((struct Obj14714 *)entry)->f0),(struct Arg *)(entry+4));
    }
}



void func_021F6F64(char *p)
{
    unsigned id;
    char *entry;
    u16 i;
    void *q;
    int frame;
    ((struct Obj00317 *)p)->f4C=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Obj00317 *)p)->f48,&d_021F7330);
    ((struct Obj00317 *)p)->f50=1;
    *(struct Record * *)&((struct Obj00317 *)p)->f54=(struct Record *)func_021F66C8(((struct Obj00317 *)p)->f0,((struct Obj00317 *)p)->f50);
    id=func_020489F4(*(unsigned char * *)&((struct Obj00317 *)p)->f48,((struct Obj00317 *)p)->f4C);
    ((struct Obj00317 *)p)->f4E=0;
    entry=*(char * *)&((struct Obj00317 *)p)->f54;
    ((struct Obj06709 *)entry)->f0=id;
    ((struct Obj06709 *)entry)->f4=0;
    ((struct Obj06709 *)entry)->f8=0;
    ((struct Obj06709 *)entry)->fC=0;
    ((struct Obj06709 *)entry)->f40=1;
    for(i=0;i<((struct Obj00317 *)p)->f50;i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+i*68)),0);
    ((struct Obj00317 *)p)->f58=0;
    q=(void *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+((struct Obj00317 *)p)->f4E*68));
    frame=0;
    ((struct Obj00317 *)p)->f5C=0;
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q,1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q,2);
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)q,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)q,2,&frame);
}


void func_021F7028(char *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj04636 *)p)->f48,((struct Obj04636 *)p)->f4C);func_021F6718(((struct Obj04636 *)p)->f54);((struct Obj04636 *)p)->f50=0;}



void func_021F7048(char *p)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < ((struct Obj01083 *)p)->f50; i++) {
        G3D_SYSTEM_LoopObjectAnimeFrame((void *)func_02048A18((unsigned char *)(((struct Obj01083 *)p)->f48), *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + i * 0x44)), 0, 0x1000);
    }
    ((struct Obj01083 *)p)->f58 = ((struct Obj01083 *)p)->f58 + 1;
    q = (void *)func_02048A18((unsigned char *)(((struct Obj01083 *)p)->f48), *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + ((struct Obj01083 *)p)->f4E * 0x44));
    if (((struct Obj01083 *)p)->f5C == 1) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, 0x5000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, 0x5000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 2;
    } else if (((struct Obj01083 *)p)->f5C == 3) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, -0x2000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, -0x2000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 0;
    }
}

void func_021F70F8(char *p){((struct Obj01083 *)p)->f5C=1;}
int func_021F7100(char *p){return ((struct Obj01083 *)p)->f5C==2;}
void func_021F7110(char *p){((struct Obj01083 *)p)->f5C=3;}
