/*
 * file:     ctvt_draw_p02.c
 * unit:     yes
 * function: func_021BD7D0, func_021BD820, func_021BD844, func_021BDB5C, func_021BDBC4, func_021BDC70, func_021BDCB8, func_021BDD6C, func_021BDEF0, func_021BDFDC, func_021BDFE4, func_021BDFEC, func_021BDFFC, func_021BE004, func_021BE00C, func_021BE010, func_021BE018, func_021BE024, func_021BE02C, func_021BE030, func_021BE034, func_021BE03C, func_021BE044, func_021BE04C, func_021BE054, func_021BE058, func_021BE05C, func_021BE078, func_021BE07C, func_021BE08C, func_021BE0A0, func_021BE0A4
 * address:  0x021BD7D0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082A90 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C450 0x0201C450 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0202F038  0x0202F038  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_021B8FB8 0x021B8FB8 thumb ov172
 *   func_021BBE5C 0x021BBE5C thumb ov172
 *   func_021BA8C4 0x021BA8C4 thumb ov172
 *   func_021B8CC8 0x021B8CC8 thumb ov172
 *   func_021BBA94 0x021BBA94 thumb ov172
 *   func_021BA2C4 0x021BA2C4 thumb ov172
 *   func_0202223C 0x0202223C thumb
 *   func_021B8084 0x021B8084 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021B7B80 0x021B7B80 thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B7B30 0x021B7B30 thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B9F98  0x021B9F98  thumb
 *   func_021B8720 0x021B8720 thumb ov172
 */
#include "../../matched/include/Obj24105.h"
#include "../../matched/include/Obj14310.h"
#include "../../matched/include/Obj01758.h"
#include "../../matched/include/Obj02215.h"
#include "../../matched/include/Obj02216.h"
#include "../../matched/include/Obj24107.h"
#include "../../matched/include/Obj24108.h"
#include "../../matched/include/Obj24109.h"
#include "../../matched/include/Obj24110.h"
#include "../../matched/include/Obj24111.h"
#include "../../matched/include/Obj24113.h"
#include "../../matched/include/Obj24114.h"
#include "../../matched/include/Obj24115.h"
#include "../../matched/include/Obj24116.h"
#include "../../matched/include/Obj24117.h"
#include "../../matched/include/Obj24118.h"
#include "../../matched/include/Obj24119.h"
#include "../../matched/include/Obj24120.h"
#include "../../matched/include/Obj24121.h"
#include "../../matched/include/Obj24122.h"
#include "../../matched/include/Obj24123.h"
#include "../../matched/include/Obj24125.h"
#include "../../matched/include/Obj24126.h"
#include "../../matched/include/Obj24127.h"

#define W(o) (*(u32 *)(p + (o)))
#define BG (*(void **)(p + 0x17c))
#define HEAP (*(u16 *)p)
struct Bank;
struct BgTemplate;
struct Sub0200852CObj;
struct Obj;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct Rec;
struct S02031140;
struct Cfg;
struct Descriptor;
struct StrObj;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int s32;

struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };

struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(u32 p);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32 which);
extern void func_020409B4(u32 index);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void func_02049238(void *arc);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *e, unsigned short f, unsigned short g);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201C450(u16 n, u32 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201DD68(void);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0202F038(u8 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_021B8FB8(void *,char *);
extern void func_021BBE5C(void *,char *);
extern void func_021BA8C4(u16 *a0, char *p);
extern void func_021B8CC8(void *,char *);
extern void func_021BBA94(void *a0, u8 *p);
extern void func_021BA2C4(void *a0, u8 *p);
extern void func_0202223C(u32 a, u32 color);
extern void func_021B8084(void *,char *);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern u32 func_021B7B30(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(u8 *p, u32 v);
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(u32 owner, void *b, short y, u32 c, void *d, u32 e, u32 f);
extern void func_02045808(struct U16Vec *vec);
extern int func_021B9F98(int unused, int *p);
extern void func_021B8720(void *a0, u32 *a1, u32 a2);
void func_021BD7D0(void *a0);
void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type);
void func_021BD844(u8 *p);
void func_021BDB5C(u8 *p);
void func_021BDBC4(u8 *p);
void func_021BDC70(u32 *a0);
void func_021BDCB8(u8 *p);
void func_021BDD6C(u8 *p);
void func_021BDEF0(u8 *p, char *a, u32 b);
u32 func_021BDFDC(void *p);
u32 func_021BDFE4(void *p);
int func_021BDFEC(void *p);
u32 func_021BDFFC(void *p);
u32 func_021BE004(void *p);
u16 func_021BE00C(u16 *p);
u32 func_021BE010(void *p);
u32 func_021BE018(void *p, int i);
u32 func_021BE024(void *p);
u32 func_021BE02C(void *p);
void func_021BE030(void *p, u32 v);
u32 func_021BE034(void *p);
u32 func_021BE03C(void *p);
u32 func_021BE044(void *p);
u32 func_021BE04C(void *p);
u8 func_021BE054(void *p);
void func_021BE058(void *p, u32 v);
int func_021BE05C(void *p);
u32 func_021BE078(void *p);
void func_021BE07C(u32 *p, u32 v);
void func_021BE08C(void *p);
void func_021BE0A0(void *p, u32 v);
u32 func_021BE0A4(void *p);






/*
 * Masks the display control word down to 0xffff1fff, hands the +0x1ac handle to
 * the two release probes and then drops priorities 7,6,5,4,1,0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD7D0(void *a0)
{
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    func_0204A5AC(func_0204B1CC((struct Bank *)(((struct Obj24105 *)a0)->f1AC)));
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}






void func_021BD820(const struct BgTemplate *tmpl, u32 bgId, u32 type)
{
    func_0203FCA0(bgId, tmpl, type);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}




void func_021BD844(u8 *p)
{
    struct Sub0200852CObj *t;
    void *dev;
    u32 o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct Sub0200852CObj *)func_02012944(*(void **)W(0x1f8));
    BG = func_020490F4(0xac, HEAP);
    if (func_02008550(t) == 0) {
        func_02049B68(BG, 7, 4, 0, 0xc0, HEAP);
    } else {
        func_02049B68(BG, 6, 4, 0, 0xc0, HEAP);
    }
    z = 0;
    func_02049658(BG, 0xb, 7, 0, z, z, HEAP);
    func_020498F4(BG, 0xe, 7, 0, z, z, HEAP);
    func_020409B4(7);
    func_02049B68(BG, 0, 0, 0x20, 0x20, HEAP);
    func_02049658(BG, 8, 1, 0, z, z, HEAP);
    func_020498F4(BG, 0xd, 1, 0, z, z, HEAP);
    func_020409B4(1);
    W(0x180) = func_0204ACEC(BG, 3, 0, 0, HEAP);
    W(0x190) = func_0204A6C8(BG, 0x18, 0, 0, HEAP);
    W(0x1a0) = func_0204AF28(BG, 0x14, 0x16, HEAP);
    W(0x184) = func_0204ACEC(BG, 3, 1, 0, HEAP);
    W(0x194) = func_0204A6C8(BG, 0x17, 0, 1, HEAP);
    W(0x1a4) = func_0204AF28(BG, 0x13, 0x15, HEAP);
    dev = func_020490F4(func_020275E4(), HEAP);
    func_02049B68(dev, func_02027624(), 0, 0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 0, 0, z, z, HEAP);
    func_02049B68(dev, func_02027624(), 4, 0xc0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 5, z, z, z, HEAP);
    func_020498F4(dev, func_0202762C(), 5, z, z, z, HEAP);
    func_020413B0(5, z, 0x15, 0x20, 3, 6);
    func_020409B4(5);
    W(0x18c) = func_0204AC18(dev, func_02027614(), z, 0xe0, z, 3, HEAP);
    W(0x19c) = func_0204A6C8(dev, func_02027618(), z, z, HEAP);
    W(0x188) = func_0204AC18(dev, func_02027614(), 1, 0xe0, z, 3, HEAP);
    W(0x198) = func_0204A6C8(dev, func_02027618(), z, 1, HEAP);
    W(0x1a8) = func_0204AF28(dev, func_0202761C(2), func_02027620(2), HEAP);
    func_02049238(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = func_021BE024(p);
    i0 = func_021BE018(p, 4);
    i1 = func_021BE018(p, z);
    i2 = func_021BE018(p, 8);
    W(0x1b0) = (u32)func_0204B294((void *)o, i0, i1, i2, &cfg, z, HEAP);
    func_0204B3DC((void *)W(0x1b0), z);
    func_0204B92C((void *)W(0x1b0), 1);
    if (func_02008550(t) == 0) {
        dev = func_02049F78(BG, 7, (u32)(&pal), HEAP);
    } else {
        dev = func_02049F78(BG, 6, (u32)(&pal), HEAP);
    }
    func_02082A90(pal->raw + 0xc0, p + 0x3c, 0x140);
    func_020307B0(dev);
}



void func_021BDB5C(u8 *p)
{
    u8 i;
    func_0204B3B4((struct Obj *)(((struct Obj14310 *)p)->f1B0));
    for (i = 0; i < 4; i++) func_0204ADA4(*(u32 *)(p + i * 4 + 0x180));
    for (i = 4; i < 8; i++) func_0204A8D4(*(u32 *)(p + i * 4 + 0x180));
    for (i = 8; i < 11; i++) func_0204AFD8(*(u32 *)(p + i * 4 + 0x180));
    func_02049238((void *)(((struct Obj14310 *)p)->f17C));
}



/*
 * Extent remainder: zero alignment halfword at 021BDC6E.
 */
void func_021BDBC4(u8 *p)
{
    ((struct Obj01758 *)p)->f1C8=(u32)func_0201D7EC(23,0,0,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1CC=(u32)func_02045B38(0,2,27,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D0=(u32)func_0201C450(0x800,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,0,0x140,32,((struct Obj01758 *)p)->f0);
    func_02049B40(23,5,4,0x140,32,((struct Obj01758 *)p)->f0);
    func_0201DD68();
    func_0201F5BC(4,0x140,9,0,((struct Obj01758 *)p)->f0);
    func_0201F5BC(0,0x200,9,0,((struct Obj01758 *)p)->f0);
    ((struct Obj01758 *)p)->f1D8=(u32)func_0203101C(((struct Obj01758 *)p)->f0,((struct Obj01758 *)p)->f0,1,0);
    ((struct Obj01758 *)p)->f1DC=0;
}




void func_021BDC70(u32 *a0)
{
    u32 i;
    u32 v;

    i = 0x77;
    v = a0[i];
    if (v != 0) {
        func_0202F038((u8 *)v);
        a0[i] = 0;
    }
    i = 0x76;
    func_02031140((struct S02031140 *)a0[i]);
    func_0201C6EC((struct PrintSys *)a0[i - 2]);
    func_0201C4C0((struct PrintSys *)a0[i - 2]);
    func_02045C04((struct Rec *)a0[i - 3]);
    func_0201D83C((void *)a0[i - 4]);
}


void func_021BDCB8(u8 *p)
{
    switch (*(u32 *)(p+8)) {
    case 1: func_021B8FB8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBE5C(p,*(char **)(p+0x1f0)); break;
    case 3: func_021BA8C4((u16 *)p,*(char **)(p+0x1ec)); break;
    }
    *(u32 *)(p+8)=*(u32 *)(p+12);
    switch (*(u32 *)(p+8)) {
    case 0: break;
    case 1: func_021B8CC8(p,*(char **)(p+0x1e8)); break;
    case 2: func_021BBA94(p,(u8 *)(*(char **)(p+0x1f0))); break;
    case 3: func_021BA2C4(p,(u8 *)(*(char **)(p+0x1ec))); break;
    case 5:
        func_0202223C(0,0);
        func_0202223C(1,0);
    case 4:
        func_021B8084(p,*(char **)(p+0x1e4));
        func_021B7578((int)p,*(char **)(p+0x1e0));
        func_021B7B80((int)p,*(char **)(p+0x1e0));
        break;
    }
}


void func_021BDD6C(u8 *p)
{
    u8 i;
    u32 found;
    u32 r;
    u32 m;
    u32 b;
    u32 w;
    found = 0;
    if (((struct Obj02215 *)p)->f8 == 3) {
        return;
    }
    r = func_021BE05C(p);
    for (i = found; i < 4; i++) {
        if (func_021B8BA4((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B8B8C((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i) != 1) continue;
        if (func_021B7B30((int)p, *(char * *)&((struct Obj02215 *)p)->f1E0, i) != 0) continue;
        m = 1 << i;
        if (m & p[0x1b4]) continue;
        {
            char *k = func_021B8B94((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4, i);
            if (r == 1) {
                if (i == 0) b = 2; else b = 3;
            } else {
                b = i;
            }
            func_021BDEF0(p, k, *(u32 *)(p + b * 4 + 0x1b8));
        }
        p[0x1b4] += (u8)m;
        p[0x1b5] += (u8)(1 << b);
    }
    for (i = 0; i < 4; i++) {
        m = 1 << i;
        if (!(p[0x1b5] & m)) continue;
        if (func_0201C6C4(((struct Obj02215 *)p)->f1D0, func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))) != 0) continue;
        w = *(u32 *)(p + i * 4 + 0x1b8);
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        p[0x1b5] -= (u8)m;
        found = 1;
    }
    if (found == 1) {
        u32 v = func_021B8B68((int)p, *(char * *)&((struct Obj02215 *)p)->f1E4);
        if (v != 0xff) {
            func_021BE210(p, v);
        }
    }
}


void func_021BDEF0(u8 *p, char *a, u32 b)
{
    void *s;
    int x;
    s = func_02008510(a, ((struct Obj02216 *)p)->f0);
    x = (0x60 - (u8)func_0201D304(s, ((struct Obj02216 *)p)->f1C8, 0)) / 2;
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x + 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x - 1, 1, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 2, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 0, s, ((struct Obj02216 *)p)->f1C8, 0x400);
    func_0201C724(((struct Obj02216 *)p)->f1D0, func_02045770((struct Descriptor *)b), x, 1, s, ((struct Obj02216 *)p)->f1C8, 0x3c00);
    func_02045808(s);
}



u32 func_021BDFDC(void *p)
{
    return ((struct Obj24107 *)p)->f1E0;
}



/*
 * Field getter, u32 at +0x1e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFE4(void *p)
{
    return ((struct Obj24108 *)p)->f1E4;
}



/*
 * Tail call to func_021B9F98, second argument the field at +0x1e8.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021B9F98 is ov172's own code ("ldr r0, [r1, #0x10]; bx lr"
 * after the pop at 0x021B9F94), inside ov172's window, so only ov172 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
int func_021BDFEC(void *p)
{
    return func_021B9F98((int)p, (int *)(((struct Obj24109 *)p)->f1E8));
}



/*
 * Field getter, u32 at +0x1f4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BDFFC(void *p)
{
    return ((struct Obj24110 *)p)->f1F4;
}



/*
 * Field getter, u32 at +0x1f8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE004(void *p)
{
    return ((struct Obj24111 *)p)->f1F8;
}



/*
 * Field getter, u16 at +0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BE00C(u16 *p)
{
    return *p;
}



u32 func_021BE010(void *p)
{
    return ((struct Obj24113 *)p)->f17C;
}



/*
 * Field getter, u32 at +0x180 of element i (stride 4).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE018(void *p, int i)
{
    return *(u32 *)((char *)p + i * 4 + 0x180);
}



/*
 * Field getter, u32 at +0x1ac.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE024(void *p)
{
    return ((struct Obj24114 *)p)->f1AC;
}


u32 func_021BE02C(void *p)
{
    return ((struct Obj24115 *)p)->f10;
}


void func_021BE030(void *p, u32 v)
{
    ((struct Obj24116 *)p)->f10 = v;
}



/*
 * Field getter, u32 at +0x1c8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE034(void *p)
{
    return ((struct Obj24117 *)p)->f1C8;
}



u32 func_021BE03C(void *p)
{
    return ((struct Obj24118 *)p)->f1CC;
}



/*
 * Field getter, u32 at +0x1d0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE044(void *p)
{
    return ((struct Obj24119 *)p)->f1D0;
}



/*
 * Field getter, u32 at +0x1d4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE04C(void *p)
{
    return ((struct Obj24120 *)p)->f1D4;
}



/*
 * Field getter, u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021BE054(void *p)
{
    return ((struct Obj24121 *)p)->f18;
}



/*
 * Set the u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE058(void *p, u32 v)
{
    ((struct Obj24122 *)p)->f18 = v;
}



/*
 * 1 for states 1 and 2, else 2.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE05C(void *p)
{
    u8 v = func_021BE054(p);
    if (v == 1) {
        return 1;
    }
    if (v == 2) {
        return 1;
    }
    return 2;
}



u32 func_021BE078(void *p)
{
    return ((struct Obj24123 *)p)->f1C;
}


void func_021BE07C(u32 *p, u32 v)
{
    func_021B8720(p, (u32 *)p[0x79], v);
}



/*
 * Tail call passing the inverted flag at +0x1c as the second argument.
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BE07C is ov172's own code (a tail call to func_021B8720
 * right after func_021BE078's bx lr), inside ov172's window, so only ov172
 * can be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
void func_021BE08C(void *p)
{
    u32 v = ((struct Obj24125 *)p)->f1C;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    func_021BE07C(p, v);
}


void func_021BE0A0(void *p, u32 v)
{
    ((struct Obj24126 *)p)->f1C = v;
}



/*
 * Field getter, u8 at +0x19.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE0A4(void *p)
{
    return ((struct Obj24127 *)p)->f19;
}
