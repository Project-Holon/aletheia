/*
 * file:     p_sta_oam_p03.c
 * unit:     yes
 * function: func_021D5180, func_021D51DC, func_021D5258, func_021D5280, func_021D52A8, func_021D52D4, func_021D54A8, func_021D5650, func_021D5A9C, func_021D5B58
 * address:  0x021D5180
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D89FC 0x021D89FC thumb ov131
 *   func_021D9BD4 0x021D9BD4 thumb ov131
 *   func_021D694C 0x021D694C thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201C450 0x0201C450 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02035C08 0x02035C08 arm
 *   d_021DC114 0x021DC114 data a1
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021D5C98 0x021D5C98 thumb ov131
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021DBFA8 0x021DBFA8 data a2
 *   d_021DBFB8 0x021DBFB8 data a2
 *   FX_SinCosTable_ 0x020A1B38 data
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _ffix 0x0209C494 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D5BAC 0x021D5BAC thumb ov131
 *   func_021D5C4C 0x021D5C4C thumb ov131
 */
#include "../../matched/include/Obj10504.h"
#include "../../matched/include/Obj03814.h"
#include "../../matched/include/Obj08144.h"
#include "../../matched/include/Obj23123.h"
#include "../../matched/include/Obj00039.h"
#include "../../matched/include/Obj00136.h"

struct Obj;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct Rec;
struct Mon;
struct Sav;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 pad[9]; u16 x,y; } Palette;

struct Rect36 { unsigned char b[36]; };

typedef signed char s8;

typedef signed short s16;

struct Col4 { u16 c[4]; };

struct W {
    char pad[0x1a4];
    u16 ang;
    u16 x4[4];
    u16 pal4[4];
    u16 a16[16];
    u16 b16[16];
    u16 o16[16];
    u16 o3[16];
    u16 i3[16];
};

typedef signed int     s32;

extern void func_021D89FC(void *unused, unsigned char *s);
extern void func_021D9BD4(void *a, u8 *p);
extern void func_021D694C(void *a, unsigned char *p);
extern void func_0204B3B4(struct Obj *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void *func_0201C450(u16,u32);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern int func_02035C08(const void *key);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021D5C98(u8 *p);
extern int func_021D62E4(char *);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021D5BAC(unsigned char *p, int direction, unsigned short *out);
extern void func_02017528(struct Sav *p);
extern u32 func_020307B0(void *p);
extern void *func_021D6064(unsigned char *p);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_021D5C4C(unsigned char *p);
void func_021D5180(char *p);
void func_021D51DC(char *p);
void func_021D5258(char *p);
void func_021D5280(char *p);
void func_021D52A8(char *p);
int func_021D52D4(char *p);
void func_021D54A8(char *p);
s32 func_021D5650(struct W *p);
void func_021D5A9C(char *p,int a);
int func_021D5B58(unsigned char *p,int a);
extern const struct Rect36 d_021DC114;
extern const struct Col4 d_021DBFA8;
extern const struct Col4 d_021DBFB8;
extern const s16 FX_SinCosTable_[];

void func_021D5180(char *p)
{
    u8 i;
    func_021D89FC(p,((struct Obj10504 *)p)->f94);
    func_021D9BD4(p,((struct Obj10504 *)p)->f90);
    func_021D694C(p,((struct Obj10504 *)p)->f88);
    for (i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x178));
    for (i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x198));
}

void func_021D51DC(char *p)
{
    ((struct Obj03814 *)p)->f80=func_0201D7EC(23,0,0,0,((struct Obj03814 *)p)->f0);
    ((struct Obj03814 *)p)->f7C=func_02045B38(0,2,158,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,0,448,32,((struct Obj03814 *)p)->f0);
    func_02049B40(23,5,4,448,32,((struct Obj03814 *)p)->f0);
    {
        enum { COLOR=0x4e59 } color=COLOR;
        enum { BASE=0x050005c0 } base=BASE;
        ((Palette *)base)->x=color;
        ((Palette *)base)->y=0x6a52;
    }
    ((struct Obj03814 *)p)->f84=func_0201C450(4096,((struct Obj03814 *)p)->f0);
}

