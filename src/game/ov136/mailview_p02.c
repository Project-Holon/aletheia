/*
 * file:     mailview_p02.c
 * unit:     yes
 * function: func_021C4D14, func_021C4D54, func_021C4DA8, func_021C4DD4, func_021C4DE4, func_021C4EC4, func_021C4EEC, func_021C5114, func_021C515C
 * address:  0x021C4D14
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5470 0x021C5470 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021C52F8 0x021C52F8 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_0202DC08 0x0202DC08 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020433E0 0x020433E0 arm
 *   d_021C77C4 0x021C77C4 data a1
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   g_77F4 0x021C77F4 data
 *   g_7804 0x021C7804 data
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216B4 0x020216B4 thumb
 *   func_02021640 0x02021640 thumb
 *   func_0201F548 0x0201F548 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02049238 0x02049238 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020434DC 0x020434DC arm
 *   func_021C4534 0x021C4534 thumb ov136
 *   func_021C4528 0x021C4528 thumb ov136
 *   func_02021540 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj01751.h"
#include "../../matched/include/Obj00160.h"
#include "../../matched/include/Obj00540.h"
#include "../../matched/include/Obj05421.h"

struct Rec;
struct TaskMenuState;
struct U16Vec;
struct Bank;
struct PmsDraw;
struct Obj;
struct PrintSys;
struct DispVram;
struct PalAnmSlot;
struct Node;
struct Cfg;
struct CharBuf;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

struct BgSet { struct BgTemplate t[5]; };

typedef struct {
    void *win;
    u8 flag;
    u8 pad5[3];
} WinSlot;

typedef struct {
    u32 heapId;
    u8 pad4[0x44 - 4];
    void *win[7];
    WinSlot slot[6];
    u8 pad90[0x98 - 0x90];
    void *f98;
} Obj;

extern void func_021C5470(u8 *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021C52F8(u8 *p);
extern u32 func_0201C440(void *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern void func_0202DC08(struct Obj *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *);
extern void func_0204363C(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u8 func_0201F548(int i);
extern void func_0201DD68(void);
extern void func_02049238(void *h);
extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(u32 layer);
extern void func_020434DC(u32, u32);
extern int func_021C4534(void);
extern int func_021C4528(void *a);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02045088(u16);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 layer);
int func_021C4D14(u8 *p);
void func_021C4D54(u8 *p);
void func_021C4DA8(u8 *p);
void func_021C4DD4(void);
void func_021C4DE4(u32 *p);
void func_021C4EC4(void *p);
void func_021C4EEC(u8 *p);
void func_021C5114(u8 *p);
void func_021C515C(Obj *p);
extern const char d_021C77C4[];
extern const struct DispConfig g_77F4;
extern const struct BgSet g_7804;

int func_021C4D14(u8 *p)
{
    func_021C4DA8(p);
    func_021C5470(p);
    if (p + 0x28) func_02045C04(((struct Obj01751 *)p)->f20);
    func_02045808(((struct Obj01751 *)p)->f34);
    func_02027FD8(((struct Obj01751 *)p)->f108);
    func_021C52F8(p);
    func_021C5114(p);
    func_021C4EC4(p);
    return 1;
}

void func_021C4D54(u8 *p)
{
    ((struct Obj00160 *)p)->f158 = (void *)func_0201C440((void *)((u16)((struct Obj00160 *)p)->f0));
    ((struct Obj00160 *)p)->f154 = func_0204B100(8, 1, (u16)((struct Obj00160 *)p)->f0);
    ((struct Obj00160 *)p)->f148 = func_0202DB0C(*(u32 *)&((struct Obj00160 *)p)->f154, 0, *(u32 *)&((struct Obj00160 *)p)->f158, *(u32 *)&((struct Obj00160 *)p)->f24, 0, 4, (u16)((struct Obj00160 *)p)->f0);
    func_0202DE5C(((struct Obj00160 *)p)->f148, 0);
}

void func_021C4DA8(u8 *p)
{
    func_0202DC08(((struct Obj01751 *)p)->f148);
    func_0201C4C0(((struct Obj01751 *)p)->f158);
    ((struct Obj01751 *)p)->f158 = 0;
    func_0204B1CC(((struct Obj01751 *)p)->f154);
}

void func_021C4DD4(void)
{
    func_020433E0((const struct DispVram *)d_021C77C4);
}


void func_021C4DE4(u32 *p)
{
    func_021C4DD4();
    {
        struct DispConfig d = g_77F4;
        func_0203FC28(&d);
    }
    func_0204363C(0);
    {
        struct BgSet s = g_7804;
        func_0203FCA0(0, &s.t[0], 0);
        func_0203FCA0(1, &s.t[1], 0);
        func_0203FCA0(2, &s.t[2], 0);
        func_0203FCA0(3, &s.t[3], 0);
        func_0203FCA0(4, &s.t[4], 0);
    }
    func_020414EC(0);
    func_020414EC(1);
    func_020414EC(2);
    func_020414EC(3);
    func_020414EC(4);
    func_02040B94(0, 0x20, 0, (u16)(*p));
    func_02040B94(1, 0x20, 0, (u16)(*p));
    func_02040B94(2, 0x20, 0, (u16)(*p));
    func_02040B94(3, 0x20, 0, (u16)(*p));
    func_02040B94(4, 0x20, 0, (u16)(*p));
}

void func_021C4EC4(void *p)
{
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0204363C(1);
}


/*
 * note (2026-10-02): byte-correct; only the ABS32 word for func_021C4534 (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 */
