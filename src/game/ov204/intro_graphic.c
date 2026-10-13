/*
 * file:     intro_graphic.c
 * unit:     yes
 * function: func_021BDA40, func_021BDAE4, func_021BDB30, func_021BDB70, func_021BDC18, func_021BDCF0, func_021BDD4C, func_021BDD60, func_021BDD6C, func_021BDD78, func_021BDD84, func_021BDD98, func_021BDDF8, func_021BDE10, func_021BDE28, func_021BDE30, func_021BDF34, func_021BDF74, func_021BDF90, func_021BDF98, func_021BDFA4, func_021BE03C, func_021BE0D4, func_021BE0EC
 * address:  0x021BDA40
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021BF594 0x021BF594 thumb ov204
 *   func_021BF8DC 0x021BF8DC thumb ov204
 *   func_021BFC24 0x021BFC24 thumb ov204
 *   func_021BEF20 0x021BEF20 thumb ov204
 *   ov067_id 0x00000043 data
 *   func_021BFCD0 0x021BFCD0 thumb ov204
 *   func_021BF5E0 0x021BF5E0 thumb ov204
 *   func_021BF9D0 0x021BF9D0 thumb ov204
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021BEF74 0x021BEF74 thumb ov204
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BEF88  0x021BEF88  thumb  ov204
 *   func_021BF898  0x021BF898  thumb  ov204
 *   func_021BF610  0x021BF610  thumb  ov204
 *   func_021BFCE0  0x021BFCE0  thumb  ov204
 *   func_021BF9FC  0x021BF9FC  thumb  ov204
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BFDAC 0x021BFDAC data a2
 *   func_02030734 0x02030734 arm
 *   func_0204335C 0x0204335C arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021C09C0 0x021C09C0 data a4
 *   d_021BFE4C 0x021BFE4C data a4
 *   d_021BFE1C 0x021BFE1C data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFF1C 0x021BFF1C data a4
 *   func_020419E4 0x020419E4 arm
 *   d_021BFEFC 0x021BFEFC data a4
 *   d_021BFEDC 0x021BFEDC data a4
 *   d_021BFE7C 0x021BFE7C data a4
 *   d_021BFE9C 0x021BFE9C data a4
 *   d_021BFEBC 0x021BFEBC data a4
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B60 0x02048B60 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   d_021BFD68 0x021BFD68 data a4
 *   d_021BFD5C 0x021BFD5C data a4
 *   d_021BFD74 0x021BFD74 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021BFD4C 0x021BFD4C data a4
 *   d_021BFD54 0x021BFD54 data a4
 *   func_02048AD0 0x02048AD0 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02047970 0x02047970 arm
 */
#include "../../matched/include/Obj00689.h"
#include "../../matched/include/Obj25331.h"
#include "../../matched/include/Obj25332.h"
#include "../../matched/include/Obj25333.h"
#include "../../matched/include/Obj03918.h"
#include "../../matched/include/Obj03919.h"
#include "../../matched/include/Obj25334.h"
#include "../../matched/include/G_DispConfig.h"
#include "../../matched/include/Obj14602.h"
#include "../../matched/include/Obj25335.h"
#include "../../matched/include/Obj25336.h"
#include "../../matched/include/G_021BFD68.h"
#include "../../matched/include/G_021BFD5C.h"
#include "../../matched/include/G_021BFD74.h"
#include "../../matched/include/Obj14603.h"
#include "../../matched/include/Obj25337.h"

#define REG3D (*(volatile unsigned short *)0x04000060)
struct Obj0203159C;
struct GfFont;
struct MsgBank;
struct Rec;
struct S020315D4;
struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Light;
struct LightSet;
struct LightSlot;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

struct BgTemplate { u32 a,b,c,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; };

typedef struct { u32 x, y, z; } Vec3;

