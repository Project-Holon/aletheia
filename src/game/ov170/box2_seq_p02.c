/*
 * file:     box2_seq_p02.c
 * unit:     yes
 * function: func_021E1458, func_021E152C, func_021E1628, func_021E1988, func_021E19D4, func_021E1A28, func_021E1A78, func_021E1ACC, func_021E1B1C, func_021E1E34
 * address:  0x021E1458
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
 *   func_021ED544 0x021ED544 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021DEA4C 0x021DEA4C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEB08 0x021DEB08 thumb ov170
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_021EA878 0x021EA878 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021ED2F4 0x021ED2F4 thumb
 *   func_02035CB8 0x02035CB8 arm
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021DEA3C 0x021DEA3C thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021E0FB0 0x021E0FB0 thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   d_021EF7B4 0x021EF7B4 data a1
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF248 0x021EF248 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EDD38 0x021EDD38 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_021DD930 0x021DD930 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021EAB50 0x021EAB50 thumb ov170
 *   func_021EBF74 0x021EBF74 thumb ov170
 *   d_021EFA7C 0x021EFA7C data a4
 */
#include "../../matched/include/Obj08237.h"
#include "../../matched/include/Obj10653.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23881.h"
#include "../../matched/include/Obj23882.h"
#include "../../matched/include/Obj23883.h"
#include "../../matched/include/Obj23884.h"
#include "../../matched/include/Obj03847.h"
#include "../../matched/include/Obj23885.h"
#include "../../matched/include/Obj23886.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define CNT(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define SYS(p) (*(unsigned **)(p))
struct WinMgr;
struct Sound;
struct PrintSys;
typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk_021E1458;

typedef unsigned int   u32;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
} Blk_021E152C;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E1628;

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk_021E19D4;

typedef unsigned char  u8;

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk_021E1A28;

typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk_021E1A78;

typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk_021E1ACC;

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk_021E1B1C;

extern void func_021ED544(char *p, int b);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_020061E4(unsigned se);
extern void func_021ED108(char *p, int on);
extern void func_021EBFA8(char *p, int i, int v);
extern u32 func_021EBFEC(char *p, int i);
extern void func_021EC000(char *p, int i, int v);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void func_021DEA4C(char *p, int a, int b);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DEB08(unsigned char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern void func_021EA878(unsigned char *p, int v);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021ED2F4(char *w);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF1DC(short x, int y);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern void func_021ED888(char *w, int a);
extern int func_021EF248(void);
extern void func_021EF3D8(struct WinMgr *mgr);
extern unsigned func_0202136C(unsigned short v);
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021EF180(int a, int b);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EE364(char **p, int idx, int v);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021E0FB0(char *w, int x, int y);
extern int func_021DEAFC(int a);
extern void func_021ED6E4(char **p, int v);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EDD38(char *p, int d);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern int func_021E01B0(unsigned char *p);
extern int func_02035C38(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern int func_021EF60C(struct WinMgr *mgr);
extern int func_021DE5C8(char *p, unsigned id);
extern void func_021DF43C(char *p, int x, int y);
extern int func_021DD930(unsigned char *p);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **p, int flag);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021ED7C4(char *p, int i);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_021EAB50(unsigned char *w);
extern void func_021EBF74(char *);
int func_021E1458(char *p);
int func_021E152C(unsigned char *p);
int func_021E1628(unsigned char *p);
int func_021E1988(unsigned char *p);
int func_021E19D4(char *p);
int func_021E1A28(char *p);
int func_021E1A78(char *p);
int func_021E1ACC(char *p);
int func_021E1B1C(unsigned char *p);
int func_021E1E34(char *p, int *state);
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];