void func_021D5258(char *p)
{
    func_0201C6EC(((struct Obj08144 *)p)->f84);
    func_0201C4C0(((struct Obj08144 *)p)->f84);
    func_02045C04(((struct Obj08144 *)p)->f7C);
    func_0201D83C(((struct Obj08144 *)p)->f80);
}

void func_021D5280(char *p)
{
    struct Rect36 r = d_021DC114;
    ((struct Obj23123 *)p)->f24 = func_02035C08(&r);
}

void func_021D52A8(char *p)
{
    if (((struct Obj00039 *)p)->f44 == 1 && func_0201C6B4(((struct Obj00039 *)p)->f84) == 1 && func_021D52D4(p) == 0) {
        func_021D54A8(p);
    }
}

int func_021D52D4(char *p)
{
    int max;
    if (func_0203633C() & 0x80) {
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,3);
            func_0204B878(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x40) {
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,11);
            func_0204B878(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x10) {
        max=2;
        if (((struct Obj00039 *)p)->f40==0) max=1;
        if (((struct Obj00039 *)p)->f58<max && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58+1);
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_0203633C() & 0x20) {
        if (((struct Obj00039 *)p)->f58>0 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=(int)((u32)((struct Obj00039 *)p)->f58-1);
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=0;
            return 1;
        }
    } else if (func_020362DC() & 2) {
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x400) && func_021D62E4(p)==1) {
        ((struct Obj00039 *)p)->f54=2;
        (*(u8 **)(p+8))[0x12]=2;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f190,8);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
        func_020061E4(1366);
        ((struct Obj00039 *)p)->f1C=0;
        return 1;
    } else if ((func_020362DC() & 0x800) && func_021D62E4(p)==1) {
        if (((struct Obj00039 *)p)->f58<3) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                func_0204B878(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                func_0204B878(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=0;
        }
        return 1;
    }
    return 0;
}

/*
 * arithmetic: signed p+58 guard accepts negatives; scaled address uses
 *   unsigned 32-bit multiply/add for the original wrapping lsl/add sequence.
 */
