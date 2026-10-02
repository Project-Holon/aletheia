/*
 * function: func_021BABDC
 * address:  0x021BABDC
 * packet:   pkt_ov099_021BABDC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the k==4||k==5 test is a switch (case 4/5) so it stays two
 * compares and keeps obj in r5.
 *
 * symbols:
 *   func_02020D0C  0x02020D0C  thumb
 *   func_021C27E0  0x021C27E0  thumb  ov099
 *   func_02020268  0x02020268  thumb
 */

typedef unsigned char  u8;
typedef unsigned long  u32;

extern u8 *func_02020D0C(void *p);
extern int func_021C27E0(void *a);
extern void func_02020268(void *obj, u8 a, u8 b, u8 c);

void func_021BABDC(void *obj, int k)
{
    u8 *w = func_02020D0C(obj);

    if (func_021C27E0(*(void **)(w + 8)) == 0) {
        switch (k) {
        case 4:
        case 5:
            func_02020268(obj, 2, 15, 2);
            break;
        default:
            func_02020268(obj, 1, 15, 2);
            break;
        }
    } else {
        func_02020268(obj, 1, 15, 2);
    }
}
