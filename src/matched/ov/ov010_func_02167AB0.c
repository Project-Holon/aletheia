/*
 * function: func_02167AB0
 * address:  0x02167AB0
 * packet:   pkt_ov010_02167AB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to ARM func_0203CBAC with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 func_021CA5C4 at 0x021CB4F4.
 *
 * symbols:
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 d_02172014[];

void func_02167AB0(void *p)
{
    func_0203CBAC((struct Req *)d_02172014, 0, (u32)p);
}