int func_021E1458(char *p)
{
    Blk_021E1458 *b = (Blk_021E1458 *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        func_021ED544(p, 7);
        b->state = 1;
    case 1:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state = 2;
            break;
        }
        func_021EC0B0(WORK(p), 10, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 2:
        func_020061E4(0x667);
        func_021ED544(p, 6);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED544(p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}


int func_021E152C(unsigned char *p)
{
    Blk_021E152C *b = (Blk_021E152C *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            int dir = func_021DD210(p, p[0x14], p[0x17]);
            p[0x14] = p[0x17];
            func_021EC35C((char **)p, p[0x14]);
            func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        func_021ED544((char *)p, 7);
        func_021DEA4C((char *)p, *(unsigned short *)(WORK(p) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (func_021E00C4((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (func_021E0128((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (func_021DEB08(p) == 0) {
            func_020061E4(0x667);
            b->state = 5;
        }
        break;
    case 5:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        func_021ED544((char *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}


/*
 * Twin of src/matched/ov170_func_021E0ABC.c.
 */
int func_021E1628(unsigned char *p)
{
    Blk_021E1628 *b = (Blk_021E1628 *)(WORK(p) + 0x58);
    int busy = func_021EF5C4(MGR(p));
    int wait = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        func_021EA878(p, (short)CNT(p));
        if (CNT(p) != 0) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
            b->state = 1;
        } else {
            func_021EF534(MGR(p));
            b->state = 11;
        }
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) == 1)
            break;
        func_021ED108(WORK(p), 0);
        func_021ED2F4(WORK(p));
        b->state = 2;
    case 2:
        if (func_021EF45C(MGR(p)) == 1)
            func_021ED888(WORK(p), 1);
        if (func_02035CB8(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            if (wait == 1 || func_021EF45C(MGR(p)) == 1)
                flag = 1;
            else
                flag = 0;
            if (wait == 0 && func_021EF45C(MGR(p)) == 1) {
                r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
                if (r == 0xFF)
                    r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            } else {
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF7B4);
            }
            first = r;
            if (r == 0xFF)
                r = p[0x16];
            else if (func_021DDE80(p, p[0x16], r) == 0)
                r = p[0x16];
            if (flag == 1) {
                func_021DEA3C((int)p, first, r, 2);
                b->state = 7;
            } else {
                func_021DEA3C((int)p, first, r, 1);
                if (r == p[0x16] && (func_0202136C(CNT(p)) == 0 || first == p[0x16]))
                    func_021EF534(MGR(p));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && func_021EF45C(MGR(p)) == 0 && func_021EF248() == 0) {
            func_021EF3D8(MGR(p));
            func_021ECB20((char *)p, 0x81, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            func_021EC000(WORK(p), 4, 0);
            func_021EE038((char *)p, 2, 1, 1);
            p[0x1E] = 1;
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 3;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 4;
            }
        }
        func_021E0FB0(WORK(p), x, y);
        break;
    case 3:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 7:
    case 8:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if (CNT(p) != 0) {
                    func_021ED108(WORK(p), 0);
                    func_021ED2F4(WORK(p));
                }
                func_021EE038((char *)p, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021EC000(WORK(p), 10, 0);
            func_021ED108(WORK(p), 0);
            b->state = 11;
        }
        break;
    case 11:
        if (busy == 0 && wait == 0) {
            b->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int func_021E1988(unsigned char *p)
{
    char *w = *(char * *)&((struct Obj10653 *)p)->f2C;
    char *b = w + 0x58;
    switch (((struct Obj08237 *)b)->fC) {
    case 0:
        if (!func_021EBFEC(w, 10)) {
            unsigned old = p[0x16];
            p[0x16] = **(unsigned short * *)&((struct Obj08237 *)b)->f8;
            func_021DEA3C((int)p, old, old, 1);
            ((struct Obj08237 *)b)->fC = 1;
        }
        break;
    case 1:
        if (!func_021DEAFC((int)p)) {
            ((struct Obj08237 *)b)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}


int func_021E19D4(char *p)
{
    Blk_021E19D4 *b = (Blk_021E19D4 *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23881 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)-b->fE);
    return 1;
}


int func_021E1A28(char *p)
{
    Blk_021E1A28 *b = (Blk_021E1A28 *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23882 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}

int func_021E1A78(char *p)
{
    Blk_021E1A78 *b = (Blk_021E1A78 *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23883 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 1 && r <= 4)
            func_021EE008(p, r - 1, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)-b->fE);
    return 1;
}

int func_021E1ACC(char *p)
{
    Blk_021E1ACC *b = (Blk_021E1ACC *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23884 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 1 && r <= 4)
            func_021EE008(p, r - 1, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}


/*
 * Sibling of src/matched/ov170_func_021DFA30.c.
 */
int func_021E1B1C(unsigned char *p)
{
    Blk_021E1B1C *b = (Blk_021E1B1C *)(WORK(p) + 0x58);
    int busy;
    unsigned r;
    unsigned x;
    unsigned y;
    if (func_0202CE40(MGR(p), 8) == 1)
        busy = func_021E01B0(p);
    else
        busy = 0;
    r = func_021EF5C4(MGR(p));
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_02035CB8(&x, &y) == 0) {
            r = 0xFF;
            if (func_021EF45C(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (SYS(p)[9] == 4 && SYS(p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            if (func_021DE158(p, p[0x16], r) == 0)
                r = 0xFF;
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            if (r != 0xFF)
                p[0x16] = func_021DE5C8((char *)p, 0x24);
            if (func_021EF45C(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            if (r == 0xFF && p[0x14] != p[0x17]) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 4;
                else
                    b->state = 5;
            } else {
                b->state = 2;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0 && func_021EF45C(MGR(p)) == 0 && p[0x16] != func_021EF180(x, y)) {
            p[0x1A] = 2;
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_021EE038((char *)p, 2, 1, 2);
            *(int *)(WORK(p) + 0xA168) = p[0x16];
            *(int *)(WORK(p) + 0x68) = 0x17;
        }
        if (b->timer == 0) {
            int dir = func_021EF1B4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD16C(p, 0);
                b->state = 6;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD16C(p, 1);
                b->state = 7;
            }
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 4:
        if (func_021E00C4((char *)p) == 0)
            b->state = 2;
        break;
    case 5:
        if (func_021E0128((char *)p) == 0)
            b->state = 2;
        break;
    case 2:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 7:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 16:
        func_021DE66C(p, b->moves);
        if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
        } else {
            func_021ED6E4((char **)p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            func_021EE3E4((char **)p, p[0x16]);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}

extern int (*const d_021EFA7C[])(char *);

int func_021E1E34(char *p, int *state)
{
    if (!*(char * *)&((struct Obj03847 *)p)->f2C || !((struct Obj23885 *)(*(char * *)&((struct Obj03847 *)p)->f2C))->f8C || func_0201C6B4(((struct Obj23886 *)(*(char * *)&((struct Obj03847 *)p)->f2C))->f8C))
        *state = d_021EFA7C[*state](p);
    if (*state == 0x69)
        return 0;
    if (*(char * *)&((struct Obj03847 *)p)->f2C) {
        func_021EAB50((unsigned char *)(*(char * *)&((struct Obj03847 *)p)->f2C));
        func_021EBF74(*(char * *)&((struct Obj03847 *)p)->f2C);
    }
    return 1;
}
