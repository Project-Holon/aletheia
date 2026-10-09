/*
 * file:     vs_multi_list.c
 * unit:     yes
 * function: func_021F6560, func_021F6590, func_021F65C4, func_021F65D4, func_021F6654, func_021F6684, func_021F66B4, func_021F67C8, func_021F67F0, func_021F681C, func_021F682C, func_021F683C, func_021F68E0, func_021F68FC, func_021F6970, func_021F69C0, func_021F69E4, func_021F69FC, func_021F6A08, func_021F6A28, func_021F6A98, func_021F6B1C, func_021F6B38, func_021F6B7C, func_021F6CE4, func_021F6D70, func_021F6EE8, func_021F6F24, func_021F6F3C, func_021F6F50, func_021F6F80, func_021F6F88, func_021F7108, func_021F714C, func_021F72BC, func_021F72DC, func_021F7308, func_021F734C
 * address:  0x021F6560
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   D_021F7608 0x021F7608 data a4
 *   func_0202CD94 0x0202CD94 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021F75E0 0x021F75E0 thumb ov097
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0202208C 0x0202208C thumb
 *   d_021F761C 0x021F761C data a4
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_021F75F8     0x021F75F8  data  ov097  a4
 *   d_021F7688     0x021F7688  data  ov097  a4
 *   d_021F7668     0x021F7668  data  ov097  a4
 *   d_021F76A8     0x021F76A8  data  ov097  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049238  0x02049238  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045738 0x02045738 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02043AF4 0x02043AF4 arm
 *   func_0204A48C 0x0204A48C arm
 *   d_021F764C 0x021F764C data a4
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0202136C 0x0202136C thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   d_021F76C8 0x021F76C8 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CAC4 0x0202CAC4 thumb
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0204162C 0x0204162C arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   d_021F78C0 0x021F78C0 data a4
 */
#include "../../matched/include/Obj21988.h"
#include "../../matched/include/Obj10194.h"
#include "../../matched/include/Obj10193.h"
#include "../../matched/include/Obj21989.h"
#include "../../matched/include/Obj00111.h"
#include "../../matched/include/Obj21990.h"
#include "../../matched/include/Obj21991.h"
#include "../../matched/include/Obj06345.h"
#include "../../matched/include/Obj21992.h"
#include "../../matched/include/Obj07928.h"
#include "../../matched/include/Obj05257.h"
#include "../../matched/include/Obj07929.h"
#include "../../matched/include/Obj13675.h"
#include "../../matched/include/Obj00410.h"
#include "../../matched/include/Obj21993.h"
#include "../../matched/include/Obj21994.h"
#include "../../matched/include/Obj21995.h"
#include "../../matched/include/Obj21996.h"

struct Obj0203159C;
struct WinMgr;
struct S020315D4;
struct P;
struct PrintSys;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Node;
struct Descriptor;
struct CharBuf;
struct StrObj;
struct U16Vec;
struct Bmp;
struct Bank;
struct Obj;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef short s16;

typedef int s32;

typedef struct {
    u32 w[4];
} Disp;

typedef struct {
    u32 w[8];
} Bg;

typedef short s16_021F6B7C;

typedef enum { ZERO } Zero;

typedef enum { INDEX_ZERO } Index;

typedef struct { struct Descriptor *text; unsigned char dirty; unsigned char pad05[3]; } Window;

typedef struct {
    unsigned char pad00[0x10];
    u32 ink;
    struct MsgBank *catalogue;
    struct WordSet *formatter;
    void *renderer;
    Window window[6];
} Owner;

typedef signed short   s16_021F6D70;

struct Cfg { unsigned w[7]; };

typedef int s32_021F6F80;

struct T { u32 a, b, i, j, k; };

struct P_021F714C {
    u8 *parent;
    u8 pad04[0x4c];
    struct Bank *bank;
    union { struct Obj *all[24]; struct { struct Obj *a[6], *b[6], *c[6], *d[6]; } set; } actors;
    u32 tabA[9], tabB[4], tabC[4];
    void *mons[6];
};

