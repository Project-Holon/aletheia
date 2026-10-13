/*
 * function: func_021DFA30
 * address:  0x021DFA30
 * packet:   pkt_ov170_021DFA30
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021DCFC0 0x021DCFC0 thumb
 *   func_021DD090 0x021DD090 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021DD1E8 0x021DD1E8 thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021DD930 0x021DD930 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DF254 0x021DF254 thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E01C4 0x021E01C4 thumb
 *   func_021E01E0 0x021E01E0 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021EF1C4 0x021EF1C4 thumb
 *   func_021EF224 0x021EF224 thumb
 *   func_021EF264 0x021EF264 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_021EF45C 0x021EF45C thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF60C 0x021EF60C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021EF680 0x021EF680 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_021EF69C 0x021EF69C thumb
 *   func_021EF75C 0x021EF75C thumb
 *   func_021EF770 0x021EF770 thumb
 *   d_021EF79C 0x021EF79C data a1
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
typedef unsigned char  u8;
struct Sound;
extern int func_021E01C4(char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int TOUCHPANEL_GetCont(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DF254(unsigned char *p, short x, short y);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_021EF75C(struct WinMgr *mgr);
extern void func_021EE008(char *p, int a, int b);
extern void func_020061E4(unsigned se);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern int func_021DF1DC(short x, int y);
extern int func_021EF60C(struct WinMgr *mgr);
extern void func_021ED6E4(char **p, int v);
extern int func_021DE5C8(char *p, unsigned id);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern int func_021EF180(int a, int b);
extern void func_021DD1E8(char *p);
extern void func_021EE364(char **p, int idx, int v);
extern void func_021EE038(char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern int func_021EF264(void);
extern void func_021DD090(unsigned char *p, unsigned idx);
extern void func_021EF3A0(struct WinMgr *mgr);
extern int func_021EF1C4(void);
extern void func_021DD1C4(char *p, int a);
extern int func_021EF224(int a, int b);
extern void func_021DF43C(char *p, int x, int y);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DD930(unsigned char *p);
extern int func_021E1A28(char *p);
extern int func_021E19D4(char *p);
extern int func_021DCFC0(char *p);
extern int func_021E01E0(char *p);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(char **p, int flag);
extern void func_021EF680(char *p);
extern void func_021EF68C(char *p);
extern int func_021EF400(unsigned char *p);
extern void func_021EF69C(char *p);
extern void func_021EF670(char *p);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021ED55C(char **p, int flag);
extern void func_021ED7C4(char *p, int i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

int func_021DFA30(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int busy = 0;
    unsigned r;
    unsigned x;
    unsigned y;
    if (b->state != 0xA && b->state != 0xB && b->state != 0xE) {
        if (BGWINFRM_IsMoving(MGR(p), 9) == 1)
            busy = func_021E01C4((char *)p);
    }
    r = func_021EF5C4(MGR(p));
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            *(unsigned char *)(WORK(p) + 0xA171) = 0;
            r = 0xFF;
            if (func_021EF770(MGR(p)) == 1) {
                r = func_021DF254(p, *(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
                if (p[0x16] >= 0x1E && (r == 0xFF || func_021DE158(p, p[0x16], r) == 0)) {
                    func_021EF75C(MGR(p));
                    func_021EE008((char *)p, 0, 0);
                    func_020061E4(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (func_021EF45C(MGR(p)) == 1)
                r = func_021DF228(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184)));
            if (func_021DE158(p, p[0x16], r) == 0)
                r = 0xFF;
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4((char **)p, 0);
            if (r != 0xFF) {
                if (r >= 0x24)
                    p[0x16] = r - 2;
                else
                    p[0x16] = func_021DE5C8((char *)p, 0x24);
            } else {
                func_021EE008((char *)p, 0, 0);
            }
            if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            if (r == 0xFF && p[0x16] < 0x1E && p[0x14] != p[0x17]) {
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
        if (busy == 0 && r == 0 && func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            if (p[0x16] != func_021EF180(x, y)) {
                p[0x19] = p[0x14];
                func_021DD1E8((char *)p);
                func_020061E4(0x669);
                func_021EE364((char **)p, 4, p[0x16]);
                func_021EE038((char *)p, 2, 1, 2);
                *(int *)(WORK(p) + 0xA168) = p[0x16];
                *(int *)(WORK(p) + 0x68) = 0x17;
            }
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
        if (busy == 0 && r == 0) {
            if (func_021EF264() != -1) {
                if (*(unsigned char *)(WORK(p) + 0xA171) == 0) {
                    if (func_021EF770(MGR(p)) == 1) {
                        func_021EF75C(MGR(p));
                        func_021DD090(p, 0xA);
                        func_020061E4(0x54C);
                        func_020061E4(0x669);
                        *(unsigned char *)(WORK(p) + 0xA171) = 1;
                        b->state = 0xB;
                    }
                    if (func_021EF45C(MGR(p)) == 1) {
                        func_021EF3A0(MGR(p));
                        func_021DD090(p, 0xB);
                        func_020061E4(0x54C);
                        func_020061E4(0x669);
                        *(unsigned char *)(WORK(p) + 0xA171) = 1;
                        b->state = 0xD;
                    }
                }
            } else {
                *(unsigned char *)(WORK(p) + 0xA171) = 0;
            }
        }
        if (func_021EF770(MGR(p)) == 1) {
            int dir = func_021EF1C4();
            if (dir == 0) {
                func_020061E4(0x548);
                func_021DD1C4((char *)p, -1);
                b->state = 8;
                b->timer = 0;
            } else if (dir == 1) {
                func_020061E4(0x548);
                func_021DD1C4((char *)p, 1);
                b->state = 9;
                b->timer = 0;
            }
        }
        if (func_021EF770(MGR(p)) == 1) {
            int k = func_021EF224(x, y);
            if (k != 0xFF)
                func_021EE008((char *)p, k - 0x24, 1);
            else
                func_021EE008((char *)p, 0, 0);
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
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 7:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 8:
        if (func_021E1A28((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 9:
        if (func_021E19D4((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 10:
        if (func_021E01C4((char *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 11:
        func_021DCFC0((char *)p);
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0((char **)p, 1);
            func_021EF680(WORK(p));
            func_021EF68C(WORK(p));
            func_020061E4(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 12:
        if (func_021EF400(p) == 0) {
            p[0x1A] = 2;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 13:
        func_021DCFC0((char *)p);
        if (func_021EF400(p) == 0) {
            func_021DD1E8((char *)p);
            func_021EF69C(WORK(p));
            func_021EF670(WORK(p));
            func_020061E4(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021DF43C((char *)p, x, y);
        break;
    case 14:
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_020061E4(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (func_021EF400(p) == 0) {
            func_021DE158(p, p[0x16], func_021DF1DC(*(int *)(WORK(p) + 0xA180), (short)(*(int *)(WORK(p) + 0xA184))));
            func_021ED6E4((char **)p, 0);
            b->state = 2;
        }
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
            func_021ED55C((char **)p, 1);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}
