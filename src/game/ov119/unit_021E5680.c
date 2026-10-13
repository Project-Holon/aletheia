/*
 * file:     unit_021E5680.c
 * unit:     yes
 * function: func_021E5680, func_021E57A4, func_021E57E8, func_021E57FC, func_021E5868, func_021E58A0, func_021E5958, func_021E5998, func_021E5B6C, func_021E5BE4, func_021E5C64, func_021E5D84, func_021E5DFC, func_021E5EF8, func_021E5F14, func_021E6008, func_021E60BC, func_021E625C, func_021E6294, func_021E62D4, func_021E6308, func_021E6334, func_021E6440, func_021E64B8, func_021E64DC, func_021E6544, func_021E665C, func_021E66E8, func_021E6700, func_021E6718, func_021E6790, func_021E67A8, func_021E67C4, func_021E67E0, func_021E68B4, func_021E68F4, func_021E69A4, func_021E69C0, func_021E6AB0, func_021E6B90
 * address:  0x021E5680
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021E7EE4 0x021E7EE4 data a4
 *   d_021E7F04 0x021E7F04 data a4
 *   d_021E7F64 0x021E7F64 data a4
 *   d_021E7E04 0x021E7E04 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   d_021E7D20 0x021E7D20 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049990 0x02049990 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040618 0x02040618 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_021E81D4 0x021E81D4 data a4
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_02027694 0x02027694 thumb
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   func_020276B4 0x020276B4 thumb
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   POKERUS_IsCured 0x0201B280 thumb
 *   func_020275E4 0x020275E4 thumb
 *   d_021E7EC4 0x021E7EC4 data a4
 *   d_021E7F84 0x021E7F84 data a4
 *   func_02049B40 0x02049B40 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   d_021E7D70 0x021E7D70 data a4
 *   d_021E7DA0 0x021E7DA0 data a4
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_0207C7B4 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021E7248 0x021E7248 thumb ov119
 *   func_021E729C 0x021E729C thumb ov119
 *   func_0207D63C 0x0207D63C arm
 *   d_021E7DEC 0x021E7DEC data a2
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_0204047C 0x0204047C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02049740 0x02049740 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   d_021E7E44 0x021E7E44 data a4
 *   POKERUS_IsInfected  0x0201B25C  thumb  arm9
 */
#include "pokemontrade_types.h"
#include "../../matched/include/Obj06428.h"
#include "../../matched/include/Obj10382.h"
#include "../../matched/include/Obj06429.h"
#include "../../matched/include/Obj08074.h"
#include "../../matched/include/Obj13925.h"
#include "../../matched/include/Obj22816.h"

struct DispConfig;
struct Obj;
struct Vec2;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Actor;
struct PtS;
struct Curve;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct { u16 x, y, z; u8 a, b; } Sprite;

typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;

typedef struct { u16 x, y; } Pos_021E5680;

typedef short s16;

typedef struct { u32 x, y; } Pos_021E5C64;

typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In_021E5680;

typedef struct { int f0,f4,f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In_021E6008;

typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;

typedef struct { int v[8]; } Coords;

typedef struct { int v[8][2]; } States;

typedef struct {
    char pad[0x1008];
    int h[2][3];
    int w[2][3];
} Work_021E5680;

typedef struct {
    char pad[0x1008];
    int h[2][3];
} Work_021E6308;

typedef struct { short x,y,z; u8 a,b; } Create;

typedef struct { short x,y; } Pt;

typedef signed long long s64;

typedef struct { int x,y,z; } T;

typedef struct { T a,b,c,d,e; int i,n; } S;

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad1[0x884-0x5f6];
    int g884;
    char pad2[0x898-0x888];
    int g898;
    char pad3[0x8b4-0x89c];
    int g8b4;
    char pad4[0x9c4-0x8b8];
    int g9c4;
    char pad5[0x10ac-0x9c8];
    int slot[8];
} Work;

typedef struct { Pt pos[6]; } Table;

extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32),func_02041300(u32,int,int,int,u8,u8,u8),func_020409B4(u32);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_0203FC28(struct DispConfig *cfg);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u8 func_020355C4(void);
extern void *func_021D8FA4(void *p, int a);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern u32 func_0201BA68(void *mon);
extern int POKE_TOOL_GetIconPalette(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32 bit);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern void UI_SCENE_LoadActorGfx(void *,In_021E5680 *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern u32 POKERUS_IsInfected(void *);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern unsigned int POKERUS_IsCured(void *a);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern u32 func_02017EAC(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern void *func_020185F0(void *);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern int func_0207C7B4(int);
extern void func_021E7248(S *,T *,T *,T *,T *,int);
extern int func_021E729C(struct Curve *c);
extern void func_0207D63C(int, int, int, int, int);
extern void CLACT_SetActorBgPriority(void *,unsigned int);
extern void func_0204047C(int,unsigned short);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
void func_021E5680(char *p);
void func_021E57A4(int p);
void func_021E57E8(int i);
void func_021E57FC(int p);
void func_021E5868(char *p);
void func_021E58A0(int p);
void func_021E5958(int p);
void func_021E5998(char *p);
void func_021E5B6C(int p, int b, int c);
void func_021E5BE4(int a);
void func_021E5C64(char *p);
void func_021E5D84(char *p);
void func_021E5DFC(char *p, int side, void *mon);
void func_021E5EF8(void *p);
void func_021E5F14(char *p, int side, int flag, void *mon);
void func_021E6008(char *p, int b, void *c);
void func_021E60BC(char *p,void *mon,int flag);
void func_021E625C(void *p);
void func_021E6294(char *p, int n, u32 x);
void func_021E62D4(Work_021E5680 *p, int a, int b);
void func_021E6308(Work_021E6308 *p, int a, int v);
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible);
void func_021E6440(int p, int a, int b);
void func_021E64B8(void *p);
void func_021E64DC(int p, int i, int j, int x, int y, void *q);
void func_021E6544(char *p);
int func_021E665C(char *p);
void func_021E66E8(void *p);
void func_021E6700(void *p);
void func_021E6718(char *p, int i);
void func_021E6790(void *p, int i, int a);
void func_021E67A8(void *p, int i);
void func_021E67C4(void *p, int i);
void func_021E67E0(Work *p, int z, int i);
void func_021E68B4(int p, int n);
void func_021E68F4(int p, int i);
void func_021E69A4(char *p);
int func_021E69C0(char *p);
void func_021E6AB0(const char *p);
void func_021E6B90(char *p);
extern const BgTemplate d_021E7EE4,d_021E7F04,d_021E7F64,d_021E7E04;
extern const char d_021E7D20[];
extern Pos_021E5C64 d_021E81D4[26];
extern const Coords d_021E7EC4;
extern const States d_021E7F84;
extern const int d_021E7D70[6][2];
extern const int d_021E7DA0[6][2];
extern const Table d_021E7DEC;
extern const BgTemplate d_021E7E44;







void func_021E5680(char *p)
{
 BgTemplate a,b,c,d;
 a=d_021E7EE4;func_0203FCA0(4,&a,0);func_02041300(4,0,0,0,32,24,17);
 b=d_021E7F04;func_0203FCA0(5,&b,0);func_02040C14(5,0,1,0);func_02041300(5,0,0,0,32,24,17);func_020409B4(5);
 c=d_021E7F64;func_0203FCA0(7,&c,0);func_02041300(7,0,0,0,64,24,17);func_020409B4(7);
 d=d_021E7E04;func_0203FCA0(6,&d,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 p[0x11eb]=1;
}







void func_021E57A4(int p)
{
    if (((TradeWork *)p)->f11EB == 1) {
        func_02040DA8(4, 1, 0);
        func_02040DA8(6, 1, 0);
        func_020403F4(4);
        func_020403F4(5);
        func_020403F4(6);
        func_020403F4(7);
        ((TradeWork *)p)->f11EB = 0;
    }
}







void func_021E57E8(int i)
{
    func_0203FC28((struct DispConfig *)(d_021E7D20 + i * 16));
}







void func_021E57FC(int p)
{
    void *a;
    if (((TradeWork *)p)->f898 == 0) {
        a = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f898 = CLACT_RegisterCharacter(a, 0x15, 0, 0, ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f884 = CLACT_RegisterPaletteEx(a, 0x12, 0, 0xc0, 0, 6, ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f8B4 = CLACT_RegisterCellAnim(a, 0x14, 0x13, ((TradeWork *)p)->f5F4);
        ARC_TOOL_DeleteHandle(a);
    }
}







void func_021E5868(char *p)
{
    if (((TradeWork *)p)->f898 != 0) {
        CLACT_ReleaseCharacter(((TradeWork *)p)->f898);
        CLACT_ReleasePalette(((TradeWork *)p)->f884);
        CLACT_ReleaseCellAnim(((TradeWork *)p)->f8B4);
        ((TradeWork *)p)->f898 = 0;
        ((TradeWork *)p)->f884 = 0;
        ((TradeWork *)p)->f8B4 = 0;
    }
}







void func_021E58A0(int p)
{
    void *a;
    Sprite s;
    a = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f894 = CLACT_RegisterCharacter(a, 0x18, 0, 1, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f880 = CLACT_RegisterPaletteEx(a, 0x12, 1, 0xc0, 0, 6, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f8B0 = CLACT_RegisterCellAnim(a, 0x17, 0x16, ((TradeWork *)p)->f5F4);
    ARC_TOOL_DeleteHandle(a);
    s.x = 0x80; s.y = 0xb4; s.z = 2; s.a = 0xe; s.b = 0;
    ((TradeWork *)p)->fF04 = (int)CLACT_CreateActor((void *)((TradeWork *)p)->f9C4, ((TradeWork *)p)->f894, ((TradeWork *)p)->f880, ((TradeWork *)p)->f8B0, &s, 1, ((TradeWork *)p)->f5F4);
    func_0204B92C((struct Obj *)((TradeWork *)p)->fF04, 0);
    func_0204B3DC((struct Obj *)((TradeWork *)p)->fF04, 1);
}







void func_021E5958(int p)
{
    void *a = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    func_02049990(a, (int)0x1d, (int)2, (int)0, (u16)(((TradeWork *)p)->f86C), (int)0, (int)0, ((TradeWork *)p)->f5F4);
    ARC_TOOL_DeleteHandle(a);
}







void func_021E5998(char *p)
{
    void *arc;
    void *a, *b;
    int z;
    ObjTmpl u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.prio = 0x13;
    u.pal = 0xe;
    u.mode = 1;
    ((TradeWork *)p)->fF08 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)(*(void * *)&((TradeWork *)p)->f894), (unsigned int)(*(void * *)&((TradeWork *)p)->f880),
        (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &u, 1, ((TradeWork *)p)->f5F4);
    func_0204B92C(((TradeWork *)p)->fF08, 1);
    func_0204B3DC(((TradeWork *)p)->fF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.prio = 0;
    u.pal = 0xb;
    u.mode = 1;
    (*(void * *)&((TradeWork *)p)->fF0C) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)(*(void * *)&((TradeWork *)p)->f894), (unsigned int)(*(void * *)&((TradeWork *)p)->f880),
        (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &u, 1, ((TradeWork *)p)->f5F4);
    func_0204B92C((*(void * *)&((TradeWork *)p)->fF0C), 1);
    if (func_020355C4()) {
        func_0204B3DC((*(void * *)&((TradeWork *)p)->fF0C), 0);
    }
    arc = func_020490F4(7, ((TradeWork *)p)->f5F4);
    z = 0;
    a = POKE_TOOL_GetBoxParam(func_021D8FA4(p, 0));
    b = POKE_TOOL_GetBoxParam(func_021D8FA4(p, 1));
    (*(void * *)&((TradeWork *)p)->f89C) = (void *)CLACT_RegisterCharacter(arc, func_0201BA68(a), z, 1, ((TradeWork *)p)->f5F4);
    (*(void * *)&((TradeWork *)p)->f8A0) = (void *)CLACT_RegisterCharacter(arc, func_0201BA68(b), z, 1, ((TradeWork *)p)->f5F4);
    t.x = 0x60;
    t.y = 0xc;
    t.prio = z;
    t.pal = 0xc;
    t.mode = 1;
    (*(void * *)&((TradeWork *)p)->fF10) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)(*(void * *)&((TradeWork *)p)->f89C), (unsigned int)((TradeWork *)p)->f87C,
        (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->f5F4);
    func_0204B92C((*(void * *)&((TradeWork *)p)->fF10), 0);
    func_0204B3DC((*(void * *)&((TradeWork *)p)->fF10), 1);
    func_0204B6F4((*(void * *)&((TradeWork *)p)->fF10), POKE_TOOL_GetIconPalette(a), 1);
    t.x = 0xa0;
    (*(void * *)&((TradeWork *)p)->fF14) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->f9C4), (unsigned int)(*(void * *)&((TradeWork *)p)->f8A0), (unsigned int)((TradeWork *)p)->f87C,
        (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->f5F4);
    func_0204B92C((*(void * *)&((TradeWork *)p)->fF14), 0);
    func_0204B3DC((*(void * *)&((TradeWork *)p)->fF14), 1);
    func_0204B6F4((*(void * *)&((TradeWork *)p)->fF14), POKE_TOOL_GetIconPalette(b), 1);
    ARC_TOOL_DeleteHandle(arc);
}







/*
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 */
void func_021E5B6C(int p, int b, int c)
{
    Pos_021E5680 pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        func_0204B404((struct Obj *)(((TradeWork *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        func_0204B404((struct Obj *)(((TradeWork *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        func_0204B404((struct Obj *)(((TradeWork *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        func_0204B404((struct Obj *)(((TradeWork *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    }
}








void func_021E5BE4(int a)
{
    if ((*(int *)&((TradeWork *)a)->fF08) != 0)
        CLACT_DeleteActor((struct Obj *)((*(int *)&((TradeWork *)a)->fF08)));
    if (((TradeWork *)a)->fF0C != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF0C));
    if (((TradeWork *)a)->fF10 != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF10));
    if (((TradeWork *)a)->fF14 != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF14));
    (*(int *)&((TradeWork *)a)->fF08) = 0;
    ((TradeWork *)a)->fF0C = 0;
    ((TradeWork *)a)->fF10 = 0;
    ((TradeWork *)a)->fF14 = 0;
    if (((TradeWork *)a)->f89C != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->f89C);
    if (((TradeWork *)a)->f8A0 != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->f8A0);
    ((TradeWork *)a)->f89C = 0;
    ((TradeWork *)a)->f8A0 = 0;
}







void func_021E5C64(char *p)
{
    u32 i;
    void *h;
    func_02040588(4, 0);
    func_02040588(6, 0);
    h = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    func_02049990(h, 16, 4, 0, (u16)(*(int *)&((TradeWork *)p)->f870), 0, 0, ((TradeWork *)p)->f5F4);
    func_02041B6C(4);
    func_02040618(4, 0, -4);
    func_02040618(6, 0, -4);
    ARC_TOOL_DeleteHandle(h);
    GF_FONT_SetTextColor(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)BMP_WIN_Create(6, (u8)d_021E81D4[i].x, (u8)d_021E81D4[i].y, 2, 2, 14, 0);
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->f720), i + 0x35, (void *)(((TradeWork *)p)->f730));
        PRINTSYS_Print(func_02045770(*(void **)(p + i * 4 + 0x750)), 0, 0, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0x750));
        BMP_WIN_TransferChars(*(void **)(p + i * 4 + 0x750));
    }
    func_02041B6C(6);
    func_02040588(4, 1);
    func_02040588(6, 1);
}







/*
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 */
void func_021E5D84(char *p)
{
    unsigned i;
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_02040618(6, 0, 0);
    if (((TradeWork *)p)->fF04) func_0204B3DC((struct Obj *)((TradeWork *)p)->fF04, 1);
    if (((TradeWork *)p)->fF18) func_0204B3DC((struct Obj *)((TradeWork *)p)->fF18, 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            func_0201F7A8((void *)(*(int *)(p + i * 4 + 0x750)), 2);
            func_020452E8((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            *(int *)(p + i * 4 + 0x750) = 0;
        }
    }
    func_02041B6C(6);
}







/*
 * interface: x/y are u8 at 021E5ED6..021E5EE2; ov067's own u16 coordinate prototype is narrowed for this caller.
 * domain: side is 0/1 from 021E1E20/021E1E2C at call 021E1F14, or 2 at call 021E23B2 (r1 set 021E23AE).
 * initialization: both domain arms fill x, y, f0 and b1c; all remaining descriptor fields read by ov067 021B6208 are filled below.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`x
 * = side*128;` before `x = side*128+16;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_021E5DFC(char *p, int side, void *mon)
{
    char *q = p + 0x950;
    In_021E5680 in;
    int x,y;
    int flag = 0;
    u32 species = func_02017E1C(mon,6,0);
    if (func_0202136C(species)) flag = 1;
    if (((struct Obj06428 *)q)->f10) {
        if (!species) func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,0);
        else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj06428 *)q)->f10),flag);
            func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,1);
        }
        return;
    }
    if (!species) return;
    switch (side) {
    case 0: case 1:
        x = side*128+16; y = 132;
        in.f0 = 1; in.b1c = 12;
        break;
    case 2:
        x = 32; y = 172;
        in.f0 = 0; in.b1c = 6;
        break;
    }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027694();
    in.f10 = func_02027698();
    in.f14 = func_0202769C(2);
    in.f18 = func_020276A0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (In_021E5680 *)&in, ((TradeWork *)p)->f9C4, ((TradeWork *)p)->f5F4);
    ((struct Obj06428 *)q)->f10 = UI_SCENE_CreateActor(q,((TradeWork *)p)->f9C4,x,y,flag,((TradeWork *)p)->f5F4);
}








void func_021E5EF8(void *p)
{
    if (((struct Obj10382 *)p)->f10) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj10382 *)p)->f10));
        UI_SCENE_FreeActorGfx(p);
        ((struct Obj10382 *)p)->f10 = 0;
    }
}







/*
 * interface: x is narrowed to u8 at 021E5FE4/021E5FEC although ov067's callee declares u16.
 * initialization: ov067 UI_SCENE_LoadActorGfx reads only the seven words and bytes 1c..1e initialized below.
 * domain: call 021E1F20 loads side from the 0/1 slot initialized at 021E1E20/021E1E2C; call 021E2406 sets side=0 at 021E2400. Thus side*128+108 is 108 or 236.
 */
void func_021E5F14(char *p, int side, int flag, void *mon)
{
    char *q = p + 0x964;
    In_021E5680 in;
    u32 a = POKERUS_IsInfected(mon);
    if (((struct Obj06429 *)q)->f10) {
        if (!a) func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,0);
        else func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,1);
        return;
    }
    if (!a) {
        if (!flag) func_021E6008(p,side,(void *)mon);
        return;
    }
    if (flag) { in.f0 = 0; in.b1c = 0; }
    else { in.f0 = 1; in.b1c = 11; }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_020276B4();
    in.f10 = func_020276B8();
    in.f14 = func_020276BC(2);
    in.f18 = func_020276C0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (In_021E5680 *)&in, ((TradeWork *)p)->f9C4, ((TradeWork *)p)->f5F4);
    if (flag) ((struct Obj06429 *)q)->f10 = UI_SCENE_CreateActor(q,((TradeWork *)p)->f9C4,244,104,0,((TradeWork *)p)->f5F4);
    else ((struct Obj06429 *)q)->f10 = UI_SCENE_CreateActor(q,((TradeWork *)p)->f9C4,side*128+108,24,0,((TradeWork *)p)->f5F4);
}





/*
 * lever: caller truncates x to u8 despite callee's wider x type.
 */
void func_021E6008(char *p, int b, void *c)
{
    char *q = p + 0x978;
    In_021E6008 in;
    int a = POKERUS_IsCured(c);
    if (a == 0) return;
    if (((struct Obj08074 *)q)->f10) {
        if (a == 0) func_0204B3DC((struct Obj *)((struct Obj08074 *)q)->f10, 0);
        else func_0204B3DC((struct Obj *)((struct Obj08074 *)q)->f10, 1);
        return;
    }
    in.f0 = 1; in.b1c = 14; in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027748();
    in.f10 = func_0202774C(2);
    in.f14 = func_02027750(2);
    in.f18 = func_02027754(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (In_021E5680 *)&in, ((TradeWork *)p)->f9C4, ((TradeWork *)p)->f5F4);
    ((struct Obj08074 *)q)->f10 = UI_SCENE_CreateActor(q, ((TradeWork *)p)->f9C4, 108 + b * 128, 20, 13, ((TradeWork *)p)->f5F4);
}




/*
 * lever: signed long loop index, u8-qualified guard base versus char-qualified creation base, and mutable p keep the byte index live without a cached address spill.
 * domain: the local counter visits exactly 0..7; all unsigned index conversions preserve its full value. Creator x/state are caller-observed u8 arguments (021E61F8 and 021E620E); B878 state is u16 (021E61DA).
 * table-bounds: original words 021E7EC4..021E7EE0 are 25,26,27,28,29,30,20,21; coords.v[i]*8 is 160..240 without signed overflow or value loss.
 * initialization: both table objects are copied in full; every meaningful descriptor field is assigned before 021B6208.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`offOwner=0x98c;` before `offOwner=0x98c+0x38;`; `offStore=0x98c;` before
 * `offStore=0x98c+0x14;` and 2 more). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021E60BC(char *p,void *mon,int flag)
{
    In in;
    Coords coords;
    States states;
    int offOwner,offStore,offLoad,offSprite;
    u32 bits;
    long i;
    int state,sprite;
    int *row;
    bits=func_02017E1C(mon,11,0);
    coords=d_021E7EC4;
    states=d_021E7F84;
    in.f0=0; in.f4=0;
    in.f8=func_020275E4();
    in.fC=func_02027748();
    in.f10=func_0202774C(2);
    in.f14=func_02027750(2);
    in.f18=func_02027754(2);
    in.b1c=13; in.b1d=0; in.b1e=1;
    if (!flag && func_02017EAC(mon)) bits|=64;
    if (POKERUS_IsCured(mon)) bits|=128;
    if (!((TradeWork *)p)->f99C) {
        UI_SCENE_LoadActorGfx((void *)(p+0x98c), (In_021E5680 *)&in, ((TradeWork *)p)->f9C4, ((TradeWork *)p)->f5F4);
        ((TradeWork *)p)->f99C=1;
    }
    offOwner=0x98c+0x38;
    offStore=0x98c+0x14;
    offLoad=0x98c+0x14;
    offSprite=0x98c+0x14;
    for (i=0;i<8;i++) {
        sprite=*(int *)((const u8 *)p+(unsigned long)i*4+offSprite);
        if (bits&(1<<i)) { row=states.v[(unsigned)i]; state=states.v[i][0]; }
        else { row=states.v[i]; state=row[1]; }
        if (sprite) {
            if (state==-1) func_0204B3DC((struct Obj *)sprite,0);
            else if (flag && i==6) func_0204B3DC((struct Obj *)sprite,0);
            else { CLACT_SetActorAnimSeq((struct Obj *)sprite,state); func_0204B3DC((struct Obj *)sprite,1); }
        } else {
            *(int *)(p+(unsigned long)i*4+offStore)=UI_SCENE_CreateActor((void *)(p+0x98c),*(int *)(p+offOwner),coords.v[(unsigned long)i]*8,101,state==-1?row[0]:state,((TradeWork *)p)->f5F4);
            sprite=*(int *)(p+(unsigned long)i*4+offLoad);
            if (state==-1) func_0204B3DC((struct Obj *)sprite,0);
            else if (flag && i==6) func_0204B3DC((struct Obj *)sprite,0);
        }
    }
}





void func_021E625C(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct Obj13925 *)q)->f10) {
        UI_SCENE_FreeActorGfx((unsigned int *)q);
        ((struct Obj13925 *)q)->f10 = 0;
    }
}




void func_021E6294(char *p, int n, u32 x) {
    int offset = n * 32;
    func_02049B40(23,5,x,offset,32,((TradeWork *)p)->f5F4);
    ARC_UTIL_UploadPaletteFromArchive(func_020275E4(),31,x,28,offset+28,4,((TradeWork *)p)->f5F4);
}





void func_021E62D4(Work_021E5680 *p, int a, int b)
{
    if (p->h[a][b]) {
        CLACT_DeleteActor((struct Obj *)p->h[a][b]);
        p->h[a][b] = 0;
        CLACT_ReleaseCharacter(p->w[a][b]);
    }
}




void func_021E6308(Work_021E6308 *p, int a, int v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->h[a][i])
            func_0204B3DC((struct Obj *)p->h[a][i], v);
    }
}



/*
 * initialization: both coordinate arms initialize x/y; z/a/b are stored before creation.
 * domain: primary calls 021D9084, 021DD670 and 021E25FA prove i=0..1,j=0..2. Wrappers 021D90AC/C0/D4 supply j=0/1/2; 021DD428 returns -1 or 0..2 and caller rejects -1; 021E24E8 has bounded 2x3 loops. Table row i*3+j=0..5 and byte offset i*12+j*4=0..20.
 * interface: 0204B294's fifth full-word payload is a Create address; its body forwards unchanged to 0204CFDC's request pointer. r0 is consumed after that void-declared wrapper.
 * interface: 020185F0 is an empty forwarder; caller supplies r0 and consumes its unchanged pointer result at 021E6346.
 */
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible)
{
    Create c;
    void *q = func_020185F0(mon);
    void *h = func_020490F4(7,((TradeWork *)p)->f5F4);
    int n;
    func_021E62D4((Work_021E5680 *)p, i, j);
    if (selected) {
        c.x=d_021E7D70[i*3+j][0]; c.y=d_021E7D70[i*3+j][1]; n=0;
    } else {
        c.x=d_021E7DA0[i*3+j][0]; c.y=d_021E7DA0[i*3+j][1]; n=1;
    }
    c.z=1; c.a=16; c.b=1;
    *(int *)(p+0x1020+i*12+j*4) = CLACT_RegisterCharacter((void *)((u32)h),func_0201BA68(q),0,n,((TradeWork *)p)->f5F4);
    *(int *)(p+0x1008+i*12+j*4) = (int)CLACT_CreateActor((void *)((TradeWork *)p)->f9C4,*(int *)(p+0x1020+i*12+j*4),*(int *)&((TradeWork *)p)->f890,*(int *)&((TradeWork *)p)->f8C0,&c,n,((TradeWork *)p)->f5F4);
    func_0204B6F4((struct Obj *)(*(int *)(p+0x1008+i*12+j*4)),POKE_TOOL_GetIconPalette(q),1);
    func_0204B92C((struct Obj *)*(int *)(p+0x1008+i*12+j*4),0);
    func_0204B3DC((struct Obj *)*(int *)(p+0x1008+i*12+j*4),visible);
    ARC_TOOL_DeleteHandle((void *)((int)h));
}



void func_021E6440(int p, int a, int b) {
    int i,j;
    Pt pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (*(int *)(p+i*12+j*4+0x1008)) {
                pos.x=d_021E7DA0[i*3+j][0]; pos.y=d_021E7DA0[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                func_0204B404((struct Obj *)(*(int *)(p+i*12+j*4+0x1008)),(const struct Vec2 *)(&pos),1);
            }
        }
    }
}




void func_021E64B8(void *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            func_021E62D4((Work_021E5680 *)p, i, j);
}



void func_021E64DC(int p, int i, int j, int x, int y, void *q) {
    Create c;
    c.x=x; c.y=y; c.z=1; c.a=0; c.b=0;
    ((TradeWork *)p)->fF20=(int)CLACT_CreateActor((void *)((TradeWork *)p)->f9C4,*(int *)(p+i*20+j*4+0x9cc),(*(int *)&((TradeWork *)p)->f87C),(*(int *)&((TradeWork *)p)->f8AC),&c,1,((TradeWork *)p)->f5F4);
    func_0204B6F4((struct Obj *)(((TradeWork *)p)->fF20),POKE_TOOL_GetIconPalette(q),1);
}



static inline int mul(int a,int b) { return (int)(((s64)a*b+0x800LL)>>12); }



/*
 * initialization: 0204B454 writes both signed coordinates; all four vector arguments are fully assigned before 021E7248 reads each three-word object.
 * arithmetic: coordinate products fit signed32 for every signed-short input; fixed-point scalar sums use modulo32 ADD. Signed32 products plus 0x800 fit signed64 for every possible input.
 */
void func_021E6544(char *p)
{
    T end,third,second,first;
    Pt pos;
    int x,y,dx,dy,speed;
    CLACT_GetActorSurfacePos((struct Actor *)(*(void * *)&((TradeWork *)p)->fF20),(struct PtS *)&pos,1);
    dx=(pos.x-((TradeWork *)p)->fF6C)*4096;
    dy=(pos.y-((TradeWork *)p)->fF6E)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-((TradeWork *)p)->fF6C)*4096;
    second.y=(pos.y*2-((TradeWork *)p)->fF6E)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=func_0207C7B4((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    func_021E7248((S *)(p+0x1190),&first,&second,&third,&end,19);
    ((TradeWork *)p)->f11DC=21;
}



int func_021E665C(char *p) {
    Pt pos;
    if (((TradeWork *)p)->f11DC) {
        --((TradeWork *)p)->f11DC;
        if (!((TradeWork *)p)->f11DC) return 1;
        CLACT_GetActorSurfacePos((struct Actor *)((TradeWork *)p)->fF20,(struct PtS *)&pos,1);
        if (pos.y<0) ((TradeWork *)p)->f11DC=1;
        if (((TradeWork *)p)->f11DC==1) func_021E66E8(p);
        else {
            func_021E729C((struct Curve *)(p+0x1190));
            pos.x=((TradeWork *)p)->f1190/4096;
            pos.y=((TradeWork *)p)->f1194/4096;
            func_0204B404((struct Obj *)(((TradeWork *)p)->fF20),(const struct Vec2 *)(&pos),1);
        }
    }
    return 0;
}




void func_021E66E8(void *p)
{
    if (((TradeWork *)p)->fF20) {
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)p)->fF20));
        ((TradeWork *)p)->fF20 = 0;
    }
}




void func_021E6700(void *p)
{
    func_0207D63C(0x04001050, 0, 15, 8, 8);
}



void func_021E6718(char *p, int i) {
    Create c;
    if (!*(int *)(p+0x10bc+i*4)) {
        c.x=i*24+8; c.y=144; c.z=i+11; c.a=50; c.b=1;
        *(int *)(p+0x10bc+i*4)=(int)CLACT_CreateActor((void *)((TradeWork *)p)->f9C4,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->f5F4);
    }
    func_0204B92C((struct Obj *)*(int *)(p+0x10bc+i*4),1);
    func_0204B3DC((struct Obj *)*(int *)(p+0x10bc+i*4),1);
}



void func_021E6790(void *p, int i, int a)
{
    func_0204B3DC((struct Obj *)*(int *)((char *)p + i * 4 + 0x10bc), a);
}



void func_021E67A8(void *p, int i)
{
    if (*(int *)((char *)p + 0x10bc + i * 4)) {
        CLACT_DeleteActor((struct Obj *)(*(int *)((char *)p + 0x10bc + i * 4)));
        *(int *)((char *)p + 0x10bc + i * 4) = 0;
    }
}



void func_021E67C4(void *p, int i)
{
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)((char *)p + i * 4 + 0x10bc)), (u16)(i + 15));
}


void func_021E67E0(Work *p, int z, int i) {
    Create c;
    c.x=i*206+8; c.y=160; c.z=4; c.a=1; c.b=0;
    if (!p->slot[i*2]) {
        p->slot[i*2]=(int)CLACT_CreateActor((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2],1);
        func_0204B3DC((struct Obj *)p->slot[i*2],1);
    } else {
        func_0204B3DC((struct Obj *)p->slot[i*2],1);
    }
    if (!p->slot[i*2+1]) {
        c.a=0; c.z=z;
        p->slot[i*2+1]=(int)CLACT_CreateActor((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2+1],1);
        func_0204B3DC((struct Obj *)p->slot[i*2+1],1);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)p->slot[i*2+1],z);
    }
}


