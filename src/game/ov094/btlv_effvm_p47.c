/*
 * file:     btlv_effvm_p47.c
 * unit:     yes
 * function: func_021FC354, func_021FC374, func_021FC3D8, func_021FC434, func_021FC448, func_021FC744, func_021FC9D0, func_021FC9E4
 * address:  0x021FC354
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020113D0 0x020113D0 thumb
 *   func_0201134C 0x0201134C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02048F60 0x02048F60 arm
 *   func_020113B0 0x020113B0 thumb
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_021FE930  0x021FE930  thumb  ov094
 *   d_0220AE68     0x0220AE68  data   ov094
 *   func_021F8934 0x021F8934 thumb ov094
 *   func_021FDB08 0x021FDB08 thumb ov094
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_02201CA4 0x02201CA4 thumb ov094
 *   func_021F8A10 0x021F8A10 thumb ov094
 *   func_021FE4F8 0x021FE4F8 thumb ov094
 *   func_021FE520 0x021FE520 thumb ov094
 *   func_02011290 0x02011290 thumb
 *   func_021F8764 0x021F8764 thumb ov094
 *   func_021EB2A8 0x021EB2A8 thumb ov093
 *   func_0204047C 0x0204047C arm
 *   func_02040618 0x02040618 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02006210 0x02006210 thumb
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_02040588 0x02040588 arm
 *   func_0201127C 0x0201127C thumb
 *   func_021FF374 0x021FF374 thumb ov094
 *   func_021F8684 0x021F8684 thumb ov094
 *   func_021F722C 0x021F722C thumb ov094
 *   func_021FF16C 0x021FF16C thumb ov094
 *   func_021FFCB0 0x021FFCB0 thumb ov094
 *   func_02200494 0x02200494 thumb ov094
 *   func_021F8700 0x021F8700 thumb ov094
 *   func_0220985C 0x0220985C thumb ov094
 *   func_02051614 0x02051614 arm
 *   func_021F8324 0x021F8324 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02006BD0 0x02006BD0 thumb
 */
#include "../../matched/include/Obj13597.h"
#include "../../matched/include/Obj03713.h"
#include "../../matched/include/Obj21683.h"
#include "../../matched/include/Obj21684.h"
#include "../../matched/include/Obj13598.h"
#include "../../matched/include/Obj21685.h"

struct Cursor;
struct Cur;
struct Res;
struct ScriptVm;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int pad0;
    int pad4;
    void *f8;
    char pad1[0x238 - 0xc];
    u16 h238;
    char pad2[2];
    int f23c;
} State_021FC3D8;

typedef unsigned char u8;

typedef union {
    unsigned word;
    struct {
        unsigned gap0 : 4;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned gap7 : 5;
        unsigned b12 : 1;
        unsigned gap13 : 4;
        unsigned b17 : 1;
        unsigned b18 : 1;
    } bit;
} Flags_021FC448;

typedef struct {
    Flags_021FC448 flags;
    int f4;
    int pad8;
    void *objects[16];
    int ids[16];
    char pad8c[0xcc - 0x8c];
    int res[4];
    int fdc;
    char pade0[0x1e8 - 0xe0];
    char *f1e8;
    char *f1ec;
    int f1f0;
    void *bufs[16];
    int nbufs;
    u16 h238;
    char pad23a[2];
    int f23c;
    char pad240[0x249 - 0x240];
    u8 b249;
    char pad24a[0x258 - 0x24a];
    u16 h258;
    char pad25a[0x264 - 0x25a];
    int f264;
    int f268;
} State_021FC448;

typedef enum { SLOT_ZERO, SLOT_LAST = 14 } Slot;

typedef union {
    unsigned word;
    struct {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned gap4 : 3;
        unsigned b7 : 1;
        unsigned b8 : 1;
        unsigned gap9 : 2;
        unsigned b11 : 1;
        unsigned gap12 : 4;
        unsigned b16 : 1;
    } bit;
} Flags_021FC744;

typedef struct {
    Flags_021FC744 flags;
    char pad[8];
    void *objects[16];
    char pad2[0x240 - 0x4c];
    unsigned mode;
    int f244;
    char pad3[0x26c - 0x248];
    int slots[6];
} State_021FC744;

typedef struct {
    unsigned lo : 7;
    unsigned bit : 1;
} Flags_021FC9E4;