void func_021C4EEC(u8 *p)
{
    u32 k = (*(u8 **)(p + 0x1C))[0xB];
    void *h = func_020490F4(0x9B, (u16)((struct Obj00540 *)p)->f0);
    u32 sz;
    u32 pal;
    u32 chr;

    func_0201F5BC(0, 1, 4, 0, (u16)((struct Obj00540 *)p)->f0);
    func_0201F5BC(0, 0xD, 6, 0, (u16)((struct Obj00540 *)p)->f0);
    pal = k + 0xC;
    func_02049658(h, pal, 3, 0, 0, 1, (u16)((struct Obj00540 *)p)->f0);
    func_02049658(h, pal, 4, 0, 0, 1, (u16)((struct Obj00540 *)p)->f0);
    chr = k + 0x18;
    sz = 0x800;
    func_020498F4(h, chr, 3, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
    func_020498F4(h, chr, 4, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
    func_02049B68(h, k, 4, 0, 0, (u16)((struct Obj00540 *)p)->f0);
    func_02049B40(0x17, 5, 0, 0xA0, 0x20, (u16)((struct Obj00540 *)p)->f0);
    ((struct Obj00540 *)p)->f38 = (u32)func_02021518(((struct Obj00540 *)p)->f0);
    func_0202155C((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0, 0xE0, (u16)((struct Obj00540 *)p)->f0);
    func_020216B4((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), h, k, (u16)((struct Obj00540 *)p)->f0, 0, 0x60, 0);
    func_02021640((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0x17, 7, (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x30);
    func_02021640((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 0x17, 5, (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x50);
    func_02021640((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 5, func_0201F548(0), (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x40);
    func_02021640((struct PalAnmSlot *)(((struct Obj00540 *)p)->f38), 5, func_0201F548(1), (u16)((struct Obj00540 *)p)->f0, 0, 0x20, 0x60);
    func_0201DD68();
    func_02049238(h);
    func_02041300(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    func_02041B6C(4);
    func_020434DC(1, 1);
    func_020434DC(2, 1);
    func_020434DC(8, 1);
    if (p[0xB] != 0) {
        h = func_020490F4(0x9B, (u16)((struct Obj00540 *)p)->f0);
        func_020498F4(h, 0x24, 2, 0, sz, 1, (u16)((struct Obj00540 *)p)->f0);
        func_02049238(h);
        ((struct Obj00540 *)p)->f3C = (void *)func_021C4534;
        ((struct Obj00540 *)p)->f40 = (void *)func_021C4528;
        func_020434DC(4, 1);
    }
}

void func_021C5114(u8 *p)
{
    func_020215A0(((struct Obj05421 *)p)->f38, 0);
    func_02021540(((struct Obj05421 *)p)->f38);
    ((struct Obj05421 *)p)->f38 = 0;
    func_02030EAC(((struct Obj05421 *)p)->fFC);
    func_02030DA4(((struct Obj05421 *)p)->fF8);
    func_020307B0(((struct Obj05421 *)p)->fF4);
    func_0207D63C((void *)0x04000050, 0, 0, 31, 0);
}


void func_021C515C(Obj *p)
{
    int i;
    void *w;

    func_02045088((u16)p->heapId);
    p->win[0] = (void *)func_020450F0(1, 0, 0, 1, 1, 5, 0);
    p->win[1] = (void *)func_020450F0(1, 3, 3, 0x1A, 4, 1, 0);
    p->win[2] = (void *)func_020450F0(1, 3, 8, 0x1A, 4, 1, 0);
    p->win[3] = (void *)func_020450F0(1, 3, 0xD, 0x1A, 4, 1, 0);
    p->win[4] = (void *)func_020450F0(1, 8, 0x13, 0xB, 2, 1, 0);
    p->win[5] = (void *)func_020450F0(1, 0x15, 0x13, 8, 2, 1, 0);
    p->win[6] = (void *)func_020450F0(0, 2, 1, 0x1C, 4, 5, 1);
    for (i = 0; i < 6; i++) {
        p->slot[i].win = p->win[i];
        p->slot[i].flag = 0;
    }
    p->f98 = (void *)func_0201C440((void *)((u16)p->heapId));
    for (i = 0; i < 7; i++) {
        func_02043B5C(func_02045770(p->win[i]), 0);
        if (i < 5) {
            w = p->win[i];
            func_02045334(w);
            func_02045374(w);
            func_020409B4(func_02045730(w));
        }
    }
}
