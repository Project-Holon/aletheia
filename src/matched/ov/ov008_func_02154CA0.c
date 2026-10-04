/*
 * function: func_02154CA0
 * address:  0x02154CA0
 * packet:   pkt_02154CA0
 * region:   ov008
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02031324  0x02031324  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void  func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern u8   *func_0203159C(void *ctx, int size, int heap);
extern u32   func_02031324(int heap);

int func_02154CA0(void *ctx)
{
    u8 *p;

    func_0203064C(1, 0x76, 0x4000);
    p = func_0203159C(ctx, 0x1c, 0x76);
    *(u32 *)p = func_02031324(0x76);
    return 1;
}
