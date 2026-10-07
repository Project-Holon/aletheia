/*
 * file:     c_gear_power_onoff_p03.c
 * unit:     yes
 * function: func_021F0218, func_021F0254, func_021F0298, func_021F02FC, func_021F0340, func_021F0354, func_021F0364, func_021F0370, func_021F037C, func_021F0468
 * address:  0x021F0218
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
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045790 0x02045790 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045374 0x02045374 arm
 *   d_021F0640    0x021F0640 data ov035 a4
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
#include "../../matched/include/Obj09807.h"
#include "../../matched/include/Obj09808.h"
#include "../../matched/include/Obj06146.h"
#include "../../matched/include/Obj09809.h"
#include "../../matched/include/Obj13079.h"
#include "../../matched/include/Obj20482.h"
#include "../../matched/include/Obj20483.h"
#include "../../matched/include/Obj01129.h"
#include "../../matched/include/Obj01362.h"

struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
struct MsgBank;
struct Cfg;
struct CharBuf;
struct TaskMenu;
struct Comm;
struct Ctx;
struct IcaAnime;
typedef unsigned int   u32;

typedef signed short   s16;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F614(int, unsigned int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void func_02045334(struct Descriptor *d);
extern void func_02045790(struct Descriptor *p, u8 v);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02045374(struct Cfg *cfg);
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
extern int d_021F0640[];
extern char d_021F064C[];

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
    int *d = d_021F0640;

    d[3] = a1;
    d[8] = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 5);
    d[11] = (int)func_02045EC0((struct MsgBank *)(((struct Obj06146 *)p)->f38), 6);
    ((struct Obj06146 *)p)->f44 = func_0202784C((int)d_021F064C, ((struct Obj06146 *)p)->f40);
    func_02027CD8(((struct Obj06146 *)p)->f44, 1);
    func_02045808((struct U16Vec *)d[8]);
    func_02045808((struct U16Vec *)d[11]);
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