static inline void clear(int p, int i) {
    if (*(int *)(p+i*4+0x10ac)) {
        CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*4+0x10ac)));
        *(int *)(p+(unsigned int)i*4+0x10ac)=0;
    }
}


/*
 * lever: unsigned cast on the store index prevents address CSE with the signed read index; without it 56 bytes, 37 byte DIFF.
 */
void func_021E68B4(int p, int n) {
    int i=n*2;
    clear(p,i+1);
    clear(p,i);
}


void func_021E68F4(int p, int i) {
    Table t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(((TradeWork *)p)->fFD4) func_0204B3DC((struct Obj *)((TradeWork *)p)->fFD4,0);
    } else {
        if(!((TradeWork *)p)->fFD4) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            ((TradeWork *)p)->fFD4=(int)CLACT_CreateActor((void *)((TradeWork *)p)->f9C4,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->f5F4);
        }
        func_0204B92C((struct Obj *)((TradeWork *)p)->fFD4,1);
        func_0204B3DC((struct Obj *)((TradeWork *)p)->fFD4,1);
        func_0204B404((struct Obj *)(((TradeWork *)p)->fFD4),(const struct Vec2 *)(&t.pos[i]),1);
    }
}



void func_021E69A4(char *p)
{
    if (((TradeWork *)p)->fFD4) {
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)p)->fFD4));
        ((TradeWork *)p)->fFD4 = 0;
    }
}


