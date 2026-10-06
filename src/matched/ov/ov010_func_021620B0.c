/*
 * function: func_021620B0
 * address:  0x021620B0
 * packet:   pkt_ov010_021620B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * pass 3 2026-10-06 P3L07: EXACT. The list is compacted: each empty 0x18-byte entry takes the next
 * used entry after it. The copy destination is written through a second base name dst (= p) under
 * #pragma opt_propagation off, so `i * 0x18` is a common subexpression of two different bases. The
 * front end then makes the offset its own temporary local, which takes the stack slot below the
 * named counter i (sp+0 under sp+4), as in the image. With one base name the offset was a back-end
 * spill temporary above i (7 B, 92/92); without the pragma dst folds into p (7 B).
 * symbols:
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02082D44  0x02082D44  arm
 */

extern int func_02161ECC(char *);
extern void func_02161E78(char *);
extern void func_02082D44(char *, char *, int);

#pragma opt_propagation off
void func_021620B0(char *p)
{
    int i;
    int j;
    char *dst;

    dst = p;
    i = 0;
    do {
        if (func_02161ECC(p + i * 0x18) == 0) {
            for (j = i + 1; j < 10; j++) {
                if (func_02161ECC(p + j * 0x18) != 0) {
                    func_02082D44(p + j * 0x18, dst + i * 0x18, 0x18);
                    func_02161E78(p + j * 0x18);
                    break;
                }
            }
        }
        i++;
    } while (i < 10);
}
#pragma opt_propagation reset