struct PtS { short x, y; };

typedef signed int s32_021F734C;

struct Pair { void *data; u32 other; };

struct P_021F734C {
    u8 *parent; u32 pad04; struct WinMgr *window; u8 pad0c[20];
    struct Pair images[6]; u8 pad50[0xa8]; void *mons[6];
};

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *,unsigned int,unsigned int);
extern void func_02082BCC(void *,int,unsigned int);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0204A600(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0203D34C(u32 a, u32 b);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021F75E0(int *);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_020061E4(u32);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049238(void *h);
extern void func_02040EBC(u32 a, u32 b);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(u16 n, u32 heap);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void *func_020056A0(void (*)(void), void *, u32);
extern void func_02030EAC(struct Node *n);
extern void func_020419E4(void);
extern void func_0204A648(void);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02045738(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02017E1C(void *, u32, u32);
extern u8 func_02017F00(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_02043AF4(struct Bmp *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_0204A48C(const struct Cfg *, unsigned, unsigned);
extern void func_0204A5AC(void);
extern void *func_020185F4(void *);
extern u32 func_0201BA68(void *);
extern u32 func_0201BABC(u32, u32, u32, u32);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int func_0204AF28(void *, u32, u32, u32);
extern u32 func_020275E4(void);
extern int func_0204ABF0(void *, u32, u32, u32, u16);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Bank *func_0204B100(int, u8, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_0204B92C(struct Obj *, u32);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *, u32, u32);
extern u32 func_0202136C(u16);
extern void func_0204B8C4(struct Obj *, u32);
extern void func_0204B878(struct Obj *, u16);
extern void func_0204B3B4(struct Obj *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32_021F734C x, s32_021F734C y, u8 w, u8 h, u8 pal);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u32 func_0204162C(int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void MIi_CpuCopy16(const void *, void *, u32);
int func_021F6560(struct Obj0203159C *a, int b, int c);
int func_021F6590(int a,int *b,int c,char *d);
int func_021F65C4(void *p);
void func_021F65D4(int a);
int func_021F6654(u8 *p);
int func_021F6684(u8 *p);
int func_021F669C(u8 *p);
int func_021F66B4(u8 *p);
int func_021F67C8(u8 *p, int value);
int func_021F67F0(u8 *p, int value);
int func_021F681C(u8 *p, int count, int result);
void func_021F682C(void);
void func_021F683C(void);
void func_021F68E0(void);
void func_021F68FC(int a0);
void func_021F6970(u8 *p);
void func_021F69C0(u8 *p);
void func_021F69E4(u8 *p);
void func_021F69FC(u8 *p);
void func_021F6A08(void);
void func_021F6A28(int *p);
void func_021F6A98(int a);
void func_021F6B1C(u8 *p);
void func_021F6B38(char *p);
void func_021F6B7C(int p, int i);
void func_021F6CE4(Owner *a, Index b);
void func_021F6D70(char *p, int idx);
void func_021F6EE8(unsigned p, unsigned i);
void func_021F6F24(struct P *p);
void func_021F6F3C(char *p);
void func_021F6F50(void);
void func_021F6F80(void);
void func_021F6F88(int p);
void func_021F7108(char *p);
void func_021F714C(struct P_021F714C *p);
void func_021F72BC(char *p);
void func_021F72DC(unsigned p, unsigned i, int dx);
void func_021F7308(int a, unsigned b, int c);
void func_021F734C(struct P_021F734C *p);
extern const struct DispVram d_021F761C;
extern const Disp d_021F75F8;
extern const Bg d_021F7688;
extern const Bg d_021F7668;
extern const Bg d_021F76A8;
extern u32 SDK_AUTOLOAD_DTCM_START[];
extern const struct Cfg d_021F764C;
extern const struct T d_021F76C8[];
extern const char d_021F78C0[];




int func_021F6560(struct Obj0203159C *a, int b, int c) { void *p; func_0203064C(1,0x71,0x18000); p=func_0203159C(a,0x120,0x71); func_02082BCC(p,0,0x120); ((struct Obj21988 *)p)->f0=c; return 1; }




extern int (*D_021F7608[])(char *);




int func_021F6590(int a,int *b,int c,char *d) { *b=D_021F7608[*b](d); if(*b==5) return 1; func_0202CD94(*(struct WinMgr * *)&((struct Obj10194 *)d)->f8); func_021F6B38(d); func_0204A600(); return 0; }




int func_021F65C4(void *p) { func_020315D4(p); func_020306F0(0x71); return 1; }





void func_021F65D4(int a)
{
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_021F6A28((int *)a);
    func_021F682C();
    func_021F683C();
    func_021F68FC(a);
    func_021F6970((u8 *)a);
    func_021F6A98(a);
    func_021F6F24((struct P *)a);
    func_021F734C((struct P_021F734C *)a);
    func_0203D34C(1, 0x71);
    func_020434DC(0x17, 1);
    func_021F69E4((u8 *)a);
    func_021F67C8((u8 *)a, func_021F681C((u8 *)a, 0x80, 4));
}




int func_021F6654(u8 *p) { func_021F69FC(p); func_020434DC(0x17,0); func_021F75E0((int *)p); func_021F6F3C((char *)p); func_021F6B1C(p); func_021F69C0(p); func_021F68E0(); return 5; }




int func_021F6684(u8 *p) { if(func_020221A4()==1) return ((struct Obj21989 *)p)->f118; return 2; }




int func_021F669C(u8 *p) { if(((struct Obj10193 *)p)->f11C==0) return ((struct Obj10193 *)p)->f114; (((struct Obj10193 *)p)->f11C)--; return 3; }




/*
 * lever: byte-pointer object base keeps field addresses inline instead
 * of the integer-base spelling's extra loop-invariant address register.
 */
int func_021F66B4(u8 *p)
{
    u32 i;
    switch (((struct Obj00111 *)p)->f110) {
    case 0:
        if (func_0201C6B4(((struct Obj00111 *)p)->f1C) == 0) break;
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 3, -1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 9, -1, 0, 16);
            }
        } else {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i, 1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 6, 1, 0, 16);
            }
        }
        func_020061E4(0x642);
        (((struct Obj00111 *)p)->f110)++;
    case 1:
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 3) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 3, -8);
        } else {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 0) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 0, 8);
        }
        break;
    case 2:
        return func_021F67F0(p, 1);
    }
    return 4;
}




