/*
 * function: func_021E0200
 * address:  0x021E0200
 * packet:   pkt_ov170_021E0200
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State machine in the family of src/matched/ov170_func_021DFA30.c.
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_02035CB8 0x02035CB8 arm
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
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

extern int func_021EF5C4(int a);
extern int func_021EF400(unsigned char *p);
extern int func_02035C38(void);
extern void func_021EF57C(int mgr);
extern int func_021EF480(int a);
extern void func_021ED888(char *p, int v);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021DF1DC(short x, short y);
extern void func_021DE428(unsigned char *p, unsigned a, unsigned b);
extern int func_021EF60C(int a);
extern void func_021ED6E4(unsigned char *p, int v);
extern int func_021DE5C8(unsigned char *p, unsigned id);
extern void func_020061E4(unsigned se);
extern void func_021EF36C(int a);
extern void func_021EF534(int mgr);
extern int func_021EF248(void);
extern void func_021EF3A0(int a);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021DF43C(unsigned char *p, int x, int y);
extern int func_021E00C4(unsigned char *p);
extern int func_021E0128(unsigned char *p);
extern int func_021DD930(unsigned char *p);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_021ED7C4(char *p, int i);
extern int func_021DDAE8(unsigned char *p);
extern void func_021DF040(unsigned char *p);
extern void func_021ECB20(unsigned char *p, int a, int b);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(int *)(WORK(p) + 0x74))

int func_021E0200(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    unsigned r = func_021EF5C4(MGR(p));
    int busy = func_021EF400(p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (func_02035C38() == 1)
            func_021EF57C(MGR(p));
        b->state = 1;
        break;
    case 1:
        if (func_021EF480(MGR(p)) == 0)
            func_021ED888(WORK(p), 1);
        if (func_02035CB8(&x, &y) == 0) {
            r = 0xFF;
            if (func_021EF480(MGR(p)) == 0 && busy == 0)
                r = func_021DF1DC(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
            func_021DE428(p, p[0x16], r);
            if (func_021EF60C(MGR(p)) == 0)
                func_021ED6E4(p, 0);
            p[0x16] = func_021DE5C8(p, 0x24);
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
        func_021DF43C(p, x, y);
        break;
    case 2:
        if (func_021E00C4(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C(p, x, y);
        break;
    case 3:
        if (func_021E0128(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021DF43C(p, x, y);
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
            func_021ED6E4(p, 1);
            b->state = 8;
        }
        break;
    case 6:
        if (func_021DDAE8(p) == 0) {
            func_021DE66C(p, b->moves);
            func_021DF040(p);
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
        func_021ECB20(p, 1, 1);
        func_021ECB20(p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}
