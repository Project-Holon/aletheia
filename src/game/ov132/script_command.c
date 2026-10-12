/*
 * file:     script_command.c
 * unit:     yes
 * function: func_021F9E40, func_021F9E44, func_021F9E4C, func_021F9E50, func_021F9E94, func_021F9ECC, func_021F9ED4, func_021F9EDC, func_021F9F58, func_021F9F74, func_021F9FB4, func_021F9FD0, func_021F9FEC, func_021FA04C, func_021FA064, func_021FA0D0, func_021FA0D4, func_021FA0D8, func_021FA278, func_021FA27C, func_021FA2A0, func_021FA3A8, func_021FA4AC, func_021FA528, func_021FA558, func_021FA56C, func_021FA57C, func_021FA5B0, func_021FA64C, func_021FA6CC, func_021FA7E0, func_021FA99C, func_021FAAB8, func_021FAAF4, func_021FAB58, func_021FABD8, func_021FAC74, func_021FAD0C, func_021FAD2C, func_021FAD7C, func_021FADA0, func_021FADF8, func_021FAE1C, func_021FAE4C, func_021FAEA8, func_021FAEE8, func_021FAF1C, func_021FAF28, func_021FAF38, func_021FAF54, func_021FAF70, func_021FAFDC, func_021FB050, func_021FB0DC, func_021FB104, func_021FB190, func_021FB1C0, func_021FB1CC, func_021FB1E4, func_021FB1F4, func_021FB208, func_021FB258, func_021FB2B0, func_021FB3E0, func_021FB528, func_021FB55C, func_021FB5A4, func_021FB5EC, func_021FB640, func_021FB698, func_021FB6F0, func_021FB738, func_021FB774, func_021FB7A4, func_021FB7D8, func_021FB808, func_021FB8CC, func_021FB948, func_021FBA14, func_021FBA6C, func_021FBD78, func_021FBDCC, func_021FBE00, func_021FBE38, func_021FBE64, func_021FBE90, func_021FBF74, func_021FBFA8, func_021FBFDC, func_021FC014, func_021FC080, func_021FC0AC, func_021FC178, func_021FC1D4, func_021FC22C, func_021FC268, func_021FC34C, func_021FC380, func_021FC490, func_021FC4CC, func_021FC53C, func_021FC560, func_021FC570, func_021FC5A0, func_021FC5BC, func_021FC5D8, func_021FC5E8, func_021FC61C, func_021FC634, func_021FC644, func_021FC684, func_021FC694, func_021FC6EC, func_021FC7DC, func_021FC804, func_021FC81C, func_021FC848, func_021FCA38, func_021FCAA0, func_021FCAA8, func_021FCDEC, func_021FCE00, func_021FCE28, func_021FCE44, func_021FCE74, func_021FCEA8, func_021FCEDC, func_021FD14C, func_021FD208, func_021FD218, func_021FD22C, func_021FD2B8, func_021FD328, func_021FD350, func_021FD3D8, func_021FD3F0, func_021FD400, func_021FD470, func_021FD4D0
 * address:  0x021F9E40
 * region:   ov132
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
 *   func_02050B80 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02051574 0x02051574 arm
 *   func_02051534 0x02051534 arm
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 *   func_02051620 0x02051620 arm
 *   func_02050DB8 0x02050DB8 arm
 *   func_020515B4 0x020515B4 arm
 *   func_02051630  0x02051630  arm
 *   func_02051838  0x02051838  arm
 *   d_021FDCC4 0x021FDCC4 data a4
 *   func_021F9DFC 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   func_0215725C 0x0215725C thumb ov010
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
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   d_021FDC20 0x021FDC20 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_0207D658 0x0207D658 arm
 *   func_021F9730 0x021F9730 thumb ov132
 *   func_021F9768 0x021F9768 thumb ov132
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020355D8 0x020355D8 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_0206E964 0x0206E964 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E804 0x0207E804 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02060468 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 *   func_02011290 0x02011290 thumb
 *   func_02011264 0x02011264 thumb
 *   func_02060614 0x02060614 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02030D28 0x02030D28 arm
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201127C 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   func_02011298 0x02011298 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   func_020604AC 0x020604AC arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020605B4 0x020605B4 arm
 *   _fadd 0x0209C95C arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0201134C 0x0201134C thumb
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
 *   func_021F8068  0x021F8068  thumb  ov112
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
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021F9664  0x021F9664  thumb
 *   func_021F9680  0x021F9680  thumb
 *   func_021F9690  0x021F9690  thumb
 *   func_021F969C 0x021F969C thumb ov132
 *   func_021F96B0  0x021F96B0  thumb
 *   func_021F96C4  0x021F96C4  thumb
 *   d_021FDE5C 0x021FDE5C data a4
 *   func_02026400 0x02026400 thumb
 *   func_0203CBAC 0x0203CBAC arm
 *   func_02087C6C 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D378 0x0203D378 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02012124 0x02012124 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203A574 0x0203A574 arm
 *   d_021FDC38 0x021FDC38 data a4
 *   func_02012F44 0x02012F44 thumb
 *   func_020173EC 0x020173EC thumb
 *   func_020173E8 0x020173E8 thumb
 *   func_02008468 0x02008468 thumb
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
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203996C 0x0203996C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020084BC 0x020084BC thumb
 */
#include "ov132_types.h"

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
extern void func_02050B80(unsigned);
extern void func_02050ED4(void);
extern u32 func_020307B0(void *p);
extern int func_02051574(void);
extern int func_02051534(void);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void func_02051230(void *, void *, unsigned, unsigned);
extern void func_02051620(u32);
extern void func_02050DB8(u8 *p);
extern int func_020515B4(void *p, int b, int c);
extern void func_02051630(void **p, void *q);
extern void func_02051838(void *, int);
extern u16 func_021F9DFC(void *p);
extern unsigned func_02005728(unsigned);
extern u8 func_0215725C(u8 *, int);
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
extern void func_0204B3B4(struct Obj_021F9E40 *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_02035C08(const void *);
extern void func_0207D658(unsigned long,int,int);
extern void func_021F9730(char *p, int value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B3DC(struct Obj_021F9E40 *,unsigned int);
extern void func_0204B404(struct Obj_021F9E40 *p, const struct Vec2 *delta, u32 which);
extern void func_020355D8(u8);
extern int func_021F9768(char *p);
extern u32 func_0204B3F4(struct Obj_021F9E40 *p);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_021F9E0C(u8 *p);
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4F70(int *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204B270(struct Bank *bank);
extern void func_02049238(void *);
extern void func_0204B92C(struct Obj_021F9E40 *,u32);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16),func_0204A6C8(void *,u32,u32,u32,u16),func_0204AF28(void *,u32,u32,u32),func_0204ABF0(void *,u32,u32,u32,u16);
extern struct Obj_021F9E40 *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int func_0204A1BC(int,int,int,int);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void func_020862F0(void *,u32);
extern void func_0207E5D0(const void *,u32,u32);
extern void func_0207E804(const void *,void *,u32);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02060468(int p0, int p1);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void func_02011264(void *);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_02030DA4(void *);
extern void func_02030D28(struct Ctx *c);
extern struct ScriptVm *func_0201121C(u32 heapId, const struct ScriptVmParams *params);
extern void func_0201126C(struct ScriptVm *vm, void *user);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern int func_02011298(struct ScriptVm *vm);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void func_020604AC(void *, void *);
extern void func_02030EAC(struct Node *n);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_0207CEE4(int, void *, void *, void *);
extern void func_0207C9D0(const Vec *, const Vec *, Vec *);
extern u32 func_0201134C(struct Cursor *p);
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
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021F9664(char *p, int a);
extern void func_021F9680(char *p, int a);
extern void func_021F9690(char *p);
extern int func_021F969C(char *p, u32 a, u32 b, u32 d);
extern void func_021F96B0(char *p, int a);
extern void func_021F96C4(char *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern void func_02026400(struct Comm *);
extern u8 *func_02012944(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int);
extern void func_0203A5E4(u32);
extern void func_0203D7BC(u8 a0);
extern u32 func_0200FB24(void);
extern u32 func_0203D378(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02012124(struct Ctx *p, u32 v);
extern int func_0203CDBC(void);
extern void func_0203A574(u32,u32,u32,u32);
extern void *func_02012F44(void *);
extern u32 func_020173EC(void);
extern u32 func_020173E8(void);
extern int func_02008468(void);
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
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
extern struct Entry *func_0203996C(int);
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







void func_021F9E40(u8 *p,u32 v) { ((struct ActingScene *)p)->f14=v; }







u32 func_021F9E44(u8 *p) { return ((struct ActingScene *)p)->f1E8; }







void func_021F9E4C(u8 *a0) { }







char *func_021F9E50(unsigned heap)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x24244, 0, d_021FDCB0, 76);
    ((struct ScriptCtx *)p)->f0.h = heap;
    func_02050B80(heap);
    for (; i < 8; i++)
        *(int *)(p + i * 0x4848 + 4) = 0;
    return p;
}







/*
 * lever: the load uses p+index*0x4848+4, while the outgoing pointer uses p+4+index*0x4848; the latter keeps p+4 hoisted in r6. Using the load's grouping for both gave 49 concrete byte differences.
 */
void func_021F9E94(u8 *p) { u8 i; for(i=0;i<8;i++) { if(*(u32 *)(p+i*0x4848+4)==1) func_021F9F58(p,p+4+i*0x4848); } func_02050ED4(); func_020307B0(p); }







int func_021F9ECC(u8 *a0) { return func_02051574(); }







int func_021F9ED4(u8 *a0) { return func_02051534(); }







char *func_021F9EDC(char *p, u32 a)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    ((struct TargetBank *)q)->f4804.p = (void *)func_02050C04((int)(q + 4), 0x4800, 0, ((struct ScriptCtx *)p)->f0.h);
    v = (void *)func_0205121C(47, a, ((struct ScriptCtx *)p)->f0.h);
    func_02051230(((struct TargetBank *)q)->f4804.p, v, 0, func_020056BC());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    ((struct TargetBank *)q)->f0.s = 1;
    return q;
}







void func_021F9F58(u8 *unused,u8 *p) { ((struct TargetBank *)p)->f0.u=0; func_02051620(((struct TargetBank *)p)->f4804.u); func_02050DB8((u8 *)(((struct TargetBank *)p)->f4804.u)); }







static inline void set(Vec *p, int x, int y, int z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}







/*
 * lever: Non-const Vec source preserves alias dependence: inline setter
 * arguments load z, y, x after the handle store and before vector stores.
 * const int * and const Vec * sources both gave DIFF, 19 concrete bytes.
 */
void func_021F9F74(char *p, unsigned i, Vec *v)
{
    int a = func_020515B4(((struct TargetBank *)p)->f4804.p, i, (int)v);
    if (a == 0 || i < 4) {
        ((Obj_021F9E40 *)p)->part[i].a = a;
        set(&((Obj_021F9E40 *)p)->part[i].v, v->x, v->y, v->z);
    }
}








/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x02051630 now has an
 * EXACT arm9 shard entry (pkt_02051630), so the blx at +0012 resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void func_021F9FB4(char *p, int i)
{
    int v = *(int *)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051630(((struct TargetBank *)p)->f4804.p, (void *)v);
}








/*
 * Addresses are Black-image addresses.
 */
void func_021F9FD0(char *p, int i, int a)
{
    void *v = *(void **)(p + i * 16 + 0x4808);

    if (v != 0)
        func_02051838(v, a);
}







char *func_021F9FEC(unsigned heap, void *a, unsigned b)
{
    u8 i = 0;
    char *p = func_02030734(heap, 0x3e4, 0, d_021FDCC4, 115);
    ((struct ScriptOwner *)p)->f0 = heap;
    func_021FA0D0(p);
    func_021FA0D8(p, (char *)b);
    ((struct ScriptOwner *)p)->f1E8 = a;
    ((struct ScriptOwner *)p)->f200 = 0;
    for (; i < 4; i++) *(int *)(p + i * 4 + 0x1ec) = 0;
    ((struct ScriptOwner *)p)->f1FC = 255;
    return p;
}








void func_021FA04C(u8 *p)
{
    func_021FA278(p);
    func_021FA0D4(p);
    func_020307B0(p);
}







/*
 * extent: compiled ends 021FA0CE; two zero padding bytes before labelled 021FA0D0.
 */
void func_021FA064(char *p)
{
    u8 i;
    if (func_021F9DFC(((struct ScriptOwner *)p)->f1E8) == 0) {
        if (func_02005728(10) == 0) {
            for (i = 0; i < 3; i++) {
                u8 a = func_02005728(4);
                u8 b = func_02005728(60);
                func_021FA3A8(p, (u8 *)(p + 0x204 + b * 8), a);
            }
        }
    } else {
        if (((struct ScriptOwner *)p)->f200 == 1) {
            func_021FA4AC(p);
            ((struct ScriptOwner *)p)->f200 = 0;
        }
        func_021FA27C(p);
    }
}







void func_021FA0D0(char *a0) { }







void func_021FA0D4(void *p) { }







#pragma opt_common_subs off







/*
 * note 2026-10-05: needs per-function opt_common_subs off (the original does not share
 * idx*8 between the record stores and the call argument; without the pragma only
 * the rec/off register pair is swapped). Callee func_021FA3A8 takes (p, rec, type).
 * Caller passes q as a pointer: field 0x14 is a byte table read by func_0215725C.
 */
void func_021FA0D8(char *p, char *q)
{
    u16 sum = 0;
    u8 b[4];
    u8 a[4] = {0, 0, 0, 0};
    u8 c[60];
    u8 n = 0;
    u8 i, j, k, g, x, idx;
    int base;
    u8 r;
    int off;
    u8 *rec;
    for (i = 0; i < 4; i++) {
        b[i] = func_0215725C(*(u8 **)(q + 0x14), i);
        sum = sum + b[i];
    }
    for (i = 0; i < 4; i++) {
        a[i] = (b[i] * 60) / sum;
        n = n + a[i];
    }
    for (; n < 60; n++)
        a[func_02005728(4)]++;
    k = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < a[i]; j++) {
            c[k] = i;
            k++;
        }
    for (r = 0; r < 3; r++) {
        for (i = 0; i < 60; i++) {
            u8 t;
            x = func_02005728(60);
            t = c[i];
            c[i] = c[x];
            c[x] = t;
        }
    }
    for (g = 0; g < 5; g++) {
        i = 0;
        base = g * 12;
        for (; i < 12; i++) {
            idx = i + base;
            off = idx * 8;
            rec = (u8 *)(p + off);
            rec[0x20A] = i + 2;
            rec[0x20B] = g;
            rec[0x206] = c[idx];
            rec[0x205] = func_02005728(60) + 1;
            rec[0x204] = 0xff;
            if (i < 2)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 3);
            else if (i < 4)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 2);
            else if (i < 6)
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 1);
            else
                func_021FA3A8(p, (u8 *)(p + 0x204 + off), 0);
        }
    }
}








