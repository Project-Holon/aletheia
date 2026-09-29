/*
 * function: func_021F0AC4
 * address:  0x021F0AC4
 * packet:   pkt_ov033_021F0AC4
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_021A0F30 0x021A0F30 thumb ov021
 */

extern int func_02035D20(unsigned *, unsigned *);
extern void func_020355D8(unsigned);
extern unsigned func_020362DC(void);
extern void func_0204B878(unsigned, unsigned);
extern void func_020061E4(unsigned);
extern int func_0204B98C(unsigned);
extern void func_021A0F30(unsigned, unsigned);

typedef struct {
    unsigned f00;
    unsigned f04;
    char pad[0x1C];
    unsigned f24;
    unsigned f28;
} T;

void func_021F0AC4(T *p)
{
    unsigned x;
    unsigned y;
    int hit;

    switch (p->f28) {
    case 0:
        hit = 0;
        if (func_02035D20(&x, &y) != 0) {
            if (x >= 0xE8 && x < 0x100 && y >= 0xA8 && y < 0xC0) {
                func_020355D8(1);
                hit = 1;
            }
        }
        if (hit == 0) {
            if (func_020362DC() & 0x400) {
                func_020355D8(0);
                hit = 1;
            }
        }
        if (hit != 0) {
            p->f28 = 1;
            func_0204B878(p->f24, 8);
            func_020061E4(0x556);
            return;
        }
        break;
    case 1:
        if (func_0204B98C(p->f24) == 0) {
            p->f28 = 2;
            func_0204B878(p->f24, 0);
            return;
        }
        break;
    case 2:
        func_021A0F30(p->f04, 0);
        p->f28 = 3;
        break;
    case 3:
        break;
    }
}
