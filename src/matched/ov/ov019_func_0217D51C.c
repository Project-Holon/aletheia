/*
 * function: func_0217D51C
 * address:  0x0217D51C
 * packet:   pkt_ov019_0217D51C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_02172EDC  0x02172EDC  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02173650  0x02173650  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_0217BB04(u8 *a);
extern void func_02172EDC(u8 *a);
extern int func_02172D68(u8 *a);
extern int func_0203CDBC(void);
extern void func_02173650(u8 *a, int b);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern void func_02172D50(u8 *a);
extern u32 func_0217F1EC(u8 *p);
extern u32 func_020362DC(void);

int func_0217D51C(u8 *a, int *b, int c, u8 *d)
{
    int r, t;
    if (*d < 3 && func_0217BB04(a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_02172EDC(a);
        (*d)++;
        break;
    case 1:
        if (func_02172D68(a) != 0)
            break;
        r = func_0203CDBC();
        if (r == 1) {
            t = b[8];
            if (t != 0) {
                func_02173650((u8 *)(b + 5), t);
                func_021734A8(a, 3, 0);
            }
            func_02172D50(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_02172D68(a) == 0)
            (*d)++;
        break;
    case 3:
        if (func_0217F1EC(a) == 1) {
            if (func_020362DC() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}
