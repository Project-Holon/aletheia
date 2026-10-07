/*
 * file:     oekaki_p05.c
 * unit:     yes
 * function: func_021848E0, func_021849F8, func_02184B04, func_02184B34, func_02184B78, func_02184C48
 * address:  0x021848E0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_02186B3C     0x02186B3C  data  ov023  a4
 *   d_02186BCC     0x02186BCC  data  ov023  a4
 *   d_02186B6C     0x02186B6C  data  ov023  a4
 *   d_02186B8C     0x02186B8C  data  ov023  a4
 *   d_02186BAC     0x02186BAC  data  ov023  a4
 *   d_02186B4C     0x02186B4C  data  ov023  a4
 *   func_020457B0  0x020457B0  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02045CAC  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   d_02186F58     0x02186F58  data  ov023  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0207D534  0x0207D534  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02049238  0x02049238  arm
 */
#include "../../matched/include/Obj00049.h"
#include "../../matched/include/Obj09768.h"

struct DispConfig;
struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct Bank;
struct Cfg;
typedef struct { int w[4]; } B16;

typedef struct { int w[8]; } B32;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u8 e:3; u8 f:3; u8 g:2; u8 h[5]; } Rec;

typedef signed int     s32;

extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_02186558(char *p);
extern u16 func_02039338(void);
extern void func_02186444(char *p, u32 v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
void func_0207D534(volatile u16 *reg, int brightness);
void func_020403F4(u32 i);
void func_0203F9B4(void);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_02049238(void *h);
void func_021848E0(void);
void func_021849F8(u8 *p);
void func_02184B04(char *p);
void func_02184B34(void);
void func_02184B78(u8 *p, void *h);
void func_02184C48(u8 *p, void *q);
extern const B16 d_02186B3C;
extern const B32 d_02186BCC;
extern const B32 d_02186B6C;
extern const B32 d_02186B8C;
extern const B32 d_02186BAC;
extern const B32 d_02186B4C;
extern char d_02186F58[];
extern u8 d_020A1448[];
extern u8 d_02186ACC[];


void func_021848E0(void)
{
    B16 t;
    B32 t0;
    B32 t1;
    B32 t2;
    B32 t4;
    B32 t5;

    t = d_02186B3C;
    func_0203FC28((struct DispConfig *)(&t));

    t0 = d_02186BCC;
    func_0203FCA0(0, (const struct BgTemplate *)(&t0), 0);
    func_020414EC(0);

    t1 = d_02186B6C;
    func_0203FCA0(1, (const struct BgTemplate *)(&t1), 0);
    func_020414EC(1);

    t2 = d_02186B8C;
    func_0203FCA0(2, (const struct BgTemplate *)(&t2), 0);

    t4 = d_02186BAC;
    func_0203FCA0(4, (const struct BgTemplate *)(&t4), 0);
    func_020414EC(4);

    t5 = d_02186B4C;
    func_0203FCA0(5, (const struct BgTemplate *)(&t5), 0);

    func_02040B94(0, 0x20, 0, 0x28);
    func_02040B94(4, 0x20, 0, 0x28);
    func_02040B94(1, 0x20, 0, 0x28);
    func_02040B94(5, 0x20, 0, 0x28);
}


void func_021849F8(u8 *p)
{
    int i = 0;
    int z = i;

    for (; i < 5; i++) {
        *(u32 *)(p + i * 4 + 0x18) = (u32)func_020457B0(8, 0x28);
        ((Rec *)(p + 0x4216))[i].f = 0;
        *(u16 *)(p + i * 4 + 0x4232) = z;
        *(u32 *)(p + 0x1C8 + i * 8) = z;
        *(u32 *)(p + 0x1CC + i * 8) = z;
    }
    ((struct Obj00049 *)p)->f2C = (u32)func_020457B0(0xA, 0x28);
    ((struct Obj00049 *)p)->f30 = (u32)func_020457B0(0x50, 0x28);
    ((struct Obj00049 *)p)->f420A = z;
    ((struct Obj00049 *)p)->f420B = 1;
    ((struct Obj00049 *)p)->f9E6C = 1;
    ((struct Obj00049 *)p)->f9E70 = z;
    ((struct Obj00049 *)p)->f1AC = 2;
    ((struct Obj00049 *)p)->f1B0 = func_02186558((char *)p);
    ((struct Obj00049 *)p)->f9E74 = z;
    ((struct Obj00049 *)p)->f9E78 = z;
    ((struct Obj00049 *)p)->f198 = z;
    ((struct Obj00049 *)p)->f9E7C = z;
    ((struct Obj00049 *)p)->f9E80 = z;
    ((struct Obj00049 *)p)->f178 = z;
    func_02039338();
    func_02186444((char *)p, 4);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00049 *)p)->f14), 7, (void *)(((struct Obj00049 *)p)->f2C));
    ((struct Obj00049 *)p)->f4288 = func_02030734(0x28, 0x3C00, z, d_02186F58, 0x31D);
    ((struct Obj00049 *)p)->f1A8 = z;
}

void func_02184B04(char *p)
{
    int i;
    func_020307B0(((struct Obj09768 *)p)->f4288);
    for (i = 0; i < 5; i++)
        func_02045808(*(void **)(p + 0x18 + i * 4));
    func_02045808(((struct Obj09768 *)p)->f30);
    func_02045808(((struct Obj09768 *)p)->f2C);
}


void func_02184B34(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}


void func_02184B78(u8 *p, void *h)
{
    func_02049B68(h, 0, 0, 0, 0x180, 0x28);
    func_02049B68(h, 1, 4, 0, 0x180, 0x28);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x28);
    func_02049B40(0x17, 5, 4, 0x1A0, 0x20, 0x28);
    func_02049658(h, 2, 2, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 6, 2, 0, 0x600, 0, 0x28);
    func_02049658(h, 4, 5, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 7, 5, 0, 0x600, 0, 0x28);
    func_0201F5BC(0, 1, 10, 0, 0x28);
    func_0201F5BC(0, 0x1F, 11, 0, 0x28);
}


void func_02184C48(u8 *p, void *q)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x28);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_02186ACC, 0x28);
    ((struct Obj00049 *)p)->f38 = (u32)func_0204B100(0x35, 1, 0x28);
    ((struct Obj00049 *)p)->f40 = func_0204A6C8(q, 3, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f3C = func_0204ABF0(q, 0, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f44 = func_0204AF28(q, 5, 8, 0x28);
    ((struct Obj00049 *)p)->f4C = func_0204A6C8(h, func_02027618(), 0, 0, 0x28);
    ((struct Obj00049 *)p)->f48 = func_0204AC18(h, func_02027614(), 0, 0x160, 0, 3, 0x28);
    t = func_0202761C(0);
    ((struct Obj00049 *)p)->f50 = func_0204AF28(h, t, func_02027620(0), 0x28);
    ((struct Obj00049 *)p)->f58 = func_0204A6C8(q, 3, 0, 1, 0x28);
    ((struct Obj00049 *)p)->f54 = func_0204ABF0(q, 0, 1, 0, 0x28);
    ((struct Obj00049 *)p)->f5C = func_0204AF28(q, 5, 8, 0x28);
    func_02049238(h);
}
