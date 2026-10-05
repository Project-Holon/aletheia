/*
 * function: func_021F133C
 * address:  0x021F133C
 * packet:   pkt_ov029_021F133C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F2BB8  0x021F2BB8  thumb  ov029
 *   func_021F2BD4  0x021F2BD4  thumb  ov029
 *   func_021F0D14  0x021F0D14  thumb  ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj00042.h"

extern int func_021F2B9C(void *, int, int);
extern int func_021F2BB8(void *, int, int);
extern int func_021F2BD4(void *, int, int, int);
extern void func_021F0D14(int, int, int *, int *);
extern void func_021F1290(void *, int, int, int);
struct Sub020090B0Obj;
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

int func_021F133C(char *p, int v, int *o1, int *o2)
{
    int a = 0;
    int b = 0;
    int found = 0;
    int i;
    int j;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (v == func_021F2B9C(p, i, j)) {
                if (found == 0) {
                    a = i;
                    b = j;
                    found = 1;
                }
                if (func_021F2BB8(p, i, j)) {
                    func_021F0D14(i, j, o1, o2);
                    return 1;
                }
                if (func_021F2BD4(p, i, j, v)) {
                    a = i;
                    b = j;
                    found = 1;
                }
            }
        }
    }
    if (found) {
        func_021F0D14(a, b, o1, o2);
        func_020091AC((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), a, b, v, 1, 0);
        func_021F1290(p, a, b, v);
        func_020409B4(4);
        return 1;
    }
    return 0;
}