int func_021F67C8(u8 *p, int value) { func_0202208C(0,1,1,0,6,1,0x71); ((struct Obj21990 *)p)->f118=value; return 2; }




/*
 * extent: trailing two-byte zero alignment padding.
 */
int func_021F67F0(u8 *p, int value) { func_0202208C(0,0,0,0,6,1,0x71); ((struct Obj21991 *)p)->f118=value; return 2; }




int func_021F681C(u8 *p, int count, int result) { ((struct Obj00111 *)p)->f11C = count; ((struct Obj00111 *)p)->f114 = result; return 3; }




void func_021F682C(void) { func_020433E0(&d_021F761C); }





void func_021F683C(void)
{
    Disp a;
    Bg b0;
    Bg b1;
    Bg b2;
    func_0203F8F4(0x71);
    a = d_021F75F8;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021F7688;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414EC(0);
    func_02040B94(0, 0x20, 0, 0x71);
    b1 = d_021F7668;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021F76A8;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
}




void func_021F68E0(void) { func_020403F4(2); func_020403F4(1); func_020403F4(0); func_0203F9B4(); }





void func_021F68FC(int a0)
{
    void *h;
    h = func_020490F4(0x64, 0x8071);
    func_02049658(h, 0x12, 2, 0, 0, 1, 0x8071);
    func_020498F4(h, 0, 2, 0, 0, 1, 0x8071);
    func_02049B68(h, 0x13, 0, 0, 0, 0x8071);
    func_020498F4(h, 0x10, 1, 0, 0x800, 1, 0x8071);
    func_02049238(h);
    func_02040EBC(4, 0);
}





