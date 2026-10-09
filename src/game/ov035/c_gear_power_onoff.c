/*
 * file:     c_gear_power_onoff.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF2C, func_021EFF3C, func_021EFF78, func_021EFFD4, func_021F000C, func_021F0100, func_021F0140, func_021F015C, func_021F0168, func_021F0218, func_021F0254, func_021F0298, func_021F02FC, func_021F0340, func_021F0354, func_021F0364, func_021F0370, func_021F037C, func_021F0468
 * address:  0x021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0678    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021F0640 0x021F0640 data ov035 a4
 *   func_021A0FA0 0x021A0FA0 thumb ov021
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021A12D4 0x021A12D4 thumb ov021
 *   func_021A0FB4 0x021A0FB4 thumb ov021
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   d_021F05B0    0x021F05B0 data a4
 *   d_021F05BC    0x021F05BC data ov035 a4
 *   d_021F05C8    0x021F05C8 data ov035 a4
 *   d_021F05E8    0x021F05E8 data ov035 a4
 *   d_021F0608    0x021F0608 data ov035 a4
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045790 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0203101C 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   d_021F064C    0x021F064C data ov035 a4
 *   func_0202784C 0x0202784C thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02012204 0x02012204 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02026400 0x02026400 thumb
 *   func_02012158 0x02012158 thumb
 *   func_020121CC 0x020121CC thumb
 */
#include "../../matched/include/Obj02409.h"
#include "../../matched/include/Obj04315.h"
#include "../../matched/include/Obj05127.h"
#include "../../matched/include/Obj13078.h"
#include "../../matched/include/Obj20480.h"
#include "../../matched/include/Obj20481.h"
#include "../../matched/include/Obj09807.h"
#include "../../matched/include/Obj09808.h"
#include "../../matched/include/Obj06146.h"
#include "../../matched/include/Obj09809.h"
#include "../../matched/include/Obj13079.h"
#include "../../matched/include/Obj20482.h"
#include "../../matched/include/Obj20483.h"
#include "../../matched/include/Obj01129.h"
#include "../../matched/include/Obj01362.h"

struct Ctx;
struct PrintSys;
struct GfFont;
struct MsgBank;
struct Rec;
struct BgTemplate;
struct Sub0200852CObj;
struct R;
struct TaskMenuState;
struct CharBuf;
struct Descriptor;
struct Cfg;
struct Rec3;
struct S02031140;
struct U16Vec;
struct TaskMenu;
struct Comm;
struct IcaAnime;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct GearTable {
    int (*fn[3])(char *);
    int f0C;
    unsigned char pad10[0x10];
    int f20;
    unsigned char pad24[0x8];
    int f2C;
} GearTable;

typedef unsigned char  u8;

