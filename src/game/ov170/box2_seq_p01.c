/*
 * file:     box2_seq_p01.c
 * unit:     yes
 * function: func_021E09E0, func_021E0A40, func_021E0ABC, func_021E0E50, func_021E0ED4, func_021E0F4C, func_021E0FB0, func_021E0FD8, func_021E122C, func_021E1324
 * address:  0x021E09E0
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
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021DE428 0x021DE428 thumb ov170
 *   func_021DDAE8 0x021DDAE8 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021E066C 0x021E066C thumb ov170
 *   func_021EF5C4 0x021EF5C4 thumb ov170
 *   func_021ED2F4 0x021ED2F4 thumb ov170
 *   func_021EF400 0x021EF400 thumb
 *   func_021EA878 0x021EA878 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_02035CB8 0x02035CB8 arm
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021DEA3C 0x021DEA3C thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   func_021EC01C 0x021EC01C thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021ED14C 0x021ED14C thumb
 *   func_021ED310 0x021ED310 thumb
 *   func_021DE980 0x021DE980 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj08234.h"
#include "../../matched/include/Obj23878.h"
#include "../../matched/include/Obj10651.h"
#include "../../matched/include/Obj08235.h"
#include "../../matched/include/Obj08236.h"
#include "../../matched/include/Obj10652.h"
#include "../../matched/include/Obj14264.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define CNT(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define W(p) (*(char **)((p) + 0x2C))
struct WinMgr;
struct Sound;
typedef unsigned int   u32;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E0ABC;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk_021E0FD8;

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char pad[8];
    Entry *entry;
    unsigned short state;
} Blk_021E122C;

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk_021E1324;

extern void func_021ED544(char *p, int a);
extern void func_021DE428(unsigned char *p, unsigned a, unsigned b);
extern int func_021DDAE8(unsigned char *p);
extern void func_021DE66C(char *p, void *a);
extern void func_020061E4(u32 a);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern int func_021E066C(char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern void func_021ED2F4(char *w);
extern int func_021EF400(unsigned char *p);
extern void func_021EA878(unsigned char *p, int v);
extern void func_021EF534(struct WinMgr *mgr);
extern unsigned int func_021EBFEC(char *p, int i);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF1DC(short x, int y);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern int func_021EF180(int a, int b);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **p, int flag);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EE364(char **p, int idx, int v);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DEAFC(int a);
extern void func_021ED6E4(char **p, int v);
extern u32 func_021EC01C(char *p, int i);
extern int func_021E0190(char *p);
extern void func_021ED14C(int a, int b, int c);
extern void func_021ED310(char *w);
extern void func_021DE980(unsigned char *p, int mode);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021ED1C8(char *w);
int func_021E09E0(char *p);
int func_021E0A40(char *p);
int func_021E0ABC(unsigned char *p);
int func_021E0E50(char *p);
int func_021E0ED4(unsigned char *p);
int func_021E0F4C(unsigned char *p);
void func_021E0FB0(char *w, int x, int y);
int func_021E0FD8(unsigned char *p);
int func_021E122C(unsigned char *p);
int func_021E1324(char *p);
extern const unsigned char d_021EF79C[];

int func_021E09E0(char *p)
{
    char *s;
    s = *(char * *)&((struct Obj00000 *)p)->f2C + 0x58;
    switch (((struct Obj08234 *)s)->fC) {
    case 0:
        func_021ED544(p, 7);
        func_021DE428((unsigned char *)p, ((struct Obj00000 *)p)->f16, ((struct Obj23878 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA17E);
        ((struct Obj08234 *)s)->fC = 1;
        break;
    case 1:
        if (func_021DDAE8((unsigned char *)p) == 0) {
            func_021DE66C(p, ((struct Obj08234 *)s)->f8);
            func_021ED544(p, 6);
            func_020061E4(0x667);
            ((struct Obj08234 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int func_021E0A40(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((struct Obj10651 *)s)->fC) {
    case 0:
        if (*(unsigned short *)(WORK(p) + 0xA16C)) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
        }
        (((struct Obj10651 *)s)->fC)++;
    case 1:
        a = func_021E066C(p);
        b = func_021EF5C4(*(struct WinMgr **)(WORK(p) + 0x74));
        if (a == 0 && b == 0) {
            if (*(unsigned short *)(WORK(p) + 0xA16C)) {
                func_021ED108(WORK(p), 0);
                func_021ED2F4(WORK(p));
            }
            ((struct Obj10651 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}


/*
 * Same state-machine family as src/matched/ov170_func_021DFA30.c.  The spill
 * slots of `first` and `flag` follow declaration order (later declaration,
 * lower address), and the two identical "fall back to p[0x16]" arms are an
 * if/else-if that the compiler tail-merges (bne then b), not one `||`.
 */
