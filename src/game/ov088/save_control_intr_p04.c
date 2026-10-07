/*
 * file:     save_control_intr_p04.c
 * unit:     yes
 * function: func_021BCE70, func_021BCE80, func_021BCF18, func_021BCF44, func_021BCF6C, func_021BCFD4, func_021BCFEC, func_021BD04C, func_021BD078, func_021BD0C8, func_021BD0D8, func_021BD0F4, func_021BD10C
 * address:  0x021BCE70
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
 *   func_0202F0B0  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 *   func_021BD188  0x021BD188  thumb  ov088
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02005654  0x02005654  thumb
 *   func_020070A4  0x020070A4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021DFF18  0x021DFF18  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   func_02007230  0x02007230  thumb
 *   func_0200725C  0x0200725C  thumb
 *   func_02007400  0x02007400  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   func_02087BCC  0x02087BCC  arm
 *   ov228_id       0x000000E4  data
 *   func_020221A4  0x020221A4  thumb
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021BD9B0     0x021BD9B0  data  a4
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02040EBC  0x02040EBC  arm
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020461E4  0x020461E4  arm
 *   func_020461D4  0x020461D4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *   func_020419E4  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02fe0000 data
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../../matched/include/Obj00578.h"
#include "../../matched/include/Obj04350.h"
#include "../../matched/include/Obj04351.h"

struct Ctrl;
struct Descriptor;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub020072A4Ctrl;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct Rec;
struct S02031140;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct Banks {
    u32 w[12];
} Banks;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

extern void func_0202F0B0(u8 *p);
extern int func_021BD188(char *p);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int func_02005654(int a, int b);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern int func_02034AC4(s32 handle);
extern void func_021DFF18(u32 heap);
extern void func_02034A5C(s32 handle);
extern void *func_02007230(struct Sub020071E4Ctrl *ctrl);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void func_02007400(char *a0, u32 a1, u32 a2);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_0200566C(void);
extern void func_02087BCC(u32 parameter);
extern u32 func_020221A4(void);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern u8 func_020461E4(void);
extern void func_020461D4(u8);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_020419E4(void);
extern void *func_020056A0(void (*)(void), void *, int);
void func_02030EAC(struct Node *n);
void func_021BCE70(void);
void func_021BCE80(u8 *p, int *a1);
void func_021BCF18(void *p, int *st);
void func_021BCF44(void);
void func_021BCF6C(void);
void func_021BCFD4(void);
void func_021BCFEC(u8 *p);
void func_021BD04C(unsigned char *p);
void func_021BD078(int *p);
void func_021BD0C8(unsigned char *p);
void func_021BD0D8(void);
void func_021BD0F4(void **p);
void func_021BD10C(int *p);
extern void *d_021BDA20;
extern char ov228_id[];
extern Banks d_021BD9B0;
extern A16 d_021BD980;
extern B32 d_021BD990;
extern unsigned int SDK_AUTOLOAD_DTCM_START;


void func_021BCE70(void)
{
    func_0202F0B0(d_021BDA20);
}


void func_021BCE80(u8 *p, int *a1)
{
    void *r;
    u32 i;

    if (func_021BD188((char *)p) == 0) {
        d_021BDA20 = func_0202EE30(0, ((struct Obj00578 *)p)->f1C, 0xf, 0x10, 0x81);
        func_020409B4(func_02045730(((struct Obj00578 *)p)->f1C));
        func_02005654((int)func_021BCE70, 0);
        r = func_020070A4();
        func_02034AC4((u32)ov228_id);
        func_021DFF18(0x81);
        func_02034A5C((u32)ov228_id);
        func_02007230(r);
        for (i = 0; i < 9; i++) {
            if (func_0200725C(r, i, 0x81) == 1)
                func_02007400(r, i, 0x81);
            func_020072A4(r, i);
        }
        func_0200566C();
        func_02087BCC(0);
    }
}


void func_021BCF18(void *p, int *st)
{
    if (func_020221A4() == 1) {
        func_021BD10C(p);
        func_021BD0C8(p);
        func_021BD04C(p);
        func_021BCFD4();
        *st = 8;
    }
}


void func_021BCF44(void)
{
    Banks b = d_021BD9B0;

    func_0204335C(0);
    func_020433E0((const struct DispVram *)(&b));
}


void func_021BCF6C(void)
{
    A16 a;
    B32 b;

    func_0203F8F4(0x81);
    a = d_021BD980;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BD990;
    func_0203FCA0(0, (const struct BgTemplate *)(&b), 0);
    func_020434DC(1, 1);
    func_02040EBC(0, 0x7D8C);
    func_02040EBC(4, 0x7D8C);
}


/*
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 */
void func_021BCFD4(void)
{
    func_020434DC(1, 0);
    func_020403F4(0);
    func_0203F9B4();
}


void func_021BCFEC(u8 *p)
{
    p[0xc] = func_020461E4();
    func_020461D4(0);
    ((struct Obj04350 *)p)->f8 = func_02045B38(0, 2, 1, 0x81);
    ((struct Obj04350 *)p)->f4 = func_0201D7EC(0x17, 0, 0, 0, 0x81);
    ((struct Obj04350 *)p)->f10 = func_020457B0(0x400, 0x81);
    ((struct Obj04350 *)p)->f18 = func_0203101C(0x81, 0x81, 1, 4);
    ((struct Obj04350 *)p)->f24 = func_02028590(0xf, 1, 0, 0x81);
}


void func_021BD04C(unsigned char *p)
{
    func_02028604((int)(((struct Obj04351 *)p)->f24));
    func_02031140(((struct Obj04351 *)p)->f18);
    func_02045808(((struct Obj04351 *)p)->f10);
    func_0201D83C(((struct Obj04351 *)p)->f4);
    func_02045C04(((struct Obj04351 *)p)->f8);
    func_020461D4(p[0x0C]);
}


void func_021BD078(int *p)
{
    int h = 0x81;
    int w = 0x1e;
    func_02045088(0x81);
    p[7] = func_020450F0(0, 1, 0x13, w, 4, 0xf, 1);
    func_0201F5BC(0, 1, 0xe, 0, h);
    func_02049B40(0x17, 5, 0, w << 4, 0x20, h);
}


void func_021BD0C8(unsigned char *p)
{
    func_020452E8(((struct Obj04351 *)p)->f1C);
    func_020450C8();
}


void func_021BD0D8(void)
{
    func_020419E4();
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}


void func_021BD0F4(void **p)
{
    *p = func_020056A0(func_021BD0D8, p, 0);
}


void func_021BD10C(int *p)
{
    func_02030EAC((struct Node *)p[0]);
}
