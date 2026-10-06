/*
 * function: func_021DDC00
 * address:  0x021DDC00
 * packet:   pkt_ov170_021DDC00
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD684 0x021DD684 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_021DD694 0x021DD694 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021DD25C 0x021DD25C thumb
 */

extern int func_021DD684(unsigned char *p, unsigned i);
typedef unsigned int   u32;
extern int func_020078C4(void *save, u32 box);
extern int func_021DD694(void ***p, unsigned skip);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern unsigned func_0202136C(unsigned short v);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);

#define SYS(p) (*(unsigned **)(p))
#define RESULT(p) (*(unsigned char *)(*(char **)((p) + 0x2C) + 0xA173))

int func_021DDC00(unsigned char *p, unsigned a, unsigned b)
{
    unsigned m;
    if (b >= 0x24) {
        int n = func_021DD684(p, b - 0x24);
        if (n == p[0x14] || func_020078C4((void *)SYS(p)[1], n) == 0x1E) {
            RESULT(p) = 1;
            return 0;
        }
        if (a >= 0x1E) {
            if (func_021DD694((void ***)p, a - 0x1E) == 0) {
                RESULT(p) = 3;
                return 0;
            }
            if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
                RESULT(p) = 2;
                return 0;
            }
        }
        m = 0;
    } else {
        m = func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0);
    }
    if (SYS(p)[9] == 4) {
        if (SYS(p)[5] == 1) {
            RESULT(p) = 5;
            return 0;
        }
        if (a < 0x1E && b >= 0x1E && b < 0x24 && func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
        if (a >= 0x1E && a < 0x24 && b < 0x1E && m != 0 && func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0) {
            RESULT(p) = 4;
            return 0;
        }
    }
    if (a >= 0x1E) {
        if (func_021DD694((void ***)p, a - 0x1E) == 0) {
            if (m == 0) {
                if ((b < 0x1E || b >= 0x24) && SYS(p)[9] != 4) {
                    RESULT(p) = 3;
                    return 0;
                }
            } else if (func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0 && b < 0x1E && SYS(p)[9] != 4) {
                RESULT(p) = 3;
                return 0;
            }
        }
        if (b < 0x1E && func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], a - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
    } else if (b >= 0x1E && m != 0) {
        if (func_0202136C(func_02017E1C(func_0201AB28((void *)SYS(p)[2], b - 0x1E), 6, 0)) == 1) {
            RESULT(p) = 2;
            return 0;
        }
        if (func_021DD25C((void ***)p, a, p[0x17], 0x4C, 0) != 0 && func_021DD694((void ***)p, b - 0x1E) == 0 && SYS(p)[9] != 4) {
            RESULT(p) = 3;
            return 0;
        }
    }
    RESULT(p) = 0;
    return 1;
}