extern int func_02034AC4(int);
extern void func_0203064C(unsigned int, unsigned, unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void func_02082BCC(void *, unsigned, unsigned);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern struct MsgBank *func_02045B38(unsigned, unsigned, unsigned, unsigned);
extern void *func_021BF594(unsigned int heap, int kind);
extern char *func_021BF8DC(void *owner, int kind, u32 heap);
extern char *func_021BFC24(void *owner, unsigned heap);
extern char *func_021BEF20(void *, unsigned, unsigned, char *, unsigned, unsigned short);
extern void func_021BFCD0(char *);
extern void func_021BF5E0(u8 *p);
extern void func_021BF9D0(char *);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_021BEF74(u8 *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(s32 handle);
extern int func_021BEF88(char *p);
extern void func_021BF898(char *p);
extern void func_021BF610(u8 *p);
extern void func_021BFCE0(int);
extern void func_021BF9FC(char *p);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(BOOL, int, int, int);
extern void func_0207DD24(unsigned short, int, int, int, BOOL);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0204335C(u32);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0201DD60(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern u32 func_02043658(void);
extern void func_02041EE4(u32, u32, u32);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, u16 heap, void (*setup)(void));
extern u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                          Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B60(struct Light *l, const u32 *in);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_02048C4C(u32);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
/* Original consumes 02048AD0's live r0 through the next veneer call. */
extern void *func_02048AD0(struct Light *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047970(void);
int func_021BDA40(struct Obj0203159C *owner, int unused, char *args);
int func_021BDAE4(struct S020315D4 *owner, int unused1, int unused2, char *p);
int func_021BDB30(int a, int b, int c, void *p);
void func_021BDB70(void);
void *func_021BDC18(int swap, int mode, u16 heap);
void func_021BDCF0(unsigned char *p);
void func_021BDD4C(u8 *p);
void func_021BDD60(char *p);
void func_021BDD6C(char *p);
unsigned func_021BDD78(char *p);
void func_021BDD84(u32 a, u8 *b);
void func_021BDD98(void *p, unsigned heap);
void func_021BDDF8(u8 *p);
void func_021BDE10(u8 *a0);
void func_021BDE28(void *a0);
void func_021BDE30(void *p,u16 heap);
void func_021BDF34(unsigned char *p, int a, int b);
void func_021BDF74(u8 *p);
void func_021BDF90(void *a0);
void func_021BDF98(void *a0);
unsigned func_021BDFA0(char *p);
void func_021BDFA4(u8 *p, u16 heap);
void func_021BE03C(u8 *p, u16 heap);
void func_021BE0D4(u8 *p);
void func_021BE0EC(char *p);
void func_021BE100(char *unused);
int func_021BE108(void);
extern const char ov067_id[];
extern const unsigned short d_021BFDAC[][4];
extern const struct DispVram d_021BFE4C,d_021BFE1C;
extern const char d_021C09C0[];
extern const unsigned d_021BFF1C[][11];
extern struct DispConfig d_021BFD80;
extern const struct BgTemplate d_021BFEFC,d_021BFEDC,d_021BFE7C,d_021BFE9C,d_021BFEBC;
extern struct G_021BFD68 d_021BFD68;
extern struct G_021BFD5C d_021BFD5C;
extern struct G_021BFD74 d_021BFD74;
extern const short d_020A1EB8[];
extern const struct LightSet d_021BFD4C;
extern const struct LightSet d_021BFD54;


int func_021BDA40(struct Obj0203159C *owner, int unused, char *args)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_0203064C(1, 111, 0x100000);
    p = func_0203159C(owner, 0x24, 111);
    func_02082BCC(p, 0, 0x24);
    ((struct Obj00689 *)p)->f0 = 111;
    *(char * *)&((struct Obj00689 *)p)->f4 = args;
    *(unsigned char * *)&((struct Obj00689 *)p)->f8 = func_021BDC18(1, ((struct Obj25331 *)args)->f8, ((struct Obj00689 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00689 *)p)->fC = func_0201D7EC(23, 0, 0, 0, ((struct Obj00689 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00689 *)p)->f10 = func_02045B38(0, 2, 65, ((struct Obj00689 *)p)->f0);
    *(char * *)&((struct Obj00689 *)p)->f18 = func_021BF594(((struct Obj00689 *)p)->f0, ((struct Obj25332 *)(*(char * *)&((struct Obj00689 *)p)->f4))->f8);
    ((struct Obj00689 *)p)->f1C = func_021BF8DC(*(unsigned char * *)&((struct Obj00689 *)p)->f8, ((struct Obj25333 *)(*(char * *)&((struct Obj00689 *)p)->f4))->f8, ((struct Obj00689 *)p)->f0);
    ((struct Obj00689 *)p)->f20 = func_021BFC24(*(unsigned char * *)&((struct Obj00689 *)p)->f8, ((struct Obj00689 *)p)->f0);
    *(char * *)&((struct Obj00689 *)p)->f14 = func_021BEF20(((struct Obj00689 *)p)->f1C, *(unsigned *)&((struct Obj00689 *)p)->f20, *(unsigned *)&((struct Obj00689 *)p)->f18, *(char * *)&((struct Obj00689 *)p)->f4, *(unsigned *)&((struct Obj00689 *)p)->f8, ((struct Obj00689 *)p)->f0);
    return 1;
}


int func_021BDAE4(struct S020315D4 *owner, int unused1, int unused2, char *p)
{
    unsigned short heap;
    func_021BFCD0(*(char * *)&((struct Obj03918 *)p)->f20);
    func_021BF5E0((u8 *)(*(char * *)&((struct Obj03918 *)p)->f18));
    func_021BF9D0(*(char * *)&((struct Obj03918 *)p)->f1C);
    func_02045C04(*(struct Rec * *)&((struct Obj03918 *)p)->f10);
    func_0201D83C(((struct Obj03918 *)p)->fC);
    func_021BEF74((u8 *)(*(char * *)&((struct Obj03918 *)p)->f14));
    func_021BDCF0(*(unsigned char * *)&((struct Obj03918 *)p)->f8);
    heap = ((struct Obj03918 *)p)->f0;
    func_020315D4(owner);
    func_020306F0((unsigned)heap);
    func_02034A5C((unsigned)ov067_id);
    return 1;
}



int func_021BDB30(int a, int b, int c, void *p)
{
    if (func_021BEF88((char *)(((struct Obj03919 *)p)->f14)) == 0) {
        return 1;
    }
    func_021BDD4C((u8 *)(((struct Obj03919 *)p)->f8));
    func_021BDD60((char *)(((struct Obj03919 *)p)->f8));
    func_021BF898((char *)(((struct Obj03919 *)p)->f18));
    func_021BF610((u8 *)(((struct Obj03919 *)p)->f18));
    func_021BFCE0(((struct Obj03919 *)p)->f20);
    func_021BF9FC((char *)(((struct Obj03919 *)p)->f1C));
    func_021BDD6C((char *)(((struct Obj03919 *)p)->f8));
    return 0;
}


static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }


static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }


static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)0x04000340 = ref; } else REG3D &= (unsigned short)~0x3004; }


