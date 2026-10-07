/*
 * file:     zukan_info_p03.c
 * unit:     yes
 * function: func_021BA550, func_021BA64C, func_021BA6B0, func_021BA7C8, func_021BA814, func_021BA864, func_021BA890
 * address:  0x021BA550
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_021BB160 0x021BB160 thumb ov206
 *   func_021BA4F4 0x021BA4F4 thumb ov206
 *   func_021BB0FC 0x021BB0FC thumb ov206
 *   func_021BBC38 0x021BBC38 thumb ov206
 *   func_021BB13C 0x021BB13C thumb ov206
 *   func_021BBE34 0x021BBE34 thumb ov206
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 *   func_021BB4E0 0x021BB4E0 thumb ov206
 *   func_021BBDA8 0x021BBDA8 thumb ov206
 *   func_021BAA4C 0x021BAA4C thumb ov206
 *   func_021BACB0 0x021BACB0 thumb ov206
 *   func_021BBC68 0x021BBC68 thumb ov206
 *   func_02040588 0x02040588 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204A39C 0x0204A39C arm
 *   func_02049B68 0x02049B68 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_021BC174 0x021BC174 data a1
 */
#include "../../matched/include/Obj00598.h"
#include "../../matched/include/Obj00031.h"
#include "../../matched/include/Obj00551.h"
#include "../../matched/include/Obj08387.h"
#include "../../matched/include/Obj00022.h"

struct Personal;
struct S;
struct State;
struct CharBuf;
struct Descriptor;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; } State_021BA7C8;

typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; char pad4f[0x1b4-0x4f]; int delta; } State_021BA814;

typedef unsigned char u8;

struct Tab16 { u8 b[16]; };

extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_021BB160(char *p, int i);
extern void func_021BA4F4(char *p);
extern void func_021BB0FC(void *obj);
extern void func_021BBC38(struct S *p);
extern void func_021BB13C(void *a0, void *a1, void *a2, void *a3);
extern void func_021BBE34(struct S *p, int v);
extern void func_021BAF50(char *);
extern void func_021BB92C(char *,int);
extern void func_021BB4E0(char *,int,int);
extern void func_021BBDA8(struct State *p, int v);
extern void func_021BAA4C(char *);
extern void func_021BACB0(char *,int);
extern void func_021BBC68(struct S *p, int v);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
void func_021BA64C(char *p,int mode);
void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
void func_021BA7C8(State_021BA7C8 *p);
void func_021BA814(State_021BA814 *p);
void func_021BA864(int unused, char *p);
void func_021BA890(char *p);
extern const struct Tab16 d_021BC174;

void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00598 *)p)->f26C != 0) func_0201AE14(((struct Obj00598 *)p)->f26C);
    ((struct Obj00598 *)p)->f26C = func_0201ADE4(a1, a2, ((struct Obj00598 *)p)->f0);
    if (((struct Obj00598 *)p)->fB4 != 0) ((struct Obj00598 *)p)->fB4 = 0; else ((struct Obj00598 *)p)->fB4 = 1;
    if (((struct Obj00598 *)p)->fE0 != 0) ((struct Obj00598 *)p)->fE0 = 0; else ((struct Obj00598 *)p)->fE0 = 1;
    if (((struct Obj00598 *)p)->f190 != 0) ((struct Obj00598 *)p)->f190 = 0; else ((struct Obj00598 *)p)->f190 = 1;
    func_021BB160(p, ((struct Obj00598 *)p)->fB4);
    func_021BA4F4(p);
    ((struct Obj00598 *)p)->fC = a1;
    ((struct Obj00598 *)p)->fE = a2;
    ((struct Obj00598 *)p)->f10 = a3;
    ((struct Obj00598 *)p)->f12 = a4;
    ((struct Obj00598 *)p)->f14 = a5;
    ((struct Obj00598 *)p)->f8 = a6;
    h = (u16)func_0201AE1C(((struct Obj00598 *)p)->f26C, 0x20);
    if (((struct Obj00598 *)p)->fE >= h) ((struct Obj00598 *)p)->fE = 0;
    func_021BB0FC(p);
    func_021BBC38((struct S *)p);
    switch (((struct Obj00598 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00598 *)p)->f1B4)), (void *)(((struct Obj00598 *)p)->fB4));
    func_021BBE34((struct S *)p, (((struct Obj00598 *)p)->f44 != 0) ? 0 : 1);
}

