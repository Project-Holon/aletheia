/*
 * file:     box2_seq_p20.c
 * unit:     yes
 * function: func_021E87A0, func_021E8950, func_021E8A58, func_021E8A74, func_021E8BF8
 * address:  0x021E87A0
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
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EA808 0x021EA808 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1ACC 0x021E1ACC thumb
 *   func_021E1A78 0x021E1A78 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EA798 0x021EA798 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021EA858 0x021EA858 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_02007A80 0x02007A80 thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EBC28 0x021EBC28 thumb
 *   func_02026124 0x02026124 thumb
 *   d_021EF9C8 0x021EF9C8 data
 *   d_021EF93C 0x021EF93C data
 *   d_021EF964 0x021EF964 data
 *   d_021EF978 0x021EF978 data
 *   d_021EF98C 0x021EF98C data
 *   d_021EF9A0 0x021EF9A0 data
 *   d_021EF9E0 0x021EF9E0 data
 *   d_021EF928 0x021EF928 data
 *   d_021EF9F8 0x021EF9F8 data
 *   func_021E949C 0x021E949C thumb
 *   func_021EA928 0x021EA928 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23935.h"
#include "../../matched/include/Obj23936.h"
#include "../../matched/include/Obj23937.h"
#include "../../matched/include/Obj23938.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define STATE(p) (*(int *)((p) + 0x28))
#define CUR(p) (*(unsigned char *)(WORK(p) + 0xA17F))
#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define KIND(p) (*(unsigned char *)(WORK(p) + 0xA17C))
#define SAVE(p) (*(void **)(*(char **)(p) + 4))
#define SEL(p) (*(unsigned char *)(WORK(p) + 0xA17C))
struct Sound;
struct Struct_02025CD0;
struct WinMgr;
typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_021EF1D4(unsigned *a, unsigned *b);
extern void func_021EA808(char *p);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern int func_02025DE8(struct Sound *obj);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020061E4(unsigned se);
extern void func_021DD1C4(char *p, int a);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E1ACC(char *p);
extern int func_021E1A78(char *p);
extern void func_021EE008(char *p, int a, int b);
extern int func_021EA798(unsigned char *p, int sel);
extern int func_021E8F50(char *p, int v);
extern int func_021E954C(unsigned char *p, int id, int lo, int arg);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern void func_021ED55C(char **p, int flag);
extern void func_021EBA5C(char *, int);
extern void func_021DD14C(char *);
extern int func_021EA858(char *, int);
extern void func_021ED888(char *, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ECB20(char *, int, int);
extern void func_021EF670(char *);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021E0190(char *p);
extern int func_02007A80(void *save, unsigned bits);
extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021EBC28(unsigned char *p, int kind, int i);
extern void func_02026124(struct Sound *obj, u32 idx);
extern int func_021E949C(char *p, int a, int b);
extern int func_021EA928(unsigned char *p, int a);
int func_021E87A0(unsigned char *p);
int func_021E8950(char *p);
int func_021E8A58(char *p);
int func_021E8A74(unsigned char *p);
int func_021E8BF8(unsigned char *p);
extern const unsigned char d_021EF9C8[];
extern const unsigned char d_021EF93C[];
extern const unsigned char d_021EF964[];
extern const unsigned char d_021EF978[];
extern const unsigned char d_021EF98C[];
extern const unsigned char d_021EF9A0[];
extern const unsigned char d_021EF9E0[];
extern const unsigned char d_021EF928[];
extern const unsigned char d_021EF9F8[];


/*
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */
int func_021E87A0(unsigned char *p)
{
    unsigned x, y;
    unsigned r;

    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(WORK(p) + 0xA184) = y;
        STATE(p) = 0x61;
        func_021EA808((char *)p);
        func_020260F4(LIST(p), 0);
        return 0xF;
    }
    r = func_02025DE8(LIST(p));
    switch (r) {
    case 0:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, -1);
        return func_021E8FC0((char *)p, (int)func_021E1ACC, 0x61);
    case 5:
        func_020061E4(0x548);
        func_021DD1C4((char *)p, 1);
        return func_021E8FC0((char *)p, (int)func_021E1A78, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        CUR(p) = p[0x19] + r - 1;
        if (CUR(p) >= p[0x15])
            CUR(p) -= p[0x15];
        if (CUR(p) != p[0x14]) {
            func_021EE008((char *)p, 0, 0);
            return func_021EA798(p, 1);
        }
        func_020061E4(0x548);
        func_021EE008((char *)p, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        func_020061E4(0x551);
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x62));
    case (unsigned)-3:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x61));
    case (unsigned)-8:
        if (func_020260E0(LIST(p)) == 1) {
            func_020061E4(0x548);
            func_021DD1C4((char *)p, -1);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0x61);
        }
        break;
    case (unsigned)-7:
        if (func_020260E0(LIST(p)) == 4) {
            func_020061E4(0x548);
            func_021DD1C4((char *)p, 1);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0x61);
        }
        break;
    }
    return 0x61;
}