#pragma opt_common_subs reset







void func_021FA278(void *a0)
{
}







/*
 * Lever: keep the declared base but expand p+0x204 at the call; named base left a four-byte r5/r6 swap.
 * trailing: Two zero alignment bytes.
 */
void func_021FA27C(char *p)
{
  u8 i = 0;
  u8 *base = (u8 *) (p + 0x204);
  for (; i < 60; i++)
    func_021FA2A0(p, ((u8 *) (p + 0x204)) + (i * 8));

}







void func_021FA2A0(char *p,u8 *rec)
{
    Vec v;
    void *a,*b;
    u16 x;
    s16_021F9E40 delta;
    if(rec[1]!=0) rec[1]--;
    if(rec[1]==0) {
        if(rec[0]==255 && ((struct ScriptOwner *)p)->f1FC==255) {
            ((struct Obj00995 *)rec)->f4=65535;
            if(rec[6]<2) func_021FA3A8(p,rec,3);
            else if(rec[6]<4) func_021FA3A8(p,rec,2);
            else if(rec[6]<6) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,0);
        } else {
            func_021F9E04(((struct ScriptOwner *)p)->f1E8);
            x=((rec[6]*32-64)*4)/3;
            if(rec[0]!=255) {
                a=func_021F9DA0(((struct ScriptOwner *)p)->f1E8);
                func_021F8044(a,func_021F9DA4(((struct ScriptOwner *)p)->f1E8,rec[0]),(u32 *)(&v));
            } else {
                b=func_021F9DD4(((struct ScriptOwner *)p)->f1E8);
                func_021F6F04(b,(char *)func_021F9DDC(((struct ScriptOwner *)p)->f1E8,((struct ScriptOwner *)p)->f1FC),&v);
            }
            delta=(float)v.x/4096.f-(float)(u32)x;
            if(delta < -64) func_021FA3A8(p,rec,0);
            else if(delta >64) func_021FA3A8(p,rec,3);
            else if(delta<0) func_021FA3A8(p,rec,1);
            else func_021FA3A8(p,rec,2);
        }
        rec[1]=func_02005728(60)+1;
    }
}







/*
 * ABI: 41300 caller truncates tile to u16 and coordinates to u8 before each call.
 */
void func_021FA3A8(char *p,u8 *rec,unsigned type)
{
    u16 tile;
    int reverse=0;
    u8 row,col,x;
    u32 t;
    switch(type) {
    case 3: reverse=1; tile=*(u16 *)((u32)d_021FDC16+rec[2]*2)+0x400; break;
    case 2: reverse=1; tile=*(u16 *)((u32)d_021FDC16+rec[2]*2)+0x404; break;
    case 1: tile=*(u16 *)((u32)d_021FDC16+rec[2]*2)+4; break;
    case 0: tile=*(u16 *)((u32)d_021FDC16+rec[2]*2); break;
    }
    for(row=0;row<4;row++) {
        for(col=0;col<4;col++) {
            if(reverse==1) x=3-col+rec[6]*4;
            else x=col+rec[6]*4;
            t=tile+col+row*32;
            func_02041300(4,tile+col+row*32,x,row+rec[7]*4+2,1,1,0);
            func_02041300(6,t,x,row+rec[7]*4+5,1,1,0);
        }
    }
    func_02041B6C(4);
    func_02041B6C(6);
}







void func_021FA4AC(char *p)
{
    u8 i;
    u8 n = 0;
    u8 choices[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1ec) == 1) { choices[n] = i; n++; }
    }
    if (n == 0) func_021FA528(p);
    else {
        for (i = 0; i < 60; i++) {
            *(u8 *)(p + i * 8 + 0x205) = func_02005728(60) + 1;
            *(u8 *)(p + i * 8 + 0x204) = choices[func_02005728(n)];
        }
    }
}







void func_021FA528(char *p)
{
    u8 i;
    for (i = 0; i < 60; i++) {
        char *q = p + i * 8;
        ((struct ScriptOwner *)q)->f205 = func_02005728(60) + 1;
        ((struct ScriptOwner *)q)->f204 = 255;
    }
}










void func_021FA558(char *p, int i, int v)
{
    char *q = p + i * 4;

    ((struct ActingScene *)q)->f1EC.s = v;
    ((struct ScriptOwner *)p)->f200 = 1;
}










void func_021FA56C(char *p, u8 v)
{
    ((struct ScriptOwner *)p)->f1FC = v;
    ((struct ScriptOwner *)p)->f200 = 1;
}









void func_021FA57C(void *unused, int x)
{
    u16 v = ((x << 7) / 256) + 64;
    func_02040618(4, 0, v);
    func_02040618(6, 0, v);
    func_02040618(5, 0, v);
}









static inline void inside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x04001048 & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04001048 = tmp;
}









static inline void outside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x0400104a & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400104a = tmp;
}









/*
 * volatile: hardware register reads and writes at 021FA5FA..021FA634.
 */
char *func_021FA5B0(unsigned heap, void *a, char *b)
{
    char *p = func_02030734(heap, 0x60, 0, d_021FDCD8, 87);
    ((struct TaskObj *)p)->f0 = heap;
    ((struct TaskObj *)p)->f4 = a;
    *(char * *)&((struct TaskObj *)p)->f8 = b;
    ((struct TaskObj *)p)->fC.s = 0;
    ((struct TaskObj *)p)->f10 = 0;
    ((struct TaskObj *)p)->f14 = 2;
    ((struct TaskObj *)p)->f48 = ((struct ActingRecord *)b)->f3E;
    ((struct TaskObj *)p)->f4A = ((struct ActingRecord *)(*(char * *)&((struct TaskObj *)p)->f8))->f44;
    ((struct TaskObj *)p)->f40 = 0;
    ((struct TaskObj *)p)->f44 = 0;
    func_021FA7E0(p);
    *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xe000) | 0x2000;
    inside(31, 1);
    outside(31, 0);
    *(volatile u16 *)0x04001040 = 255;
    *(volatile u16 *)0x04001044 = 0x80c0;
    return p;
}









/*
 * volatile: hardware control read at 021FA652 and store 021FA658.
 */
void func_021FA64C(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (((struct TaskObj *)p)->f48 != 255) func_0204B3B4(((struct TaskObj *)p)->f4C);
    if (((struct TaskObj *)p)->f4A != 255) func_0204B3B4(((struct TaskObj *)p)->f50);
    func_0204B3B4(((struct TaskObj *)p)->f5C);
    func_0204ADA4((u32)(((struct TaskObj *)p)->f1C.p));
    func_0204A8D4((u32)(((struct TaskObj *)p)->f28.p));
    func_0204AFD8((u32)(((struct TaskObj *)p)->f34.p));
    func_0204ADA4((u32)(((struct TaskObj *)p)->f20.p));
    func_0204A8D4((u32)(((struct TaskObj *)p)->f2C.p));
    func_0204AFD8((u32)(((struct TaskObj *)p)->f38.p));
    func_0204ADA4((u32)(((struct TaskObj *)p)->f24.p));
    func_0204A8D4((u32)(((struct TaskObj *)p)->f30.p));
    func_0204AFD8((u32)(((struct TaskObj *)p)->f3C.p));
    func_0204B1CC(((struct TaskObj *)p)->f18);
    func_020307B0(p);
}









/*
 * checks: 1 fresh 9730/9768 show and 25EA4/23F60/B3DC/B9A0/B98C bodies confirm arities; 2 fresh A5B0/A64C/A7E0 no full twin; 3 u8/const-char pointer unchanged; 4 struct-field, chained-assignment and enum-zero idioms; 5 fresh directory/neighbours.
 * spelling: enum-typed one/zero locals retain separate constant webs; literals and enum-typed stores alone left six differing bytes. Prior permuter300 was not repeated.
 */
void func_021FA6CC(char *p)
{
    Key key;
    Pos pos;
    int hit;
    Flag one,zero;
    if(((struct TaskObj *)p)->fC.s==1) {
        key=d_021FDC20;
        hit=func_02035C08(&key);
        func_0207D658(0x04001050,16,0);
        if(hit!=-1 && *(u16 *)(p+0x48+hit*2)!=255 && *(int *)(p+0x40+hit*4)==0) {
            if(hit==0) func_021F9730(((struct TaskObj *)p)->f4,7);
            else func_021F9730(((struct TaskObj *)p)->f4,8);
            func_0207D658(0x04001050,16,-8);
            one=FLAG_ONE;
            zero=FLAG_ZERO;
            *(u32 *)(p+0x40+hit*4)=one;
            *(u32 *)&((struct TaskObj *)p)->f10=one;
            *(u32 *)&((struct TaskObj *)p)->fC=zero;
            ((struct TaskObj *)p)->f14=hit;
            pos.x=hit==0?32:224;
            pos.y=128;
            func_0204B9A0(((struct TaskObj *)p)->f5C);
            func_0204B3DC(((struct TaskObj *)p)->f5C,1);
            func_0204B404(((struct TaskObj *)p)->f5C,(const struct Vec2 *)(&pos),1);
            func_020355D8(1);
        }
    }
    if(((struct TaskObj *)p)->f14!=2) {
        if(func_021F9768(((struct TaskObj *)p)->f4)==0) {
            if(((struct TaskObj *)p)->f10==0) {
                ((struct TaskObj *)p)->fC.s=1;
                func_0204B3DC(*(void **)(p+0x4c+((struct TaskObj *)p)->f14*4),0);
                func_0204B3DC(*(void **)(p+0x54+((struct TaskObj *)p)->f14*4),0);
                ((struct TaskObj *)p)->f14=2;
            }
        } else {
            if(((struct TaskObj *)p)->f10==1) ((struct TaskObj *)p)->f10=0;
        }
    }
    if(func_0204B3F4(((struct TaskObj *)p)->f5C)==1) {
        if(func_0204B98C(((struct TaskObj *)p)->f5C)==0) func_0204B3DC(((struct TaskObj *)p)->f5C,0);
    }
}









/*
 * extent: 021FA99A zero halfword is alignment padding before labelled 021FA99C.
 * ABI: B294 forwards an address-valued u32 payload and returns the actor in r0; ABF0 tail-forwards AC18's index despite void declaration.
 */
