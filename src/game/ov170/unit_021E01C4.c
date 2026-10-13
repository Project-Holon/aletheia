/*
 * file:     unit_021E01C4.c
 * unit:     yes
 * function: func_021E01C4, func_021E01E0, func_021E0200
 * address:  0x021E01C4
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
 *   func_021ED918  0x021ED918  thumb  ov170
 *   func_020061E4 0x020061E4 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021DD16C 0x021DD16C thumb
 *   func_021DD930 0x021DD930 thumb
 *   func_021DDAE8 0x021DDAE8 thumb
 *   func_021DE428 0x021DE428 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021EF248 0x021EF248 thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_021EF480 0x021EF480 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   BGWINFRM_UpdateMove  0x0202CDD4  thumb  arm9
 */
#include "box2_types.h"

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
struct WinMgr;
typedef unsigned int u32;

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void func_021ED918(char *, int);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern int TOUCHPANEL_GetCont(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021ED888(char *p, int v);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int func_021DF1DC(short x, int y);
extern void func_021DE428(unsigned char *p, unsigned a, unsigned b);
extern int func_021EF60C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern int func_021DE5C8(char *p, unsigned id);
extern void func_020061E4(unsigned se);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021EF248(void);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021DF43C(char *p, int x, int y);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DD930(unsigned char *p);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_021ED7C4(char *p, int i);
extern int func_021DDAE8(unsigned char *p);
extern void func_021DF040(char *p);
extern void func_021ECB20(char *p, int f, int c);
int func_021E01C4(char *p);
int func_021E01E0(char *p);
int func_021E0200(unsigned char *p);

int func_021E01C4(char *p)
{
    int v = BGWINFRM_UpdateMove(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74), 9);
    func_021ED918(p, 8);
    return v;
}

int func_021E01E0(char *p)
{
    int x = BGWINFRM_UpdateMove(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74), 9);
    func_021ED918(p, -8);
    return x;
}


int func_021E0200(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    unsigned r = func_021EF5C4(MGR(p));
    int busy = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_021EF480(MGR(p)) == 0)
            func_021ED888(WORK(p), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (func_021EF480(MGR(p)) == 0 && busy == 0)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            func_021DE428(p, p[0x16], r);
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            p[0x16] = func_021DE5C8((char *)p, 0x24);
            if (p[0x16] < 0x1E) {
                b->state = 6;
            } else {
                if (func_021EF480(MGR(p)) == 0)
                    func_020061E4(0x669);
                func_021EF36C(MGR(p));
                func_021EF534(MGR(p));
                b->state = 4;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (r == 0 && busy == 0) {
            if (func_021EF480(MGR(p)) == 1) {
                if (func_021EF248() == 0) {
                    p[0x17] = 0xFF;
                    p[0x1A] = 0;
                    func_021EF3A0(MGR(p));
                    func_020061E4(0x669);
                }
            } else if (b->timer == 0) {
                int dir = func_021EF1B4();
                if (dir == 0) {
                    func_020061E4(0x548);
                    func_021DD16C(p, 0);
                    b->state = 2;
                } else if (dir == 1) {
                    func_020061E4(0x548);
                    func_021DD16C(p, 1);
                    b->state = 3;
                }
            }
        }
        func_021DF43C((char *)p, x, y);
        break;
    case 2:
        if (func_021E00C4((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 3:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 4:
        if (func_021DD930(p) == 0) {
            func_020061E4(0x667);
            b->state = 5;
        }
        break;
    case 5:
        if (busy == 0 && r == 0) {
            func_021DE66C(p, b->moves);
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4((char **)p, 1);
            b->state = 8;
        }
        break;
    case 6:
        if (func_021DDAE8(p) == 0) {
            func_021DE66C(p, b->moves);
            func_021DF040((char *)p);
            func_020061E4(0x667);
            func_020061E4(0x669);
            func_021EF36C(MGR(p));
            p[0x16] = 0xFF;
            b->state = 7;
        }
        break;
    case 7:
        if (busy == 0)
            b->state = 8;
        break;
    case 8:
        func_021ED888(WORK(p), 0);
        func_021ECB20((char *)p, 1, 1);
        func_021ECB20((char *)p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}