int func_021E0ABC(unsigned char *p)
{
    Blk_021E0ABC *b = (Blk_021E0ABC *)(WORK(p) + 0x58);
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
        if (func_02035CB8(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            int back;
            if (wait == 1 || func_021EF45C(MGR(p)) == 1)
                flag = 1;
            else
                flag = 0;
            r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (wait == 0 && func_021EF45C(MGR(p)) == 1 && r == 0xFF)
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p[0x16];
                back = 1;
            } else if (func_021DDE80(p, p[0x16], r) == 0) {
                r = p[0x16];
                back = 1;
            }
            if (flag == 1) {
                func_021DEA3C((int)p, first, r, 2);
                if (back == 1 && p[0x17] != 0xFF && p[0x17] != p[0x14]) {
                    int dir = func_021DD210(p, p[0x14], p[0x17]);
                    p[0x14] = p[0x17];
                    func_021EC35C((char **)p, p[0x14]);
                    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
                    if (dir == 0)
                        b->state = 5;
                    else
                        b->state = 6;
                } else {
                    b->state = 7;
                }
            } else {
                func_021DEA3C((int)p, first, r, 0);
                func_021EF534(MGR(p));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && func_021EF45C(MGR(p)) == 0 && p[0x16] != func_021EF180(x, y)) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_021ECB20((char *)p, 0x82, 1);
            func_020061E4(0x669);
            func_021EE364((char **)p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            func_021EE038((char *)p, 2, 1, 1);
            p[0x1E] = 0;
            *(unsigned char *)(WORK(p) + 0xA172) = 0;
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
    case 5:
        if (func_021E00C4((char *)p) == 0)
            b->state = 7;
        break;
    case 6:
        if (func_021E0128((char *)p) == 0)
            b->state = 7;
        break;
    case 7:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            b->state = 9;
        }
        break;
    case 8:
        if (func_021DEAFC((int)p) == 0) {
            func_020061E4(0x667);
            if (CNT(p) != 0) {
                func_021ED108(WORK(p), 0);
                func_021ED2F4(WORK(p));
            }
            func_021EE038((char *)p, 0, 0, 1);
            b->state = 11;
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

int func_021E0E50(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (((struct Obj08235 *)s)->fC) {
    case 0:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 2);
        }
        (((struct Obj08235 *)s)->fC)++;
    case 1:
        a = func_021E066C(p);
        b = func_021E0190(p);
        if (a == 0 && b == 0)
            (((struct Obj08235 *)s)->fC)++;
        break;
    case 2:
        if (func_021EC01C(WORK(p), 10) == 1) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
        }
        ((struct Obj08235 *)s)->fC = 0;
        return 0;
    }
    return 1;
}

int func_021E0ED4(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((struct Obj08236 *)b)->fC) {
    case 0:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 1);
            func_021EBFA8(W(p), 10, 2);
        }
        (((struct Obj08236 *)b)->fC)++;
        /* fall through */
    case 1:
        if (!func_021E0190((char *)p))
            (((struct Obj08236 *)b)->fC)++;
        break;
    case 2:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 0);
            func_021EC000(W(p), 10, 0);
        }
        ((struct Obj08236 *)b)->fC = 0;
        return 0;
    }
    return 1;
}