void func_021FA7E0(char *p)
{
    Params configs[2];
    u8 *table;
    void *narc;
    u8 i=0;
    int format;
    table=(u8 *)func_021F9E0C((u8 *)(*(char * *)&((struct TaskObj *)p)->f4));
    ((struct TaskObj *)p)->f18=func_0204B100(5,0,((struct TaskObj *)p)->f0);
    func_0204B270(((struct TaskObj *)p)->f18);
    narc=func_020490F4(47,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f1C=func_0204AC18(narc,0,1,0,0,2,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f28=func_0204A6C8(narc,6,0,1,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f34=func_0204AF28(narc,18,21,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f20=func_0204AC18(narc,1,1,64,0,1,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f2C=func_0204A6C8(narc,7,0,1,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f38=func_0204AF28(narc,19,22,((struct TaskObj *)p)->f0);
    func_02049238(narc);
    narc=func_020490F4(46,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f24=func_0204ABF0(narc,0,1,96,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f30=func_0204A6C8(narc,26,0,1,((struct TaskObj *)p)->f0);
    *(int *)&((struct TaskObj *)p)->f3C=func_0204AF28(narc,18,22,((struct TaskObj *)p)->f0);
    func_02049238(narc);
    for(i=0;i<2;i++) {
        if(*(u16 *)(p+i*2+0x48)!=255) {
            format=func_021F4F70((int *)func_021F4F54(table,*(u16 *)(p+i*2+0x48)));
            if(i==0) configs[1].x=32;
            else configs[1].x=224;
            configs[1].y=160;
            configs[1].index=i;
            configs[1].a=10;
            configs[1].b=0;
            *(void **)(p+i*4+0x4c)=func_0204B294((void *)*(u32 *)&((struct TaskObj *)p)->f18,((struct TaskObj *)p)->f28.u,((struct TaskObj *)p)->f1C.u,((struct TaskObj *)p)->f34.u,&configs[1],1,((struct TaskObj *)p)->f0);
            configs[1].index=0;
            *(void **)(p+i*4+0x54)=func_0204B294((void *)*(u32 *)&((struct TaskObj *)p)->f18,((struct TaskObj *)p)->f2C.u,((struct TaskObj *)p)->f20.u,((struct TaskObj *)p)->f38.u,&configs[1],1,((struct TaskObj *)p)->f0);
            func_0204B3DC(*(void **)(p+i*4+0x4c),0);
            func_0204B3DC(*(void **)(p+i*4+0x54),0);
            func_021FA99C((u8 *)p,i,*(u16 *)(p+i*2+0x48),format);
        }
    }
    configs[0].x=128; configs[0].y=96; configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct TaskObj *)p)->f5C=func_0204B294((void *)*(u32 *)&((struct TaskObj *)p)->f18,((struct TaskObj *)p)->f30.u,((struct TaskObj *)p)->f24.u,((struct TaskObj *)p)->f3C.u,&configs[0],1,((struct TaskObj *)p)->f0);
    func_0204B3DC(((struct TaskObj *)p)->f5C,0);
    func_0204B92C(((struct TaskObj *)p)->f5C,1);
}









/*
 * note 2026-10-05: copies a tile sheet into VRAM in 4-byte pieces (block x line x column).
 * func_0204ABBC returns a pointer (the matched ov119 021E6E7C and ov131 021DBCF4 use it so),
 * which removed the old prototype blocker. Levers: locals declared in the order of the
 * frame slots (dst, block, height, line, y, x, src), u16 slot (puts its entry spill first),
 * u8 height, case 50 reads x = y, and y = 0 written after the blob call (literal 0 in it).
 */
void func_021FA99C(u8 *p,u16 slot,int resource,u32 type)
{
    int blob;
    u32 charSize,palSize;
    u8 *dst;
    u8 block;
    u8 height;
    u8 line;
    u32 y;
    u32 x;
    u8 *src;
    u8 *tex;
    u32 palOffset;
    u8 col;
    blob=func_0204A1BC(45,resource,0,*(u16 *)p);
    y=0;
    tex=func_0206E964((unsigned char *)blob);
    src=tex+*(u32 *)(tex+20);
    charSize=*(u16 *)(tex+12)*8;
    palOffset=*(u32 *)(tex+0x38);
    palSize=*(u16 *)(tex+0x30)*8;
    dst=(u8 *)func_0204ABBC(*(u32 *)(p+0x28),1);
    dst+=(slot<<11);
    func_020862F0(tex+palOffset,palSize);
    func_0207E5D0(tex+palOffset,slot*32,palSize);
    func_020862F0(src,charSize);
    switch(type) {
    case 34: x=2; y=2; type=4; height=4; break;
    case 35: x=2; type=4; height=8; break;
    case 50: x=y; y=2; type=8; height=4; break;
    default: x=2; y=2; type=4; height=4; break;
    }
    for(block=0;block<height;block++) {
        for(line=0;line<8;line++) {
            for(col=0;col<type;col++) {
                func_0207E804(src+(col*4+(block*32*type+line*type*4)),dst+(line*4+((col+x)*32+((block+y)*256))),4);
            }
        }
    }
    func_020307B0((void *)blob);
}









void func_021FAAB8(char *p, unsigned flag)
{
    if (((struct TaskObj *)p)->f48 != 255) {
        func_0204B3DC(((struct TaskObj *)p)->f4C, flag);
        func_0204B3DC(((struct TaskObj *)p)->f54, flag);
    }
    if (((struct TaskObj *)p)->f4A != 255) {
        func_0204B3DC(((struct TaskObj *)p)->f50, flag);
        func_0204B3DC(((struct TaskObj *)p)->f58, flag);
    }
    ((struct TaskObj *)p)->fC.u = flag;
}









void *func_021FAAF4(u32 heap, void *owner)
{
    u8 i;
    char *p;
    i = 0;
    p = func_02030734(heap, 0x44, 0, d_021FDCEC, 0x3f);
    ((struct Obj05398 *)p)->f0 = heap;
    ((struct Obj05398 *)p)->f34 = owner;
    ((struct Obj05398 *)p)->f8 = func_02030734(((struct Obj05398 *)p)->f0, func_02030CB0(16), 0, d_021FDCEC, 0x43);
    ((struct Obj05398 *)p)->f4 = func_02030CBC(16, ((struct Obj05398 *)p)->f8);
    func_02060468((int)(p + 0x38), 0);
    for (; i < 10; i++) *(void **)(p + 0xc + i * 4) = 0;
    return p;
}









void func_021FAB58(char *p)
{
    u8 i;
    char **slot;
    void *cur;
    void *next;
    for (i = 0; i < 10; i++) {
        slot = (char **)(p + i * 4);
        if (slot[3] != 0) {
            func_02011290(((struct ScriptEntry *)(slot[3]))->f4);
            func_02011264(((struct ScriptEntry *)(slot[3]))->f4);
            if (((struct ScriptEntry *)(slot[3]))->f16 & 8) func_020307B0(((struct ScriptEntry *)(slot[3]))->fC);
            func_020307B0(slot[3]);
            slot[3] = 0;
        }
    }
    cur = func_02060614((struct DList *)(p + 0x38), 0);
    while (cur != 0) {
        next = func_02060614((struct DList *)(p + 0x38), cur);
        func_021FADF8(p, cur);
        cur = next;
    }
    func_02030DA4(((struct Obj06492 *)p)->f4);
    func_020307B0(((struct Obj06492 *)p)->f8);
    func_020307B0(p);
}









/*
 * note: two bytes of zero padding follow the epilogue before 021FAC74.
 */
void func_021FABD8(char *p)
{
    char **slot;
    u8 i;
    int ready;
    int count;
    ready = 1;
    count = func_021F9E44(((struct ScriptOwner *)p)->f34);
    while (count != 0) {
        for (i = 0; i < 10; i++) {
            slot = (char **)(p + i * 4);
            if (slot[3] != 0) {
                if (func_021FAD2C(p, slot[3]) == 1) {
                    func_020307B0(slot[3]);
                    slot[3] = 0;
                } else {
                    if ((((struct ScriptEntry *)(slot[3]))->f16 & 2) && !(((struct ScriptEntry *)(slot[3]))->f16 & 4)) ready = 0;
                }
            }
        }
        if (ready == 1) {
            for (i = 0; i < 10; i++) {
                char *q;
                q = *(char **)(p + 0xc + i * 4);
                if (q != 0 && (((struct TargetBank *)q)->f16 & 2) && (((struct TargetBank *)q)->f16 & 4)) ((struct TargetBank *)q)->f16 ^= 4;
            }
        }
        func_02030D28(((struct ScriptOwner *)p)->f4);
        count--;
    }
}









void *func_021FAC74(char *p, void *arg, int flag)
{
    u8 i;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) == 0) break;
    ((char **)(p + 0xc))[i] = func_02030734(((struct ScriptOwner *)p)->f0, 0x1c, 0, d_021FDCEC, 0xc4);
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f8 = arg;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->fC = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f14 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f10 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f16 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f18 = 0;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f19 = i;
    if (flag == 1) ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f16 |= 2;
    *(char **)((char **)(p + 0xc))[i] = p;
    ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4 = func_0201121C(((struct ScriptOwner *)p)->f0, (const struct ScriptVmParams *)d_021FDC2C);
    func_0201126C(((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4, ((char **)(p + 0xc))[i]);
    func_0201127C(((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f4, ((struct ScriptEntry *)(((char **)(p + 0xc))[i]))->f8);
    return ((char **)(p + 0xc))[i];
}









char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag)
{
    char *q = func_021FAC74(p, base + *(unsigned *)(base + index * 4), 0);
    *(char * *)&((struct TargetBank *)q)->fC = base;
    ((struct TargetBank *)q)->f16 |= 8;
    ((struct TargetBank *)q)->f18 = flag;
    return q;
}









int func_021FAD2C(void *unused, char *p)
{
    if (((struct TargetBank *)p)->f14 != 0) (((struct TargetBank *)p)->f14)--;
    if (((struct TargetBank *)p)->f14 == 0 && !(((struct TargetBank *)p)->f16 & 4)) {
        func_02011298(((struct TargetBank *)p)->f4);
        if (((struct TargetBank *)p)->f16 & 1) {
            func_02011290(((struct TargetBank *)p)->f4);
            func_02011264(((struct TargetBank *)p)->f4);
            if (((struct TargetBank *)p)->f16 & 8) func_020307B0(((struct TargetBank *)p)->fC);
            return 1;
        }
    }
    (((struct TargetBank *)p)->f10)++;
    return 0;
}









/*
 * note: unlabelled follower in 021FAD2C extent; counts ten nonnull slots.
 */
u8 func_021FAD7C(char *p)
{
    u8 i;
    u8 count;
    count = 0;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) != 0) count++;
    return count;
}









void *func_021FADA0(char *p, u32 fn, u32 arg, u32 key)
{
    char *q;
    q = func_02030734(((struct ScriptOwner *)p)->f0, 16, 0, d_021FDCEC, 0x115);
    ((struct ScriptOwner *)q)->fC = func_02030DA8(((struct ScriptOwner *)p)->f4, fn, arg, key);
    if (((struct ScriptOwner *)q)->fC != 0) {
        ((struct ScriptOwner *)q)->f8 = arg;
        func_020604AC(p + 0x38, q);
        return q;
    }
    func_020307B0(q);
    return 0;
}









void func_021FADF8(char *p, char *q)
{
    func_020307B0(((struct Obj02192 *)q)->f8);
    func_02030EAC(((struct Obj02192 *)q)->fC);
    func_020605B4((volatile struct DList *)(p + 0x38), q);
    func_020307B0(q);
}










int func_021FAE1C(char *p, int *out)
{
    int start;
    int delta;
    ((struct ScriptTask *)p)->fE += 1;
    if (((struct ScriptTask *)p)->fE >= ((struct ScriptTask *)p)->fC) {
        *out = ((struct ScriptTask *)p)->f8.s;
        return 1;
    }
    start = ((struct ScriptTask *)p)->f4.s;
    delta = ((struct ScriptTask *)p)->f8.s - start;
    *out = start + (delta * ((struct ScriptTask *)p)->fE) / ((struct ScriptTask *)p)->fC;
    return 0;
}









int func_021FAE4C(char *p, int *out)
{
    int v;
    (((struct ScriptOwner *)p)->f2A)++;
    if (((struct ScriptOwner *)p)->f2A >= ((struct ScriptOwner *)p)->f28) {
        out[0] = ((struct ScriptOwner *)p)->f10;
        out[1] = ((struct ScriptOwner *)p)->f14;
        out[2] = ((struct ScriptOwner *)p)->f18;
        return 1;
    }
    if (((struct ScriptOwner *)p)->f2A != 0) v = (int)(0.5f + (float)(((struct ScriptOwner *)p)->f2A << 12));
    else v = (int)((float)(((struct ScriptOwner *)p)->f2A << 12) - 0.5f);
    func_0207CEE4(v, p + 0x1c, p + 4, out);
    return 0;
}









/*
 * note: extent ends with two bytes of zero alignment padding.
 */
int func_021FAEA8(char *p, void *out)
{
    int v[3];
    func_021F8044(func_021F9DA0(((struct Obj06489 *)p)->f0), (u32 *)(((struct Obj06489 *)p)->f4), (u32 *)v);
    func_0207C9D0((const Vec *)v, (const Vec *)(p + 8), (Vec *)out);
    (((struct Obj06489 *)p)->f16)++;
    if (((struct Obj06489 *)p)->f16 >= ((struct Obj06489 *)p)->f14) return 1;
    return 0;
}










/*
 * follower: func_021FAF10 at 0x021FAF10
 */
int func_021FAEE8(char *p)
{
    ((struct ScriptSlot *)p)->f4.u += 1;
    if (((struct ScriptSlot *)p)->f4.u >= ((struct ScriptSlot *)p)->f8.u) {
        ((struct ScriptSlot *)p)->fC -= 1;
        ((struct ScriptSlot *)p)->f4.u = 0;
        if (((struct ScriptSlot *)p)->fC == 0) return 2;
        return 1;
    }
    return 0;
}










int func_021FAF10(void *unused, char *p)
{
    ((struct ScriptCtx *)p)->f16 = 1 | ((struct ScriptCtx *)p)->f16;
    return 1;
}









int func_021FAF1C(void *a, char *p)
{
    func_0201134C(((struct ScriptCtx *)p)->f4.p);
    return 0;
}










/*
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the +0006 call now attests as
 * `matched`.  The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int func_021FAF28(void *a, u8 *p)
{
    ((struct ScriptCtx *)p)->f14 = (u16)func_0201134C(((struct ScriptCtx *)p)->f4.p);
    return 1;
}










/*
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the call now attests as `matched`.
 * The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * Addresses are Black-image addresses.
 */
int func_021FAF38(void *a, u8 *p)
{
    int v = func_0201134C(((struct Obj06492 *)p)->f4);
    if (((struct Obj06492 *)p)->f10 >= (u32)v)
        return 0;
    ((struct Obj06492 *)p)->f14 = (u16)(v - ((struct Obj06492 *)p)->f10);
    return 1;
}










int func_021FAF54(int a, char *b)
{
    func_0201134C(((struct ActingRecord *)b)->f4);
    if (((struct ActingRecord *)b)->f16 & 2)
        ((struct ActingRecord *)b)->f16 |= 4;
    return 1;
}









int func_021FAF70(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    wait = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    p = func_02030734(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1a4);
    *(char * *)&((struct ScriptTask *)p)->f10 = owner;
    ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
    ((struct ScriptTask *)p)->fE = 0;
    ((struct ScriptTask *)p)->f4.s = func_021F9DFC(((struct ScriptOwner *)owner)->f34);
    ((struct ScriptTask *)p)->f8.s = 224;
    delta = 224 - ((struct ScriptTask *)p)->f4.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->fC = delta / 2;
    ((struct ScriptTask *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
        return 1;
    }
    return 0;
}









int func_021FAFDC(void *unused, char *ctx)
{
    char *owner;
    char *p;
    int wait;
    int delta;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    wait = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    p = func_02030734(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1c1);
    *(char * *)&((struct ScriptTask *)p)->f10 = owner;
    ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
    ((struct ScriptTask *)p)->fE = 0;
    ((struct ScriptTask *)p)->f4.s = func_021F9DFC(((struct ScriptOwner *)owner)->f34);
    ((struct ScriptTask *)p)->f8.s = 0;
    delta = ((struct ScriptTask *)p)->f8.s - ((struct ScriptTask *)p)->f4.s;
    if (delta < 0) delta = -delta;
    ((struct ScriptTask *)p)->fC = delta / 2;
    ((struct ScriptTask *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
    func_021F96D0(((struct ScriptOwner *)owner)->f34);
    if (wait == 1) {
        ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
        return 1;
    }
    return 0;
}









int func_021FB050(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    time = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    target = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    wait = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    if (time == 0) {
        func_021F9E00(((struct ScriptOwner *)owner)->f34, target);
    } else {
        p = func_02030734(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x1e9);
        *(char * *)&((struct ScriptTask *)p)->f10 = owner;
        ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
        ((struct ScriptTask *)p)->fE = 0;
        ((struct ScriptTask *)p)->f4.s = func_021F9DFC(((struct ScriptOwner *)owner)->f34);
        ((struct ScriptTask *)p)->f8.s = target;
        ((struct ScriptTask *)p)->fC = time;
        ((struct ScriptTask *)p)->f14 = func_021FADA0(owner, (u32)func_021FB0DC, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
            return 1;
        }
    }
    return 0;
}









void func_021FB0DC(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E00(((struct ScriptTask *)p)->f0, v);
    if (done == 1) func_021FADF8(*(char * *)&((struct ScriptTask *)p)->f10, *(char * *)&((struct ScriptTask *)p)->f14);
}









int func_021FB104(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct ScriptCtx *)ctx)->f0;
    time = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    target = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    wait = func_0201134C(((struct ScriptCtx *)ctx)->f4.p);
    if (time == 0) {
        func_021F9E08(((struct ScriptOwner *)owner)->f34, target);
    } else {
        p = func_02030734(((struct ScriptOwner *)owner)->f0, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct ScriptTask *)p)->f10 = owner;
        ((struct ScriptTask *)p)->f0 = ((struct ScriptOwner *)owner)->f34;
        ((struct ScriptTask *)p)->fE = 0;
        ((struct ScriptTask *)p)->f4.s = func_021F9E04(((struct ScriptOwner *)owner)->f34);
        ((struct ScriptTask *)p)->f8.s = target;
        ((struct ScriptTask *)p)->fC = time;
        ((struct ScriptTask *)p)->f14 = func_021FADA0(owner, (u32)func_021FB190, (u32)p, 10);
        if (wait == 1) {
            ((struct ScriptCtx *)ctx)->f14 = ((struct ScriptTask *)p)->fC;
            return 1;
        }
    }
    return 0;
}









void func_021FB190(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E08(((struct ScriptTask *)p)->f0, v);
    if (done == 1) {
        func_021F9E40(((struct ScriptTask *)p)->f0, 0);
        func_021FADF8(*(char * *)&((struct ScriptTask *)p)->f10, *(char * *)&((struct ScriptTask *)p)->f14);
    }
}









int func_021FB1C0(void *unused,char *p) { func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); return 0; }










int func_021FB1CC(int a, char **pp)
{
    char *p = *pp;

    func_021F9D80(((struct ScriptOwner *)p)->f34);
    func_021F9AD8(((struct ScriptOwner *)p)->f34, 0, 0);
    return 0;
}










int func_021FB1E4(void *a, void **pp)
{
    func_021F9D90(((struct ScriptOwner *)((u8 *)*pp))->f34);
    return 0;
}










int func_021FB1F4(char *p, int i)
{
    if (i == -1)
        return ((struct ScriptCtx *)p)->f18;
    return 1 << i;
}









int func_021FB208(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    int value;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    value = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80D4(ctx, func_021F9DA4(((struct ScriptOwner *)obj)->f34, i), value);
        }
    }
    return 0;
}









/*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 */
int func_021FB258(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    value = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            char *slot;
            int flag;
            slot = func_021F9DA4(((struct ScriptOwner *)obj)->f34, i);
            flag = 0;
            if (value != 0) flag = 1;
            func_021F812C((int)ctx, (int *)slot, flag);
        }
    }
    return 0;
}









