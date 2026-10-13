/*
 * function: func_021E0470
 * address:  0x021E0470
 * packet:   pkt_ov170_021E0470
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF400 0x021EF400 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   func_021EF57C 0x021EF57C thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
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
 *
 * State machine in the 021DFA30 family (template 021E0ABC): pick a box with
 * the pen, slide the cursor there, then close.
 */

typedef struct {
    unsigned char pad[8];
    void *entry;
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern int TOUCHPANEL_GetCont(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
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

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021E0470(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = func_021EF5C4(MGR(p));
    int wait = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
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
