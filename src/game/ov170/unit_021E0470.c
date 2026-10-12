/*
 * file:     unit_021E0470.c
 * unit:     yes
 * function: func_021E0470, func_021E066C, func_021E070C, func_021E072C, func_021E0778, func_021E087C
 * address:  0x021E0470
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
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_021EF57C 0x021EF57C thumb
 *   func_02035CB8 0x02035CB8 arm
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DF228 0x021DF228 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   func_021DE530 0x021DE530 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021DD930 0x021DD930 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021ECC1C 0x021ECC1C thumb ov170
 *   func_021ED544 0x021ED544 thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EF75C 0x021EF75C thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E01E0 0x021E01E0 thumb
 *   func_021E01B0 0x021E01B0 thumb
 */
#include "box2_types.h"
#include "../../matched/include/Obj18462.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define W(p) (*(char **)((p)+0x2C))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))
struct WinMgr;
typedef struct {
    unsigned char pad[8];
    void *entry;
    unsigned short state;
    unsigned short timer;
} Blk_021E0470;

typedef struct {
    unsigned char x, y, dx, dy;
    unsigned directionX:1;
    unsigned directionY:1;
    unsigned count:30;
} Motion;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk_021E087C;

extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern int func_02035C38(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern void func_021DE530(unsigned char *p, int a, int b);
extern int func_021EF60C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern int func_021DE5C8(char *p, unsigned id);
extern void func_020061E4(unsigned se);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021EF180(int a, int b);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021DF43C(char *p, int x, int y);
extern int func_021DD930(unsigned char *p);
extern void func_021EF534(struct WinMgr *mgr);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_021ED7C4(char *w, int i);
extern void func_021DF040(char *p);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC0B0(char *w, int i, short *x, short *y, unsigned short z);
extern void func_021ECC1C(unsigned char *p);
extern void func_021ED544(char *p, int b);
extern void func_021EC768(char *p, unsigned i, int flag);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EF75C(struct WinMgr *mgr);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021E01E0(char *p);
extern int func_021E01B0(unsigned char *p);
int func_021E0470(unsigned char *p);
int func_021E066C(char *p);
int func_021E070C(char *p);
void func_021E072C(unsigned char *p);
int func_021E0778(u8 *p);
int func_021E087C(unsigned char *p);
extern const unsigned char d_021EF79C[];


/*
 * State machine in the 021DFA30 family (template 021E0ABC): pick a box with
 * the pen, slide the cursor there, then close.
 */
int func_021E0470(unsigned char *p)
{
    Blk_021E0470 *b = (Blk_021E0470 *)(WORK(p) + 0x58);
    int busy = func_021EF5C4(MGR(p));
    int wait = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_02035CB8(&x, &y) == 0) {
            int r = 0xFF;
            if (func_021EF45C(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            func_021DE530(p, p[0x16], r);
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            p[0x16] = func_021DE5C8((char *)p, 0x24);
            if (p[0x16] >= 0x1E) {
                b->state = 5;
                break;
            }
            if (wait == 1 || func_021EF45C(MGR(p)) == 1) {
                func_020061E4(0x669);
                func_021EF3A0(MGR(p));
            }
            b->state = 2;
            break;
        }
        if (busy == 0 && wait == 0 && func_021EF45C(MGR(p)) == 0 && p[0x16] != func_021EF180(x, y)) {
            func_020061E4(0x669);
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EE038((char *)p, 2, 2, 1);
            *(int *)(WORK(p) + 0xA168) = p[0x16];
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 2:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 3;
        }
        if (wait == 0)
            func_021EF534(MGR(p));
        break;
    case 3:
        if (wait == 0) {
            func_021EF534(MGR(p));
            b->state = 4;
        }
        break;
    case 4:
        if (busy == 0) {
            func_021DE66C(p, b->entry);
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
            b->state = 7;
        }
        break;
    case 5:
        if (func_021DD930(p) == 0) {
            func_021DE66C(p, b->entry);
            func_020061E4(0x667);
            func_020061E4(0x669);
            p[0x16] = 0xFF;
            func_021EF3A0(MGR(p));
            b->state = 6;
        }
        break;
    case 6:
        if (wait == 0) {
            func_021DF040((char *)p);
            b->state = 7;
        }
        break;
    case 7:
        func_021ECB20((char *)p, 1, 0);
        func_021ECB20((char *)p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}

int func_021E066C(char *p)
{
    Motion *m;
    short xy[2];
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 0) {
        func_021EC08C(WORK(p), 4, m->x, m->y, 0);
        func_021ECC1C((unsigned char *)p);
        return 0;
    }
    m->count--;
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    if (m->directionX == 0)
        xy[1] += m->dx;
    else
        xy[1] -= m->dx;
    if (m->directionY == 0)
        xy[0] += m->dy;
    else
        xy[0] -= m->dy;
    func_021EC08C(WORK(p), 4, xy[1], xy[0], 0);
    func_021ECC1C((unsigned char *)p);
    return 1;
}

/*
 * 1 unless both queries come back zero.
 */
int func_021E070C(char *p)
{
    if (func_021E066C(p) == 0 && func_021EF5C4(*(struct WinMgr **)(((struct Obj18462 *)p)->f2C + 0x74)) == 0)
        return 0;
    return 1;
}


void func_021E072C(unsigned char *p)
{
    short xy[2];
    func_021ED544((char *)p, 8);
    func_021EC0B0(WORK(p), 4, &xy[1], &xy[0], 0);
    func_021EC08C(WORK(p), *(unsigned char *)(WORK(p) + 0x3DF6), (short)xy[1], (short)(xy[0] + 4), (short)0);
    func_021EC768(WORK(p), 0x24, 0);
}

int func_021E0778(u8 *p)
{
    char *s=W(p)+0x58;
    short xy[2];
    int k;
    switch(((BoxSeq *)s)->fC) {
    case 0:
        func_021ED544((char *)p,7);
        (((BoxSeq *)s)->fC)++;
    case 1:
        if(((BoxSeq *)s)->fE==4) {
            ((BoxSeq *)s)->fE=0;
            (((BoxSeq *)s)->fC)++;
            break;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,(short)xy[1],(short)(xy[0]+2),(short)0);
        (((BoxSeq *)s)->fE)++;
        break;
    case 2:
        func_020061E4(0x666);
        func_021ED544((char *)p,8);
        (((BoxSeq *)s)->fC)++;
    case 3:
        if(((BoxSeq *)s)->fE==4) {
            ((BoxSeq *)s)->fE=0;
            ((BoxSeq *)s)->fC=0;
            return 0;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,(short)xy[1],(short)(xy[0]-2),(short)0);
        k=*(u8 *)(W(p)+0x3DF6);
        func_021EC0B0(W(p),k,&xy[1],&xy[0],0);
        func_021EC08C(W(p),k,(short)xy[1],(short)(xy[0]-2),(short)0);
        func_021ED7C4(W(p),0x24);
        (((BoxSeq *)s)->fE)++;
        break;
    }
    return 1;
}


/*
 * Drop callback while carrying a Pokemon (block at work + 0x58, template
 * func_021DFA30): changes box if the cursor sits on another box, then
 * settles the carried icon; returns 0 once the drop is finished.
 */
int func_021E087C(unsigned char *p)
{
    Blk_021E087C *b = (Blk_021E087C *)(WORK(p) + 0x58);
    int r;

    switch (b->state) {
    case 0:
        if (p[0x16] >= 0x1E && func_021EF770(MGR(p)) == 1) {
            if (HELD(p) < 0x1E || HELD(p) == 0xFF || func_021DE158(p, p[0x16], HELD(p)) == 0) {
                func_021EE008((char *)p, 0, 0);
                func_021EF75C(MGR(p));
                func_020061E4(0x669);
                b->state = 5;
                break;
            }
        }
        if (p[0x16] < 0x1E && p[0x14] != p[0x17]) {
            if (HELD(p) == 0xFF || func_021DE158(p, p[0x16], HELD(p)) == 0) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 2;
                else
                    b->state = 3;
                break;
            }
        }
    case 1:
        func_021ED544((char *)p, 7);
        func_021DE158(p, p[0x16], HELD(p));
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
        if (func_021DD930(p) == 0) {
            func_021DE66C(p, b->moves);
            func_021ED544((char *)p, 6);
            func_021ED6E4((char **)p, 0);
            func_020061E4(0x667);
            b->state = 0;
            return 0;
        }
        break;
    case 5:
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_020061E4(0x669);
            b->state = 6;
        }
        break;
    case 6:
        if (func_021E01B0(p) == 0)
            b->state = 1;
        break;
    }
    return 1;
}
