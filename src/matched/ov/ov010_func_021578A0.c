/*
 * function: func_021578A0
 * address:  0x021578A0
 * packet:   pkt_ov010_021578A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02157700  0x02157700  thumb  ov010
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_021576C4  0x021576C4  thumb  ov010
 *   func_0215788C  0x0215788C  thumb  ov010
 *   func_021576CC  0x021576CC  thumb  ov010
 *   d_021727E0  0x021727E0  data  ov010
 *   d_02172780  0x02172780  data  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_0203CD98(void);
extern void func_02157700(void *);
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern void func_021576C4(char *p, int v, int line);
extern void func_0215788C(void *p);
extern void func_021576CC(void);
extern u8 d_021727E0[];
extern u8 d_02172780[];

int func_021578A0(u32 *p)
{
    if (func_0203CD98() != 0)
        return 0;
    d_021727E0[7] = *p;
    *((u8 *)p + 0x31B8) = 0xFF;
    func_02157700(p);
    func_0203CBAC((struct Req *)d_02172780, (u32)func_0215788C, (u32)p);
    func_021576C4((char *)p, (int)func_021576CC, 0x1F2);
    return 1;
}