extern void func_020113D0(char *p, int val);
extern unsigned int func_0201134C(struct Cursor *p);
extern unsigned int func_020307B0(void *p);
extern void *func_02048F60(unsigned int archive_id, unsigned int member, unsigned int heap);
extern void func_020113B0(struct Cur *c, u32 v);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern void *func_02030DA8(void *owner, void *fn, void *p, unsigned a3);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE930(void *p);
extern void func_021F8934(int);
extern void func_021FDB08(void *);
extern int func_021F86F0(void);
extern void func_02201CA4(struct Res *r, int i);
extern void func_021F8A10(int);
extern void func_021FE4F8(State_021FC448 *);
extern void func_021FE520(State_021FC448 *);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern int func_021F8764(void);
extern void func_021EB2A8(const u8 *a);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02006210(void);
extern int func_021F8694(void);
extern int func_021FFD9C(char *p, int key);
extern int func_021FFF38(char *p, int key);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0201127C(struct ScriptVm *vm, u8 *pc);
extern void func_021FF374(void *, int, int);
extern int func_021F8684(void);
extern int func_021F722C(char *p);
extern void func_021FF16C(void *);
extern int func_021FFCB0(void *, int);
extern int func_02200494(char *p, int key);
extern int func_021F8700(void);
extern int func_0220985C(void *);
extern int func_02051614(int **p);
extern int func_021F8324(unsigned);
extern int func_02006238(void);
extern int func_02006224(unsigned);
extern u32 func_02006BD0(u32 i);
int func_021FC354(void *a, char *s);
int func_021FC374(void *a, char *s);
int func_021FC3D8(struct Cursor *a, State_021FC3D8 *s);
int func_021FC434(void *a, char *s);
int func_021FC448(void *a, State_021FC448 *s);
int func_021FC744(int a, State_021FC744 *s);
int func_021FC9D0(void *a, char *s);
int func_021FC9E4(void *a, Flags_021FC9E4 *s);
extern char d_0220AE68[];


/*
 * Script command: sets flag bit 7, waits on func_021FC9E4, and suspends.
 */
int func_021FC354(void *a, char *s)
{
    ((struct Obj13597 *)s)->f0 |= 0x80;
    func_020113D0(a, (int)func_021FC9E4);
    ((struct Obj13597 *)s)->f23C = 1;
    return 1;
}


/*
 * Script command: loads script id (archive 0x42 below 0x231, else 0x43) into the buffer at 0x1e8 and jumps into it.
 */
