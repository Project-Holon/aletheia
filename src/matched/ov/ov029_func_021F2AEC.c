/*
 * function: func_021F2AEC
 * address:  0x021F2AEC
 * packet:   pkt_ov029_021F2AEC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F2BB8  0x021F2BB8  thumb  ov029
 *   func_021F2BD4  0x021F2BD4  thumb  ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020091AC  0x020091AC  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_021F20AC  0x021F20AC  thumb  ov029
 */

extern unsigned int func_021F2B9C(unsigned char *p, int row, int col);
typedef unsigned char  u8;
struct Sub020090B0Obj;
extern int func_021F2BB8(u8 *p, int row, int col);
extern int func_021F2BD4(u8 *p, int row, int col, int kind);
extern void func_021F1290(void *q, int a, int b, int c);
extern void func_020091AC(struct Sub020090B0Obj *obj, int row, int col, int kind, int marked, int flagged);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);
extern void func_021F20AC(char *p);

void func_021F2AEC(unsigned char *p, int a1, int a2, int a3, int k)
{
    int j;
    int i;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 9; i++) {
            if (k == func_021F2B9C(p, i, j)) {
                if (func_021F2BB8((u8 *)p, i, j) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 1);
                    func_021F1290((void *)p, i, j, k);
                } else if (func_021F2BD4((u8 *)p, i, j, k) != 0) {
                    func_020091AC((struct Sub020090B0Obj *)a1, i, j, k, 0, 0);
                }
            }
        }
    }
    func_020091AC((struct Sub020090B0Obj *)a1, a2, a3, k, 1, 0);
    func_021F1290((void *)p, a2, a3, k);
    func_020409B4(4);
    func_021F20AC((char *)p);
}
