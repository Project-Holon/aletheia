/*
 * function: func_021BCCCC
 * address:  0x021BCCCC
 * packet:   pkt_ov088_021BCCCC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 *
 * Init of the second title proc (heap 0x81, 0x30000 bytes; 0x2C-byte work
 * area zeroed).  Same shape as func_021B95A0.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 */

extern void  func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);

int func_021BCCCC(struct Obj0203159C *a0)
{
    func_0203064C(1, 0x81, 0x30000);
    func_02082BCC(func_0203159C(a0, 0x2c, 0x81), 0, 0x2c);
    return 1;
}