int func_021FB2B0(int unused,char *p)
{
    int mask;
    char *owner,*q,*target;
    Vec pos;
    int delta[3];
    u32 wait,z,y,x,rate;
    char *ctx;
    u8 i;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    mask=func_021FB1F4(p,func_0201134C(((struct ScriptCtx *)p)->f4.p));
    rate=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    x=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    y=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    z=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    wait=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx=func_021F9DA0(((struct ScriptOwner *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(((struct ScriptOwner *)owner)->f34,i);
            if (rate==0) {
                pos.x=x;pos.y=y;pos.z=z;
                func_021F8054(ctx,(u32 *)target,(const u32 *)(&pos));
            } else {
                q=func_02030734(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x2DA);
                *(char * *)&((struct Obj02192 *)q)->f30=owner;
                *(char * *)&((struct Obj02192 *)q)->f0=target;
                ((struct Obj02192 *)q)->f4=((struct ScriptOwner *)owner)->f34;
                ((struct Obj02192 *)q)->f2E=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                ((struct Obj02192 *)q)->f14=x;((struct Obj02192 *)q)->f18=y;((struct Obj02192 *)q)->f1C=z;
                ((struct Obj02192 *)q)->f2C=rate;
                func_0207CA00(q+20,q+8,delta);
                ((struct Obj02192 *)q)->f20=delta[0]/(int)rate;
                ((struct Obj02192 *)q)->f24=delta[1]/(int)rate;
                ((struct Obj02192 *)q)->f28=delta[2]/(int)rate;
                ((struct Obj02192 *)q)->f34=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->f14=rate;return 1;}
    return 0;
}









static inline void vset(Vec *v,Coord x,Coord y,Coord z)
{
    v->x=x;v->y=y;v->z=z;
}









#pragma opt_loop_invariants off









/*
 * pass 2 2026-10-06 P2L34: EXACT in --lang c99 and --lang c. The last 23 bytes were spill slots:
 *   with loop invariant motion on, x,y,z (each used two or three times inside the loop) got new
 *   loop webs and fell below the other spills.  for this function
 *   keeps them as declared locals, and the slots then follow declaration order
 *   (mask, x, y, z, wait / i, ctx).
 */
int func_021FB3E0(int unused,char *p)
{
    int mask;
    Coord x,y,z;
    char *owner;
    int rate;
    Coord wait;
    owner=*(char **)p;
    mask=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
    rate=func_0201134C(*(void **)(p+4));
    x=func_0201134C(*(void **)(p+4));
    y=func_0201134C(*(void **)(p+4));
    z=func_0201134C(*(void **)(p+4));
    wait=func_0201134C(*(void **)(p+4));
    {
    u8 i;
    void *ctx;
    char *q,*target;
    u32 pos[3];
    ctx=func_021F9DA0(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(*(void **)(owner+52),i);
            if (rate==0) {
                func_021F8044(ctx,(u32 *)target,pos);
                pos[0]+=x;pos[1]+=y;pos[2]+=z;
                func_021F8054(ctx,(u32 *)target,pos);
            } else {
                q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x31B);
                *(char **)(q+48)=owner;
                *(char **)q=target;
                *(void **)(q+4)=*(void **)(owner+52);
                *(u16 *)(q+46)=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                vset((Vec *)(q+20),*(int *)(q+8)+x,*(int *)(q+12)+y,*(int *)(q+16)+z);
                *(u16 *)(q+44)=rate;
                *(int *)(q+32)=(int)x/(int)rate;
                *(int *)(q+36)=(int)y/(int)rate;
                *(int *)(q+40)=(int)z/(int)rate;
                *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}









#pragma opt_loop_invariants reset









/*
 * lever: Void callback return omits the extra zero result instruction.
 */
void func_021FB528(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DA0(((struct Obj06492 *)p)->f4); result=func_021FAE4C(p+4,pos); func_021F8054(ctx,*(unsigned int * *)&((struct Obj06492 *)p)->f0,(unsigned int *)pos); if(result==1)func_021FADF8(((struct Obj06492 *)p)->f30,((struct Obj06492 *)p)->f34); }









int func_021FB55C(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80B0(ctx, func_021F9DA4(((struct ScriptOwner *)obj)->f34, i));
        }
    }
    return 0;
}









int func_021FB5A4(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80A0((int)ctx, func_021F9DA4(((struct ScriptOwner *)obj)->f34, i));
        }
    }
    return 0;
}








/*
 * note: func_021F80C8 is called with a u8 third parameter (its matched unit declares unsigned int; the narrowing is loop-invariant and hoisted).
 * note: older draft in docs/notes/pkt_ov132_021FB5EC.c.txt (DIFF6) is superseded.
 */
int func_021FB5EC(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = func_021FB1F4(p, func_0201134C(*(void **)(p + 4)));
    value = func_0201134C(*(void **)(p + 4));
    ctx = func_021F9DA0(*(char **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80C8((int)ctx, func_021F9DA4(*(char **)(obj + 0x34), i), value);
        }
    }
    return 0;
}








int func_021FB640(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    value = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F8140((int)ctx, func_021F9DA4(((struct ScriptOwner *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}








int func_021FB698(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    value = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F8154((int)ctx, func_021F9DA4(((struct ScriptOwner *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}








int func_021FB6F0(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    ctx = func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F9DA4(((struct ScriptOwner *)obj)->f34, i);
            func_021F9D18(((struct ScriptOwner *)obj)->f34, i);
        }
    }
    return 0;
}








/*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 */
int func_021FB738(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char * *)&((struct ScriptCtx *)p)->f0; mask=func_021FB1F4(p,func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4)); for(i=0;i<4;i++)if((1<<i)&mask)func_021F95CC(*(char * *)&((struct ScriptOwner *)obj)->f34,i,1); return 0; }








int func_021FB774(int unused,char *p) { char *obj; obj=*(char * *)&((struct ScriptCtx *)p)->f0; func_021F95CC(*(char * *)&((struct ScriptOwner *)obj)->f34,0,0);func_021F95CC(*(char * *)&((struct ScriptOwner *)obj)->f34,1,0);func_021F95CC(*(char * *)&((struct ScriptOwner *)obj)->f34,2,0);func_021F95CC(*(char * *)&((struct ScriptOwner *)obj)->f34,3,0);return 0; }








/*
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 */
int func_021FB7A4(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char * *)&((struct ScriptCtx *)p)->f0;index=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);n=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);func_021F9140(*(unsigned char * *)&((struct ScriptOwner *)obj)->f34,n,index);func_021F9AD8(*(char * *)&((struct ScriptOwner *)obj)->f34,1,index);return 0; }








int func_021FB7D8(int unused,char *p) { char *obj; int mask; unsigned int n; obj=*(char * *)&((struct ScriptCtx *)p)->f0;mask=func_021FB1F4(p,func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4));n=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);func_021F91A8((char *)(*(unsigned char * *)&((struct ScriptOwner *)obj)->f34),n,mask);return 0; }







