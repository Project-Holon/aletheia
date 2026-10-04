/*
 * function: func_021E99B0
 * address:  0x021E99B0
 * packet:   pkt_ov170_021E99B0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB988 0x021EB988 thumb
 *   func_021EF4E4 0x021EF4E4 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_021ED588 0x021ED588 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021EA75C 0x021EA75C thumb
 *   func_021EC61C 0x021EC61C thumb
 *   func_021DD1E8 0x021DD1E8 thumb
 *   func_021E01C4 0x021E01C4 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021E072C 0x021E072C thumb
 *   func_021ED75C 0x021ED75C thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021ED594 0x021ED594 thumb
 *   func_021EA770 0x021EA770 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   d_021EFA10 0x021EFA10 data a1
 *
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */

struct WinMgr;
extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021EF4E4(struct WinMgr *mgr);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021ED588(unsigned char *p);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ED888(char *w, int a);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_021EA75C(int p);
extern void func_021EC61C(unsigned char *p);
extern void func_021DD1E8(unsigned char *p);
extern int func_021E01C4(unsigned char *p);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EF670(char *w);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021E072C(unsigned char *p);
extern void func_021ED75C(unsigned char *p, int i);
extern void func_021EE008(unsigned char *p, int a, int b);
extern void func_021ED594(unsigned char *p, unsigned i);
extern void func_021EA770(int p);
extern void func_021EF68C(char *w);
extern const unsigned char d_021EFA10[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define HELD_WIN(p) (*(unsigned char *)(WORK(p) + 0x3DF6))

int func_021E99B0(unsigned char *p)
{
    switch (p[0x13]) {
    case 0:
        func_021EB988(p, d_021EFA10, 6);
        func_021EF4E4(MGR(p));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ED588(p);
        return 0x11;
    case 1:
        func_021EB988(p, d_021EFA10, 6);
        func_021EF4E4(MGR(p));
        func_021EBC58(p, p[0x16], 1, 0x18);
        func_021ECB20(p, 1, 1);
        func_021ED888(WORK(p), 0);
        func_021EE364(p, 5, 10);
        func_021EA75C((int)p);
        func_021ED588(p);
        return 0x1B;
    case 2:
        if (p[0x1B] == 1)
            func_021EC61C(p);
        func_021EE364(p, 4, p[0x16]);
        func_021DD1E8(p);
        while (func_021E01C4(p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        p[0x16] = 0xFF;
        return 0x15;
    case 3:
        if (p[0x16] >= 0x1E) {
            func_021EC61C(p);
            func_021ECB84(WORK(p), p[0x16]);
        } else if (p[0x14] == p[0x17]) {
            func_021ECB84(WORK(p), p[0x16]);
        } else {
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        }
        func_021E072C(p);
        func_021ED75C(p, 0x24);
        func_021EE364(p, 4, p[0x1D]);
        func_021DD1E8(p);
        while (func_021E01C4(p) != 0)
            ;
        func_021EDF5C(p);
        func_021EF670(WORK(p));
        if (p[0x1D] >= 0x22 && p[0x1D] <= 0x25)
            func_021EE008(p, p[0x1D] - 0x22, 1);
        func_021ED594(p, 0x24);
        return 0x15;
    case 4:
        func_021EA770((int)p);
        func_021EE364(p, 6, p[0x16]);
        func_021EF68C(WORK(p));
        p[0x16] = 0xFF;
        return 0x20;
    case 5:
        func_021EA770((int)p);
        if (p[0x16] < 0x1E && p[0x14] != p[0x17])
            func_021EC48C(p, p[0x17], p[0x16], HELD_WIN(p));
        else
            func_021ECB84(WORK(p), p[0x16]);
        func_021E072C(p);
        func_021ED75C(p, 0x24);
        func_021EE364(p, 6, p[0x1D]);
        func_021EF68C(WORK(p));
        func_021ED594(p, 0x24);
        return 0x20;
    }
    return 0;
}
