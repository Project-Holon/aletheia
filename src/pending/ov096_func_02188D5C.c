/*
 * function: func_02188D5C
 * address:  0x02188D5C
 * packet:   pkt_ov096_02188D5C
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Blocker: codegen only, register colouring.  The original keeps the first
 *          func_021C7E14 result in r7 and t in r6 across the loop; mwccarm
 *          here keeps the loop counter in r6 and t in r7 and spills the
 *          first result to [sp,#8], growing the frame 0x10 -> 0x18
 *          (168 vs 164 bytes).  Moving the counter declaration did not help.
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 */

extern int func_0201134C(int);
extern int func_021D5440(int);
extern int func_021D5448(int);
extern int func_021D54C0(int, int);
extern int func_021C7E14(int, int, int, int, int, int);

int func_02188D5C(int a, int b)
{
    int t;
    int y;
    int z;
    unsigned int r;
    int i;

    t = func_0201134C(a);
    y = func_021D5440(*(int *)(b + 0xbc));
    z = func_021D5440(*(int *)(b + 0xc0));
    r = func_021C7E14(*(int *)(b + 0xb4), y, z,
                      *(unsigned short *)(b + 2), 1, t);
    if (r == 0) {
        *(int *)(b + 0x38) = 0;
    } else {
        *(int *)(b + 0x38) = 2;
        for (i = 0; i < func_021D5448(*(int *)(b + 0xbc)); i++) {
            unsigned int item =
                func_021D54C0(*(int *)(b + 0xbc), (unsigned char)i);

            if (i == *(unsigned char *)(b + 1))
                continue;
            if (func_021C7E14(*(int *)(b + 0xb4), y, z, item, 1, t) > r) {
                *(int *)(b + 0x38) = 1;
                break;
            }
        }
    }
    return *(int *)(b + 0xc4);
}