typedef signed short   s16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02012138(const struct Ctx *);
extern int func_0202EB44(void);
extern u32 func_0201214C(const struct Ctx *);
extern u32 func_020307B0(void *p);
extern void func_021A0FA0(int *p, int v);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void func_0201DD68(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int func_0201C440(void *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021A12D4(u32 *p, u32 x);
extern void func_021A0FB4(u32 *p, u32 a);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void func_02049238(void *h);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020403F4(u32 i);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02049B40(int, int, int, int, int, int);
extern void *func_0201F5DC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045790(struct Descriptor *p, u8 v);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern int func_0203101C(int, int, int, int);
extern int func_02028590(int, int, int, int);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F614(int, unsigned int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void func_0201F7A8(void *desc, u32 kind);
extern int func_0202784C(int a0, int a1);
extern int func_02027CD8(int a0, int a1);
extern void func_02027858(struct TaskMenu *m);
extern void func_02027974(void *p);
extern u8 func_02027A04(const u8 *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u32 func_020221A4(void);
extern int func_02035C60(void);
extern u32 func_02012204(const struct Ctx *p);
extern u32 func_02026454(void *h);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);
void *func_021EFEC0(int a0, int a1, u16 a2);
void func_021EFF2C(char *p);
void func_021EFF3C(char *p, int a1);
void func_021EFF78(char *p, u16 a1);
void func_021EFFD4(char *p);
void func_021F000C(char *p, u32 heap);
void func_021F0100(char *p);
void func_021F0140(char *p, u16 heap);
void func_021F015C(char *p);
void func_021F0168(int *p, int a1);
void func_021F0218(char *p);
void func_021F0254(char *p, int a1, int a2);
void func_021F0298(char *p, int a1, int a2, int a3);
void func_021F02FC(char *p, int a1);
void func_021F0340(char *p);
void func_021F0354(char *p);
u8 func_021F0364(char *p);
u32 func_021F0370(char *p);
int func_021F037C(char *p);
int func_021F0468(char *p);
extern char d_021F0678[];
extern GearTable d_021F0640;
extern const u32 d_021F05B0[];
extern const u32 d_021F05BC[];
extern const u8 d_021F05C8[];
extern const u8 d_021F05E8[];
extern const u8 d_021F0608[];
extern char d_021F064C[];



void *func_021EFEC0(int a0, int a1, u16 a2)
{
    char *p = (char *)func_02030734((u32)a2, 0x50, 1, d_021F0678, 0x12D);
    ((struct Obj02409 *)p)->f4 = a1;
    ((struct Obj02409 *)p)->f8 = func_02012138((const struct Ctx *)a1);
    *(int *)&((struct Obj02409 *)p)->fC = a0;
    ((struct Obj02409 *)p)->f0 = (short unsigned int)a2;
    func_021EFF78(p, a2);
    if (func_0202EB44() == 0)
        ((struct Obj02409 *)p)->f48 = 2;
    else if (func_0201214C((const struct Ctx *)a1) == 1)
        ((struct Obj02409 *)p)->f48 = 1;
    else
        ((struct Obj02409 *)p)->f48 = 0;
    func_021EFF3C(p, 1);
    return p;
}


void func_021EFF2C(char *p) { func_021EFFD4(p); func_020307B0(p); }


void func_021EFF3C(char *p, int a1) { if(((struct Obj02409 *)p)->f4E==0) { if(d_021F0640.fn[*(unsigned short *)(p+0x48)](p)) { func_021A0FA0(((struct Obj02409 *)p)->fC,14); ((struct Obj02409 *)p)->f4E=1; } } func_0201C4E4(((struct Obj02409 *)p)->f3C); }



void func_021EFF78(char *p, u16 a1)
{
    *(int *)&((struct Obj04315 *)p)->f34 = (int)func_0201D7EC(0x17, 0, 0, 0, (unsigned int)a1);
    func_0201DD68();
    ((struct Obj04315 *)p)->f38 = (int)func_02045B38(0, 2, 0x16, (unsigned int)a1);
    *(int *)&((struct Obj04315 *)p)->f3C = func_0201C440((void *)a1);
    func_021F000C(p, (u32)a1);
    func_021F0140(p, a1);
    func_021F0168((int *)p, (int)a1);
    func_0203D34C(0, (u32)a1);
    func_021A12D4((u32 *)(((struct Obj04315 *)p)->fC), (int)a1);
}


void func_021EFFD4(char *p) { func_021A0FB4(((struct Obj05127 *)p)->fC,((struct Obj05127 *)p)->f0); func_021F0218(p); func_021F015C(p); func_021F0100(p); func_0201C6EC(((struct Obj05127 *)p)->f3C); func_0201C4C0(((struct Obj05127 *)p)->f3C); func_02045C04(((struct Obj05127 *)p)->f38); func_0201D83C(((struct Obj05127 *)p)->f34); }




void func_021F000C(char *p, u32 heap)
{
    int i;
    void *h;
    u32 r;

    for (i = 4; i <= 7; i++)
        func_02040588((u8)i, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F0608, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588((u8)6, 1);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F05C8, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588((u8)5, 1);
    func_0203FCA0(4, (const struct BgTemplate *)d_021F05E8, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588((u8)4, 1);
    h = func_020490F4(0x1E, heap);
    i = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(((struct Obj13078 *)p)->f4)));
    func_02049B68(h, d_021F05BC[i], 4, 0, 1, heap);
    r = func_02049740(h, d_021F05B0[i], 6, 0, 0, heap);
    ((struct Obj13078 *)p)->f10 = r;
    func_02049990(h, 3, 6, 0, (u16)r, 0, 0, heap);
    func_02049238(h);
}




void func_021F0100(char *p)
{
    unsigned int v = ((struct Obj20480 *)p)->f10;
    func_0203FB44(6, (unsigned short)v, (unsigned short)(v >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}



void func_021F0140(char *p, u16 heap)
{
    ((struct Obj04315 *)p)->f40 = func_02027F60(4, 3, ((struct Obj04315 *)p)->f34, ((struct Obj04315 *)p)->f3C, heap);
}




void func_021F015C(char *p)
{
    func_02027FD8((struct TaskMenuState *)(((struct Obj20481 *)p)->f40));
}




void func_021F0168(int *p, int a1)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, a1);
    p[5] = (int)func_0201F5DC((void *)5, 2, 0, a1);
    p[6] = func_020450F0(5, 1, 1, 0x1E, 6, 1, 1);
    p[7] = func_020450F0(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    func_02045790((struct Descriptor *)p[6], 4);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)p[6]), 0xF);
    func_02045334((struct Descriptor *)p[6]);
    func_02045374((struct Cfg *)p[6]);
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)p[7]), 0xF);
    func_02045334((struct Descriptor *)p[7]);
    func_02045374((struct Cfg *)p[7]);
    p[8] = func_0203101C(a1, a1, 1, 4);
    p[0xC] = func_02028590(0xF, 0, 1, a1);
}