/*
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 */
int func_021E69C0(char *p)
{
    Pt a,b,c;
    int i;
    if(((TradeWork *)p)->f11DE<128) ((TradeWork *)p)->f11DE+=4;
    else return 1;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x10cc),(struct PtS *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        func_0204B404(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x-=4;
            func_0204B404(*(void **)(p+i*4+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1014),(struct PtS *)&c,1);
            c.x+=4;
            func_0204B404(*(void **)(p+i*4+0x1014),(const struct Vec2 *)(&c),1);
        }
    }
    func_02040618(5,0,-((TradeWork *)p)->f11DE);
    func_02040618(4,0,((TradeWork *)p)->f11DE-128);
    return 0;
}


/*
 * lever: split temporary for first loop base and second loop index; 10-byte
 *         register swap without them. Permuter budget 300, 271 compiles.
 * output: 0204B454 and its full getter chain write both coordinate halfwords.
 */
void func_021E6AB0(const char *p)
{
    int i,j;
    Pt a,b,c;
    int tmp;
    const char *tmp1;
    for(i=0;i<8;i++) {
        tmp1=p+i*4;
        tmp1=tmp1+0x10cc;
        CLACT_GetActorSurfacePos(((struct Obj22816 *)tmp1)->f0,(struct PtS *)&a,1);
        if(i/4) {
            a.x-=128;
            CLACT_SetActorBgPriority(*(void **)(p+i*4+0x10cc),3);
        } else a.x+=128;
        func_0204B404(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x+=128;
            tmp=i;
            tmp=tmp*4;
            func_0204B404(*(void **)(p+tmp+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(*(void **)(p+j*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+j*4+0x1014),(struct PtS *)&c,1);
            c.x-=128;
            func_0204B404(*(void **)(p+j*4+0x1014),(const struct Vec2 *)(&c),1);
            CLACT_SetActorBgPriority(*(void **)(p+j*4+0x1014),3);
        }
    }
    func_0204047C(4,2);
    func_0204047C(5,3);
}


void func_021E6B90(char *p)
{
    void *h;
    BgTemplate t;
    (*(void * *)&((TradeWork *)p)->f644) = func_0201F5DC((void *)6, 15, 0, ((TradeWork *)p)->f5F4);
    h = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f870 = func_02049740(h, 13, 5, 0, 0, ((TradeWork *)p)->f5F4);
    func_02049990(h, 7, 4, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->f5F4);
    func_02049990(h, 7, 5, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->f5F4);
    t = d_021E7E44;
    func_020403F4(7);
    func_0203FCA0(7, &t, 0);
    func_02049990(h, 8, 7, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->f5F4);
    func_02040618(4, 0, -0x80);
    func_02040618(7, 0, 0);
    func_0204047C(4, 3);
    func_02049990(h, 11, 2, 0, (u16)(*(unsigned int *)&((TradeWork *)p)->f86C), 0, 0, ((TradeWork *)p)->f5F4);
    ARC_TOOL_DeleteHandle(h);
    (*(unsigned short *)&((TradeWork *)p)->f11DE) = 0;
    func_021E6AB0(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}