void func_021F6970(u8 *p)
{
    ((struct Obj00111 *)p)->f14 = func_02045B38(0, 2, 0x12, 0x71);
    ((struct Obj00111 *)p)->fC = func_0201D7EC(0x17, 0, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f10 = func_0201D7EC(0x17, 3, 0, 0, 0x71);
    ((struct Obj00111 *)p)->f18 = func_0201EC64(0x71);
    ((struct Obj00111 *)p)->f1C = func_0201C450(0x800, 0x71);
}




void func_021F69C0(u8 *p) { func_02045C04(((struct Obj06345 *)p)->f14); func_0201D83C(((struct Obj06345 *)p)->fC); func_0201D83C(((struct Obj06345 *)p)->f10); func_0201ED04(((struct Obj06345 *)p)->f18); func_0201C4C0(((struct Obj06345 *)p)->f1C); }




void func_021F69E4(u8 *p) { ((struct Obj00111 *)p)->f4 = func_020056A0(func_021F6A08, p, 0); }




void func_021F69FC(u8 *p) { func_02030EAC((struct Node *)(((struct Obj21992 *)p)->f4)); }




static inline void OS_SetIrqCheckFlag(u32 intr) { *(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3ff8) |= intr; }




/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 021F6A18/021F6A1C, HW_INTR_CHECK_BUF.
 */
void func_021F6A08(void) { func_020419E4(); func_0204A648(); OS_SetIrqCheckFlag(1); }





void func_021F6A28(int *p)
{
    int *s;
    int a;
    int b;
    unsigned i;

    s = (int *)p[0];
    if (s[2] == 0) {
        a = s[0];
        b = s[1];
    } else {
        a = s[1];
        b = s[0];
    }
    for (i = 0; i < 3; i++) {
        if (func_0201AA18((void *)a) > i)
            p[0xf8 / 4 + i] = (int)func_0201AB28((void *)a, i);
        else
            p[0xf8 / 4 + i] = 0;
        if (func_0201AA18((void *)b) > i)
            p[0x104 / 4 + i] = (int)func_0201AB28((void *)b, i);
        else
            p[0x104 / 4 + i] = 0;
    }
}





void func_021F6A98(int a)
{
    unsigned int i;
    int *p;

    func_02045088(0x71);
    for (i = 0; i < 6; i++)
        *(int *)(a + i * 8 + 0x20) = func_020450F0(0, 0, 0, 0xf, 5, 9, 1);
    for (i = 0; i < 6; i++) {
        p = (int *)(a + i * 8);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[8])), 0);
        if (*(int *)(a + i * 4 + 0xf8) != 0) {
            func_021F6B7C(a, i);
            func_021F6CE4((Owner *)a, i);
            func_021F6D70((char *)a, i);
            func_021F6EE8(a, i);
        } else {
            func_02045334((struct Descriptor *)p[8]);
        }
    }
}




void func_021F6B1C(u8 *p) { u32 i; for(i=0; i<6; i++) { func_020452E8(*(void **)((u32)p+i*8+0x20)); } func_020450C8(); }





void func_021F6B38(char *p)
{
    unsigned i;
    char *e;
    int q;

    func_0201C4E4((struct PrintSys *)(((struct Obj10194 *)p)->f1C));
    for (i = 0; i < 6; i++) {
        q = ((struct Obj10194 *)p)->f1C;
        e = p + i * 8;
        if (((struct Obj07928 *)e)->f24 != 0) {
            if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj07928 *)e)->f20))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj07928 *)e)->f20);
                ((struct Obj07928 *)e)->f24 = 0;
            }
        }
    }
}



static inline void print_text(int p, u32 windows, u32 dirty, int i, void *s, int x, int y, u16 color)
{
    void *owner = ((struct Obj13675 *)p)->f1C;
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, y, (u32)s, ((struct Obj13675 *)p)->fC, color);
    *(u8 *)(dirty + i * 8) = 1;
}



