/*
 * file:     guru2_main_p11.c
 * unit:     yes
 * function: func_021DF800, func_021DF83C, func_021DF864, func_021DF984, func_021DF998, func_021DFA14, func_021DFA68, func_021DFAD8, func_021DFB60, func_021DFC74, func_021DFE40, func_021DFE6C, func_021DFEA0, func_021DFEB8, func_021DFEC4, func_021DFEFC, func_021DFF20, func_021DFF44, func_021DFF70, func_021DFFC8, func_021DFFF8, func_021E00D4, func_021E0130, func_021E01B0, func_021E026C, func_021E0304, func_021E0338, func_021E03A0, func_021E03D8, func_021E0450, func_021E0478
 * address:  0x021DF800
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E04B4 0x021E04B4 thumb ov137
 *   func_02048B6C 0x02048B6C arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0206AA3C 0x0206AA3C arm
 *   func_0206AA78 0x0206AA78 arm
 *   func_0206AA8C 0x0206AA8C arm
 *   func_0206AAB0 0x0206AAB0 arm
 *   func_021E0698 0x021E0698 thumb ov137
 *   func_021E05D4 0x021E05D4 thumb ov137
 *   func_021E0848 0x021E0848 thumb ov137
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0202F0B0 0x0202F0B0 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_02045088 0x02045088 arm
 *   d_021E1EA4 0x021E1EA4 data a4
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   func_0207DD24 0x0207DD24 arm
 *   d_021E1D90 0x021E1D90 data a2
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_02048A24 0x02048A24 arm
 *   d_021E2020 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E1D00 0x021E1D00 data a4
 *   d_021E1D0C 0x021E1D0C data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   d_021E202C 0x021E202C data a4
 *   d_021E204C 0x021E204C data a4
 *   d_021E206C 0x021E206C data a4
 *   d_021E208C 0x021E208C data a4
 *   d_021E20AC 0x021E20AC data a4
 *   d_021E20CC 0x021E20CC data a4
 *   func_021E1634 0x021E1634 thumb ov137
 *   func_02062A98 0x02062A98 arm
 *   func_020215BC 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02022004 0x02022004 thumb
 *   func_02062A00 0x02062A00 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02021640 0x02021640 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 *   func_02039338 0x02039338 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   d_021E1E30 0x021E1E30 data a4
 */
#include "../../matched/include/Obj14228.h"
#include "../../matched/include/Obj00835.h"
#include "../../matched/include/Obj02870.h"
#include "../../matched/include/Obj23767.h"
#include "../../matched/include/Obj23768.h"
#include "../../matched/include/Obj23769.h"
#include "../../matched/include/Obj23770.h"
#include "../../matched/include/Obj03842.h"
#include "../../matched/include/Obj23771.h"
#include "../../matched/include/Obj03306.h"
#include "../../matched/include/Obj23772.h"
#include "../../matched/include/Obj05432.h"
#include "../../matched/include/Obj03843.h"
#include "../../matched/include/Obj02498.h"
#include "../../matched/include/Obj02871.h"
#include "../../matched/include/Obj02869.h"
#include "../../matched/include/Obj23773.h"
#include "../../matched/include/Obj14230.h"
#include "../../matched/include/Obj23774.h"
#include "../../matched/include/Obj14231.h"

#define DISP3D (*(volatile u16 *)0x04000060)
struct Descriptor;
struct Light;
struct PrintSys;
struct DispVram;
struct NitroFileHeader;
struct PalAnmSlot;
struct Cfg;
struct CharBuf;
struct Bank;
struct Util;
struct Setup;
struct Ctx;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

typedef short s16;

typedef struct { u32 x, y, z; } Vec3;

struct DispConfig {u32 w[4];};

struct BgTemplate {u32 w[8];};

typedef signed int     s32;

typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Desc;