/*
 * note: task allocation is 32 bytes; the product local reproduces count-first multiply scheduling.
 */
int func_021FB808(int unused, char *p)
{
    char *obj;
    int mask, wait, amplitude, duration, count;
    u8 i;
    TaskData *data;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct ScriptCtx *)p)->f4.p));
    duration = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    count = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    amplitude = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    wait = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    func_021F9DA0(((struct ScriptOwner *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            data = func_02030734(((struct ScriptOwner *)obj)->f0, 0x20, 0, d_021FDD00, 0x443);
            data->owner = obj;
            data->slot = func_021F9DA4(((struct ScriptOwner *)obj)->f34, i);
            data->amplitude = amplitude;
            data->context = ((struct ScriptOwner *)obj)->f34;
            data->tick = 0;
            data->duration = duration;
            data->count = count;
            data->task = func_021FADA0(obj, (u32)func_021FB8CC, (u32)data, 10);
        }
    }
    if (wait == 1) {
        int product;
        product = count;
        product *= duration;
        ((struct ScriptCtx *)p)->f14 = product;
        return 1;
    }
    return 0;
}







void func_021FB8CC(int unused, char *p)
{
    void *ctx;
    ctx = func_021F9DA0(((struct ScriptSlot *)p)->f0);
    if (func_021FAEE8(p) == 2) {
        Vec zero = { 0, 0, 0 };
        func_021F8084(ctx, ((struct ScriptSlot *)p)->f10, (const u32 *)(&zero));
        func_021FADF8(((struct ScriptSlot *)p)->f18.p, ((struct ScriptSlot *)p)->f1C.p);
        return;
    }
    else {
        Vec v;
        int sine;
        v.x = 0;
        sine = d_020A1B38[((int)(((u32)((struct ScriptSlot *)p)->f4.s << 15) / (u32)((struct ScriptSlot *)p)->f8.s) >> 4) * 2];
        v.y = -(int)(((long long)sine * ((struct ScriptSlot *)p)->f14.s + 0x800) >> 12);
        v.z = 0;
        func_021F8084(ctx, ((struct ScriptSlot *)p)->f10, (const u32 *)(&v));
    }
}







int func_021FB948(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    mask=func_021FB1F4(p,func_0201134C(((struct ScriptCtx *)p)->f4.p));
    rate=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    start=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    delta=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    wait=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    func_021F9DA0(((struct ScriptOwner *)owner)->f34);
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=func_02030734(((struct ScriptOwner *)owner)->f0,36,0,d_021FDD00,0x493);
            *(char * *)&((struct ScriptTask *)q)->f1C=owner;
            ((struct ScriptTask *)q)->f18.p=func_021F9DA4(((struct ScriptOwner *)owner)->f34,i);
            ((struct ScriptTask *)q)->f0=((struct ScriptOwner *)owner)->f34;
            ((struct ScriptTask *)q)->f4.u=start;
            ((struct ScriptTask *)q)->f8.u=start+delta;
            ((struct ScriptTask *)q)->fC=rate;
            ((struct ScriptTask *)q)->fE=0;
            ((struct ScriptTask *)q)->f20=func_021FADA0(owner,(u32)func_021FBA14,(u32)q,10);
        }
    }
    if(wait==1) {((struct ScriptCtx *)p)->f14=rate;return 1;}
    return 0;
}








/*
 * note:     the bl to 0x021F8068 named an unlabelled leaf in the co-resident
 *           ov112 (ov112 0x021F36C0..0x021F8480 abuts ov132 0x021F8480..);
 *           it was filed EXACT as src/matched/ov112_func_021F8068.c, so the
 *           site now attests as `matched` and every concrete byte reproduces.
 *           EXACT* only because the inferred extent runs into an unlabelled
 *           follower in ov132; there is no byte difference.
 */
void func_021FBA14(int a0, int *a1)
{
    int r4 = (int)func_021F9DA0((char *)a1[0]);
    int local;
    if (func_021FAE1C((char *)a1, &local) == 1) {
        func_021F8068(r4, (char *)a1[6], (u16)func_0209C0A4(a1[2] << 16, 0x168));
        func_021FADF8((char *)a1[7], (char *)a1[8]);
    } else {
        func_021F8068(r4, (char *)a1[6], (u16)func_0209C0A4(local << 16, 0x168));
    }
}





int func_021FBA6C(int unused, Msg *m)
{
    Obj_021FBA6C *o = m->f0;
    u32 vec[4];
    Vec3 v;
    Tag tag;
    u32 x = func_0201134C(m->f4);
    u32 y = func_0201134C(m->f4);
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








int func_021FBD78(int unused, char *p)
{
    int a, b, c, d;
    a = func_0201134C(((struct ScriptTask *)p)->f4.p);
    b = func_0201134C(((struct ScriptTask *)p)->f4.p);
    c = func_0201134C(((struct ScriptTask *)p)->f4.p);
    d = func_0201134C(((struct ScriptTask *)p)->f4.p);
    ((struct ScriptTask *)p)->f18.b = 0;
    if (a == 1) ((struct ScriptTask *)p)->f18.b += 1;
    if (b == 1) ((struct ScriptTask *)p)->f18.b += 2;
    if (c == 1) ((struct ScriptTask *)p)->f18.b += 4;
    if (d == 1) ((struct ScriptTask *)p)->f18.b += 8;
    return 0;
}








/*
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 */
int func_021FBDCC(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct ScriptCtx *)p)->f0;a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);entry=func_021F6B18(func_021F9DAC(((struct ScriptOwner *)obj)->f34),b);func_021F9DB8(((struct ScriptOwner *)obj)->f34,entry,(unsigned char)a);return 0; }








/*
 * extent: Two bytes of zero alignment padding follow the 54-byte body.
 */
int func_021FBE00(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=func_021F9DAC(((struct ScriptOwner *)obj)->f34);func_021F6B80(ctx,func_021F9DB0(((struct ScriptOwner *)obj)->f34,n));func_021F9DB8(((struct ScriptOwner *)obj)->f34,0,(unsigned char)n);return 0; }








int func_021FBE38(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=func_021F9DAC(((struct ScriptOwner *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct ScriptOwner *)obj)->f34,n),1);return 0; }








int func_021FBE64(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct ScriptCtx *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);ctx=func_021F9DAC(((struct ScriptOwner *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct ScriptOwner *)obj)->f34,n),0);return 0; }








int func_021FBE90(int unused,char *p)
{
    char *owner,*q;
    u32 pos[3];
    int delta[3];
    u32 e,d,c,b,a;
    u32 *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    b=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    c=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    d=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    e=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx=func_021F9DAC(((struct ScriptOwner *)owner)->f34);
    target=func_021F9DB0(((struct ScriptOwner *)owner)->f34,a);
    if (b==0) {
        pos[0]=c;pos[1]=d;pos[2]=e;
        func_021F6B9C(ctx,target,pos);
    } else {
        q=func_02030734(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x601);
        *(char * *)&((struct Obj02192 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02192 *)q)->f0=target;
        ((struct Obj02192 *)q)->f4=((struct ScriptOwner *)owner)->f34;
        ((struct Obj02192 *)q)->f2E=0;
        func_021F6BB0(ctx,target,(u32 *)(q+8));
        ((struct Obj02192 *)q)->f14=c;((struct Obj02192 *)q)->f18=d;((struct Obj02192 *)q)->f1C=e;
        ((struct Obj02192 *)q)->f2C=b;
        func_0207CA00(q+20,q+8,delta);
        ((struct Obj02192 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02192 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02192 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02192 *)q)->f34=func_021FADA0(owner,(u32)func_021FBF74,(u32)q,10);
    }
    return 0;
}








void func_021FBF74(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=func_021F9DAC(((struct Obj06492 *)p)->f4);result=func_021FAE4C(p+4,pos);func_021F6B9C(ctx,*(unsigned int * *)&((struct Obj06492 *)p)->f0,(unsigned int *)pos);if(result==1)func_021FADF8(((struct Obj06492 *)p)->f30,((struct Obj06492 *)p)->f34);}








/*
 * prototype: Own 021F9EDC source takes u16; original caller passes the
 * full word b+0x33 without truncation, so the extern parameter is widened.
 */
int func_021FBFA8(int unused,char *p) { char *obj; unsigned int a,b; char *entry;obj=*(char * *)&((struct ScriptCtx *)p)->f0;a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4);entry=func_021F9EDC(func_021F9DC0(((struct ScriptOwner *)obj)->f34),b+0x33);func_021F9DCC(((struct ScriptOwner *)obj)->f34,entry,(unsigned char)a);return 0; }








int func_021FBFDC(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); ctx=func_021F9DC0(((struct ScriptOwner *)o)->f34); func_021F9F58(ctx,func_021F9DC4(((struct ScriptOwner *)o)->f34,a)); func_021F9DCC(((struct ScriptOwner *)o)->f34,0,(u8)a); return 0; }








int func_021FC014(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    Vec vec;
    obj = *(char * *)&((struct ScriptCtx *)p)->f0;
    a = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    b = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    c = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    d = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    e = func_0201134C(((struct ScriptCtx *)p)->f4.p);
    target = func_021F9DC4(((struct ScriptOwner *)obj)->f34, (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    func_021F9F74((char *)target, (u16)b, &vec);
    return 0;
}








int func_021FC080(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); func_021F9FB4(func_021F9DC4(((struct ScriptOwner *)o)->f34,a),(u16)b); return 0; }








int func_021FC0AC(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    b=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    c=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    d=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    e=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    f=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    g=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    h=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    i=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    j=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    target=func_021F9DC4(((struct ScriptOwner *)owner)->f34,a);
    q=func_02030734(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x691);
    *(char * *)&((struct Obj01741 *)q)->f30=owner;
    ((struct Obj01741 *)q)->f10=target;
    ((struct Obj01741 *)q)->f2C=b;
    ((struct Obj01741 *)q)->f14=e;
    ((struct Obj01741 *)q)->f18=f;
    ((struct Obj01741 *)q)->f1C=g;
    ((struct Obj01741 *)q)->f20=h-e;
    ((struct Obj01741 *)q)->f24=i-f;
    ((struct Obj01741 *)q)->f28=j-g;
    ((struct Obj01741 *)q)->f0=((struct ScriptOwner *)owner)->f34;
    ((struct Obj01741 *)q)->f4=0;
    ((struct Obj01741 *)q)->f8=c;
    ((struct Obj01741 *)q)->fC=d;
    ((struct Obj01741 *)q)->f34=func_021FADA0(owner,(u32)func_021FC178,(u32)q,10);
    return 0;
}








void func_021FC178(int a, char *p)
{
    u32 v[3];
    int s;
    s=func_021FAEE8(p);
    if(s==2) {
        func_021FADF8(((struct ScriptSlot *)p)->f30,((struct ScriptSlot *)p)->f34);
        return;
    }
    if(s==1) {
        v[0]=(((struct ScriptSlot *)p)->f14.u+func_02005728((u32)(((struct ScriptSlot *)p)->f20)))>>4;
        v[1]=(0xc0000-(((struct ScriptSlot *)p)->f18.u+func_02005728((u32)(((struct ScriptSlot *)p)->f24))))>>4;
        v[2]=((struct ScriptSlot *)p)->f1C.u+func_02005728((u32)(((struct ScriptSlot *)p)->f28));
        func_021F9F74((char *)((struct ScriptSlot *)p)->f10,((struct ScriptSlot *)p)->f2C,(Vec *)v);
    }
}








int func_021FC1D4(int a,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=func_0201134C((struct Cursor *)p[1]);
    y=func_0201134C((struct Cursor *)p[1]);
    r=func_021F9DD4(((struct ScriptOwner *)q)->f34);
    s=func_021F6E78(r,1);
    func_021F6F14(r,s,0x3ff,0x10);
    func_021F6F1C(r,s,y,0);
    func_021F9DE8(((struct ScriptOwner *)q)->f34,s,x);
    func_021F95E8(((struct ScriptOwner *)q)->f34);
    return 0;
}








int func_021FC22C(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); ctx=func_021F9DD4(((struct ScriptOwner *)o)->f34); func_021F6EE4(ctx,func_021F9DDC(((struct ScriptOwner *)o)->f34,a)); func_021F9DE8(((struct ScriptOwner *)o)->f34,0,a); func_021F95E8(((struct ScriptOwner *)o)->f34); return 0; }