static inline void print_right(int p, u32 windows, u32 dirty, int i, void *window, u32 id, u16 color)
{
    void *s = func_02045EC0(((struct Obj07929 *)p)->f14, id);
    u32 font = ((struct Obj07929 *)p)->fC;
    u32 w = func_02045738(window);
    s16_021F6B7C x = (s16_021F6B7C)(w * 8 - func_0201D304(s, ((struct Obj07929 *)p)->fC, 0));
    void *owner = ((struct Obj07929 *)p)->f1C;
    func_0201C724(owner, (u32)func_02045770(*(void **)(windows + i * 8)), x, 7, (u32)s, font, color);
    *(u8 *)(dirty + i * 8) = 1;
    func_02045808(s);
}



/*
 * lever: Named monster base/index and byte gender if/else retain the original scheduling; inline print helpers retain owner spills.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`windows = p;` before `windows = p + 0x20;`; `dirty = p;` before `dirty =
 * p + 0x24;`). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void func_021F6B7C(int p, int i)
{
    u32 windows, dirty, mons, mi;
    u8 gender;
    void *window, *t, *s;
    windows = p + 0x20;
    window = *(void **)(windows + i * 8);
    t = func_020457B0(0xc, 0x8071);
    s = func_02045EC0(((struct Obj05257 *)p)->f14, 0);
    mons = p + 0xf8;
    mi = i * 4;
    func_0201EEF4(((struct Obj05257 *)p)->f18, 0, *(void **)(mons + mi));
    func_0201F250(((struct Obj05257 *)p)->f18, t, s);
    dirty = p + 0x24;
    print_text(p, windows, dirty, i, t, 0x20, 7, 0x3dc0);
    func_02045808(s);
    func_02045808(t);
    if (func_02017E1C(*(void **)(mons + mi), 0xad, 0) == 1 &&
        func_02017E1C(*(void **)(mons + mi), 0x4c, 0) == 0) {
        gender = func_02017F00(*(void **)(mons + mi));
        if (gender == 0) print_right(p, windows, dirty, i, window, 0x16, 0x2960);
        else if (gender == 1) print_right(p, windows, dirty, i, window, 0x17, 0x31a0);
    }
}




static inline void print_window(Owner *a, Index b, void *t)
{
    void *owner = a->renderer;
    func_0201C724(owner,
                  (u32)func_02045770(a->window[(u32)b].text), 8, 0x20, (u32)t,
                  a->ink, 0x3dc0);
    a->window[(u32)b].dirty = 1;
}



/*
 * lever: six Window records initialized by matched 021F6A98; direct per-field Owner.window[b] accesses retain index scaling and recompute the dirty-byte address.
 * checks: 1 every callee copied from its own matched definition; 2 021F6A98 initializes six 8-byte records and gives the fixed bound; 3 enum zero gave84, readonly header38; 4 struct-array-per-field idiom closes38 to EXACT; 5 fresh idiom directory and matched neighbours read.
 * permuter: historical once-only types300 consumed; no repeat in wave77.
 */
void func_021F6CE4(Owner *a, Index b)
{
    struct U16Vec *t;
    void *u;
    unsigned char z = ZERO;

    t = func_020457B0(0x20, 0x8071);
    u = func_02045EC0(a->catalogue, 0xb);
    func_0201EFA4(a->formatter, 0,
                  func_02017E1C(*(void **)((u32)a + (u32)b * 4 + 0xf8), 0x9e, 0), 3, z, 1);
    func_0201F250(a->formatter, t, u);
    print_window(a, b, t);
    func_02045808(u);
    func_02045808(t);
}




static inline u8 center_x(u32 w)
{
    return 0x5c - (w >> 1);
}




