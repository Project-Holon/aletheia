/*
 * file:     oekaki_p04.c
 * unit:     yes
 * function: func_02184674, func_021847C8, func_0218489C, func_021848A8, func_021848CC, func_021848D0
 * address:  0x02184674
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
 *   func_02039338  0x02039338  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_0218644C  0x0218644C  thumb  ov023
 *   func_020221A4  0x020221A4  thumb
 *   func_021840FC  0x021840FC  thumb  ov022
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02185F74  0x02185F74  thumb  ov023
 *   func_02186324  0x02186324  thumb  ov023
 *   func_02185F10  0x02185F10  thumb  ov023
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02184174  0x02184174  thumb  ov022
 *   func_0218417C  0x0218417C  thumb  ov022
 *   func_021867C4  0x021867C4  thumb  ov023
 *   func_0204A600  0x0204A600  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02186708  0x02186708  thumb  ov023
 *   func_0200FB24  0x0200FB24  thumb
 *   d_02186E80     0x02186E80  data   a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02186694  0x02186694  thumb  ov023
 *   func_02185004  0x02185004  thumb  ov023
 *   func_02184B34  0x02184B34  thumb  ov023
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02184B04  0x02184B04  thumb  ov023
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_02186860 0x02186860 thumb ov023
 *   func_021866C4 0x021866C4 thumb ov023
 *   func_020433E0  0x020433E0  arm
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 */
#include "../../matched/include/Obj00460.h"
#include "../../matched/include/Obj01361.h"

struct Tcbl;
struct Bank;
struct Node;
struct Rec;
struct WordSet;
struct S020315D4;
struct DispVram;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Step {
    int (*fn)(char *p, int state);
    void *f4;
} Step;

extern u16 func_02039338(void);
extern int func_02186558(char *p);
extern void func_0218644C(char *p, int state);
extern u32 func_020221A4(void);
extern void func_021840FC(u32 obj, void (*a)(void), void (*b)(void), char *arg);
extern void func_02184560(char *p, int a);
extern void func_02185F74(void *win, int color, char *p);
extern int func_02186324(u8 *p);
extern void func_02185F10(u16 *p);
extern void func_0203A5E4(u32 key);
extern void func_02184174(u8 *p);
extern u32 func_0218417C(u8 *p);
extern void func_021867C4(char *p);
extern void func_0204A600(void);
extern void func_020310C4(struct Tcbl *p);
extern void func_02186708(char *p);
extern u32 func_0200FB24(void);
extern void func_02030EAC(struct Node *n);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02186694(char *p);
extern void func_02185004(char *p);
extern void func_02184B34(void);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_02184B04(char *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
void func_0204A648(void);
void func_020419E4(void);
extern void func_02186860(char *p, int x, int y);
extern void func_021866C4(u32 *p);
extern void func_020433E0(const struct DispVram *);
int func_02184674(void *task, int *state, int a2, char *p);
int func_021847C8(u32 a, int *seq, u8 *c, u8 *d);
void func_0218489C(void);
void func_021848A8(int a, int unused, char *p);
void func_021848CC(void);
void func_021848D0(void);
extern Step d_02186E80[];
extern const struct DispVram d_02186ACC;


/*
 * The step-table callbacks take (p, *state): the switch value, reused as
 * their second argument, is what keeps it live in r1 through the dispatch
 * (a one-argument callback puts the whole dispatch in r0). func_0218644C
 * is void but leaves r0 = p; no hidden argument here.
 *
 * Addresses are Black-image addresses.
 */
int func_02184674(void *task, int *state, int a2, char *p)
{
    int (*fn)(char *p, int state);
    int r;

    if (func_02039338() == 0 && ((struct Obj00460 *)p)->f9280 != 0) {
        ((struct Obj00460 *)p)->f9280 = func_02186558(p) & ((struct Obj00460 *)p)->f9280;
    }
    ((struct Obj00460 *)p)->f194 = *state;
    func_0218644C(p, *state);
    switch (*state) {
    case 0:
        if (func_020221A4() != 0) {
            func_021840FC(**(u32 * *)&((struct Obj00460 *)p)->f4, (void (*)(void))func_021848A8, func_021848CC, p);
            if (func_02039338() == 0) {
                func_02184560(p, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0) {
            *state = fn(p, *state);
        }
        func_02185F74(p + 0x104, 0x44f, p);
        if (func_02039338() == 0) {
            r = func_02186324((u8 *)p);
            if (*state == 1) {
                *state = r;
            }
        }
        func_02185F10((u16 *)(p + 0x4208));
        break;
    case 2:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0 && d_02186E80[*(int *)(p + 0x198)].f4 != 0) {
            *state = fn(p, *state);
        }
        break;
    case 3:
        if (func_020221A4() != 0) {
            func_0203A5E4(0x2900);
            func_02184174((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4));
            *state = 4;
        }
        break;
    case 4:
        if (func_0218417C((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4)) != 0) {
            return 1;
        }
        break;
    }
    func_021867C4(p);
    func_0204A600();
    func_020310C4((struct Tcbl *)(((struct Obj00460 *)p)->f170));
    func_02186708(p);
    if (func_020221A4() != 0 && func_0200FB24() != 0) {
        return 1;
    }
    return 0;
}


int func_021847C8(u32 a, int *seq, u8 *c, u8 *d)
{
    switch (*seq) {
    case 0:
        func_02030EAC((struct Node *)(((struct Obj01361 *)d)->f8));
        func_0204A8D4(((struct Obj01361 *)d)->f58);
        func_0204ADA4(((struct Obj01361 *)d)->f54);
        func_0204AFD8(((struct Obj01361 *)d)->f5C);
        func_0204A8D4(((struct Obj01361 *)d)->f4C);
        func_0204ADA4(((struct Obj01361 *)d)->f48);
        func_0204AFD8(((struct Obj01361 *)d)->f50);
        func_0204A8D4(((struct Obj01361 *)d)->f40);
        func_0204ADA4(((struct Obj01361 *)d)->f3C);
        func_0204AFD8(((struct Obj01361 *)d)->f44);
        func_0204B1CC((struct Bank *)(((struct Obj01361 *)d)->f38));
        func_0204A5AC();
        if (((struct Obj01361 *)d)->f178 != 0) {
            func_02186694((char *)d);
        }
        func_02185004((char *)d);
        func_02184B34();
        func_02045C04((struct Rec *)(((struct Obj01361 *)d)->f14));
        func_0201ED04((struct WordSet *)(((struct Obj01361 *)d)->f10));
        func_0201D83C((void *)(((struct Obj01361 *)d)->fC));
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (((struct Obj01361 *)d)->f9E78 != 0) {
            if (func_02186558((char *)d) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        func_02184B04((char *)d);
        func_020315D4((struct S020315D4 *)a);
        func_020306F0(0x28);
        return 1;
    }
    return 0;
}


void func_0218489C(void)
{
    func_0204A648();
    func_020419E4();
}

/*
 * Extent follower 0x021848CC is already matched separately.
 */
void func_021848A8(int a, int unused, char *p)
{
    if (func_02039338() == 0)
        func_02186860(p, 0x2903, a);
    func_021866C4((u32 *)p);
}

/*
 * Unlabelled empty callback (a lone bx lr after func_021848A8's pool);
 * func_02184674 hands its address to ov022 func_021840FC. Blocker of
 * ov023 func_02184674.
 */
void func_021848CC(void)
{
}


/*
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 */
void func_021848D0(void)
{
    func_020433E0(&d_02186ACC);
}