int func_021FC268(int unused,char *p)
{
    char *owner,*q;
    Vec pos;
    int delta[3];
    u32 e,d,c,b,a;
    void *target;
    void *ctx;
    owner=*(char * *)&((struct ScriptCtx *)p)->f0;
    a=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    b=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    c=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    d=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    e=func_0201134C(((struct ScriptCtx *)p)->f4.p);
    ctx=func_021F9DD4(((struct ScriptOwner *)owner)->f34);
    target=func_021F9DDC(((struct ScriptOwner *)owner)->f34,a);
    if (b==0) {
        pos.x=c;pos.y=d;pos.z=e;
        func_021F6EF4(ctx,target,(const u32 *)(&pos));
    } else {
        q=func_02030734(((struct ScriptOwner *)owner)->f0,56,0,d_021FDD00,0x704);
        *(char * *)&((struct Obj02192 *)q)->f30=owner;
        *(u32 * *)&((struct Obj02192 *)q)->f0=target;
        ((struct Obj02192 *)q)->f4=((struct ScriptOwner *)owner)->f34;
        ((struct Obj02192 *)q)->f2E=0;
        func_021F6F04(ctx,target,(Vec *)(q+8));
        ((struct Obj02192 *)q)->f14=c;((struct Obj02192 *)q)->f18=d;((struct Obj02192 *)q)->f1C=e;
        ((struct Obj02192 *)q)->f2C=b;
        func_0207CA00(q+20,q+8,delta);
        ((struct Obj02192 *)q)->f20=delta[0]/(int)b;
        ((struct Obj02192 *)q)->f24=delta[1]/(int)b;
        ((struct Obj02192 *)q)->f28=delta[2]/(int)b;
        ((struct Obj02192 *)q)->f34=func_021FADA0(owner,(u32)func_021FC34C,(u32)q,10);
    }
    return 0;
}








void func_021FC34C(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(((struct Obj06492 *)p)->f4); result=func_021FAE4C(p+4,pos); func_021F6EF4(ctx,*(u32 * *)&((struct Obj06492 *)p)->f0,(u32 *)pos); if(result==1) func_021FADF8(*(char * *)&((struct Obj06492 *)p)->f30,*(char * *)&((struct Obj06492 *)p)->f34); }








int func_021FC380(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char * *)&((struct ScriptCtx *)p)->f0;
 a=func_0201134C(((struct ScriptCtx *)p)->f4.p);
 b=func_021FB1F4(p,func_0201134C(((struct ScriptCtx *)p)->f4.p));
 c=func_0201134C(((struct ScriptCtx *)p)->f4.p);
 d=func_0201134C(((struct ScriptCtx *)p)->f4.p);
 e=func_0201134C(((struct ScriptCtx *)p)->f4.p);
 f=func_0201134C(((struct ScriptCtx *)p)->f4.p);
 ctx=func_021F9DD4(((struct ScriptOwner *)owner)->f34);
 target=func_021F9DDC(((struct ScriptOwner *)owner)->f34,a);
 scene=func_021F9DA0(((struct ScriptOwner *)owner)->f34);
 duration=c;
 for(i=0;i<4;i++) {
  obj=func_021F9DA4(((struct ScriptOwner *)owner)->f34,i);
  if(b&(1<<i)) {
   if(c==0) {
    func_021F8044(scene,obj,(u32 *)(&pos));
    delta.x=d;delta.y=e;delta.z=f;
    func_0207C9D0(&pos,&delta,&pos);
    func_021F6EF4(ctx,target,(const u32 *)(&pos));
   } else {
    func_021F9DF4(((struct ScriptOwner *)owner)->f34);
    q=func_02030734(((struct ScriptOwner *)owner)->f0,0x30,0,d_021FDD00,0x74D);
    *(char * *)&((struct Obj02487 *)q)->f28=owner;
    ((struct Obj02487 *)q)->f0=i;
    ((struct Obj02487 *)q)->f4=target;
    ((struct Obj02487 *)q)->f8=((struct ScriptOwner *)owner)->f34;
    ((struct Obj02487 *)q)->fC=obj;
    ((struct Obj02487 *)q)->f1E=0;
    ((struct Obj02487 *)q)->f10=d;((struct Obj02487 *)q)->f14=e;((struct Obj02487 *)q)->f18=f;
    ((struct Obj02487 *)q)->f1C=duration;
    ((struct Obj02487 *)q)->f2C=func_021FADA0(owner,(u32)func_021FC490,(u32)q,7);
   }
  }
 }
 return 0;
}








void func_021FC490(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(((struct Obj06492 *)p)->f8); func_021F9DF4(((struct Obj06492 *)p)->f8); result=func_021FAEA8(p+8,pos); func_021F6EF4(ctx,*(u32 * *)&((struct Obj06492 *)p)->f4,(u32 *)pos); if(result==1) func_021FADF8(*(char * *)&((struct Obj06492 *)p)->f28,*(char * *)&((struct Obj06492 *)p)->f2C); }








/*
 * follower: two-byte zero alignment padding at 021FC53A.
 */
int func_021FC4CC(int a,char **p)
{
    char *q;
    u32 v,w,x,y,z;
    void *r,*s;
    q=p[0];
    v=func_0201134C((struct Cursor *)p[1]);
    w=func_0201134C((struct Cursor *)p[1]);
    x=func_0201134C((struct Cursor *)p[1]);
    y=func_0201134C((struct Cursor *)p[1]);
    z=func_0201134C((struct Cursor *)p[1]);
    r=func_021F9DD4(((struct ScriptOwner *)q)->f34);
    s=func_021F9DDC(((struct ScriptOwner *)q)->f34,v);
    func_021F6F14(r,s,(u8)w|((u8)x<<5)|((u8)y<<10),z);
    return 0;
}








int func_021FC53C(int unused,char *p) { char *o; u32 a,b; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); func_021F93D8(*(u8 * *)&((struct ScriptOwner *)o)->f34,a,b); return 0; }








int func_021FC560(void *a, void **pp)
{
    func_021F94B0(((struct ScriptOwner *)((u8 *)*pp))->f34);
    return 0;
}







int func_021FC570(int unused,char *p) { u32 a,b,c; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); c=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); func_0201DD78((u8)a,(u8)b,(u8)c); return 0; }








int func_021FC5A0(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    func_021F9664(((struct ScriptOwner *)p)->f34, (unsigned short)x);
    return 0;
}








int func_021FC5BC(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    func_021F9680(((struct ScriptOwner *)p)->f34, (unsigned short)x);
    return 0;
}








int func_021FC5D8(int a, char **pp)
{
    func_021F9690(((struct ScriptOwner *)(*pp))->f34);
    return 0;
}







int func_021FC5E8(int unused,char *p) { char *o; u32 a,b,c; o=*(char * *)&((struct ScriptCtx *)p)->f0; a=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); b=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); c=func_0201134C(*(struct Cursor * *)&((struct ScriptCtx *)p)->f4); func_021F969C(*(char * *)&((struct ScriptOwner *)o)->f34,(u16)a,(u16)b,(u16)c); return 0; }








int func_021FC61C(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C((struct Cursor *)(((struct ScriptCtx *)pp)->f4.s));

    func_021F96B0(((struct ScriptOwner *)p)->f34, x);
    return 0;
}








int func_021FC634(int a, char **pp)
{
    func_021F96C4(((struct ScriptOwner *)(*pp))->f34);
    return 0;
}







void func_021FC644(int a, void *b, void *c, int d)
{
    char *p;
    p = func_02030734(4, 0x1ac, 1, d_021FDE5C, 0x14c);
    ((struct ActingHost *)p)->fC = d;
    ((struct ActingHost *)p)->f54 = b;
    ((struct ActingHost *)p)->f58 = func_020120F4(b);
    ((struct ActingHost *)p)->f50 = c;
    ((struct ActingHost *)p)->f4 = 0;
    ((struct ActingHost *)p)->f8 = 0;
    func_020263D8(c, 4, (u32)p);
}







void func_021FC684(char *p) { func_021FCA38(p); func_02026400(*(struct Comm * *)&((struct ActingHost *)p)->f50); }







void *func_021FC694(int a,char *p)
{
    ((struct ScriptCtx *)p)->f5C=func_02012944(((struct ScriptCtx *)p)->f58);
    if(((struct ScriptCtx *)p)->fC==1) d_021FDE4C[5]=4;
    else {
        d_021FDE4C[5]=0;
        func_0203CBAC((struct Req *)d_021FDDEC,(u32)func_021FCAA0,(u32)p);
    }
    func_02008494(((struct ScriptCtx *)p)->f5C,p+0x20);
    func_02087C6C(p+0x40);
    ((struct ScriptCtx *)p)->f46=0x3a0b;
    return p;
}







/*
 * 0203D1B4's forwarding matched void declaration loses its live result.
 * 0203D7BC retains the original caller's unused zero argument.
 */
int func_021FC6EC(int *state,u8 *p)
{
 switch(*state) {
 case 0:
  if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(((struct ActingHost *)p)->fC==1) func_0203A5E4(0x1100);
  if(((struct ActingHost *)p)->f8==1) {func_0203D7BC(0);func_021FCDEC((int)p,0x41);*state=1;}
  else *state=2;
  break;
 case 1:
  if(func_021FCE00((char *)p,0x41)==1) *state=2;
  if(func_0203D1B4()<=1 || func_0200FB24()!=0) *state=10;
  break;
 case 2:
  if(((struct ActingHost *)p)->f8==0) {func_0203CEAC(0);return 1;}
  if(func_0203D378()==0) {
   if(func_0203D3A8(func_020399A8(),1,0,0)==1) return 1;
  } else if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(func_0200FB24()!=0) *state=10;
  break;
 case 10:
  if(func_0200FB24()!=0) func_02012124(*(struct Ctx * *)&((struct ActingHost *)p)->f54,1);
  func_0203CEAC(0);return 1;
 }
 return 0;
}







int func_021FC7DC(int unused,int unused1,void *p) { if(func_0203CDBC()==1) {func_020307B0(p);return 1;} return 0; }







void func_021FC7F8(int unused,int unused1,char *p) { func_021FCAA8(p); }







void func_021FC804(char *p) { if(func_0203D378()==1) ((struct ActingHost *)p)->f48=1; else ((struct ActingHost *)p)->f48=2; }







void func_021FC81C(char *p) { func_0203A574(0x1100,(u32)d_021FDC38,9,(u32)p); if(func_0203D378()==1) ((struct ActingHost *)p)->f48=1; else ((struct ActingHost *)p)->f48=2; }







static inline void clear8(void *dest,u32 size)
{
 func_02082BCC(dest,0,size);
}







/*
 * 02012F44 returns the live pointer from its forwarding target 020071CC;
 * its matched void prototype discards that result.
 * Lever: row is block-local; the final fill has a per-entry pointer.
 * The SDK MI_CpuClear8 inline spelling restores both fill-call setup orders
 * (direct MI_CpuFill8 leaves 15 bytes; data/size signedness changes are flat).
 */
