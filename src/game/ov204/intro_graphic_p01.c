/*
 * file:     intro_graphic_p01.c
 * unit:     yes
 * function: func_021BDA40, func_021BDAE4, func_021BDB30, func_021BDB70, func_021BDC18, func_021BDCF0, func_021BDD4C, func_021BDD60, func_021BDD6C, func_021BDD78, func_021BDD84, func_021BDD98
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
 *   func_021BDE30 0x021BDE30 thumb ov204
 *   func_021BDF34 0x021BDF34 thumb ov204
 *   func_021BE03C 0x021BE03C thumb ov204
 *   func_021BDFA4 0x021BDFA4 thumb ov204
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021C09C0 0x021C09C0 data a4
 *   d_021BFE4C 0x021BFE4C data a4
 *   d_021BFE1C 0x021BFE1C data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE0D4 0x021BE0D4 thumb ov204
 *   func_021BDF74 0x021BDF74 thumb ov204
 *   func_021BDDF8 0x021BDDF8 thumb ov204
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BDF90  0x021BDF90  thumb  ov204
 *   func_021BDE10  0x021BDE10  thumb  ov204
 *   func_021BE0EC 0x021BE0EC thumb ov204
 *   func_021BE100 0x021BE100 thumb ov204
 *   func_021BDFA0 0x021BDFA0 thumb ov204
 *   func_021BDE28  0x021BDE28  thumb  ov204
 *   func_021BDF98  0x021BDF98  thumb  ov204
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFF1C 0x021BFF1C data a4
 */
#include "../../matched/include/Obj00689.h"
#include "../../matched/include/Obj25331.h"
#include "../../matched/include/Obj25332.h"
#include "../../matched/include/Obj25333.h"
#include "../../matched/include/Obj03918.h"
#include "../../matched/include/Obj03919.h"
#include "../../matched/include/Obj25334.h"
#include "../../matched/include/G_DispConfig.h"

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
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

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
extern void func_021BDE30(void *,u16);
extern void func_021BDF34(u8 *,int,int);
extern void func_021BE03C(void *,u32);
extern void func_021BDFA4(void *,u32);
extern void func_0201DD60(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *);
extern void func_021BE0D4(unsigned char *);
extern void func_021BDF74(unsigned char *);
extern void func_021BDDF8(unsigned char *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BDF90(void *a0);
extern void func_021BDE10(u8 *);
extern void func_021BE0EC(char *);
extern void func_021BE100(char *);
extern unsigned func_021BDFA0(char *);
extern void func_021BDE28(void *a0);
extern void func_021BDF98(void *a0);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
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
extern const char ov067_id[];
extern const unsigned short d_021BFDAC[][4];
extern const struct DispVram d_021BFE4C,d_021BFE1C;
extern const char d_021C09C0[];
extern const unsigned d_021BFF1C[][11];
extern struct DispConfig d_021BFD80;

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
