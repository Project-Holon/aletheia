/*
 * file:     box2_ui_p06.c
 * unit:     yes
 * function: func_021EE544, func_021EE57C, func_021EE64C, func_021EE65C, func_021EE72C, func_021EE744, func_021EE754, func_021EE7C4
 * address:  0x021EE544
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EEFA4  0x021EEFA4  thumb
 *   d_021F0188  0x021F0188  data
 *   d_021F0DCC  0x021F0DCC  data
 *   d_021F0370  0x021F0370  data
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE408 0x021EE408 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021EE038 0x021EE038 thumb
 */
#include "../../matched/include/Obj12179.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24038.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
struct WinMgr;
struct Sound;
typedef struct { unsigned char a, b, pad[10]; } E;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef struct {
    int pad[9];
    int x24;
} Top;

extern void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
extern u8 func_020260E0(struct Sound *obj);
extern int func_02025DE8(struct Sound *obj);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE408(char *p, int v);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);
extern void func_021EEF74(char *q, int a, int b);
extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);
extern int func_021EF45C(struct WinMgr *mgr);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021EE038(char *p, int a, int b, int c);
void func_021EE544(char *p, unsigned int i);
unsigned func_021EE57C(char *p);
void func_021EE64C(void *a, int tag);
unsigned func_021EE65C(char *p);
void func_021EE72C(char *p, int a, int b);
void func_021EE744(void *a, int tag);
void func_021EE754(unsigned char *p, unsigned r);
void func_021EE7C4(char *p, int a, int b);
extern const unsigned char d_021F0188[];
extern E d_021F0DCC[];
extern E d_021F0370[];

void func_021EE544(char *p, unsigned int i)
{
    E *e; const unsigned char *g = d_021F0188;
    if (i < 0x1e) { e = &d_021F0DCC[i]; } else { e = &d_021F0370[i - 0x1e]; }
    func_021EEFA4(*(char **)(p + 0x2c), e->a, e->b, g[0], g[1]);
}


unsigned func_021EE57C(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x23 && r <= 0x27) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x21;
        }
        if (r == 0x21) {
            func_020355D8(1);
            return 0x21;
        }
        if (r == 0x22) {
            func_020260E4(OBJ(p), sel);
            return 0x22;
        }
    } else if (r - 0x21 <= 1) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}


/*
 * Ignore the two known tags, otherwise run the update.
 */
void func_021EE64C(void *a, int tag)
{
    if (tag != 0x21 && tag != 0x22)
        func_021EE408(a, tag);
}


unsigned func_021EE65C(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x24 && r <= 0x29) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}


/*
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
void func_021EE72C(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12179 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12179 *)p)->f2C, (int)((void *)&func_021E066C));
}


void func_021EE744(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}


void func_021EE754(unsigned char *p, unsigned r)
{
    int a = 0;
    int f = 0;
    if (p[0x18] == 1) {
        a = 2;
        if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3)
            f = 1;
    } else if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        f = 1;
    } else if (r >= 0x1E) {
        if (func_021EF45C(*(struct WinMgr * *)&((struct Obj24038 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 0 || func_021DD25C((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    } else {
        if (func_021DD25C((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    }
    func_021EE038((char *)p, a, 1, f);
}

/*
 * Stage the pair, forward it, re-key the queue with the
 *   0x021E066D selector and record the first argument at 0xA168.
 */
void func_021EE7C4(char *p, int a, int b)
{
    func_021EE754((unsigned char *)p, a);
    func_021EEF74((char *)(*(int *)&((struct Obj00000 *)p)->f2C), a, b);
    func_021DC9B4((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA168) = a;
}
