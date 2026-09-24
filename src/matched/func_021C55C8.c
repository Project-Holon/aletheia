/*
 * function: func_021C55C8
 * address:  0x021C55C8
 * packet:   pkt_021C55C8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C55C8 0x021C55C8 arm
 *   func_021D696C 0x021D696C arm
 *   func_021D6A7C 0x021D6A7C arm
 *   func_021D6824 0x021D6824 arm
 *   func_021D6864 0x021D6864 arm
 *   func_021D68A4 0x021D68A4 arm
 *   func_021BCB28 0x021BCB28 arm
 *   func_021C628C 0x021C628C arm
 *   func_021CFFAC 0x021CFFAC arm
 *   func_021CE9D0 0x021CE9D0 arm
 *   func_021C6488 0x021C6488 arm
 *   func_021C641C 0x021C641C arm
 *   func_021C62D8 0x021C62D8 arm
 *   func_021DA524 0x021DA524 data
 *   g_021DE5D8    0x021DE5D8 data
 *   g_021DAA7C    0x021DAA7C data
 */

typedef unsigned char u8;
typedef signed char s8;

extern int func_021D696C(const void *);
extern int func_021D6A7C(const void *);
extern int func_021D6824(int);
extern int func_021D6864(int);
extern int func_021D68A4(int);
extern void func_021BCB28(int);
extern void func_021C628C(void);
extern void func_021CFFAC(int);
extern void func_021CE9D0(void);
extern void func_021C6488(void);
extern void func_021C641C(void);
extern void func_021C62D8(int);
extern char func_021DA524[];

extern char g_021DE5D8[];
extern char g_021DAA7C[];

void func_021C55C8(void)
{
    int r7;
    char *r5 = (char *)g_021DE5D8;
    char *r1 = *(char **)(r5 + 4);

    if (*(void **)(r1 + 0x38) != 0 || *(u8 *)(r1 + 0x57) != 0) {
        return;
    }

    if (func_021D696C(&g_021DAA7C)) {
        char *r0 = *(char **)(r5 + 4);
        r0[0x50] = (char)-1;
        for (r7 = 0; r7 < 5; r7++) {
            if (func_021D696C((char *)func_021DA524 + r7 * 8)) {
                if (r7 < 4) {
                    (*(char **)(r5 + 4))[0x50] = (char)r7;
                    goto loc_021C5650;
                } else {
                    func_021BCB28(1);
                    r5[0] = (char)r7;
                    func_021C628C();
                    return;
                }
            }
        }
    }

loc_021C5650:
    if (func_021D6A7C(&g_021DAA7C)) {
        for (r7 = 0; r7 < 4; r7++) {
            if (func_021D6A7C((char *)func_021DA524 + r7 * 8)) {
                char *r1_b = *(char **)(r5 + 4);
                if (*(s8 *)(r1_b + 0x50) == r7) {
                    if (r7 >= *(u8 *)(r1_b + 0x51)) {
                        func_021CFFAC(9);
                        goto loc_021C56C0;
                    }
                    func_021BCB28(1);
                    r5[0] = (char)r7;
                    func_021C628C();
                    return;
                }
            }
        }
    }

loc_021C56C0:
    r7 = 1;
    if (func_021D6824(1)) {
        func_021BCB28(1);
        func_021CE9D0();
        return;
    }

    if (func_021D6824(2)) {
        func_021BCB28(0);
        return;
    }

    if (func_021D6864(0x200)) {
        func_021C6488();
        return;
    }
    if (func_021D68A4(0x200)) {
        (*(char **)(r5 + 4))[0x59] = 0;
        return;
    }

    if (func_021D6864(0x100)) {
        func_021C641C();
        return;
    }
    if (func_021D68A4(0x100)) {
        (*(char **)(r5 + 4))[0x59] = 0;
        return;
    }

    if (func_021D6864(0x40)) {
        func_021C62D8(1);
        return;
    }
    if (func_021D68A4(0x40)) {
        (*(char **)(r5 + 4))[0x59] = 0;
        return;
    }

    if (func_021D6864(0x80)) {
        func_021C62D8(3);
        return;
    }
    if (func_021D68A4(0x80)) {
        (*(char **)(r5 + 4))[0x59] = 0;
        return;
    }
}
