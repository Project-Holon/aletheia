/*
 * file:     box2_seq_p19.c
 * unit:     yes
 * function: func_021E8340, func_021E83C0, func_021E8508, func_021E85F0, func_021E86EC
 * address:  0x021E8340
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
 *   func_021EC9D8 0x021EC9D8 thumb ov170
 *   func_021ECA38 0x021ECA38 thumb ov170
 *   func_021DE7B4 0x021DE7B4 thumb ov170
 *   func_021ED588 0x021ED588 thumb ov170
 *   func_021EBBC8 0x021EBBC8 thumb ov170
 *   func_021E912C 0x021E912C thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EF5E8 0x021EF5E8 thumb ov170
 *   func_021EC01C 0x021EC01C thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EF57C 0x021EF57C thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021EF770 0x021EF770 thumb ov170
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EF680 0x021EF680 thumb ov170
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021EF45C 0x021EF45C thumb ov170
 *   func_021EF69C 0x021EF69C thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021EB988 0x021EB988 thumb ov170
 *   func_021EF534 0x021EF534 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EBC28 0x021EBC28 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   d_021EF908 0x021EF908 data a4
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8F50 0x021E8F50 thumb ov170
 *   func_021E949C 0x021E949C thumb ov170
 *   func_021E8FE0 0x021E8FE0 thumb ov170
 *   func_021E8FD0 0x021E8FD0 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EA83C 0x021EA83C thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23929.h"
#include "../../matched/include/Obj23930.h"
#include "../../matched/include/Obj23931.h"
#include "../../matched/include/Obj23932.h"
#include "../../matched/include/Obj23933.h"
#include "../../matched/include/Obj23934.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
#define M (*(struct WinMgr **)(W + 0x74))
struct WinMgr;
struct Sound;
typedef unsigned char u8;

typedef struct { unsigned short a; unsigned short b; } Ent;

typedef struct { u8 pad[0x1c]; u8 lo : 4; u8 hi : 4; } Flags;

typedef unsigned int   u32;

extern int func_021EC9D8(char *p);
extern void func_021ECA38(int *p);
extern void func_021DE7B4(char *p);
extern void func_021ED588(char *p);
extern void func_021EBBC8(unsigned char *p, unsigned kind, int i);
extern int func_021E912C(unsigned char *p);
extern void func_021EC000(char *, int, int);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ED888(char *, int);
extern int func_021EF5E8(struct WinMgr *mgr);
extern u32 func_021EC01C(char *p, int i);
extern void func_021ED6E4(char **, int);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E8FC0(char *, int, int);
extern int func_021E0190(char *);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EE008(char *, int, int);
extern void func_021EF680(char *);
extern int func_021EA858(char *, int);
extern int func_021EF45C(struct WinMgr *mgr);
extern void func_021EF69C(char *);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021E01B0(u8 *);
extern void func_021EB988(char *, Ent *, unsigned);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021ECB20(char *, int, int);
extern void func_021EBC28(u8 *, int, int);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021ED544(char *, int);
extern int func_02025DE8(struct Sound *obj);
extern void func_020061E4(unsigned);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern void func_021ED55C(char **p, int flag);
extern void func_021EE038(char *, int, int, int);
extern void func_021EF670(char *);
extern int func_021EA83C(char *p, int a);
int func_021E8340(unsigned char *p);
int func_021E83C0(char *p);
int func_021E8508(u8 *p);
int func_021E85F0(char *p);
int func_021E86EC(unsigned char *p);
extern Ent d_021EF908[];

int func_021E8340(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (func_021EC9D8(SLOT(p)) != 0)
            break;
        func_021ECA38((int *)SLOT(p));
        func_021DE7B4((char *)p);
        func_021ED588((char *)p);
        func_021EBBC8(p, 4, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 1:
        func_021EBBC8(p, 5, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 2:
        STEP(p) = 0;
        return func_021E912C(p);
    }
    return 0x5C;
}

/*
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int func_021E83C0(char *p)
{
    switch (S) {
    case 0:
        S++;
        func_021EC000(W, 4, 0);
        func_021ED508((unsigned char *)p, 14, 0);
        func_021ED888(W, 0);
        if (func_021EF5E8(M) == 1) {
            if (func_021EC01C(W, 10) == 1)
                func_021EC000(W, 10, 0);
            func_021ED6E4((char **)p, 0);
            func_021EBA5C(W, 24);
            func_021DD14C(p);
            func_021EF57C(M);
            return func_021E8FC0(p, (int)func_021E0190, 0x5d);
        } else if (func_021EF770(M) == 1) {
            func_021EE008(p, 0, 0);
            func_021EF680(W);
            return func_021EA858(p, 0x5d);
        } else if (func_021EF45C(M) == 1) {
            func_021EF69C(W);
            func_021EF3A0(M);
            return func_021E8FC0(p, (int)func_021E01B0, 0x5d);
        } else {
            func_021EF680(W);
        }
    case 1:
        func_021EB988(p, d_021EF908, 4);
        func_021EF534(M);
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5d);
    case 2:
        S = 0;
        func_021ECB20(p, 1, 1);
        func_021EBC28((u8 *)p, 0, 24);
        func_021EE364((char **)p, 10, 0);
        ((Flags *)p)->lo = 0;
        func_021ED544(p, 6);
        return 0x5e;
    }
    return 0x5d;
}

int func_021E8508(u8 *p)
{
    unsigned v = func_02025DE8(((struct Obj23929 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
    switch (v) {
    case 0:
        func_020061E4(0x54c);
        return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x60));
    case 1:
        func_020061E4(0x54c);
        ((struct Obj23930 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA17C = 0;
        return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x64));
    case 2:
        func_020061E4(0x54c);
        return func_021E949C((char *)p, 4, 0x67);
    case 3:
        func_020061E4(0x551);
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5f));
    case -2:
        func_020061E4(0x551);
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5f));
    case -3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x5e));
    }
    return 0x5e;
}

int func_021E85F0(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(W, 24);
        func_021DD14C(p);
        func_021EE038(p, 0, 0, 1);
        func_021EF57C(*(struct WinMgr **)(W + 0x74));
        S++;
        return func_021E8FC0(p, (int)func_021E0190, 0x5f);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021ED508((unsigned char *)p, 14, 1);
        if (((struct Obj23931 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23932 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23933 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23934 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x5f;
}

int func_021E86EC(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        *(unsigned char *)(WORK(p) + 0xA17A) = 1;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x60);
    case 1:
        p[0x19] = p[0x14];
        STEP(p)++;
        func_020061E4(0x669);
        return func_021EA83C((char *)p, 0x60);
    case 2:
        STEP(p) = 0;
        func_021EE008((char *)p, 0, 1);
        func_021EE364((char **)p, 0xC, 1);
        *(int *)(WORK(p) + 0xA168) = 1;
        func_021EBC28(p, 1, 0x19);
        func_021EE038((char *)p, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}