extern void func_021E04B4(u8 *p);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void);
extern void func_0206AA3C(int,int,int,int),func_0206AA78(int,u32),func_0206AA8C(u32,u32,u32),func_0206AAB0(u32,u32,u32);
extern void func_021E0698(u8 *),func_021E05D4(u8 *),func_021E0848(u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern void func_0202F0B0(u8 *p);
extern void func_020433E0(const struct DispVram *);
extern void func_02045088(u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_0207DCF8(const u16 *);
extern void func_0207DD24(u16, int, int, int, int);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern void func_02046BE0(u32, u32);
extern void *func_02048A24(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void *func_021E1634(char *,u32,int);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_020307B0(void *p);
extern void func_02022004(u32,u32,u16,u32,u32);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern int func_02062B30(void *,void **);
extern void func_02040AE0(u32,const void *,u32);
extern void func_020409B4(u32);
extern void func_020450C8(void);
extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void *func_02021518(u32);
extern void func_02021EE4(struct PalAnmSlot *,int);
extern void func_0202155C(struct PalAnmSlot *,u32,u32,u32);
extern void func_020215A0(struct PalAnmSlot *,u32);
extern void func_02021540(struct PalAnmSlot *);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204A8D4(u32),func_0204ADA4(u32),func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201C440(void *);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_021DEB10(char *p);
extern char *func_02184180(unsigned char *p, int i);
extern u16 func_02039338(void);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F7A8(void *,u32);
void func_021DF800(char *p);
void func_021DF83C(char *p);
void func_021DF864(u8 *p);
void func_021DF984(char *p);
void func_021DF998(char *a0);
void func_021DFA14(char *a0);
void func_021DFA68(void);
void func_021DFAD8(u8 *p);
void func_021DFB60(char *a0);
void func_021DFC74(char *p);
void func_021DFE40(char *p);
void func_021DFE6C(u8 *p,int file);
void func_021DFEA0(u8 *p);
void func_021DFEAC(u8 *p);
void func_021DFEB8(u8 *p);
void func_021DFEC4(char *p);
void func_021DFEFC(char *p);
void func_021DFF20(u8 *p,int a);
void func_021DFF44(u8 *p);
void func_021DFF70(u8 *p);
void func_021DFFC8(u8 *p);
void func_021DFFF8(u8 *p);
void func_021E00D4(u8 *p);
void func_021E0130(u8 *p,int message);
void func_021E01B0(u8 *p,int message,void *value);
void func_021E026C(u8 *p,int message,unsigned value);
void func_021E0304(u8 *p);
void func_021E0338(u8 *p,int count);
void func_021E03A0(u8 *p);
void func_021E03D8(u8 *p,void *text,int index,int color);
void func_021E0450(u8 *p,void *text,int index,int a);
void func_021E0478(u8 *p,u32 i);
extern const struct DispVram d_021E1EA4;
extern const u16 d_021E1D90[];
extern const Vec3 d_021E2020;
extern const s16 d_020A1EB8[];
extern Vec3 d_021E1D00, d_021E1D0C;
extern const struct DispConfig d_021E202C;
extern const struct BgTemplate d_021E204C,d_021E206C,d_021E208C,d_021E20AC,d_021E20CC;
extern const struct Cfg d_020A1448;
extern const Desc *const d_021E1E30[];

void func_021DF800(char *p){func_021DF984(p);func_021DFAD8((u8 *)p);func_021DFB60(p);func_021DFEC4(p);func_021DFF44((u8 *)p);func_021DFC74(p);func_021DFFF8((u8 *)p);func_021DFF70((u8 *)p);func_021DF998(p);}

void func_021DF83C(char *p){func_021DFA14(p);func_021DFFC8((u8 *)p);func_021E00D4((u8 *)p);func_021DFE40(p);func_021DFEFC(p);func_021E04B4((u8 *)p);}

/*
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
void func_021DF864(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    func_02048B6C(*(void **)(p+0xd54),&flags);
    func_02047964();
    func_02048AD0(*(void **)(p+0xd54));
    func_020479D8();
    func_0206AA3C(0,0,-4096,0);
    func_0206AA78(0,0x7fff);
    func_0206AA8C(0x7fff,0x7fff,0);
    func_0206AAB0(0x7fff,0x7fff,0);
    func_021E0698(p);func_021E05D4(p);func_021E0848(p);
    func_02047970();func_0204A600();
    func_0201C4E4(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!func_0201C6C4(r,func_02045770(*(void **)(p+0xd08)))) {
            func_02045334(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!func_0201C6C4(r,func_02045770(*(void **)(p+i*8+0xd10)))) {
                func_02045334(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) func_0202F0B0(*(void **)(p+0xda8));
}

void func_021DF984(char *p){func_020433E0(&d_021E1EA4);func_02045088(114);}

static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

/*
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 */
void func_021DF998(char *a0)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_020434DC(16, 1);
    func_02043598(16, 1);
    G2_SetBG0Priority(1);
    func_0207D63C(0x04000050, 4, 40, 11, 10);
}

void func_021DFA14(char *a0)
{
    func_02040588(0, 0);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_02040588(3, 0);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020434DC(16, 0);
    func_02043598(16, 0);
}

static inline void G3X_SetShading(GXShading shading)
{
    DISP3D = (u16)((DISP3D & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}

static inline void G3X_AntiAlias(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 16);
    else DISP3D &= (u16)~0x3010;
}

static inline void G3X_AlphaTest(int enable, int ref)
{
    if (enable) {
        DISP3D = (u16)((DISP3D & ~0x3000) | 4);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else DISP3D &= (u16)~0x3004;
}

static inline void G3X_AlphaBlend(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 8);
    else DISP3D &= (u16)~0x3008;
}

static inline void G3X_EdgeMarking(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 32);
    else DISP3D &= (u16)~0x3020;
}

/*
 * volatile: DISP3DCNT 0x04000060 re-read at 021DFA70,76,82,8A,96; GXSTAT written 021DFABA.
 */
void func_021DFA68(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(1);
    func_0207DCF8(d_021E1D90);
    func_0207DD24(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}

void func_021DFAD8(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    func_02046440(0, 1, 0, 1, 0, 114, func_021DFA68);
    func_02046BE0(0, 0);
    position = d_021E2020;
    ((struct Obj14228 *)section)->f14 = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &d_021E1D00, &position, &d_021E1D0C, 114);
    func_02048AD0(((struct Obj14228 *)section)->f14);
}

/*
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 */
void func_021DFB60(char *a0)
{
    func_0203F8F4(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=d_021E202C; func_0203FC28(&t);}
    {struct BgTemplate t=d_021E204C; func_0203FCA0(1,&t,0); func_020414EC(1); func_02040B94(1,32,0,114);}
    {struct BgTemplate t=d_021E206C; func_0203FCA0(2,&t,0); func_020414EC(2);}
    {struct BgTemplate t=d_021E208C; func_0203FCA0(3,&t,0); func_020414EC(3);}
    {struct BgTemplate t=d_021E20AC; func_0203FCA0(6,&t,0); func_020414EC(6);}
    {struct BgTemplate t=d_021E20CC; func_0203FCA0(7,&t,0); func_020414EC(7);}
}

void func_021DFC74(char *p)
{
    void *buf;
    u8 *data;
    buf=func_021E1634(p,17,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(((struct Obj00835 *)p)->fD78,((struct Obj23767 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,0,0,64);
    func_020307B0(buf);
    buf=func_021E1634(p,20,0);
    func_02062A98(buf,(void **)(p+0xd64));
    func_020215BC(((struct Obj00835 *)p)->fD78,((struct Obj23768 *)(*(u8 * *)&((struct Obj00835 *)p)->fD64))->fC,1,0,64);
    func_020307B0(buf);
    func_02022004(*(u32 *)&((struct Obj00835 *)p)->fD78,1,65535,8,0);
    buf=func_021E1634(p,16,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(3,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,22,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(6,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,21,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD60;
    func_02040B1C(7,((struct Obj02870 *)data)->f14,((struct Obj02870 *)data)->f10,0);
    func_020307B0(buf);
    buf=func_021E1634(p,19,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(2,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(2);
    func_020307B0(buf);
    buf=func_021E1634(p,18,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(3,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(3);
    func_020307B0(buf);
    buf=func_021E1634(p,24,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(6,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(6);
    func_020307B0(buf);
    buf=func_021E1634(p,23,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Obj00835 *)p)->fD5C;
    func_02040AE0(7,data+12,((struct Obj02870 *)data)->f8);
    func_020409B4(7);
    func_020307B0(buf);
}

void func_021DFE40(char *p){func_020450C8();func_020403F4(1);func_020403F4(2);func_020403F4(3);func_020403F4(6);func_020403F4(7);func_0203F9B4();}

/*
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 */
void func_021DFE6C(u8 *p,int file)
{
    void *buf;
    u8 *screen;
    buf=func_021E1634((char *)p,file,0);
    func_02062B30(buf,(void **)(p+3420));
    screen=*(u8 * *)&((struct Obj23769 *)p)->fD5C;
    func_02040AE0(6,screen+12,((struct Obj23770 *)screen)->f8);
    func_020409B4(6);
    func_020307B0(buf);
}

void func_021DFEA0(u8 *p) { func_021DFE6C(p,26); }

void func_021DFEAC(u8 *p) { func_021DFE6C(p,24); }

void func_021DFEB8(u8 *p) { func_021DFE6C(p,25); }

void func_021DFEC4(char *p){*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78=func_02021518(114);func_02021EE4(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,0,512,114);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1,512,114);}

void func_021DFEFC(char *p){func_020215A0(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,0);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,1);func_02021540(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78);}

void func_021DFF20(u8 *p,int a){func_02022004(((struct Obj23771 *)p)->fD78,1,65535,(u8)a,0);}

/*
 * blocking: ABS32 data d_020A1448 at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 */
void func_021DFF44(u8 *p){func_0204A48C(&d_020A1448,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=func_0204B100(30,1,114);}

void func_021DFF70(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    ((struct Obj00835 *)p)->fD6C = func_0204A6C8(arc,6,0,0,114);
    ((struct Obj00835 *)p)->fD70 = func_0204ABF0(arc,0,0,0,114);
    ((struct Obj00835 *)p)->fD74 = func_0204AF28(arc,10,14,114);
    func_02049238(arc);
    func_0203D34C(1,114);
}

void func_021DFFC8(u8 *p){func_0204A8D4(((struct Obj03842 *)p)->fD6C);func_0204ADA4(((struct Obj03842 *)p)->fD70);func_0204AFD8(((struct Obj03842 *)p)->fD74);func_0204B1CC(*(struct Bank * *)&((struct Obj03842 *)p)->fD68);func_0204A5AC();}

void func_021DFFF8(u8 *p)
{
    int i;
    u8 *s=p+0xce0;
    func_0201F5BC(1,1,15,0,114);
    func_02021640(((struct Obj00835 *)p)->fD78,5,3,114,0,32,224);
    func_02021640(((struct Obj00835 *)p)->fD78,23,5,114,0,32,240);
    ((struct Obj03306 *)s)->f4=func_0201D7EC(23,0,0,0,114);
    ((struct Obj03306 *)s)->f8=func_02045B38(0,2,41,114);
    ((struct Obj03306 *)s)->fC=func_0201EC64(114);
    ((struct Obj03306 *)s)->f10=func_020450F0(1,2,19,26,4,15,1);
    ((struct Obj03306 *)s)->f5C=func_020457B0(256,114);
    for(i=0;i<5;i++) {*(void **)(p+0xa4+i*4)=func_020457B0(8,114);}
    ((struct Obj03306 *)s)->f28=((struct Obj03306 *)s)->f10;
    ((struct Obj03306 *)s)->f2C=0;
    ((struct Obj03306 *)s)->f58=func_0201C440((void *)114);
    func_021E0338(p,((struct Obj23772 *)(*(u8 * *)&((struct Obj00835 *)p)->fD8))->f8);
}

/*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 */
void func_021E00D4(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=((struct Obj05432 *)s)->f10;
    func_020456F8(obj);
    func_020409B4(func_02045730(obj));
    func_020452E8(((struct Obj05432 *)s)->f10);
    func_021E03A0(p);
    func_02045C04(((struct Obj05432 *)s)->f8);
    func_0201ED04(((struct Obj05432 *)s)->fC);
    func_0201D83C(((struct Obj05432 *)s)->f4);
    func_02045808(((struct Obj05432 *)s)->f5C);
    for(i=0;i<5;i++) func_02045808(*(void **)(p+164+i*4));
    func_020450C8();
}

void func_021E0130(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Obj03843 *)s)->f10;
    func_02043B5C(func_02045770(window),15);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    func_02045CAC(((struct Obj03843 *)s)->f8,message,((struct Obj03843 *)s)->f5C);
    owner=((struct Obj03843 *)s)->f58;
    data=func_02045770(((struct Obj03843 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj03843 *)s)->f5C),(u32)(((struct Obj03843 *)s)->f4),1088);
    ((struct Obj03843 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}

void func_021E01B0(u8 *p,int message,void *value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Obj02498 *)s)->f10;
    func_0201F02C(((struct Obj02498 *)s)->fC,1,func_02184180(func_021DEB10((char *)p),(u8)func_02039338()));
    func_0201F02C(((struct Obj02498 *)s)->fC,2,value);
    text=func_020457B0(256,114);
    func_02045CAC(((struct Obj02498 *)s)->f8,message,text);
    func_0201F250(((struct Obj02498 *)s)->fC,((struct Obj02498 *)s)->f5C,text);
    func_02045808(text);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj02498 *)s)->f58;
    data=func_02045770(((struct Obj02498 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj02498 *)s)->f5C),(u32)(((struct Obj02498 *)s)->f4),1088);
    ((struct Obj02498 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}

/*
 * extent: Two zero alignment bytes at 021E0302.
 */
void func_021E026C(u8 *p,int message,unsigned value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Obj02871 *)s)->f10;
    func_0201EF40(((struct Obj02871 *)s)->fC,0,value);
    text=func_020457B0(256,114);
    func_02045CAC(((struct Obj02871 *)s)->f8,message,text);
    func_0201F250(((struct Obj02871 *)s)->fC,((struct Obj02871 *)s)->f5C,text);
    func_02045808(text);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj02871 *)s)->f58;
    data=func_02045770(((struct Obj02871 *)s)->f28);
    func_0201C724(owner,(u32)data,0,0,(u32)(((struct Obj02871 *)s)->f5C),(u32)(((struct Obj02871 *)s)->f4),1088);
    ((struct Obj02871 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}

void func_021E0304(u8 *p){struct Descriptor *w=*(struct Descriptor * *)&((struct Obj02869 *)p)->fCF0;func_0201F7A8(w,0);func_02043B5C(func_02045770(w),0);func_02045334(w);func_02045374((struct Cfg *)w);func_02041B6C(func_02045730(w));}

/*
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 */
void func_021E0338(u8 *p,int count)
{
    int i;
    u8 *s;
    const Desc *table;
    u32 obj;
    u32 *slot;
    const Desc *entry;
    s=p+3296;
    i=0;
    table=d_021E1E30[count];
    ((struct Obj23773 *)s)->f0=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=func_020450F0((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}

void func_021E03A0(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<((struct Obj23774 *)s)->f0;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor * *)&((struct Obj14230 *)q)->f14;func_020456F8(w);func_020409B4(func_02045730(w));func_020452E8(*(struct Descriptor * *)&((struct Obj14230 *)q)->f14);}}

void func_021E03D8(u8 *p,void *text,int index,int color)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=*(void **)(s+20+index*4);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    owner=((struct Obj14231 *)s)->f58;
    data=func_02045770(*(void **)(s+48+index*8));
    func_0201C724(owner,(u32)data,4,1,(u32)text,(u32)(((struct Obj14231 *)s)->f4),color);
    *(u8 *)(s+52+index*8)=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}

void func_021E0450(u8 *p,void *text,int index,int a){int c=0x440;if(a==func_02039338())c=0xc80;func_021E03D8(p,text,index,c);}

void func_021E0478(u8 *p,u32 i){struct Descriptor *w=*(struct Descriptor **)(p+i*4+0xcf4);func_0201F7A8(w,0);func_02043B5C(func_02045770(w),0);func_02045334(w);func_02045374((struct Cfg *)w);func_02041B6C(func_02045730(w));}
