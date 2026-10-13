/*
 * function: func_021FBA6C
 * address:  0x021FBA6C
 * packet:   pkt_ov132_021FBA14
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    unlabelled Thumb function after func_021FBA14 (its listing extent
 *           ran past it); seeded in layout/function_starts.txt.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillEffect  0x02051630  arm
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *   d_021FDCC4 0x021FDCC4 data a4
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   MUSICAL_PROGRAM_GetCategoryBonus 0x0215725C thumb ov010
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6F04 0x021F6F04 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021FDC16 0x021FDC16 data a2
 *   func_02040618 0x02040618 arm
 *   d_021FDCD8 0x021FDCD8 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   d_021FDC20 0x021FDC20 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_0207D658 0x0207D658 arm
 *   func_021F9730 0x021F9730 thumb ov132
 *   func_021F9768 0x021F9768 thumb ov132
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020355D8 0x020355D8 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E804 0x0207E804 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02060468 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 *   func_02011290 0x02011290 thumb
 *   VM_Delete 0x02011264 thumb
 *   func_02060614 0x02060614 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   VM_Start 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   VM_Control 0x02011298 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   func_020604AC 0x020604AC arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020605B4 0x020605B4 arm
 *   _fadd 0x0209C95C arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   VM_GetU32 0x0201134C thumb
 *   d_021FDD00 0x021FDD00 data ov132 a4
 *   func_021F96D0 0x021F96D0 thumb ov132
 *   func_021F9E00 0x021F9E00 thumb ov132
 *   func_021F9E08 0x021F9E08 thumb ov132
 *   func_021F9D80  0x021F9D80  thumb
 *   func_021F9AD8  0x021F9AD8  thumb
 *   func_021F9D90  0x021F9D90  thumb
 *   func_021F80D4 0x021F80D4 thumb ov112
 *   func_021F812C 0x021F812C thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_0207CA00 0x0207CA00 arm
 *   func_021F80B0 0x021F80B0 thumb ov112
 *   func_021F80A0 0x021F80A0 thumb ov112
 *   func_021F80C8 0x021F80C8 thumb ov112
 *   func_021F8140 0x021F8140 thumb ov112
 *   func_021F8154 0x021F8154 thumb ov112
 *   func_021F9D18 0x021F9D18 thumb ov132
 *   func_021F95CC 0x021F95CC thumb ov132
 *   func_021F9140 0x021F9140 thumb ov132
 *   func_021F91A8 0x021F91A8 thumb ov132
 *   func_021F8084 0x021F8084 thumb ov112
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021F9E20 0x021F9E20 thumb ov132
 *   func_021F9E34 0x021F9E34 thumb ov132
 *   func_021F9E3C 0x021F9E3C thumb ov132
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209CE10 0x0209CE10 arm
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F6B18 0x021F6B18 thumb ov112
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 *   func_021F6B9C 0x021F6B9C thumb ov112
 *   func_021F6BB0 0x021F6BB0 thumb ov112
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9DCC 0x021F9DCC thumb ov132
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6F14 0x021F6F14 thumb ov112
 *   func_021F6F1C 0x021F6F1C thumb ov112
 *   func_021F9DE8 0x021F9DE8 thumb ov132
 *   func_021F95E8 0x021F95E8 thumb ov132
 *   func_021F6EE4 0x021F6EE4 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_021F9DF4 0x021F9DF4 thumb ov132
 *   func_021F93D8 0x021F93D8 thumb ov132
 *   func_021F94B0  0x021F94B0  thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_021F9664  0x021F9664  thumb
 *   func_021F9680  0x021F9680  thumb
 *   func_021F9690  0x021F9690  thumb
 *   func_021F969C 0x021F969C thumb ov132
 *   func_021F96B0  0x021F96B0  thumb
 *   func_021F96C4  0x021F96C4  thumb
 *   d_021FDE5C 0x021FDE5C data a4
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   func_02087C6C 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_02012124 0x02012124 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021FDC38 0x021FDC38 data a4
 *   GAME_DATA_GetSaveBlock2A 0x02012F44 thumb
 *   func_020173EC 0x020173EC thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0200A81C 0x0200A81C thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_021FD84C 0x021FD84C thumb ov132
 *   func_021FD6C8 0x021FD6C8 thumb ov132
 *   func_021FD704 0x021FD704 thumb ov132
 *   func_021FD6DC 0x021FD6DC thumb ov132
 *   func_021FD6F0 0x021FD6F0 thumb ov132
 *   func_021FD76C 0x021FD76C thumb ov132
 *   func_021FD7D4 0x021FD7D4 thumb ov132
 *   func_021FD6A4 0x021FD6A4 thumb ov132
 *   func_021FD550 0x021FD550 thumb ov132
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020084BC 0x020084BC thumb
 *   func_021F9E40  0x021F9E40  thumb  ov132
 *   func_021FADA0  0x021FADA0  thumb  ov132
 *   func_021FB190  0x021FB190  thumb  ov132
 *   func_021FB528  0x021FB528  thumb  ov132
 *   func_021FB8CC  0x021FB8CC  thumb  ov132
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_COMM_Start  0x020263D8  thumb  arm9
 */