void func_021FC848(u8 *p,void *a,void *b,int unused,void *d,u16 heap)
{
 void *data;
 u32 size1,size2;
 u8 i,j;
 data=func_02012F44(P(p,0x58));
 ((struct ActingHost *)p)->f0=heap;
 for(i=0;i<4;i++) {
  u8 *row;
  row=p+i*0x30;
  W(row,0x60)=0;
  row[0x72]=i;
  W(row,0x78)=0;
  W(row,0x64)=0;W(row,0x68)=0;W(row,0x6C)=0;
  row[0x70]=10;row[0x71]=10;
  P(row,0x7C)=func_02030734(((struct ActingHost *)p)->f0,func_020173EC()+0x7C,0,d_021FDE5C,0x20E);
  size1=func_02008468();
  P(row,0x8C)=func_02030734(((struct ActingHost *)p)->f0,(size1+4)+func_020173E8(),0,d_021FDE5C,0x20F);
  clear8(P(row,0x7C),func_020173EC()+0x7C);
  size2=func_02008468();
  clear8(P(row,0x8C),(size2+4)+func_020173E8());
  P(row,0x80)=P(row,0x8C);
  P(row,0x84)=P(row,0x8C)+4;
  P(row,0x88)=P(row,0x8C)+4+func_02008468();
  for(j=0;j<2;j++) row[0x73+j]=0xFF;
 }
 ((struct ActingHost *)p)->f12C=func_0200A81C(data);
 ((struct ActingHost *)p)->f130=a;((struct ActingHost *)p)->f134=b;
 W(p,0x138)=0;W(p,0x124)=0;
 P(p,0x128)=func_02030734(((struct ActingHost *)p)->f0,(func_020173EC()+0x7C)*4,0,d_021FDE5C,0x221);
 size1=func_02008468();
 P(p,0x13C)=func_02030734(((struct ActingHost *)p)->f0,((size1+4)+func_020173E8())*4,0,d_021FDE5C,0x222);
 p[0x1C]=0;W(p,0x14)=0;W(p,0x18)=0;
 p[0x14C]=0;W(p,0x150)=0;
 W(p,0x158)=0;W(p,0x15C)=0;W(p,0x160)=0;W(p,0x164)=0;
 W(p,0x168)=0;W(p,0x170)=0;W(p,0x174)=0;W(p,0x17C)=0;
 W(p,0x184)=0;W(p,0x188)=0;
 p[0x180]=4;
 W(p,8)=1;
 for(j=0;j<8;j++) {
  u8 *entry=p+j*4;
  W(entry,0x18C)=0xFFFF;
 }
 ((struct ActingHost *)p)->f140.p=d;
 W(p,0x4C)=1;
}







void func_021FCA38(char *p)
{
    u8 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*0x30;
        if(((struct ActingScene *)q)->f7C) {
            func_020307B0(((struct ActingScene *)q)->f8C);
            func_020307B0(((struct ActingScene *)q)->f7C);
        }
    }
    if(((struct ActingHost *)p)->f124) func_020307B0(((struct ActingHost *)p)->f124);
    if(((struct ActingHost *)p)->f138) func_020307B0(((struct ActingHost *)p)->f138);
    if(((struct ActingHost *)p)->f128) func_020307B0(((struct ActingHost *)p)->f128);
    if(((struct ActingHost *)p)->f13C) func_020307B0(((struct ActingHost *)p)->f13C);
}







void func_021FCAA0(char *p)
{
    ((struct ActingScene *)p)->f10=1;
}






static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * n) >> 32;
}






/*
 * note 2026-10-05: state machine on p+0x4c (22-entry jump table; cases 20 and 21 are explicit
 * so the table keeps its size). Players are a 0x30-byte struct array at p+0x64. The final
 * packed-id draw is a 64-bit multiply high (_ull_mul) through an inline helper; the id is
 * added into sum (sum += list[k] << 16) before the call, which fixed the last 2 bytes.
 * Callees 021FD84C, 021FCEA8 and 021FD350 are void in their matched files but the caller
 * tests r0 == 1: their last call (a u32-returning arm9 function) leaves the result in r0,
 * so the originals return it. They are declared with return values here. Callee 021FD14C
 * and 021FD400 have no source yet (symbols resolve as labels).
 */
void func_021FCAA8(char *p)
{
    u8 i, j, n;
    u8 cnt;
    u8 list[4];
    u32 v;
    u32 ok;
    if (func_0200FB24()) {
        *(int *)(p + 4) = 1;
        if (func_0203CDBC() == 0) func_0203CEAC(0);
    }
    if (*(int *)(p + 4) == 1) return;
    switch (*(u32 *)(p + 0x4c)) {
    case 0:
        return;
    case 1:
        func_0203D7BC(1);
        func_021FCDEC((int)p, 0x46);
        *(int *)(p + 0x4c) = 2;
        break;
    case 2:
        if (func_021FCE00(p, 0x46) == 1 && func_021FD14C((Owner_021F9E40 *)p) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 3;
            else *(int *)(p + 0x4c) = 5;
        }
        break;
    case 3:
        if (func_021FD84C((u8 *)p) == 1) *(int *)(p + 0x4c) = 4;
        break;
    case 4:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].b == 1) cnt++;
        if (cnt == func_0203D1B4() && func_021FD22C(p) == 1) *(int *)(p + 0x4c) = 5;
        break;
    case 6:
        if (func_021FCE00(p, 0x40) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 7;
            else *(int *)(p + 0x4c) = 0xb;
        }
        break;
    case 7:
        if (func_021FCEA8((int)p, 8, *(u32 *)(p + 0x144), 0xff) == 1) *(int *)(p + 0x4c) = 8;
        break;
    case 8:
        if (func_021FCEA8((int)p, 9, *(u32 *)(p + 0x148), 0xff) == 1) *(int *)(p + 0x4c) = 9;
        break;
    case 9:
        if (func_021FD6C8((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xa;
        break;
    case 10:
        if (*(int *)(p + 0x164) == 1 && func_021FD704((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xb;
        break;
    case 12:
        if (func_021FCE00(p, 0x42) == 1) {
            if (*(int *)(p + 0x48) == 1) {
                if (func_021FD6DC(p) == 1) *(int *)(p + 0x4c) = 0xd;
            } else *(int *)(p + 0x4c) = 0x11;
        }
        break;
    case 13:
        if (*(int *)(p + 0x168) == 1 && func_021FD6F0(p) == 1) *(int *)(p + 0x4c) = 0xe;
        break;
    case 14:
        if (*(int *)(p + 0x16c) == 1 && func_021FD76C((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xf;
        break;
    case 15:
        if (*(int *)(p + 0x174) == 1 && func_021FD7D4((u8 *)p) == 1) *(int *)(p + 0x4c) = 0x10;
        break;
    case 16:
        *(int *)(p + 0x4c) = 0x11;
        break;
    case 17:
        if (*(int *)(p + 0x178) == 1) func_021FD6A4(p);
        break;
    case 18:
        if (func_021FD350(p, (char *)(*(u32 *)(p + 0x120))) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 0x13;
            else *(int *)(p + 0x4c) = 0x15;
        }
        break;
    case 19:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct G *)p)->pl[i].a == 1) cnt++;
        if (cnt == func_0203D1B4() && func_021FD400(p) == 1) *(int *)(p + 0x4c) = 0x15;
        break;
    case 20:
    case 21:
        break;
    default:
        break;
    }
    if (*(int *)(p + 0x184) == 1) {
        v = 0;
        v += ((struct G *)p)->pl[0].e;
        v += ((struct G *)p)->pl[1].e << 4;
        v += ((struct G *)p)->pl[2].e << 8;
        v += ((struct G *)p)->pl[3].e << 12;
        if (func_021FCEA8((int)p, 3, v, 0xff) == 1) *(int *)(p + 0x184) = 0;
    }
    {
        u32 sum = 0;
        n = 0;
        for (i = 0; i < 4; i++) {
            if (((struct G *)p)->pl[i].c == 1) {
                list[n] = i;
                n++;
            }
            sum += ((struct G *)p)->pl[i].d << (i * 4);
        }
        if (n != 0) {
            u32 k = random_below(n);
            sum += list[k] << 16;
            if (func_021FCEA8((int)p, 0xb, sum, 0xff) == 1) {
                for (j = 0; j < n; j++) {
                    ((struct G *)p)->pl[list[j]].c = 0;
                    ((struct G *)p)->pl[list[j]].d = 10;
                }
            }
        }
    }
    if (*(int *)(p + 0x188) == 1) {
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (*(u32 *)(p + i * 4 + 0x18c) != 0xFFFF) {
                if (func_021FCEA8((int)p, 0xc, *(u32 *)(p + i * 4 + 0x18c), 0xff) == 1) *(u32 *)(p + i * 4 + 0x18c) = 0xFFFF;
                ok = 0;
            }
        }
        if (ok == 1) *(int *)(p + 0x188) = 0;
    }
    func_021FD550(p);
}







void func_021FCDEC(int a, int b)
{
    func_02039C68((struct Link *)func_020399A8(), b, 0x11);
}






int func_021FCE00(char *p,int id) {if(func_02039CB4((struct Link *)func_020399A8(),id,0x11)==1)return 1;if(((struct ActingHost *)p)->f4==1)return 1;return 0;}






int func_021FCE28(char *p,u32 index) {if(((struct ActingHost *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x84);return 0;}






int func_021FCE44(char *p,u32 index) {if(((struct ActingHost *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x88);return 0;}






char *func_021FCE60(char *p){return p+0x20;}






u32 func_021FCE64(void){return 40;}






int func_021FCE68(int a,int b){if(a==b)return 1;return 0;}






void func_021FCE74(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=func_020399A8();request.kind=kind;request.value=value;func_0203D3F8((u32)e,id,0x1100,8,(u32)&request,1,0,0);}






u32 func_021FCEA8(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=func_0203996C(255);request.kind=kind;request.value=value;return func_0203D3F8((u32)e,id,0x1100,8,(u32)&request,1,0,0);}






void func_021FCEDC(unsigned long slot, int unused, const Packet *q, char *p)
{
  u8 i;
  u8 t;
  u8 code;
  u8 index;
  u8 item;
  u32 mask;
  u32 v;
  u32 tmp;
  u32 tmp1;
  switch (q->tag)
  {
    case 0:
      *((u32 *) (p + 0x18)) = 1;
      break;

    case 1:
      mask = 15;
      for (i = 0; i < 4; i++)
    {
      *((u8 *) ((p + (i * 0x30)) + 0x72)) = (q->data & mask) >> (i * 4);
      mask <<= 4;
    }

      break;

    case 2:
      *((u32 *) ((p + (slot * 0x30)) + 0x78)) = q->data;
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x184)) = 1;
      break;

    case 3:
      if ((*((u32 *) (p + 0x48))) != 1)
    {
      v = q->data;
      *((u32 *) (p + 0x78)) = v & 15;
      *((u32 *) (p + 0xa8)) = (v & 0xf0) >> 4;
      *((u32 *) (p + 0xd8)) = (v & 0xf00) >> 8;
      *((u32 *) (p + 0x108)) = (v & 0xf000) >> 12;
    }
      break;

    case 4:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 4)) = func_02030734(4, q->data, 0, d_021FDE5C, 0x4c4);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x20)) = q->data;
    }
      *((u32 *) (p + 0x164)) = 1;
      break;

    case 5:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 8)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4cd);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x24)) = q->data;
    }
      *((u32 *) (p + 0x168)) = 1;
      break;

    case 6:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 12)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4d6);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x28)) = q->data;
    }
      *((u32 *) (p + 0x16c)) = 1;
      break;

    case 7:
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x17c)) = 3;
    else
    {
      *((void **) ((*((char **) (0x140 + p))) + 16)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4e3);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x2c)) = q->data;
    }
      break;

    case 8:
      *((u32 *) (p + 0x144)) = q->data;
      break;

    case 9:
      *((u32 *) (p + 0x148)) = q->data;
      break;

    case 10:
      if ((*((u32 *) (p + 0x48))) == 1)
    {
      *((u32 *) ((((u32) p) + (slot * 0x30)) + 0x6c)) = 1;
      *((u8 *) ((p + (slot * 0x30)) + 0x70)) = q->data;
    }
      break;

    case 11:
    {
      u8 t;
      u8 i;
      u32 mask;
      mask = 15;
      for (i = 0; i < 4; i++)
      {
        t = (q->data & mask) >> (i * 4);
        if (t != 10)
          *((u8 *) ((p + (i * 0x30)) + 0x71)) = t;
        mask <<= 4;
      }

      *((u8 *) (p + 0x180)) = (q->data & 0xf0000) >> 16;
      break;
    }

    case 12:
    {
      u8 i;
      int code;
      int item;
      u16 index;
      u32 v;
      v = q->data;
      code = (u8) ((v & 0xff0000) >> 16);
      index = (u8) ((v & 0xff00) >> 8);
      item = (u8) v;
      for (i = 0; i < 2; i++)
      {
        tmp1 = ((u32) p) + (index * 0x30);
        tmp1 = tmp1 + i;
        if ((*((u8 *) (tmp1 + 0x73))) == 255)
        {
          tmp = (u32) p;
          tmp = tmp + (index * 0x30);
          *((u8 *) ((tmp + i) + 0x73)) = item;
          break;
        }
      }

      if (code == 1)
        func_020061E4(0x62c);
      else
        if (code == 2)
        func_020061E4(0x62b);
      break;
    }

  }

}




