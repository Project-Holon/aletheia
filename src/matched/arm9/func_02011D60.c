/*
 * function: func_02011D60
 * address:  0x02011D60
 * packet:   pkt_02011D60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_02011F24  0x02011F24  thumb
 *   func_020306F0  0x020306F0  arm
 */

extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
typedef unsigned int   u32;
extern u32 func_02011F24(void);
extern void func_020306F0(unsigned int a);

void func_02011D60(void)
{
    func_0203064C(9, 5, 5 << 10);
    func_02011F24();
    func_020306F0(5);
}