static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }


static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }


/*
 * volatile: 021BDB80 BG0CNT; 021BDB8E..021BDBC2 DISP3DCNT repeated hardware updates; 021BDBE0 viewport.
 */
void func_021BDB70(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) func_02046A94((unsigned char)i, d_021BFDAC[i]);
    func_02046BE0(0, 0);
}


void *func_021BDC18(int swap, int mode, u16 heap)
{
    u8 *p;
    p=func_02030734(heap,20,0,d_021C09C0,406);
    func_02082BCC(p,0,20);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    func_0204335C(0);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    if (mode==7) {
        func_020433E0(&d_021BFE4C);
        func_021BDE30(p,heap);
        func_021BDF34(p+4,(u32)&d_021BFE1C,heap);
        func_021BE03C(p+8,heap);
    } else {
        func_020433E0(&d_021BFE1C);
        func_021BDD98(p,heap);
        func_021BDF34(p+4,(u32)&d_021BFE1C,heap);
        func_021BDFA4(p+8,heap);
    }
    func_0201DD60();
    *(void **)(p+16)=func_020056A0((u32)func_021BDD84,(u32)p,0);
    return p;
}


/*
 * volatile: 021BDD1E and 021BDD28 read hardware DISPCNT for masked updates.
 */
void func_021BDCF0(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj25334 *)p)->f10);
    func_021BE0D4(p + 8);
    func_021BDF74(p + 4);
    func_021BDDF8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p, 0, 0x14);
    func_020307B0(p);
}