#include "../../game/ov132/ov132_types.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define W(q,k) (*(u32 *)((q)+(k)))
#define P(q,k) (*(u8 **)((q)+(k)))
struct Bank;
struct Obj_021F9E40;
struct Actor;
struct Vec2;
struct Ctx;
struct ScriptVm;
struct DList;
struct ScriptVmParams;
struct Node;
struct Cursor;
struct Object;
struct Entry;
struct Comm;
struct Req;
struct Big;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { int a; Vec v; } Part;

typedef struct { char pad[0x4808]; Part part[4]; } Obj_021F9E40;

typedef signed int     s32;

typedef short s16_021F9E40;

typedef signed char s8;

typedef signed short s16_021FA558;

typedef signed short s16_021FA56C;

typedef short s16_021FA6CC;

typedef enum { FLAG_ZERO, FLAG_ONE } Flag;

typedef struct {u8 bytes[12];} Key;

typedef struct {s16_021FA6CC x,y;} Pos;

typedef short s16_021FA7E0;

typedef struct {s16_021FA7E0 x,y,index;u8 a,b;} Params;

typedef enum { COORD_ZERO } Coord;

typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;

typedef signed short s16;

typedef struct Vec3 { u32 x, y, z; } Vec3;

typedef struct Tag { u32 v; } Tag;

typedef struct Obj_021FBA6C { u16 f0; u8 pad2[0x32]; char *f34; } Obj_021FBA6C;

typedef struct Msg { Obj_021FBA6C *f0; void *f4; u8 pad8[0xC]; u16 f14; } Msg;

typedef struct R38 {
    u32 f00; char *f04; Vec3 f08; Vec3 f14; Vec3 f20; u16 f2C; u16 f2E; Obj_021FBA6C *f30; void *f34;
} R38;

typedef struct R20 { char *f00; u32 f04; u32 f08; u32 f0C; void *f10; u32 f14; Obj_021FBA6C *f18; void *f1C; } R20;

typedef struct R18 { char *f00; u32 f04; u32 f08; u16 f0C; u16 f0E; Obj_021FBA6C *f10; void *f14; } R18;

typedef unsigned long long u64;

struct Pl {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
    u32 x;
    u32 e;
    u8 rest[0x18];
};

struct G {
    u8 pad[0x64];
    struct Pl pl[4];
};

struct Request {u8 kind;u32 value;};

typedef struct 
{
  u8 tag;
  u32 data;
} Packet;

typedef struct {u16 heap;u8 pad[0x12a];u32 value;void *first,*second;char *buffer;u8 tail[0x70];} Owner_021F9E40;

typedef struct { u32 w[12]; } E;

typedef struct { u8 pad[0x60]; E e[4]; } T;

struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };

struct Context { char pad0[0x60]; struct Record rec[4]; };

/* The callback owner is the 0x1ac-byte allocation in 021FC644. */
typedef struct {u8 pad[0x128];char *buffer;u8 tail[0x80];} Owner_021FD22C;

extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void PARTICLE_InitManager(unsigned);
extern void PARTICLE_ExitManager(void);
extern u32 func_020307B0(void *p);
extern int PARTICLE_UpdateAllSystems(void);
extern int PARTICLE_DrawAllSystems(void);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void PARTICLE_SetupSystem(void *, void *, unsigned, unsigned);
extern void PARTICLE_KillAllEffects(u32);
extern void PARTICLE_DeleteSystem(u8 *p);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillEffect(void **p, void *q);
extern void BUTTON_MAN_SetEmitterPos(void *, int);
extern u16 func_021F9DFC(void *p);
extern unsigned func_02005728(unsigned);
extern u8 MUSICAL_PROGRAM_GetCategoryBonus(u8 *, int);
extern u16 func_021F9E04(u8 *p);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern void func_021F6F04(void *,char *,Vec *);
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02040618(unsigned, unsigned, unsigned);
extern void CLACT_DeleteActor(struct Obj_021F9E40 *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_0207D658(unsigned long,int,int);
extern void func_021F9730(char *p, int value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void func_0204B3DC(struct Obj_021F9E40 *,unsigned int);
extern void func_0204B404(struct Obj_021F9E40 *p, const struct Vec2 *delta, u32 which);
extern void func_020355D8(u8);
extern int func_021F9768(char *p);
extern u32 func_0204B3F4(struct Obj_021F9E40 *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 func_021F9E0C(u8 *p);
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4F70(int *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0204B92C(struct Obj_021F9E40 *,u32);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16),CLACT_RegisterCharacter(void *,u32,u32,u32,u16),CLACT_RegisterCellAnim(void *,u32,u32,u32),CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern struct Obj_021F9E40 *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int ARC_UTIL_LoadMember(int,int,int,int);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void func_020862F0(void *,u32);
extern void func_0207E5D0(const void *,u32,u32);
extern void func_0207E804(const void *,void *,u32);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02060468(int p0, int p1);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void VM_Delete(void *);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_02030DA4(void *);
extern void func_02030D28(struct Ctx *c);
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
extern int VM_Control(struct ScriptVm *vm);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void func_020604AC(void *, void *);
extern void func_02030EAC(struct Node *n);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_0207CEE4(int, void *, void *, void *);
extern void func_0207C9D0(const Vec *, const Vec *, Vec *);
extern u32 VM_GetU32(struct Cursor *p);
extern void func_021F96D0(char *p);
extern void func_021F9E00(void *, u16);
extern void func_021F9E08(u8 *p, u16 v);
extern void func_021F9D80(char *p);
extern void func_021F9AD8(char *p, int mode, u8 slot);
extern void func_021F9D90(char *p);
extern void func_021F80D4(char *, char *, int);
extern int func_021F812C(int unused, int *p, int flag);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern void func_0207CA00(void *,void *,void *);
extern void func_021F80B0(char *, char *);
extern void func_021F80A0(int a, u8 *p);
extern void func_021F80C8(int, void *, u8);
extern void func_021F8140(int a, u8 *p, int b);
extern int func_021F8154(int a0, int *a1, int a2);
extern void func_021F9D18(char *p, unsigned i);
extern void func_021F95CC(char *,unsigned char,int);
extern void func_021F9140(unsigned char *,unsigned char,unsigned char);
extern void func_021F91A8(char *p, u8 n, u8 mask);
extern void func_021F8084(void *unused, u32 *p, const u32 *q);
extern int func_0209C0A4();
extern void func_021F8068(int self, char *p, u16 v);
extern u16 func_021F9E20(char *p, u32 i);
extern u16 func_021F9E34(char *p, u32 i);
extern void func_021F9E3C(char *p, u32 v);
extern int func_0209BDBC(int a);
extern u32 func_0209C494(u32 a);
extern u32 func_0209CB8C(u32 a, u32 b);
extern u32 func_0209CE10(u32 a, u32 b);
extern void *func_021F9DAC(void *p);
extern struct Entry *func_021F6B18(struct Object *,unsigned short);
extern void func_021F9DB8(void *p, void *v, u32 i);
extern unsigned int *func_021F9DB0(void *,unsigned char);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
extern void func_021F6B9C(void *,u32 *,u32 *);
extern void func_021F6BB0(void *,u32 *,u32 *);
extern void *func_021F9DC0(void *p);
extern void func_021F9DCC(void *p, void *v, u32 i);
extern void *func_021F9DC4(void *,u8);
extern u8 *func_021F6E78(u8 *p, int v);
extern void func_021F6F14(void *a, char *p, u16 b, u8 c);
extern void func_021F6F1C(void *a, char *p, u32 b, u32 c);
extern void func_021F9DE8(void *,void *,u8);
extern void func_021F95E8(char *p);
extern void func_021F6EE4(void *,u8 *);
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
extern void *func_021F9DF4(void *p);
extern void func_021F93D8(u8 *,u16,u32);
extern void func_021F94B0(u8 *p);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void func_021F9664(char *p, int a);
extern void func_021F9680(char *p, int a);
extern void func_021F9690(char *p);
extern int func_021F969C(char *p, u32 a, u32 b, u32 d);
extern void func_021F96B0(char *p, int a);
extern void func_021F96C4(char *p);
extern void *func_020120F4(const struct Ctx *p);
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *);
extern u8 *func_02012944(void *p);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void MYSTATUS_Copy(void *, void *);
extern void func_02087C6C(void *);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_IsParentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02012124(struct Ctx *p, u32 v);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern void *GAME_DATA_GetSaveBlock2A(void *);
extern u32 func_020173EC(void);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern int MYSTATUS_GetSize(void);
extern void func_02082BCC(void *,u8,u32);
extern u16 func_0200A81C(struct Big *p);
extern u32 func_0203F0A8(void);
extern int func_021FD84C(u8 *p);
extern int func_021FD6C8(u8 *p);
extern int func_021FD704(u8 *p);
extern int func_021FD6DC(char *);
extern int func_021FD6F0(char *);
extern int func_021FD76C(u8 *p);
extern int func_021FD7D4(u8 *p);
extern int func_021FD6A4(char *);
extern void func_021FD550(char *);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(int);
extern void func_020061E4(u32);
extern void func_02082D44(void *,void *,u32);
extern int func_020084BC(const u16 *values);
void func_021F9E40(u8 *p,u32 v);
u32 func_021F9E44(u8 *p);
void func_021F9E4C(u8 *a0);
char *func_021F9E50(unsigned heap);
void func_021F9E94(u8 *p);
int func_021F9ECC(u8 *a0);
int func_021F9ED4(u8 *a0);
char *func_021F9EDC(char *p, u32 a);
void func_021F9F58(u8 *unused,u8 *p);
void func_021F9F74(char *p, unsigned i, Vec *v);
void func_021F9FB4(char *p, int i);
void func_021F9FD0(char *p, int i, int a);
char *func_021F9FEC(unsigned heap, void *a, unsigned b);
void func_021FA04C(u8 *p);
void func_021FA064(char *p);
void func_021FA0D0(char *a0);
void func_021FA0D4(void *p);
void func_021FA0D8(char *p, char *q);
void func_021FA278(void *a0);
void func_021FA27C(char *p);
void func_021FA2A0(char *p,u8 *rec);
void func_021FA3A8(char *p,u8 *rec,unsigned type);
void func_021FA4AC(char *p);
void func_021FA528(char *p);
void func_021FA558(char *p, int i, int v);
void func_021FA56C(char *p, u8 v);
void func_021FA57C(void *unused, int x);
char *func_021FA5B0(unsigned heap, void *a, char *b);
void func_021FA64C(char *p);
void func_021FA6CC(char *p);
void func_021FA7E0(char *p);
void func_021FA99C(u8 *p,u16 slot,int resource,u32 type);
void func_021FAAB8(char *p, unsigned flag);
void *func_021FAAF4(u32 heap, void *owner);
void func_021FAB58(char *p);
void func_021FABD8(char *p);
void *func_021FAC74(char *p, void *arg, int flag);
char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
int func_021FAD2C(void *unused, char *p);
u8 func_021FAD7C(char *p);
void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key);
void func_021FADF8(char *p, char *q);
int func_021FAE1C(char *p, int *out);
int func_021FAE4C(char *p, int *out);
int func_021FAEA8(char *p, void *out);
int func_021FAEE8(char *p);
int func_021FAF10(void *unused, char *p);
int func_021FAF1C(void *a, char *p);
int func_021FAF28(void *a, u8 *p);
int func_021FAF38(void *a, u8 *p);
int func_021FAF54(int a, char *b);
int func_021FAF70(void *unused, char *ctx);
int func_021FAFDC(void *unused, char *ctx);
int func_021FB050(void *unused, char *ctx);
void func_021FB0DC(void *unused, char *p);
int func_021FB104(void *unused, char *ctx);
void func_021FB190(void *unused, char *p);
int func_021FB1C0(void *unused,char *p);
int func_021FB1CC(int a, char **pp);
int func_021FB1E4(void *a, void **pp);
int func_021FB1F4(char *p, int i);
int func_021FB208(int unused, char *p);
int func_021FB258(int unused, char *p);
int func_021FB2B0(int unused,char *p);
int func_021FB3E0(int unused,char *p);
void func_021FB528(int unused,char *p);
int func_021FB55C(int unused, char *p);
int func_021FB5A4(int unused, char *p);
int func_021FB5EC(int unused, char *p);
int func_021FB640(int unused, char *p);
int func_021FB698(int unused, char *p);
int func_021FB6F0(int unused, char *p);
int func_021FB738(int unused,char *p);
int func_021FB774(int unused,char *p);
int func_021FB7A4(int unused,char *p);
int func_021FB7D8(int unused,char *p);
int func_021FB808(int unused, char *p);
void func_021FB8CC(int unused, char *p);
int func_021FB948(int unused,char *p);
void func_021FBA14(int a0, int *a1);
int func_021FBA6C(int unused, Msg *m);
int func_021FBD78(int unused, char *p);
int func_021FBDCC(int unused,char *p);
int func_021FBE00(int unused,char *p);
int func_021FBE38(int unused,char *p);
int func_021FBE64(int unused,char *p);
int func_021FBE90(int unused,char *p);
void func_021FBF74(int unused,char *p);
int func_021FBFA8(int unused,char *p);
int func_021FBFDC(int unused,char *p);
int func_021FC014(int unused, char *p);
int func_021FC080(int unused,char *p);
int func_021FC0AC(int unused,char *p);
void func_021FC178(int a, char *p);
int func_021FC1D4(int a,char **p);
int func_021FC22C(int unused,char *p);
int func_021FC268(int unused,char *p);
void func_021FC34C(int unused,char *p);
int func_021FC380(int unused,char *p);
void func_021FC490(int unused,char *p);
int func_021FC4CC(int a,char **p);
int func_021FC53C(int unused,char *p);
int func_021FC560(void *a, void **pp);
int func_021FC570(int unused,char *p);
int func_021FC5A0(int a, char **pp);
int func_021FC5BC(int a, char **pp);
int func_021FC5D8(int a, char **pp);
int func_021FC5E8(int unused,char *p);
int func_021FC61C(int a, char **pp);
int func_021FC634(int a, char **pp);
void func_021FC644(int a, void *b, void *c, int d);
void func_021FC684(char *p);
void *func_021FC694(int a,char *p);
int func_021FC6EC(int *state,u8 *p);
int func_021FC7DC(int unused,int unused1,void *p);
void func_021FC7F8(int unused,int unused1,char *p);
void func_021FC804(char *p);
void func_021FC81C(char *p);
void func_021FC848(u8 *p,void *a,void *b,int unused,void *d,u16 heap);
void func_021FCA38(char *p);
void func_021FCAA0(char *p);
void func_021FCAA8(char *p);
void func_021FCDEC(int a, int b);
int func_021FCE00(char *p,int id);
int func_021FCE28(char *p,u32 index);
int func_021FCE44(char *p,u32 index);
char *func_021FCE60(char *p);
u32 func_021FCE64(void);
int func_021FCE68(int a,int b);
void func_021FCE74(int unused,int kind,u32 value,u32 id);
u32 func_021FCEA8(int unused,int kind,u32 value,u32 id);
void func_021FCEDC(unsigned long slot, int unused, const Packet *q, char *p);
u32 func_021FD14C(Owner_021F9E40 *p);
void func_021FD208(int i, int b, int c, T *p);
u32 func_021FD218(int i, T *p);
int func_021FD22C(char *p);
void func_021FD2B8(int a,int b,int c,char *p);
void *func_021FD328(int a,char *p);
int func_021FD350(char *p, char *src);
void func_021FD3D8(long i,int b,int c,struct Context *p);
void *func_021FD3F0(long i,struct Context *p);
int func_021FD400(const char *p);
void func_021FD470(int a,int b,int c,const Owner_021FD22C *p);
extern const char d_021FDCB0[];
extern const char d_021FDCC4[];
extern u16 d_021FDC16[];
extern const char d_021FDCD8[];
extern const Key d_021FDC20;
extern char d_021FDCEC[];
extern char d_021FDC2C[];
extern const char d_021FDD00[];
extern const s16_021FA558 d_020A1B38[];
extern const char d_021FDE5C[];
extern char d_021FDE4C[];
extern char d_021FDDEC[];
extern char d_021FDC38[];

int func_021FBA6C(int unused, Msg *m)
{
    Obj_021FBA6C *o = m->f0;
    u32 vec[4];
    Vec3 v;
    Tag tag;
    u32 x = VM_GetU32(m->f4);
    u32 y = VM_GetU32(m->f4);
    void *h = func_021F9DA0(o->f34);
    u32 idx;
    u32 total;
    u32 base;
    u32 maxabs = 0;
    s8 dir[4] = { 0, 0, 0, 0 };
    u16 max = 0;
    u8 i, j, k;

    for (i = 0; i < 4; i++) {
        u16 v = func_021F9E34(o->f34, i) + func_021F9E20(o->f34, i);
        if (max < v)
            max = v;
    }
    for (i = 0; i < 4; i++) {
        u16 v = func_021F9E34(o->f34, i) + func_021F9E20(o->f34, i);
        if (max == v)
            idx = i;
    }
    for (i = 0; i < 4; i++) {
        func_021F8044(h, func_021F9DA4(o->f34, i), &v.x);
        vec[i] = v.x;
        if (i == idx)
            base = v.x;
    }
    for (i = 0; i < 4; i++)
        vec[i] = vec[i] - base;
    for (i = 0; i < 4; i++) {
        if (i == idx)
            continue;
        for (j = 0; j < 4; j++) {
            if (i == j)
                continue;
            if ((int)vec[i] > 0 && (int)vec[j] >= 0 && (int)vec[i] > (int)vec[j])
                dir[i]++;
            else if ((int)vec[i] < 0 && (int)vec[j] <= 0 && (int)vec[i] < (int)vec[j])
                dir[i]--;
        }
        if ((int)maxabs < ABS(dir[i]))
            maxabs = (u8)ABS(dir[i]);
    }
    total = 0;
    for (k = 0; k < 4; k++) {
        R38 *a;
        tag.v = 0x54B;
        tag.v -= 0x1B;
        a = func_02030734(o->f0, 0x38, 0, d_021FDD00, tag.v);
        a->f30 = o;
        a->f00 = (u32)func_021F9DA4(o->f34, k);
        a->f04 = o->f34;
        a->f2E = 0;
        func_021F8044(h, (void *)a->f00, (u32 *)&a->f08);
        a->f14.x = base + (dir[k] << 18);
        a->f14.y = a->f08.y;
        a->f14.z = a->f08.z;
        a->f2C = func_0209C0A4(ABS(dir[k]) * x, maxabs);
        a->f20.x = func_0209C0A4(a->f14.x - a->f08.x, a->f2C);
        a->f20.y = func_0209C0A4(a->f14.y - a->f08.y, a->f2C);
        a->f20.z = func_0209C0A4(a->f14.z - a->f08.z, a->f2C);
        a->f34 = func_021FADA0((char *)o, (u32)func_021FB528, (u32)a, 10);
        if (a->f2C != 0) {
            R20 *b = func_02030734(o->f0, 0x20, 0, d_021FDD00, 0x54B);
            u16 t = a->f2C;
            int rem = (u8)(t % 15) ? 1 : 0;
            b->f18 = o;
            b->f10 = func_021F9DA4(o->f34, k);
            b->f14 = 0x8000;
            b->f00 = o->f34;
            b->f04 = 0;
            b->f08 = 15;
            b->f0C = (u8)(t / 15 + rem);
            b->f1C = func_021FADA0((char *)o, (u32)func_021FB8CC, (u32)b, 10);
        }
        total += a->f14.x;
    }
    {
        R18 *c = func_02030734(o->f0, 0x18, 0, d_021FDD00, 0x563);
        u32 f;
        c->f10 = o;
        c->f00 = o->f34;
        c->f0E = 0;
        c->f04 = func_021F9E04((u8 *)o->f34);
        f = func_0209BDBC((int)total / 4);
        f = func_0209CE10(f, 0x45800000);
        f = func_0209CB8C(f, 0x43000000);
        c->f08 = func_0209C494(f);
        c->f0C = x;
        c->f14 = func_021FADA0((char *)o, (u32)func_021FB190, (u32)c, 10);
        func_021F9E40((u8 *)o->f34, 1);
        func_021F9E3C(o->f34, 1);
        if (y == 1) {
            m->f14 = x;
            return 1;
        }
        return 0;
    }
}