/*
 * Return from func_021EA858 is used despite its legacy void declaration.
 */
int func_021E8950(char *p)
{
    switch (S) {
    case 0:
        *(u8 *)(W + 0xA17A) = 0;
        func_021ED55C((char **)p, 0);
        func_021EBA5C(W, 25);
        func_021DD14C(p);
        func_021EE008(p, 0, 0);
        func_020061E4(0x669);
        S++;
        return func_021EA858(p, 0x62);
    case 1:
        S = 0;
        func_021ED888(W, 1);
        func_021EE038(p, 0, 0, 1);
        func_021ED508((unsigned char *)p, 14, 1);
        if (((struct Obj23935 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23936 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 1) {
            func_021ECB20(p, 1, 0);
            func_021EE364((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23937 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 3) {
            func_021ECB20(p, 0x81, 1);
            func_021EF670(W);
            func_021EE364((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23938 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 4) {
            func_021ECB20(p, 1, 0);
            func_021EF670(W);
            func_021EE364((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x62;
}

int func_021E8A58(char *p)
{
    func_021EE008(p, func_020260E0((struct Sound *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70))) - 1, 1);
    return 0x61;
}


/*
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */
int func_021E8A74(unsigned char *p)
{
    int flag;

    switch (STEP(p)) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C((char *)p);
        func_021EF57C(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x64);
    case 1:
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 1)
                func_021EB988(p, d_021EF9C8, 6);
            else
                func_021EB988(p, d_021EF93C, 5);
        } else if (KIND(p) == 1) {
            func_021EB988(p, d_021EF964, 5);
        } else if (KIND(p) == 2) {
            func_021EB988(p, d_021EF978, 5);
        } else if (KIND(p) == 3) {
            func_021EB988(p, d_021EF98C, 5);
        } else if (KIND(p) == 4) {
            func_021EB988(p, d_021EF9A0, 5);
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 1)
                func_021EB988(p, d_021EF9E0, 6);
            else
                func_021EB988(p, d_021EF928, 5);
        } else if (KIND(p) == 6) {
            func_021EB988(p, d_021EF9F8, 6);
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0((char *)p, (int)func_021E0190, 0x64);
    case 2:
        STEP(p) = 0;
        if (KIND(p) == 0)
            func_021EBC28(p, 2, 0x18);
        else
            func_021EBC28(p, 3, 0x18);
        flag = 0;
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 0)
                flag = 1;
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 0)
                flag = 1;
        } else if (KIND(p) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            func_021EE364((char **)p, 0xB, 1);
            func_02026124(LIST(p), 0);
        } else {
            func_021EE364((char **)p, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}


int func_021E8BF8(unsigned char *p)
{
    switch ((unsigned)func_02025DE8(*(void **)(WORK(p) + 0x70))) {
    case 0:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 0);
    case 1:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 1;
            return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 1);
    case 2:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 2;
            return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 2);
    case 3:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 3;
            return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 3);
    case 4:
        func_020061E4(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 4;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 5 && func_02007A80(((void **)((struct Obj00000 *)p)->f0)[1], 2) == 1) {
            SEL(p) = 6;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 6) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 4);
    case 5:
        func_020061E4(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFE:
        func_020061E4(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFD:
        func_020061E4(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x65));
    }
    return 0x65;
}