/*
 * Addresses are Black-image addresses.
 */
void func_021BDD4C(u8 *p)
{
    func_021BDF90(p + 4);
    func_021BDE10(p);
}


void func_021BDD60(char *p){func_021BE0EC(p+8);}


void func_021BDD6C(char *p){func_021BE100(p+8);}


unsigned func_021BDD78(char *p){return func_021BDFA0(p+4);}



void func_021BDD84(u32 a, u8 *b)
{
    func_021BDE28(b);
    func_021BDF98(b + 4);
}


void func_021BDD98(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&(*(struct DispConfig *)&d_021BFD80));
    for (i = 0; i < 4; i++) {
        row = d_021BFF1C[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}



/*
 * Addresses are Black-image addresses.
 */
void func_021BDDF8(u8 *p)
{
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}



void func_021BDE10(u8 *a0)
{
    if (func_02043658() & 4) {
        func_02041EE4(2, 1, 1);
    }
}


void func_021BDE28(void *a0) { func_020419E4(); }


void func_021BDE30(void *p,u16 heap)
{
    struct BgTemplate t1,t2,t3,t4,t5;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_021BFD80);
    t1=d_021BFEFC;
    func_0203FCA0(1,&t1,0);
    t2=d_021BFEDC;
    func_0203FCA0(2,&t2,0);
    t3=d_021BFE7C;
    func_0203FCA0(3,&t3,0);
    t4=d_021BFE9C;
    func_0203FCA0(4,&t4,0);
    t5=d_021BFEBC;
    func_0203FCA0(6,&t5,0);
    func_02040588(1,1);
    func_02040588(3,1);
    func_02040588(4,1);
    func_02040588(6,1);
}



void func_021BDF34(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BFD90, a, b);
    ((struct Obj14602 *)p)->f0 = func_0204B100(0x80, 0, b);
    func_0204B270(((struct Obj14602 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}



void func_021BDF74(u8 *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj25335 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}


void func_021BDF90(void *a0){func_0204A600();}


void func_021BDF98(void *a0){func_0204A648();}


unsigned func_021BDFA0(char *p){return ((struct Obj25336 *)p)->f0;}


/*
 * lever: the fourth 02048A24 argument is the pooled 0x1555 (earlier notes
 * decoded it as 0x155, which also moved the pool order). The heap parameter
 * is u8: with the callees' own prototypes (02046440 s16 heap, 02048A24 u16
 * heap, 02048BC4 u32 heap) a u8 converts to all three with no code, matching
 * the original's unnarrowed full-word stack stores; u16/s16/u32 each add a
 * lsls/asr|lsr pair (156-160 bytes). Twin: ov204_func_021BE03C.c.
 */
void func_021BDFA4(u8 *p, u16 heap)
{
    u32 far_clip, near_clip;
    func_02046440(0, 4, 0, 2, 0, heap, func_021BDB70);
    *(u32 **)p = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&d_021BFD68), ((Vec3 *)&d_021BFD5C), ((Vec3 *)&d_021BFD74), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    func_02048B6C(*(struct Light **)p, &far_clip);
    func_02048B60(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFD4C, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}


void func_021BE03C(u8 *p, u16 heap)
{
    u32 far_clip, near_clip;
    func_02046440(0, 2, 0, 2, 0, heap, func_021BDB70);
    *(u32 **)p = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, ((Vec3 *)&d_021BFD68), ((Vec3 *)&d_021BFD5C), ((Vec3 *)&d_021BFD74), heap);
    far_clip = 0x800000;
    near_clip = 0x19A;
    func_02048B6C(*(struct Light **)p, &far_clip);
    func_02048B60(*(struct Light **)p, &near_clip);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFD54, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}



void func_021BE0D4(u8 *p)
{
    func_02048C4C(((struct Obj14603 *)p)->f4);
    func_02048AC4((void *)(((struct Obj14603 *)p)->f0));
    func_02046788();
}


void func_021BE0EC(char *p){func_02048AD0(*(struct Light * *)&((struct Obj25337 *)p)->f0);func_02047964();func_020479D8();}


void func_021BE100(char *unused){func_02047970();}


int func_021BE108(void){return 1;}
