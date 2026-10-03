/*
 * function: func_021F13FC
 * address:  0x021F13FC
 * packet:   pkt_ov029_021F13FC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020409B4  0x020409B4  arm
 *   d_021F332C     0x021F332C  data  a4
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern void func_021F1290(void *, int, int, int);
extern void func_020409B4(u32 index);
extern const int d_021F332C[2];

void func_021F13FC(void *p)
{
    int t[2];
    int i;
    int j;
    int n;

    t[0] = d_021F332C[0];
    t[1] = d_021F332C[1];
    for (i = 0; i < 9; i++) {
        n = t[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, func_021F2B9C(p, i, j));
    }
    func_020409B4(4);
}