/*
 * interface: 0201F614 forwards r0 and splits packed r1 into two halfwords;
 *            02028604 uses only r0; legacy trailing inputs are unread.
 * 2026-10-05 (D8 lane 15): 0201F614 now filed EXACT as src/matched/arm9/func_0201F614.c (u16 lo, u16 hi split of r1).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void func_021F0218(char *p)
{
    if (*(void **)(p + 0x24)) {
        func_0201CE48(*(void **)(p + 0x24));
        *(void **)(p + 0x24) = 0;
        func_02045808(*(void **)(p + 0x28));
        *(void **)(p + 0x28) = 0;
    }
    func_02028604((int)(*(void **)(p + 0x30)));
    func_02031140(*(void **)(p + 0x20));
    func_020452E8(*(void **)(p + 0x1c));
    func_020452E8(*(void **)(p + 0x18));
    func_0201F614(5, *(unsigned int *)(p + 0x14));
}




void func_021F0254(char *p, int a1, int a2)
{
    int r6 = (int)func_02045EC0((struct MsgBank *)(((struct Obj09807 *)p)->f38), a2);
    func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)a1)), 0, 0, (void *)r6, (void *)(((struct Obj09807 *)p)->f34));
    func_0201F79C((void *)a1, 0, ((struct Obj09807 *)p)->f14, 2);
    func_02045334((struct Descriptor *)a1);
    func_02045808((struct U16Vec *)r6);
}




void func_021F0298(char *p, int a1, int a2, int a3)
{
    int r7 = (int)func_02045EC0((struct MsgBank *)(((struct Obj09808 *)p)->f38), a2);

    func_02045790((struct Descriptor *)a1, a3);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)a1)), 15);
    func_0201F7A8((void *)a1, 2);
    func_02045374((struct Cfg *)a1);
    func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)a1)), 0, 0, (void *)r7, (void *)(((struct Obj09808 *)p)->f34));
    func_0201F79C((void *)a1, 0, ((struct Obj09808 *)p)->f14, 2);
    func_02045334((struct Descriptor *)a1);
    func_02045808((struct U16Vec *)r7);
}




void func_021F02FC(char *p, int a1)
{
    GearTable *d = &d_021F0640;

    d->f0C = a1;
    d->f20 = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 5);
    d->f2C = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 6);
    ((struct Obj06146 *)p)->f44 = func_0202784C((int)d_021F064C, ((struct Obj06146 *)p)->f40);
    func_02027CD8(((struct Obj06146 *)p)->f44, 1);
    func_02045808((struct U16Vec *)d->f20);
    func_02045808((struct U16Vec *)d->f2C);
}



void func_021F0340(char *p)
{
    if (((struct Obj09809 *)p)->f44 != 0) {
        func_02027858(((struct Obj09809 *)p)->f44);
        ((struct Obj09809 *)p)->f44 = 0;
    }
}



/*
 * extent: followers 021F0364 and 021F0370 already filed separately.
 */