/*
 * lever: 2026-10-05 (wD9r lane136): w8 is a narrow local (u8). mwcc does not schedule the reload of a
 *   spilled narrow local above the outgoing stack stores, so the block-3 x sum comes after them as in the
 *   image; a u32 w8 reload is hoisted (25 bytes in waves D3 to D9r). The centre shift is unsigned
 *   (lsrs), so the u8 width is widened to u32 before the shift; a plain u8 `w8 >> 1` gives asrs. An inline
 *   helper `center_x(u32 w)` gives the same EXACT bytes. Diagnostic that found it: the block-2 s16 local x
 *   used as the block-3 operand gave the image order, a u32/int x did not.
 */
void func_021F6D70(char *p, int idx)
{
    void *buf;
    void *t1;
    void *t2;
    void *t3;
    u8 w8;
    u8 r7;
    u32 f1;
    u32 f2;
    s16_021F6D70 x;
    u32 f3;
    u32 h;

    buf = func_020457B0(0x20, 0x8071);
    t1 = func_02045EC0(*(void **)(p + 0x14), 0xc);
    w8 = func_0201D304(t1, *(u32 *)(p + 0x10), 0);
    r7 = center_x(w8);
    {
        u32 y;
        f1 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f1, y, (s16_021F6D70)r7, 0x20, (u32)t1, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t1);

    t2 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, func_02017E1C((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa0, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t2);
    {
        u32 y;
        h = *(u32 *)(p + 0x10);
        x = r7 - func_0201D304(buf, h, 0);
        f2 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f2, y, x, 0x20, (u32)buf, h, 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t2);

    t3 = func_02045EC0(*(void **)(p + 0x14), 0xd);
    func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x18)), 0, func_02017E1C((void *)(*(u32 *)(p + 0xf8 + idx * 4)), 0xa1, 0), 3, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x18)), buf, t3);
    {
        u32 y;
        f3 = *(u32 *)(p + 0x1c);
        y = (u32)func_02045770((struct Descriptor *)(*(u32 *)(p + 0x20 + idx * 8)));
        func_0201C724((void *)f3, y, (s16_021F6D70)(r7 + w8), 0x20, (u32)buf, *(u32 *)(p + 0x10), 0x3dc0);
    }
    *(u8 *)(p + 0x24 + idx * 8) = 1;
    func_02045808(t3);
    func_02045808(buf);
}



void func_021F6EE8(unsigned p, unsigned i)
{
    unsigned base = p + 0x20;
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1b, 0x30, 1, 1);
    func_02043AF4(func_02045770(*(void **)(base + i * 8)), 0x40, 0x1c, 0x30, 1, 2);
}



void func_021F6F24(struct P *p)
{
    func_021F6F50();
    func_021F6F88((int)p);
    func_021F714C((struct P_021F714C *)p);
}


void func_021F6F3C(char *p)
{
    func_021F72BC(p);
    func_021F7108(p);
    func_021F6F80();
}


void func_021F6F50(void)
{
    struct Cfg c = d_021F764C;
    func_0204A48C(&c, (unsigned)&d_021F761C, 0x71);
}


void func_021F6F80(void) { func_0204A5AC(); }


static inline u32 IconBase(int obj)
{
    return (u32)&((struct Obj00410 *)obj)->fB4;
}


/*
 * lever: integer object base; the icon array address comes from a static
 * inline accessor of field fB4 (the inlined parameter and the result share
 * one spill slot: str p; adds #0xb4; str); merged icon is u16.
 * note 2026-10-05: replaced the stand-in `icons = p; icons = p + 0xb4;`
 * with the accessor IconBase(p). EXACT in --lang c99 and --lang c. An
 * accessor returning u32 * with icons[i] stores gives DIFF; one that copies
 * into a local and adds (r = obj; r += 0xb4) gives DIFF.
 */