void func_021D54A8(char *p)
{
    switch (((struct Obj00039 *)p)->f24) {
    case 0:
        if (((struct Obj00039 *)p)->f58!=0) {
            ((struct Obj00039 *)p)->f58=0;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 1:
        if (((struct Obj00039 *)p)->f58!=1 && ((struct Obj00039 *)p)->f38==0) {
            ((struct Obj00039 *)p)->f58=1;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 2:
        if (((struct Obj00039 *)p)->f58!=2 && ((struct Obj00039 *)p)->f38==0 && ((struct Obj00039 *)p)->f40==1) {
            ((struct Obj00039 *)p)->f58=2;
            func_021D5C98((u8 *)p);
            func_020061E4(1637);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 3:
        if (((struct Obj00039 *)p)->f58<3 && func_021D62E4(p)==1) {
            if (*(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)==1) {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=0;
                func_0204B878(((struct Obj00039 *)p)->f184,6);
            } else {
                *(int *)((u32)p+0x60+(u32)((struct Obj00039 *)p)->f58*4)=1;
                func_0204B878(((struct Obj00039 *)p)->f184,7);
            }
            func_020061E4(1606);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 4:
        if (func_021D5B58((u8 *)p,0)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,11);
            func_0204B878(((struct Obj00039 *)p)->f18C,2);
            ((struct Obj00039 *)p)->f48=1;
            ((struct Obj00039 *)p)->f4C=0;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 5:
        if (func_021D5B58((u8 *)p,1)==1) {
            func_021D5C98((u8 *)p);
            func_0204B878(((struct Obj00039 *)p)->f188,3);
            func_0204B878(((struct Obj00039 *)p)->f18C,10);
            ((struct Obj00039 *)p)->f48=0;
            ((struct Obj00039 *)p)->f4C=1;
            func_020061E4(1636);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 6:
        if (func_021D62E4(p)==1) {
            ((struct Obj00039 *)p)->f54=2;
            (*(u8 **)(p+8))[0x12]=2;
            ((struct Obj00039 *)p)->f50=2;
            func_0204B878(((struct Obj00039 *)p)->f190,8);
            ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f190;
            func_020061E4(1366);
            ((struct Obj00039 *)p)->f1C=1;
        }
        break;
    case 7:
        ((struct Obj00039 *)p)->f54=1;
        (*(u8 **)(p+8))[0x12]=1;
        ((struct Obj00039 *)p)->f50=2;
        func_0204B878(((struct Obj00039 *)p)->f194,9);
        ((struct Obj00039 *)p)->f1A0=((struct Obj00039 *)p)->f194;
        func_020061E4(1361);
        ((struct Obj00039 *)p)->f1C=1;
        break;
    }
}

s32 func_021D5650(struct W *p)
{
    struct Col4 A;
    struct Col4 B;
    u16 ang;
    float t;
    u8 n_1;
    u16 ca_1, cb_1;
    s8 r_1, g_1, b_1;
    u16 ca_2, cb_2;
    s8 r_2, g_2, b_2;
    u16 ca_3;
    s8 r_3, g_3, b_3, r2_3, g2_3, b2_3;
    int IR_3, IG_3, IB_3;

    ang = p->ang;
    if (ang + 0x400 >= 0x10000) {
        p->ang = ang - 0xfc00;
    } else {
        p->ang = ang + 0x400;
    }
    A = d_021DBFA8;
    B = d_021DBFB8;
    t = (float)((FX_SinCosTable_[(p->ang >> 4) * 2] + 0x1000) / 2) / 4096.0f;

    for (n_1 = 0; n_1 < 4; n_1++) {
        ca_1 = A.c[n_1];
        r_1 = (s8)(ca_1 & 0x1f);
        g_1 = (s8)((ca_1 & 0x3e0) >> 5);
        b_1 = (s8)((ca_1 & 0x7c00) >> 10);
        cb_1 = B.c[n_1];
        r_1 = (s8)(int)((float)r_1 + t * (float)((s8)(cb_1 & 0x1f) - r_1));
        g_1 = (s8)(int)((float)g_1 + t * (float)((s8)((cb_1 & 0x3e0) >> 5) - g_1));
        b_1 = (s8)(int)((float)b_1 + t * (float)((s8)((cb_1 & 0x7c00) >> 10) - b_1));
        if (r_1 < 0) r_1 = 0;
        if (g_1 < 0) g_1 = 0;
        if (b_1 < 0) b_1 = 0;
        if (r_1 > 31) r_1 = 31;
        if (g_1 > 31) g_1 = 31;
        if (b_1 > 31) b_1 = 31;
        p->pal4[n_1] = (b_1 << 10) | ((g_1 << 5) | r_1);
    }
    func_02061CA4((void *)14, 0x6c, (u32)p->pal4, 8);

    for (n_1 = 0; n_1 < 16; n_1++) {
        ca_2 = p->a16[n_1];
        r_2 = (s8)(ca_2 & 0x1f);
        g_2 = (s8)((ca_2 & 0x3e0) >> 5);
        b_2 = (s8)((ca_2 & 0x7c00) >> 10);
        cb_2 = p->b16[n_1];
        r_2 = (s8)(int)((float)r_2 + t * (float)((s8)(cb_2 & 0x1f) - r_2));
        g_2 = (s8)(int)((float)g_2 + t * (float)((s8)((cb_2 & 0x3e0) >> 5) - g_2));
        b_2 = (s8)(int)((float)b_2 + t * (float)((s8)((cb_2 & 0x7c00) >> 10) - b_2));
        if (r_2 < 0) r_2 = 0;
        if (g_2 < 0) g_2 = 0;
        if (b_2 < 0) b_2 = 0;
        if (r_2 > 31) r_2 = 31;
        if (g_2 > 31) g_2 = 31;
        if (b_2 > 31) b_2 = 31;
        p->o16[n_1] = (b_2 << 10) | ((g_2 << 5) | r_2);
    }
    func_02061CA4((void *)14, 0x180, (u32)p->o16, 0x20);

    for (n_1 = 12; n_1 <= 14; n_1++) {
        ca_3 = p->i3[n_1];
        IR_3 = ca_3 & 0x1f;
        r_3 = (s8)IR_3;
        IG_3 = (ca_3 & 0x3e0) >> 5;
        g_3 = (s8)IG_3;
        IB_3 = (ca_3 & 0x7c00) >> 10;
        b_3 = (s8)IB_3;
        r2_3 = (s8)(IR_3 + 10);
        g2_3 = (s8)(IG_3 + 10);
        b2_3 = (s8)(IB_3 + 10);
        if (r2_3 > 31) r2_3 = 31;
        if (g2_3 > 31) g2_3 = 31;
        if (b2_3 > 31) b2_3 = 31;
        r_3 = (s8)(int)((float)r_3 + t * (float)(r2_3 - r_3));
        g_3 = (s8)(int)((float)g_3 + t * (float)(g2_3 - g_3));
        b_3 = (s8)(int)((float)b_3 + t * (float)(b2_3 - b_3));
        if (r_3 < 0) r_3 = 0;
        if (g_3 < 0) g_3 = 0;
        if (b_3 < 0) b_3 = 0;
        if (r_3 > 31) r_3 = 31;
        if (g_3 > 31) g_3 = 31;
        if (b_3 > 31) b_3 = 31;
        p->o3[n_1] = (b_3 << 10) | ((g_3 << 5) | r_3);
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)p->o3, 0x20);
}

void func_021D5A9C(char *p,int a)
{
    *(int *)&((struct Obj00136 *)p)->f44=a;
    if(a==0){
        func_0204B3DC(((struct Obj00136 *)p)->f178,0);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f180,0);
        func_0204B3DC(((struct Obj00136 *)p)->f184,0);
        func_0204B3DC(((struct Obj00136 *)p)->f188,0);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,0);
        func_0204B3DC(((struct Obj00136 *)p)->f190,0);
    }else{
        func_0204B3DC(((struct Obj00136 *)p)->f178,1);
        func_0204B3DC(((struct Obj00136 *)p)->f17C,1);
        if(((struct Obj00136 *)p)->f40==1) func_0204B3DC(((struct Obj00136 *)p)->f180,1);
        func_0204B3DC(((struct Obj00136 *)p)->f188,1);
        func_0204B3DC(((struct Obj00136 *)p)->f18C,1);
        if(func_021D62E4(p)==1){
            func_0204B3DC(((struct Obj00136 *)p)->f184,1);
            func_0204B3DC(((struct Obj00136 *)p)->f190,1);
        }
    }
}

int func_021D5B58(unsigned char *p,int a) {
 unsigned short n;
 int r=func_021D5BAC(p,a,&n);
 if(r==1) {
 ((struct Obj00039 *)p)->f18=n;
 if((*(unsigned char **)(p+8))[12]==2) {
 if(((struct Obj00039 *)p)->f258) {func_02017528(((struct Obj00039 *)p)->f258);func_020307B0(((struct Obj00039 *)p)->f258);}
 ((struct Obj00039 *)p)->f258=func_0201747C(func_021D6064(p),((struct Obj00039 *)p)->f0);
 }
 func_021D5C4C(p);
 }
 return r;
}
