/*
 * function: func_0220F2DC
 * address:  0x0220F2DC
 * packet:   pkt_0220F2DC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_022110D4(void *p, int a);
extern void func_0204B454(void *h, void *out, int n);
extern void func_0204B404(void *h, void *out, int n);

void func_0220F2DC(char *p, int a1, int a2)
{
    int i1 = func_022110D4(p, a1);
    int i2 = func_022110D4(p, a2);
    u32 x;
    u32 y;

    func_0204B454(((void **)(p + 0x1ebc))[i1], &x, 1);
    func_0204B454(((void **)(p + 0x1ebc))[i2], &y, 1);
    func_0204B404(((void **)(p + 0x1ebc))[i1], &y, 1);
    func_0204B404(((void **)(p + 0x1ebc))[i2], &x, 1);

    func_0204B454(((void **)(p + 0x1ed8))[i1], &x, 1);
    func_0204B454(((void **)(p + 0x1ed8))[i2], &y, 1);
    func_0204B404(((void **)(p + 0x1ed8))[i1], &y, 1);
    func_0204B404(((void **)(p + 0x1ed8))[i2], &x, 1);

    func_0204B454(((void **)(p + 0x1ef0))[i1], &x, 1);
    func_0204B454(((void **)(p + 0x1ef0))[i2], &y, 1);
    func_0204B404(((void **)(p + 0x1ef0))[i1], &y, 1);
    func_0204B404(((void **)(p + 0x1ef0))[i2], &x, 1);

    func_0204B454(((void **)(p + 0x1f08))[i1], &x, 1);
    func_0204B454(((void **)(p + 0x1f08))[i2], &y, 1);
    func_0204B404(((void **)(p + 0x1f08))[i1], &y, 1);
    func_0204B404(((void **)(p + 0x1f08))[i2], &x, 1);
}