void func_021F6F88(int p)
{
    u32 a, b;
    void *h;
    void *h2;
    u16 i, icon;
    u32 icons;
    h = func_020490F4(7, 0x8071);
    icons = IconBase(p);
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0xf8) != 0)
            icon = func_0201BA68(func_020185F4(*(void **)(p + i * 4 + 0xf8)));
        else
            icon = func_0201BABC(0, 0, 0, 0);
        *(int *)(icons + i * 4) = func_0204A6C8(h, icon, 0, 0, 0x71);
    }
    *(int *)&((struct Obj00410 *)p)->fD8 = func_0204ACEC(h, func_0201BC3C(), 0, 0, 0x71);
    a = func_0201BC78();
    b = func_0201BCEC();
    *(int *)&((struct Obj00410 *)p)->fE8 = func_0204AF28(h, a, b, 0x71);
    func_02049238(h);
    h2 = func_020490F4(func_020275E4(), 0x8071);
    ((struct Obj00410 *)p)->fD0 = func_0204A6C8(h2, 0xc, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE0 = func_0204ABF0(h2, 0xb, 0, 0x60, 0x71);
    ((struct Obj00410 *)p)->fF0 = func_0204AF28(h2, 0xf, 0x12, 0x71);
    ((struct Obj00410 *)p)->fCC = func_0204A6C8(h2, 0x41, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fDC = func_0204ABF0(h2, 0x42, 0, 0x80, 0x71);
    ((struct Obj00410 *)p)->fEC = func_0204AF28(h2, 0x45, 0x48, 0x71);
    ((struct Obj00410 *)p)->fD4 = func_0204A6C8(h2, func_0202775C(2), 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE4 = func_0204ABF0(h2, func_02027758(), 0, 0xa0, 0x71);
    a = func_02027760(2);
    b = func_02027764(2);
    ((struct Obj00410 *)p)->fF4 = func_0204AF28(h2, a, b, 0x71);
    func_02049238(h2);
}



void func_021F7108(char *p)
{
    unsigned i;

    for (i = 0; i < 9; i++)
        func_0204A8D4(*(int *)(p + i * 4 + 0xb4));
    for (i = 0; i < 4; i++)
        func_0204ADA4(*(int *)(p + i * 4 + 0xd8));
    for (i = 0; i < 4; i++)
        func_0204AFD8(*(int *)(p + i * 4 + 0xe8));
}


/*
 * prototype: 0204B294 result stored at 021F719C despite owner void; 020185F4 preserves and returns live r0; 0204B8C4 visible r1=0 retained.
 */
void func_021F714C(struct P_021F714C *p)
{
    u32 i;
    u16 species;
    p->bank = func_0204B100(24, 0, 0x71);
    for (i = 0; i < 24; i++) {
        p->actors.all[i] = func_0204B294(p->bank,
            p->tabA[d_021F76C8[i].i],
            p->tabB[d_021F76C8[i].j],
            p->tabC[d_021F76C8[i].k], &d_021F76C8[i], 0, 0x71);
    }
    for (i = 0; i < 6; i++) {
        if (p->mons[i] == 0) {
            func_0204B3DC(p->actors.set.a[i], 0);
            func_0204B3DC(p->actors.set.b[i], 0);
            func_0204B3DC(p->actors.set.d[i], 0);
        } else {
            func_0204B92C(p->actors.set.a[i], 1);
            func_0204B6F4(p->actors.set.a[i], func_0201BBE8(func_020185F4(p->mons[i])), 1);
            species = func_02017E1C(p->mons[i], 6, 0);
            if (species == 0) func_0204B3DC(p->actors.set.b[i], 0);
            else if (func_0202136C(species) == 1) {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 1);
            } else {
                func_0204B8C4(p->actors.set.b[i], 0);
                func_0204B878(p->actors.set.b[i], 0);
            }
        }
        func_0204B3DC(p->actors.set.c[i], 0);
    }
    if (((struct Obj21993 *)(p->parent))->f8 == 0) {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i + 3, 128);
            func_021F72DC((unsigned int)p, i + 9, 128);
            func_021F72DC((unsigned int)p, i + 15, 128);
            func_021F72DC((unsigned int)p, i + 21, 128);
        }
    } else {
        for (i = 0; i < 3; i++) {
            func_021F72DC((unsigned int)p, i, -128);
            func_021F72DC((unsigned int)p, i + 6, -128);
            func_021F72DC((unsigned int)p, i + 12, -128);
            func_021F72DC((unsigned int)p, i + 18, -128);
        }
    }
}