int func_021E0F4C(unsigned char *p)
{
    char *b = W(p) + 0x58;
    switch (((struct Obj10652 *)b)->fC) {
    case 0:
        if (func_021EC01C(W(p), 10) == 1) {
            func_021ED108(W(p), 1);
            func_021EBFA8(W(p), 10, 2);
        }
        (((struct Obj10652 *)b)->fC)++;
        break;
    case 1:
        if (!func_021EBFEC(W(p), 10)) {
            func_021ED108(W(p), 0);
            func_021EC000(W(p), 10, 0);
        }
        ((struct Obj10652 *)b)->fC = 0;
        return 0;
    }
    return 1;
}


void func_021E0FB0(char *w, int x, int y)
{
    func_021ED14C((int)w, (short)x, (short)y);
    func_021ED310(w);
    ((struct Obj14264 *)w)->fA180 = x;
    ((struct Obj14264 *)w)->fA184 = y;
}


/*
 * Sibling of src/matched/ov170_func_021E0ABC.c.
 */
int func_021E0FD8(unsigned char *p)
{
    Blk_021E0FD8 *b = (Blk_021E0FD8 *)(WORK(p) + 0x58);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        func_021ED2F4(WORK(p));
        b->state = 2;
        break;
    case 2:
        if (func_02035CB8(&x, &y) == 0) {
            unsigned first;
            unsigned r;
            int back;
            r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (r == 0xFF)
                r = (unsigned short)func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p[0x16];
                back = 1;
            } else if (func_021DDE80(p, p[0x16], r) == 0) {
                r = p[0x16];
                back = 1;
            }
            func_021DEA3C((int)p, first, r, 2);
            if (back == 1 && p[0x17] != 0xFF && p[0x17] != p[0x14]) {
                int dir = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
                if (dir == 0)
                    b->state = 5;
                else
                    b->state = 6;
            } else {
                b->state = 7;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
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
    case 5:
    case 6:
        if (b->state == 5 && func_021E00C4((char *)p) == 0)
            b->state = 7;
        if (b->state == 6 && func_021E0128((char *)p) == 0)
            b->state = 7;
    case 7:
        if (func_021DEAFC((int)p) == 0 && b->state == 7) {
            func_020061E4(0x667);
            b->state = 8;
        }
        break;
    case 8:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4((char **)p, 0);
        b->state = 9;
        break;
    case 9:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021EC000(WORK(p), 10, 0);
            func_021ED108(WORK(p), 0);
            b->state = 10;
        }
        break;
    case 10:
        b->state = 0;
        return 0;
    }
    return 1;
}


/*
 * Callback of func_021E6A60 (state machine in the 021E1324 family): show
 * window 10, return the held item to its slot, then hide the window.
 */
int func_021E122C(unsigned char *p)
{
    Blk_021E122C *b = (Blk_021E122C *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        b->state = 2;
        break;
    case 2: {
        unsigned char old = p[0x16];
        p[0x16] = b->entry->idx;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14])
            func_021DE980(p, 2);
        else
            func_021DEA3C((int)p, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (func_021DEAFC((int)p) != 0)
            break;
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            b->state = 5;
        } else {
            func_020061E4(0x667);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 5;
        break;
    case 5:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021EC000(WORK(p), 10, 0);
        func_021ED108(WORK(p), 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}


int func_021E1324(char *p)
{
    Blk_021E1324 *b = (Blk_021E1324 *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        b->state++;
        break;
    case 1:
        if (func_021EBFEC(WORK(p), 10) != 0)
            break;
        func_021ED108(WORK(p), 0);
        b->state++;
        break;
    case 2:
        func_021ED544(p, 7);
        b->state++;
    case 3:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state++;
            break;
        }
        func_021EC0B0(WORK(p), 4, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 4, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 4:
        func_020061E4(0x666);
        func_021ED544(p, 8);
        b->state++;
    case 5:
        if (b->cnt == 4) {
            func_021ED1C8(WORK(p));
            func_021ED2F4(WORK(p));
            b->cnt = 0;
            b->state = 0;
            return 0;
        }
        func_021EC0B0(WORK(p), 4, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 4, (short)t[1], (short)(t[0] - 2), (short)0);
        func_021EC0B0(WORK(p), 10, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 10, (short)t[1], (short)(t[0] - 2), (short)0);
        b->cnt++;
        break;
    }
    return 1;
}