/*
 * followers: unlabelled leaves begin at 021FD208 and 021FD218 (not part of this function; function body is 188 bytes).
 * note 2026-10-05 (wave P13 lane B5): 6/188 bytes differ, all register colour: the allocation result q is in r6 and q+4 (s) in r4, the original has q r4, s r6 (m2 r7, p r5 match). Callee types checked (02008468 int, 020173E8 u32, 02030734 returns void*, 0203D3F8 u32, caller compares result with 1). Tried, all the same 6 bytes: separate locals for the first size pair; one variable reused for the first size and q; both q and s as u32; q typed as header struct with s = q->data; s declared before q; s set before or after p->buffer store and after m; s = q; s += 4; m+s order; sizes in block locals; all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole). Without a local s (q+4 written at each use) the 0x4e<<2 offset is hoisted and 121 bytes differ; p->buffer instead of q is worse (123). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, array-bases-as-pointer-locals-reopen-a-flat-declaration-order.
 * recoup 2026-10-05 P29R10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). New tries, all the same 6 bytes unless noted: q=p->buffer=alloc chain; s=q+4 before m; m reusing a; int sizes; reversed and regrouped declaration orders (7 layouts, no effect); q as u32* with s=(char*)(q+1); q as header struct with s=q->data; const void* source in func_02082D44; q and s as u32; a+b+4 order (15 bytes). Worse: s=p->buffer+4 (110), plus copy from p->buffer (123), no s local with q+4 / q+4+m / q+m+4 (121), s after first copy (125), s set at the call (125), s before p->buffer store (25). No twin in src/matched/ov (callees 02030734+02082D44+020173E8 share no file). Idioms re-read: two-long-lived-values-in-each-others-registers, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.
 * final push 2026-10-05 G2L10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). Analysis: q and s interfere, equal cost, so the tie is the simplify order; s (later vreg) is coloured first. With q+4 written at each use q does get r4 but the 0x4e<<2 offset is hoisted (121 bytes), so the named s is right. New tries, all the same 6 bytes unless noted: s=q+4 before m (24 bytes); declaration orders s,q and m,b,a; block-scoped a/b/q and m/s with initialisers; sizes inlined in the alloc call; p->buffer=q=alloc; s=p->buffer then if(s) free (and q likewise); opt_lifetimes+opt_propagation off together; q void* with (char*)q+4; q u32 with s char*; q char* with s u32; static inline halloc wrapper (0x533 as a line argument); static inline fill(p,q,m) for the three copies; u16 heap local (178); first/second pointers as locals (128); inline bufsize() for both size sums (63). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, const-on-a-read-only-source-parameter-settles-a-register-tie. Twins: ov132 021FD350 and 021FC848 (same callees, no matching shape); mwcc ALLOCATOR_CASEBOOK is PPC but says vreg birth order decides ties.
 * pass 2 2026-10-06 P2L12: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 39 compiles. New tries, all 6 bytes unless noted: local names; s reused for the 020399A8 result with a/b reused for the final sizes (with and without opt_lifetimes off); opt_lifetimes off with declaration orders s,q and m,s,b,q,a; named size locals for the copies and t=s+m; 02082D44(void*,void*,int) with int a/m; s assigned inside the first copy's argument list; s from a static inline Data(q); alloc in a static inline Alloc(p,size); register on q or s; char *const q and s in nested blocks; sibling 021FD350 form (char *p with casts, n reused, h local) with named s. Worse: cursor forms q+=4/q+=m, s=q;s+=4, q++ or q+=4 in the call argument (62 to 67): any second definition frees r7 and hoists the 0x138 offset. Coloring.c (mwcc_ref): select pops the simplify stack, so the order of q vs s comes from vreg numbering or degree; declaration order has no effect here. Assembly hits checked (adds r1,rX,#0 then adds rY,rX,#K before a call): ov010 0216787A, ov093 021C462E, ov116 021D6DF4, ov172 021B7350, all loop copies, no match.
 * pass 3 2026-10-06 P3L06: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 40 compiles. New tries, all 6 bytes unless noted: zero local (021FD350 style); s=&q[4] and &s[m]; p->buffer=alloc then q=p->buffer (store forwarded); full sibling style (int n, m reused for every size pair, h local); u8 and u16 return for 02008468 with u8/u16 m; long m and long a,b,m; s+=m in the third copy argument; 4+q and m+s; m reusing b; separate old local for the free guard; Owner *const p; opt_loop_invariants off; opt_strength_reduction off; opt_propagation off with t=alloc, s=t+4, q=t (q born after s); inline Header(p,q) returning s; inline Pack(p,q) with m and s inside; inline Copy wrapper; m/s inner block without initialisers (both orders); a/b/q inner block to the first copy; c99 mid-block declarations; local aggregates {head,body} (both orders) and {head,first,second} (021FC848 row style). Worse: first copy from s-4 (120, q and s merge); q+4+m with named s (121); inline Pack(p,q,q+4,m) (121, s propagated). Diagnostics: removing m or s gives q r4 first, so only the q/s/m clique orders s first; dsi 1.1, 1.2, 1.2p2 give the same 6 bytes. Asm scan (adds rLow,rX,#0 plus adds rY,rX,#K before a call): only ov198 02210E20 (matched, base=p+4 from a parameter, not applicable). Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register, a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register, a-no-code-self-assignment-reorders-the-register-colouring (stand-in, not used), declaration-position-orders-block-scope-colouring, a-width-stored-in-the-handle-temp-it-replaces-keeps-the-original-colours, two-long-lived-values-in-each-others-registers (callees read no hidden arguments).
 * pass 4 2026-10-06 P4L04: EXACT* (--lang c99 and --lang c). The third block pointer is computed up front as t=q+4+func_02008468() and the second copy writes to q+4 with no named s: CSE turns the shared q+4 into a temp born before the first copy, and t is forward-substituted into the third copy as temp+m, which gives the image colours (q r4, q+4 r6, size r7). Same layout as the row pointers in 021FC848 (P(row,0x88)=buf+4+func_02008468()).
 */
u32 func_021FD14C(Owner_021F9E40 *p)
{
    u32 a, b;
    char *q, *t;
    if(p->buffer) func_020307B0(p->buffer);
    a=func_02008468();
    b=func_020173E8();
    q=func_02030734(p->heap,a+4+b,0,d_021FDE5C,0x533);
    p->buffer=q;
    t=q+4+func_02008468();
    func_02082D44(&p->value,q,4);
    func_02082D44(p->first,q+4,func_02008468());
    func_02082D44(p->second,t,func_020173E8());
    return func_0203D3F8((u32)func_020399A8(),0xff,0x1101,func_02008468()+4+func_020173E8(),(u32)p->buffer,1,0,1);
}


void func_021FD208(int i, int b, int c, T *p) { p->e[i].w[2] = 1; p->e[i].w[0] = 1; }


u32 func_021FD218(int i, T *p) { p->e[i].w[2] = 0; return p->e[i].w[11]; }



int func_021FD22C(char *p)
{
    u8 i;
    u32 n;
    u32 m;
    char *q;
    u32 k;
    void *h;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char * *)&((struct ActingHost *)p)->f13C;
        k=i*(m+4+n);
        m=func_02008468();
        n=func_020173E8();
        func_02082D44(*(void **)(p+i*0x30+0x8c),q+k,m+4+n);
    }
    h=func_0203996C(0xff);
    m=func_02008468();
    n=func_020173E8();
    return func_0203D3F8((u32)h,0xff,0x1102,(m+4+n)*4,(u32)(((struct ActingHost *)p)->f13C),1,0,1);
}




/*
 * follower: loop leaf filed as ov132_func_021FD328.c.
 */
void func_021FD2B8(int a,int b,int c,char *p)
{
    u8 i;
    int n;
    u32 m,k;
    char *q,*s;
    int flag;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char * *)&((struct ActingHost *)p)->f13C;
        k=i*(m+4+n);
        m=func_02008468();
        n=m+4+func_020173E8();
        s=p+i*0x30;
        func_02082D44(q+k,((struct ActingScene *)s)->f8C,n);
        flag=func_020084BC(((struct ActingScene *)s)->f84)==0 ? 1 : 0;
        ((struct ActingScene *)s)->f60=flag;
        ((struct ActingScene *)s)->f68=flag;
    }
    ((struct ActingHost *)p)->f158=1;
}




void *func_021FD328(int a,char *p)
{
    u8 i;
    for(i=0;i<4;i++) *(int *)(p+i*0x30+0x68)=0;
    ((struct ActingHost *)p)->f158=0;
    return ((struct ActingHost *)p)->f13C;
}



/*
 * followers: larger leaves 021FD3D8 and 021FD3F0 filed separately.
 */
int func_021FD350(char *p, char *src)
{
    char *q;
    void *h;
    u32 n;
    int zero;
    if(((struct ActingHost *)p)->f124) func_020307B0(((struct ActingHost *)p)->f124);
    n=func_020173EC();
    q=func_02030734(((struct ActingHost *)p)->f0,n+0x7c,0,d_021FDE5C,0x5be);
    zero=0;
    ((struct ActingHost *)p)->f124=q;
    func_02082D44(src,q,0x7c);
    n=func_020173EC();
    q+=0x7c;
    func_02082D44(((struct Obj23284 *)src)->f4,q,n);
    h=func_020399A8();
    n=func_020173EC();
    return func_0203D3F8((u32)h,0xff,0x1103,n+0x7c,(u32)(((struct ActingHost *)p)->f124),1,zero,1);
}



/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 * padding: two zero bytes at 021FD3EE before 021FD3F0.
 */
void func_021FD3D8(long i,int b,int c,struct Context *p)
{
    char *s;
    p->rec[i].flag=1;
    s=p->rec[i].data;
    ((struct Obj23285 *)s)->f4=s+0x7c;
}



/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 */
void *func_021FD3F0(long i,struct Context *p)
{
    p->rec[i].flag=0;
    return p->rec[i].data;
}



/*
 * note: 2026-10-05 recoup: the copy length is a plain call result plus 0x7c, written the same way as the
 *   first call's n (n=f()+0x7c) and passed as n. The older draft passed n+0x7c inline and left adds r2/r1 swapped.
 */
int func_021FD400(const char *p)
{
    u8 i;
    u32 n;
    u32 k;
    u32 q;
    void *h;
    for(i=0;i<4;i++) {
        n=func_020173EC()+0x7c;
        q=*(u32 *)(p+0x128);
        k=i*n;
        n=func_020173EC()+0x7c;
        func_02082D44(*(void **)(p+i*0x30+0x7c),(void *)(q+k),n);
    }
    h=func_0203996C(0xff);
    n=func_020173EC();
    return func_0203D3F8((u32)h,0xff,0x1104,(n+0x7c)*4,*(u32 *)(p+0x128),1,0,1);
}



/*
 * note: 2026-10-05 length kept in a local before the call (n = f()+0x7c; call(q+k, src, n)); the inline n+0x7c form swapped two adds (4 B). Older DIFF notes superseded.
 */
void func_021FD470(int a,int b,int c,const Owner_021FD22C *p)
{
    u8 i;
    char *s;
    u32 k;
    char *q;
    u32 n;
    for(i=0;i<4;i++) {
        s=(char *)p+i*0x30;
        if(func_020084BC(*(u16 **)(s+0x84))==0) {
            n=func_020173EC()+0x7c;
            q=p->buffer;
            k=i*n;
            n=func_020173EC()+0x7c;
            func_02082D44(q+k,*(void **)(s+0x7c),n);
            q=*(char **)(s+0x7c);
            *(char **)(q+4)=q+0x7c;
            *(int *)(s+0x64)=1;
        } else *(int *)(s+0x64)=0;
    }
    *(int *)((char *)p+0x15c)=1;
}


/* Clears the flag of the four records, clears the word at +0x15C and returns the buffer pointer. */
typedef struct { char pad0[0x60]; struct Record rec[4]; char pad120[8]; char *buffer; char pad12c[0x30]; u32 tail; } Owner_021FD4D0;

char *func_021FD4D0(int a, Owner_021FD4D0 *p)
{
    u8 i;
    for (i = 0; i < 4; i++)
        p->rec[i].flag = 0;
    p->tail = 0;
    return p->buffer;
}
