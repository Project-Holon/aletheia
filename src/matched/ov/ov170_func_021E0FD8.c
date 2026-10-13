/*
 * function: func_021E0FD8
 * address:  0x021E0FD8
 * packet:   pkt_ov170_021E0FD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of src/matched/ov170_func_021E0ABC.c.
 *
 * symbols:
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021ED2F4 0x021ED2F4 thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_021DF1DC 0x021DF1DC thumb
 *   func_021DF228 0x021DF228 thumb
 *   func_021DDE80 0x021DDE80 thumb
 *   func_021DEA3C 0x021DEA3C thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EF1B4 0x021EF1B4 thumb
 *   func_021DD16C 0x021DD16C thumb
 *   func_021E0FB0 0x021E0FB0 thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEAFC 0x021DEAFC thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   d_021EF79C 0x021EF79C data a1
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short timer;
} Blk;

extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
typedef unsigned int   u32;
extern u32 func_021EBFEC(char *p, int i);
extern void func_021ED2F4(char *w);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern int func_021DF1DC(short x, int y);
extern int func_021DF228(short x, short y, const unsigned char *r);
extern const unsigned char d_021EF79C[];
extern int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
extern void func_021DEA3C(int a, int b, int c, int d);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void func_020061E4(unsigned se);
extern int func_021EF1B4(void);
extern void func_021DD16C(unsigned char *p, int dir);
extern void func_021E0FB0(char *w, int x, int y);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DEAFC(int a);
extern void func_021ED6E4(char **p, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E0FD8(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
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
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
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
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            func_021E0FB0(WORK(p), x, y);
        break;
    case 4:
        if (func_021E0128((char *)p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
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
