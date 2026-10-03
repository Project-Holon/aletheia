/*
 * function: func_021E1B1C
 * address:  0x021E1B1C
 * packet:   pkt_ov170_021E1B1C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021DFA30.c.
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021DD16C 0x021DD16C thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021DD930 0x021DD930 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021DE5C8 0x021DE5C8 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DF43C 0x021DF43C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021ED7C4 0x021ED7C4 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021EF180 0x021EF180 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EF45C 0x021EF45C thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF60C 0x021EF60C thumb
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
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern int func_021E01B0(unsigned char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_02035C38(void);
extern void func_021EF57C(struct WinMgr *mgr);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_020061E4(unsigned se);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern int func_021DF1DC(short x, short y);
extern int func_021EF60C(struct WinMgr *mgr);
extern void func_021ED6E4(unsigned char *p, int v);
extern int func_021DE5C8(unsigned char *p, unsigned id);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(unsigned char *p, int box);
extern int func_021DEDCC(unsigned char *p, int box);
extern void func_021DEC98(unsigned char *p, int a, int dir);
extern int func_021EF180(unsigned a, unsigned b);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021DF43C(unsigned char *p, int x, int y);
extern int func_021E00C4(unsigned char *p);
extern int func_021E0128(unsigned char *p);
extern int func_021DD930(unsigned char *p);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern void func_021EC5A0(unsigned char *p, int flag);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_020260E4(void *obj, unsigned char sel);
extern void func_021EE3E4(unsigned char *p, unsigned idx);
extern void func_021ED7C4(char *p, int i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define SYS(p) (*(unsigned **)(p))

int func_021E1B1C(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
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
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
            if (SYS(p)[9] == 4 && SYS(p)[5] == 1) {
                r = 0xFF;
                *(unsigned char *)(WORK(p) + 0xA173) = 5;
            }
            if (func_021DE158(p, p[0x16], r) == 0)
                r = 0xFF;
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4(p, 0);
            if (r != 0xFF)
                p[0x16] = func_021DE5C8(p, 0x24);
            if (func_021EF45C(MGR(p)) == 0 && busy == 0)
                func_021EF534(MGR(p));
            if (r == 0xFF && p[0x14] != p[0x17]) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C(p, p[0x14]);
                func_021DEC98(p, func_021DEDCC(p, p[0x14]), r);
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
            func_021EC5A0(p, 1);
            func_020061E4(0x669);
            func_021EE364(p, 6, p[0x16]);
            func_021EE038(p, 2, 1, 2);
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
        func_021DF43C(p, x, y);
        break;
    case 4:
        if (func_021E00C4(p) == 0)
            b->state = 2;
        break;
    case 5:
        if (func_021E0128(p) == 0)
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
        if (func_021E00C4(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C(p, x, y);
        break;
    case 7:
        if (func_021E0128(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C(p, x, y);
        break;
    case 16:
        func_021DE66C(p, b->moves);
        if (func_021EF770(MGR(p)) == 0 && func_021EF45C(MGR(p)) == 0) {
            func_021ED7C4(WORK(p), p[0x16]);
            func_021ED6E4(p, 1);
        } else {
            func_021ED6E4(p, 0);
            func_020260E4(*(void **)(WORK(p) + 0x70), p[0x16]);
            func_021EE3E4(p, p[0x16]);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}