void func_021F72BC(char *p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x54));
    func_0204B1CC(*(struct Bank * *)&((struct Obj21994 *)p)->f50);
}


void func_021F72DC(unsigned p, unsigned i, int dx)
{
    struct PtS pt;
    unsigned base = p + 0x54;
    func_0204B454(*(struct Actor **)(base + i * 4), &pt, 0);
    pt.x = pt.x + dx;
    func_0204B404((struct Obj *)(*(struct Actor **)(base + i * 4)), (const struct Vec2 *)(&pt), 0);
}



void func_021F7308(int a, unsigned b, int c)
{
    unsigned i;

    for (i = b; i < b + 3; i++) {
        func_021F72DC(a, i, c);
        func_021F72DC(a, i + 6, c);
        func_021F72DC(a, i + 12, c);
        func_021F72DC(a, i + 18, c);
    }
}


void func_021F734C(struct P_021F734C *p)
{
    u16 i;
    u8 *palette, *buf;
    p->window = func_0202C9B4(2, 12, 0x71);
    for (i = 0; i < 6; i++) {
        func_0202CA3C(p->window, i, 1, 16, 6);
        func_0202CA3C(p->window, i + 6, 0, 16, 6);
        func_0202CEBC(p->window, i + 6, p->images[i].data);
    }
    palette = (u8 *)func_0204162C(1);
    buf = func_02030734(0x8071, 0xc0, 0, d_021F78C0, 0x606);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + i * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (p->mons[i]) func_0202CAC4(p->window, i, buf);
    for (i = 0; i < 6; i++) MIi_CpuCopy16(palette + (i + 18) * 64, buf + i * 32, 32);
    for (i = 0; i < 6; i++) if (!p->mons[i]) func_0202CAC4(p->window, i, buf);
    func_020307B0(buf);
    func_020414EC(1);
    if (((struct Obj21995 *)(p->parent))->f8 == 0) {
        for (i = 3; i < 6; i++) if (p->mons[i]) func_0202CE50(p->window, i, 0, 0, 16, 6, 5);
    } else {
        for (i = 0; i < 3; i++) if (p->mons[i]) func_0202CE50(p->window, i, 0, 0, 16, 6, 5);
    }
    if (((struct Obj21996 *)(p->parent))->f8 == 0) {
        func_0202CB4C(p->window, 0, 0, 0);
        func_0202CB4C(p->window, 1, 0, 6);
        func_0202CB4C(p->window, 2, 0, 12);
        func_0202CB4C(p->window, 6, 0, 0);
        func_0202CB4C(p->window, 7, 0, 6);
        func_0202CB4C(p->window, 8, 0, 12);
        func_0202CB4C(p->window, 3, 32, 1);
        func_0202CB4C(p->window, 4, 32, 7);
        func_0202CB4C(p->window, 5, 32, 13);
        func_0202CB4C(p->window, 9, 32, 1);
        func_0202CB4C(p->window, 10, 32, 7);
        func_0202CB4C(p->window, 11, 32, 13);
    } else {
        func_0202CB4C(p->window, 0, -16, 0);
        func_0202CB4C(p->window, 1, -16, 6);
        func_0202CB4C(p->window, 2, -16, 12);
        func_0202CB4C(p->window, 6, -16, 0);
        func_0202CB4C(p->window, 7, -16, 6);
        func_0202CB4C(p->window, 8, -16, 12);
        func_0202CB4C(p->window, 3, 16, 1);
        func_0202CB4C(p->window, 4, 16, 7);
        func_0202CB4C(p->window, 5, 16, 13);
        func_0202CB4C(p->window, 9, 16, 1);
        func_0202CB4C(p->window, 10, 16, 7);
        func_0202CB4C(p->window, 11, 16, 13);
    }
}