int func_021FC374(void *a, char *s)
{
    int id = func_0201134C(a);
    char *p;

    func_020307B0(((struct Obj03713 *)s)->f1E8);
    if (id < 0x231)
        *(char * *)&((struct Obj03713 *)s)->f1E8 = func_02048F60((int)0x42, (int)id, (u16)((((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000));
    else
        *(char * *)&((struct Obj03713 *)s)->f1E8 = func_02048F60((int)0x43, (int)(id - 0x231), (u16)((((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000));
    p = *(char * *)&((struct Obj03713 *)s)->f1E8;
    ((struct Obj03713 *)s)->f4 = 0;
    func_020113B0(a, (u32)(p + ((struct Obj21683 *)p)->f4));
    return ((struct Obj03713 *)s)->f23C;
}


int func_021FC3D8(struct Cursor *a, State_021FC3D8 *s)
{
    int v = func_0201134C(a);
    int *p;

    p = func_02030734((u16)((s->h238 & 0x7fff) | 0x8000), 0xc, 0, d_0220AE68, 0x1250);
    p[0] = (int)s;
    p[1] = v;
    p[2] = 0;
    func_021F896C(func_02030DA8(s->f8, (void *)func_021FE930, p, 0), 0, 1);
    return s->f23c;
}


/*
 * Script command: passes one argument to func_021F8934.
 */
int func_021FC434(void *a, char *s)
{
    func_021F8934(func_0201134C(a));
    return ((struct Obj21684 *)s)->f23C;
}


/*
 * Script reset: frees slot objects and buffers, restores display state, then resumes the
 * pending script at 0x1ec or reloads script 0x34 when the follow-up conditions hold.
 */
int func_021FC448(void *a, State_021FC448 *s)
{
    int i;
    int v;
    u16 id;
    u16 id2;
    int b;
    int off;
    char *p;
    void *q;

    for (i = 0; i < 16; i++) {
        if (s->objects[i] != 0) {
            func_021FDB08(s->objects[i]);
            s->objects[i] = 0;
        }
        s->ids[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (s->res[i] != -1) {
            func_02201CA4((struct Res *)func_021F86F0(), s->res[i]);
            s->res[i] = -1;
        }
    }
    for (i = 0; i < s->nbufs; i++)
        func_020307B0(s->bufs[i]);
    s->nbufs = 0;
    func_021F8A10(1);
    func_021FE4F8(s);
    func_021FE520(s);
    if (s->flags.bit.b18 == 0)
        func_021F8934(1);
    func_02011290(a);
    s->f23c = 1;
    if (s->flags.bit.b4) {
        q = (void *)func_021F8764();
        if (q != 0)
            func_021EB2A8(q);
        func_0204047C(3, 0);
        s->flags.bit.b4 = 0;
        func_02040618(3, 0, s->f264);
        func_02040618(3, 3, s->f268);
    }
    if (s->flags.bit.b5) {
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
        s->flags.bit.b5 = 0;
    }
    if (s->flags.bit.b12)
        func_02006210();
    v = 0;
    if (func_021FFD9C((char *)func_021F8694(), s->fdc) != 0) {
        id = s->h258;
        if (((id == 0xf8 || id == 0x161) && s->b249 == 1) || id == 0x90 || id == 0x77 || id == 0x10b) {
        } else {
            v = func_021FFF38((char *)func_021F8694(), s->fdc) & 1;
        }
    }
    if (s->f1ec != 0) {
        func_020307B0(s->f1e8);
        p = s->f1ec;
        s->f1e8 = p;
        s->f1ec = 0;
        s->flags.bit.b6 = 0;
        off = s->f1f0;
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        s->f4 = 0;
        func_0201127C(a, (u8 *)(s->f1e8 + *(int *)(p + off)));
        return 1;
    }
    b = s->flags.bit.b17;
    if (b == 1 && s->h258 == 0x291) {
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = func_02048F60(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        func_0201127C(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    id2 = s->h258;
    if ((id2 == 0x286 || s->flags.bit.b6 == 0) && id2 != 0x90 && id2 != 0xe2 && b == 0 && v != 0) {
        if (id2 == 0x1f6)
            func_021FF374((void *)func_021F8694(), s->fdc, 0);
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = func_02048F60(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        func_0201127C(a, (u8 *)(p + ((struct Obj13598 *)p)->f4));
        return 1;
    }
    if (id2 != 0x27e) {
        func_02040588(1, 1);
        func_02040588(2, 1);
        func_02040588(3, 1);
    }
    return 1;
}


/*
 * witness: arm9 func_02051614 filed as src/matched/arm9/func_02051614.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 */
int func_021FC744(int a, State_021FC744 *s)
{
    int i;
    Slot j;

    if (s->mode <= 1) {
        if (func_021F722C((char *)func_021F8684()) == 1) return 0;
        if (s->flags.bit.b1) {
            s->flags.bit.b1 = 0;
            s->f244 = 1;
            func_021FF16C((void *)func_021F8694());
        }
    }
    if (s->mode == 0 || s->mode == 3) {
        for (j = 0; j < 14; j++) {
            if (func_021FFCB0((void *)func_021F8694(), j) == 1) return 0;
        }
    }
    if (s->mode == 4) {
        for (j = 8; j < 14; j++) {
            if (func_021FFD9C((char *)func_021F8694(), j)) {
                if (func_02200494((char *)func_021F8694(), j) == 1) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 5) {
        if (func_0220985C((void *)func_021F8700()) == 1) return 0;
    }
    if (s->mode == 0 || s->mode == 2) {
        for (i = 0; i < 16; i++) {
            if (s->objects[i] != 0) {
                if (func_02051614(s->objects[i]) != 0) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 6 || s->mode == 8) {
        if (func_021F8324(0) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 7 || s->mode == 8) {
        if (func_021F8324(1) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 9) {
        if (func_021F8324(3) != 0) return 0;
    }
    if (s->mode == 10) {
        if (func_02006238() != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 11) {
        if (func_02006224(1) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 12) {
        if (func_02006224(2) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 13) {
        if (func_02006224(4) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 14) {
        if (func_02006224(3) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 15) {
        if (func_02006224(0) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 16) {
        if (s->flags.bit.b11) return 0;
        for (i = 0; i < 6; i++) {
            if (s->slots[i] != -1) {
                if (func_02006BD0(s->slots[i]) != 0) return 0;
                s->slots[i] = -1;
            }
        }
    }
    if (s->mode == 0 || s->mode == 17) {
        if (s->flags.bit.b8) return 0;
    }
    return 1;
}

/*
 * Wait callback: decrements the countdown at 0x1e4, done when it reaches zero.
 */
int func_021FC9D0(void *a, char *s)
{
    return --((struct Obj21685 *)s)->f1E4 <= 0;
}


/*
 * Wait callback: done once flag bit 7 of the state word is clear.
 */
int func_021FC9E4(void *a, Flags_021FC9E4 *s)
{
    if (s->bit)
        return 0;
    return 1;
}
