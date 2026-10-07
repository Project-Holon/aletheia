/*
 * file:     save_control_intr_p02.c
 * unit:     yes
 * function: func_021BC52C, func_021BC568, func_021BC62C, func_021BC734, func_021BC75C, func_021BC84C, func_021BC870
 * address:  0x021BC52C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450C8 0x020450C8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021BC8AC  0x021BC8AC  thumb  ov088
 *   func_020083EC  0x020083EC  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02008450  0x02008450  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021BC944  0x021BC944  thumb  ov088
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02045088  0x02045088  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0204E720  0x0204E720  arm
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045B38  0x02045B38  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../../matched/include/Obj02128.h"
#include "../../matched/include/Obj20830.h"
#include "../../matched/include/Obj06206.h"

#define W(o) (*(u32 *)(p + (o)))
struct S020315D4;
struct Flags02008450;
struct Sub0200852CObj;
struct W;
struct GfFont;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef signed short s16;

extern unsigned int func_0201D83C(void *ptr);
extern void func_020450C8(void);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(u32 a);
extern int func_021BC8AC(u8 *p);
extern void func_020083EC(unsigned short *p, unsigned int v);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_02008450(struct Flags02008450 *p, int on);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern s32 func_021BC944(struct W *w);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02045088(u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(int a);
extern void func_020409B4(unsigned int a);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
int func_021BC52C(int a,int b,int c,u8 *p);
int func_021BC568(int a, int b, int *s, int *q);
void func_021BC62C(char *p);
void func_021BC734(const void *p,int bg);
void func_021BC75C(u8 *p);
void func_021BC84C(u8 *p);
void func_021BC870(unsigned char *p);
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];

int func_021BC52C(int a,int b,int c,u8 *p) { func_021BC84C(p);func_0201D83C((void *)(((struct Obj02128 *)p)->f8));func_020450C8();func_020403F4(3);func_020403F4(1);func_020403F4(5);func_0203F9B4();func_020315D4((struct S020315D4 *)a);func_020306F0(0x39);return 1; }


int func_021BC568(int a, int b, int *s, int *q)
{
    int r;

    switch (q[1]) {
    case 0:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_020083EC((void *)s[1], 0);
            else
                func_020083EC((void *)s[1], 1);
            func_021BC84C((u8 *)q);
            q[1] = 1;
            func_021BC75C((u8 *)q);
        }
        break;
    case 1:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_0200854C((struct Sub0200852CObj *)s[2], 0);
            else
                func_0200854C((struct Sub0200852CObj *)s[2], 1);
            func_021BC84C((u8 *)q);
            q[1] = 2;
            func_021BC75C((u8 *)q);
        }
        break;
    case 2:
        r = func_021BC8AC((u8 *)q);
        if (r != 0) {
            if (r == 1)
                func_02008450((void *)s[1], 1);
            else
                func_02008450((void *)s[1], 0);
            func_0202208C(0, 0, 0, 0, 0xc, 1, 0x39);
            q[1] = 3;
        }
        break;
    case 3:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    func_021BC944((struct W *)q);
    return 0;
}


/*
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */
void func_021BC62C(char *p)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    func_020433E0((const struct DispVram *)d_021BD8B8);
    func_0203F8F4(0x39);
    func_0203FC28((struct DispConfig *)d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    func_021BC734(d_021BD858, 3);
    func_021BC734(d_021BD878, 1);
    func_021BC734(d_021BD898, 5);
    func_02045088(0x39);
    func_02049B40(0x17, 5, 0, 0, 0x20, 0x39);
    func_02049B40(0x17, 5, 4, 0, 0x20, 0x39);
    ((struct Obj20830 *)p)->f8 = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x39);
    func_0201F5BC(1, 1, 3, 0, 0x39);
    func_0201F5BC(1, 0x1f, 4, 0, 0x39);
    func_0201F5BC(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    func_0204E720(3, 0x10, 0, 0);
}

void func_021BC734(const void *p,int bg) { func_0203FCA0(bg,p,0);func_02040588(bg,1);func_020414AC(bg);func_020409B4(bg); }


void func_021BC75C(u8 *p)
{
    u32 arc;
    u32 s;
    u8 i;
    u8 *q;

    arc = (u32)func_02045B38(0, 2, 0xab, 0x39);
    p[0] = 0;
    W(0xc) = func_020450F0((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    func_02045374((struct Cfg *)W(0xc));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)W(0xc))), 0xf);
    s = (u32)func_02045EC0((struct MsgBank *)arc, W(4));
    func_0201F73C((void *)W(0xc), 0, 1, 1);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)W(0xc))), 2, 2, (void *)s, (void *)W(8));
    func_02045808((struct U16Vec *)s);
    func_02045334((struct Descriptor *)W(0xc));
    for (i = 0; i < 2; i++) {
        q = p + i * 4;
        ((struct Obj06206 *)q)->f10 = func_020450F0((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        func_02045374((struct Cfg *)(((struct Obj06206 *)q)->f10));
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 0xf);
        s = (u32)func_02045EC0((struct MsgBank *)arc, i + 5 + W(4) * 2);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 2, 2, (void *)s, (void *)W(8));
        func_02045808((struct U16Vec *)s);
        func_02045334((struct Descriptor *)((struct Obj06206 *)q)->f10);
    }
    func_02045C04((struct Rec *)arc);
    func_021BC870(p);
}

void func_021BC84C(u8 *p) { u8 i; func_020452E8(((struct Obj02128 *)p)->fC); for(i=0;i<2;i++) func_020452E8(*(void **)((u32)p+((u32)i*4)+16)); }

void func_021BC870(unsigned char *p) { unsigned char i; for(i=0;i<2;i++) { if(i==p[0]) func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,1,3); else func_0201F73C((void *)(*(unsigned *)(p+16+4*i)),0,31,4); } }
