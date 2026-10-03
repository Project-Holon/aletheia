/*
 * function: func_021E1628
 * address:  0x021E1628
 * packet:   pkt_ov170_021E1628
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of src/matched/ov170_func_021E0ABC.c.
 *
 * symbols:
 *   func_021EF5C4 0x021EF5C4 thumb
 *   func_021EF400 0x021EF400 thumb
 *   func_021EA878 0x021EA878 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021ED2F4 0x021ED2F4 thumb
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
 *   func_021ECB20 0x021ECB20 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021E0FB0 0x021E0FB0 thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 *   d_021EF7B4 0x021EF7B4 data a1
 *   func_021ED888 0x021ED888 thumb
 *   func_021EF248 0x021EF248 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_0202136C 0x0202136C thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int func_021EF5C4(struct WinMgr *mgr);
extern int func_021EF400(unsigned char *p);
extern void func_021EA878(unsigned char *p, int v);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021EBFEC(char *w, int i);
extern void func_021ED2F4(char *w);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern int func_021EF45C(struct WinMgr *mgr);
extern int func_021DF1DC(short x, short y);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern const unsigned char d_021EF7B4[];
extern void func_021ED888(char *w, int a);
extern int func_021EF248(void);
extern void func_021EF3D8(struct WinMgr *mgr);
extern unsigned func_0202136C(unsigned short v);
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern void func_021DEA3C(unsigned char *p, unsigned a, unsigned b, int mode);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
typedef unsigned int   u32;
struct Sound;
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, int a, int dir);
extern void func_021EF180(int a, int b);
extern void func_021ECB20(unsigned char *p, int a, int b);
extern void func_020061E4(unsigned se);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021E0FB0(char *w, int x, int y);
extern int func_021E00C4(unsigned char *p);
extern int func_021E0128(unsigned char *p);
extern int func_021DEAFC(unsigned char *p);
extern void func_021ED6E4(unsigned char *p, int v);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define CNT(p) (*(unsigned short *)(WORK(p) + 0xA16C))

int func_021E1628(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
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
                r = (unsigned short)func_021DF1DC(*(int *)(WORK(p) + 0xA180), *(int *)(WORK(p) + 0xA184));
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
                func_021DEA3C(p, first, r, 2);
                b->state = 7;
            } else {
                func_021DEA3C(p, first, r, 1);
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
            func_021ECB20(p, 0x81, 1);
            func_020061E4(0x669);
            func_021EE364(p, 6, p[0x16]);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x27);
            func_02026124(*(void **)(WORK(p) + 0x70), 0x28);
            func_021EC000(WORK(p), 4, 0);
            func_021EE038(p, 2, 1, 1);
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
        if (func_021E00C4(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (func_02035CB8(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 7:
    case 8:
        if (func_021DEAFC(p) == 0) {
            func_020061E4(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if (CNT(p) != 0) {
                    func_021ED108(WORK(p), 0);
                    func_021ED2F4(WORK(p));
                }
                func_021EE038(p, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        func_021ED6E4(p, 0);
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
