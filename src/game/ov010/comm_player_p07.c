/*
 * file:     comm_player_p07.c
 * unit:     yes
 * function: func_02169E0C, func_02169E4C, func_02169E98, func_02169EA4, func_02169EBC, func_02169F34, func_02169FB8, func_02169FFC
 * address:  0x02169E0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216A128  0x0216A128  thumb  ov010
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 */
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj17747.h"
#include "../../matched/include/Obj19072.h"
#include "../../matched/include/Obj19073.h"
#include "../../matched/include/Obj04885.h"

struct Descriptor;
struct MsgBank;
struct Cfg;
struct CharBuf;
struct Rec;
struct Rec3;
struct U16Vec;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

typedef signed int     s32;

typedef struct Slot {
    void *f00;
    u8 f04;
} Slot;

extern int func_0216A128();
extern int func_0201C4C0();
extern int func_02028604(int a0);
extern int func_02031140();
extern int func_02045808();
extern int func_02045C04();
extern u32 func_020307B0(void *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern int func_0201F5BC();
extern int func_02049B40();
u32 func_020452E8(struct Descriptor *d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_021904AC(u8 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 v);
extern int func_020310C4();
extern int func_020286C4();
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
int func_02169E0C(char *a0);
void func_02169E4C(int a0);
int func_02169E98(char *p);
void func_02169EA4(Work *w, u32 n);
void func_02169EBC(Work *w);
int func_02169F34(u8 *p);
int func_02169FB8(int a0);
void func_02169FFC(Work *w, u32 msg);


int func_02169E0C(char *a0)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)func_0216A128(a0);
loc_02169E14:
a0 = (char *)(t4 + 0);
    a0 = (char *)func_02169E98(a0);
loc_02169E1A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f14);
    a0 = (char *)func_0201C4C0(a0);
loc_02169E22:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f1C);
    a0 = (char *)func_02028604((int)a0);
loc_02169E2A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)((char *)a0))->f0);
    a0 = (char *)func_02031140(a0);
loc_02169E32:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f18);
    a0 = (char *)func_02045808(a0);
loc_02169E3A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f4);
    a0 = (char *)func_02045C04(a0);
loc_02169E42:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
    a0 = (char *)func_020307B0(a0);
loc_02169E48:
    return (int)a0;}


#define Q (*(u8 **)(p + 0x18))

#define H (*(u32 *)(Q + 0x10))

#define ST (*(u32 *)(Q + 0x20))



void func_02169E4C(int a0)
{
    int a1;
    int a2;
    int a3;
    unsigned char fr[12];
    int t4;
    int t5;
    int o4;
    int o5;
    int o6;
t5 = a0 + 0;
a0 = 4;
    o4 = a0;
a0 = 0xc;
    o5 = a0;
a0 = 1;
    o6 = a0;
a0 = 6;
a1 = 1;
a2 = 1;
a3 = 0x1e;
t4 = 6;
    a0 = func_020450F0(a0, a1, a2, a3, o4, o5, o6);
loc_02169E6C:
a1 = *(int *)&((struct Obj00029 *)t5)->f18;
a2 = 0xd;
((struct Obj17747 *)a1)->f8 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 1;
a3 = 0;
    o4 = a0;
a0 = 6;
    a0 = func_0201F5BC(a0, a1, a2, a3, o4);
loc_02169E80:
a0 = 0x20;
    o4 = a0;
a0 = ((struct Obj00029 *)t5)->f10;
a1 = 5;
a2 = 4;
    o5 = a0;
a0 = 0x17;
a3 = t4 << 6;
    a0 = func_02049B40(a0, a1, a2, a3, o4, o5);
loc_02169E94:
    return;
}



int func_02169E98(char *p)
{
    return func_020452E8((struct Descriptor *)(((struct Obj19073 *)(*(char * *)&((struct Obj19072 *)p)->f18))->f8));
}



void func_02169EA4(Work *w, u32 n)
{
    func_02045CAC(w->f18->f04, n, w->f18->f18);
    func_02169EBC(w);
}



void func_02169EBC(Work *w)
{
    Res *r;
    u32 a;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    r = w->f18;
    a = func_021904AC(w->f0C);
    w->f18->f10 = func_0201CCE4(r->f08, 0, 0, r->f18, a, func_02012FFC(), r->f00, 10, w->f10, 15);
    w->f18->f20 = 0;
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
}



int func_02169F34(u8 *p)
{
    switch (func_0201CE30((void *)H)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C((struct Rec *)H, 0);
        ST = 0;
        break;
    case 1:
        if (ST == 0) {
            if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
                func_020061E4(0x547);
                func_0201CE38((void *)H);
                ST = 1;
            }
        }
        break;
    case 2:
        func_0201CE48((struct Rec3 *)H);
        ST = 0;
        return 0;
    }
    return 1;
}



int func_02169FB8(int a0)
{
    int a1;
    int a2;
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FC4:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FD0:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FD6:
    if (a0 != 0) goto loc_02169FDE;
loc_02169FDA:
a0 = 0;
    return a0;
loc_02169FDE:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)((char *)a0))->f0;
    a0 = func_020310C4(a0);
loc_02169FE6:
a2 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = ((struct Obj04885 *)a2)->f1C;
a1 = ((struct Obj04885 *)a2)->f10;
a2 = ((struct Obj04885 *)a2)->f8;
    a0 = func_020286C4(a0, a1, a2);
loc_02169FF2:
a0 = t4 + 0;
    a0 = func_02169F34((u8 *)a0);
loc_02169FF8:
    return a0;}



void func_02169FFC(Work *w, u32 msg)
{
    void *str;
    u32 a;
    Slot *s;
    void *t;
    void *p;

    func_02043B5C(func_02045770(w->f18->f08), 15);
    func_0201F73C(w->f18->f08, 2, 1, 13);
    str = func_02045EC0(w->f18->f04, msg);
    a = func_021904AC(w->f0C);
    s = (Slot *)&w->f18->f08;
    t = w->f18->f14;
    func_0201C6FC(t, (u32)func_02045770(s->f00), 0, 0, str, a);
    s->f04 = 1;
    func_02045808(str);
    p = w->f18->f08;
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
}
