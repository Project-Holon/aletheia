/*
 * function: func_021E24EC
 * address:  0x021E24EC
 * packet:   pkt_ov170_021E24EC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF1FC 0x021EF1FC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E19D4 0x021E19D4 thumb
 *   func_021E1A78 0x021E1A78 thumb
 *   func_021E1A28 0x021E1A28 thumb
 *   func_021E1ACC 0x021E1ACC thumb
 *
 * Touch-drag paging of the box list: a drag of three or more pixels
 * starts a scroll of |d| / 8 steps in its direction; each later call
 * spends one step until the count runs out.
 */

typedef struct {
    short left;
    short dir;
} Scroll;

extern int func_021EF1FC(unsigned *a, unsigned *b);
extern void func_020307B0(void *ptr);
extern void func_021DD1C4(char *p, int a);
extern void func_020061E4(unsigned se);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E19D4(char *p);
extern int func_021E1A78(char *p);
extern int func_021E1A28(char *p);
extern int func_021E1ACC(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define STATE(p) (*(int *)((p) + 0x28))
#define SCROLL(p) (*(Scroll **)(WORK(p) + 0xA190))
#define LASTY(p) (*(unsigned *)(WORK(p) + 0xA184))
#define ABS(x) ((x) < 0 ? -(x) : (x))

int func_021E24EC(unsigned char *p)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (func_021EF1FC(&x, &y) == 0) {
        func_020307B0(SCROLL(p));
        return STATE(p);
    }
    s = SCROLL(p);
    old = LASTY(p);
    LASTY(p) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            func_021DD1C4((char *)p, 1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E19D4, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1A78, 0xF);
        }
        if (s->dir == -1) {
            func_021DD1C4((char *)p, -1);
            func_020061E4(0x548);
            if (STATE(p) == 0x15)
                return func_021E8FC0((char *)p, (int)func_021E1A28, 0xF);
            return func_021E8FC0((char *)p, (int)func_021E1ACC, 0xF);
        }
    }
    return 0xF;
}