void func_021BA64C(char *p,int mode)
{
    if (((struct Obj00031 *)p)->fE0) ((struct Obj00031 *)p)->fE0=0;
    else ((struct Obj00031 *)p)->fE0=1;
    func_021BAF50(p);
    func_021BB92C(p,((struct Obj00031 *)p)->fE0);
    func_021BB4E0(p,mode,((struct Obj00031 *)p)->fE0);
    func_021BBDA8((struct State *)p,((struct Obj00031 *)p)->f8);
    if(mode==6 || ((struct Obj00031 *)p)->fC>493) func_021BAA4C(p);
    else func_021BACB0(p,mode);
}

void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00551 *)p)->f26C != 0) func_0201AE14(((struct Obj00551 *)p)->f26C);
    ((struct Obj00551 *)p)->f26C = func_0201ADE4(a1, a2, ((struct Obj00551 *)p)->f0);
    if (((struct Obj00551 *)p)->fB4 != 0) ((struct Obj00551 *)p)->fB4 = 0; else ((struct Obj00551 *)p)->fB4 = 1;
    if (((struct Obj00551 *)p)->fE0 != 0) ((struct Obj00551 *)p)->fE0 = 0; else ((struct Obj00551 *)p)->fE0 = 1;
    if (((struct Obj00551 *)p)->f190 != 0) ((struct Obj00551 *)p)->f190 = 0; else ((struct Obj00551 *)p)->f190 = 1;
    func_021BB160(p, ((struct Obj00551 *)p)->fB4);
    func_021BA4F4(p);
    ((struct Obj00551 *)p)->fC = a1;
    ((struct Obj00551 *)p)->fE = a2;
    ((struct Obj00551 *)p)->f10 = a3;
    ((struct Obj00551 *)p)->f12 = a4;
    ((struct Obj00551 *)p)->f14 = a5;
    ((struct Obj00551 *)p)->f8 = a6;
    h = (u16)func_0201AE1C(((struct Obj00551 *)p)->f26C, 0x20);
    if (((struct Obj00551 *)p)->fE >= h) ((struct Obj00551 *)p)->fE = 0;
    func_021BB0FC(p);
    if (a7 == 6 || ((struct Obj00551 *)p)->fC > 0x1ed) func_021BBC38((struct S *)p);
    else func_021BBC68((struct S *)p, a7);
    switch (((struct Obj00551 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00551 *)p)->f1B4)), (void *)(((struct Obj00551 *)p)->fB4));
    func_021BBE34((struct S *)p, (((struct Obj00551 *)p)->f44 != 0) ? 0 : 1);
}

void func_021BA7C8(State_021BA7C8 *p)
{
    if (!p->state) {
        p->state = 1;
        func_02040588(p->a, 0);
        func_02040588(p->b, 0);
        func_02041EE4(p->c, 3, -256);
        func_021BBE34((struct S *)p, p->state == 0);
    }
}

void func_021BA814(State_021BA814 *p)
{
    if (p->state) {
        p->state = 0;
        func_02040588(p->a, 1);
        func_02040588(p->b, 1);
        func_02041EE4(p->c, 3, -p->delta);
        func_021BBE34((struct S *)p, p->state == 0);
    }
}


void func_021BA864(int unused, char *p)
{
    if (((struct Obj08387 *)p)->f39 & 1)
    {
        func_02041EE4(((struct Obj08387 *)p)->f4E, 1, 1);
    }
    ((struct Obj08387 *)p)->f38 = 0;
    ((struct Obj08387 *)p)->f39 = 0;
}

void func_021BA890(char *p)
{
    struct Tab16 tab;
    int out;
    int r6;
    int i;
    ((struct Obj00022 *)p)->f2B0 = (int)func_0204A39C(((struct Obj00022 *)p)->f1C8, 0, 0, ((struct Obj00022 *)p)->f0, (u32 *)(&out));
    r6 = 0;
    if (*(int *)&((struct Obj00022 *)p)->f1C != 0) r6 = 4;
    func_02049B68(((struct Obj00022 *)p)->f1CC, 5, r6, 0x60, 0x20, ((struct Obj00022 *)p)->f0);
    tab = d_021BC174;
    for (i = 0; i < 4; i++) {
        *(void **)(p+i*4+0x6c) = (void *)func_020450F0(((struct Obj00022 *)p)->f4C, tab.b[i*4], tab.b[i*4+1], tab.b[i*4+2], tab.b[i*4+3], 3, 1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770(*(void **)(p+i*4+0x6c))), 0);
    }
    for (i = 0; i < 4; i++) {
        *(int *)(p+i*4+0x7c) = 1;
    }
}
