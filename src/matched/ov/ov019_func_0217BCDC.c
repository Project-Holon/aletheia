/*
 * function: func_0217BCDC
 * address:  0x0217BCDC
 * packet:   pkt_ov019_0217BCDC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_02173420  0x02173420  thumb  ov012
 *   func_02173524  0x02173524  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 */

typedef unsigned char u8;

extern void func_0217BAF0(int *a, int b, int c);
extern int func_0217F1EC(int *a);
extern void func_0217F074(int *a);
extern int func_0200FB24(void);
extern void func_02012124(int a, int b);
extern void func_02172D38(int *a);
extern int func_02172D68(int *a);
extern void func_02173420(int *a);
extern void func_02173524(int *a, u8 *b);
extern void func_02172D50(int *a);
extern void func_0217B8E4(int *a, int b);

int func_0217BCDC(int *a, u8 *b, int c, u8 *d)
{
    switch (*d) {
    case 0:
        func_0217BAF0(a, c, 1);
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1) {
            func_0217F074(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_0200FB24() != 0) {
            func_02012124(*(int *)(a[0] + 0xc), 1);
            return 0;
        }
        func_02172D38(a);
        (*d)++;
        break;
    case 3:
        if (func_02172D68(a) == 0)
            (*d)++;
        break;
    case 4:
        func_02173420(a);
        func_02173524(a, b + 0x14);
        func_02172D50(a);
        (*d)++;
        break;
    case 5:
        if (func_02172D68(a) == 0)
            (*d)++;
        break;
    default:
        func_0217B8E4(a, 0);
        return 1;
    }
    return 0;
}
