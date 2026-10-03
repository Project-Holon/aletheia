/*
 * function: func_021E2334
 * address:  0x021E2334
 * packet:   pkt_ov170_021E2334
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA878 0x021EA878 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021EB988 0x021EB988 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021EF534 0x021EF534 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_021EBCB4 0x021EBCB4 thumb
 *   d_021EF9B4 0x021EF9B4 data
 *   d_021EF950 0x021EF950 data
 *   d_021EFA10 0x021EFA10 data
 *   d_021EF918 0x021EF918 data
 *   d_021EF8EC 0x021EF8EC data
 *
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */

typedef short s16;

struct WinMgr;
extern void func_021EA878(unsigned char *p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021EB988(unsigned char *p, const void *e, unsigned n);
extern void func_021ED888(char *w, int a);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021EF534(struct WinMgr *mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern void func_021ED55C(unsigned char *p, int flag);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021EBCB4(unsigned char *p, int kind, int i);
extern const unsigned char d_021EF9B4[];
extern const unsigned char d_021EF950[];
extern const unsigned char d_021EFA10[];
extern const unsigned char d_021EF918[];
extern const unsigned char d_021EF8EC[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define TOP(p) (*(char **)(p))
#define MODE(p) (*(int *)(TOP(p) + 0x24))
#define SUB(p) (*(s16 *)(WORK(p) + 0xA16C))

int func_021E2334(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        switch (MODE(p)) {
        case 1:
            func_021EB988(p, d_021EF9B4, 5);
            break;
        case 0:
            func_021EB988(p, d_021EF950, 5);
            break;
        case 2:
            func_021EB988(p, d_021EFA10, 6);
            break;
        case 3:
            func_021EA878(p, SUB(p));
            break;
        case 4:
            func_021EB988(p, d_021EF918, 4);
            break;
        case 5:
            func_021EBA5C(WORK(p), 0x1B);
            func_021EB988(p, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(WORK(p) + 0xA170) == 1) {
            *(unsigned char *)(WORK(p) + 0xA170) = 0;
            if (MODE(p) == 3) {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20(p, 0x82, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20(p, 0x81, 0);
                }
            } else {
                if (p[0x16] >= 0x1E) {
                    func_021ECB20(p, 2, 0);
                } else {
                    func_021ED888(WORK(p), 1);
                    func_021ECB20(p, 1, 0);
                }
            }
        }
        func_021EF534(MGR(p));
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0xE);
    case 1:
        STEP(p) = 0;
        func_021ED55C(p, 1);
        func_021ED508(p, 0xE, 1);
        switch (MODE(p)) {
        case 1:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x2C;
        case 0:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x31;
        case 2:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(WORK(p) + 0xA16C) == 0)
                func_021EBCB4(p, 0, 0x18);
            else
                func_021EBCB4(p, 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            func_021EBC58(p, p[0x16], 1, 0x18);
            if (p[0x16] < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            func_021EBC58(p, p[0x16], 1, 0x18);
            return 0x4B;
        }
        break;
    }
    return 0xE;
}