void func_021F0354(char *p)
{
    if (((struct Obj13079 *)p)->f44 != 0)
        func_02027974(((struct Obj13079 *)p)->f44);
}




/*
 * Unlabelled tail-call leaf of func_021F0468 (reads the menu handle at +0x44).
 */
u8 func_021F0364(char *p)
{
    return func_02027A04(((struct Obj20482 *)p)->f44);
}




u32 func_021F0370(char *p)
{
    return func_020279E8(((struct Obj20483 *)p)->f44);
}




int func_021F037C(char *p)
{
    u16 v;

    switch (((struct Obj01129 *)p)->f4A) {
    case 0:
        func_021F0254(p, ((struct Obj01129 *)p)->f18, 0);
        func_021F0254(p, ((struct Obj01129 *)p)->f1C, 3);
        func_021F02FC(p, ((struct Obj01129 *)p)->f0);
        (((struct Obj01129 *)p)->f4A)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (((struct Obj01129 *)p)->f4A)++;
        break;
    case 2:
        if (func_021F0370(p) != 0) {
            if (func_021F0364(p) == 0) {
                func_02012158(((struct Obj01129 *)p)->f4, 1);
                func_020121CC(((struct Obj01129 *)p)->f4);
                v = 3;
            } else {
                v = 5;
            }
            ((struct Obj01129 *)p)->f4A = v;
            func_021F0340(p);
        }
        break;
    case 3:
        func_021F0298(p, ((struct Obj01129 *)p)->f18, 1, 6);
        (((struct Obj01129 *)p)->f4A)++;
        break;
    case 4:
        if (func_02035C60() != 0 || func_02012204(((struct Obj01129 *)p)->f4) != 0)
            (((struct Obj01129 *)p)->f4A)++;
        break;
    case 5:
        if (func_02012204(((struct Obj01129 *)p)->f4) != 0) {
            if (func_02026454(((struct Obj01129 *)p)->f8))
                func_02026400(((struct Obj01129 *)p)->f8);
            ((struct Obj01129 *)p)->f4A = 6;
            break;
        }
        return 1;
    case 6:
        if (func_02026454(((struct Obj01129 *)p)->f8) == 0)
            return 1;
        break;
    }
    func_021F0354(p);
    return 0;
}




int func_021F0468(char *p)
{
    u16 v;

    switch (((struct Obj01362 *)p)->f4A) {
    case 0:
        func_021F0254(p, ((struct Obj01362 *)p)->f18, 2);
        func_021F0254(p, ((struct Obj01362 *)p)->f1C, 3);
        func_021F02FC(p, ((struct Obj01362 *)p)->f0);
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (((struct Obj01362 *)p)->f4A)++;
        break;
    case 2:
        if (func_021F0370(p) != 0 || func_02012204(((struct Obj01362 *)p)->f4) == 1) {
            if (func_021F0364(p) == 0 || func_02012204(((struct Obj01362 *)p)->f4) == 1) {
                if (func_02026454(((struct Obj01362 *)p)->f8))
                    func_02026400(((struct Obj01362 *)p)->f8);
                v = 1;
            } else {
                v = 0;
            }
            ((struct Obj01362 *)p)->f4C = v;
            ((struct Obj01362 *)p)->f4A = 3;
            func_021F0340(p);
        }
        break;
    case 3:
        if (((struct Obj01362 *)p)->f4C != 0) {
            if (func_02026454(((struct Obj01362 *)p)->f8) != 0)
                break;
            func_02012158(((struct Obj01362 *)p)->f4, 0);
        }
        (((struct Obj01362 *)p)->f4A)++;
        break;
    case 4:
        return 1;
    }
    func_021F0354(p);
    return 0;
}
