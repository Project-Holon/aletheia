/*
 * unit:     yes
 * function: func_021B6524, func_021B652C, func_021B6538
 * address:  0x021B6524
 * packet:   pkt_ov071_021B6524
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 *
 * symbols:
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02045088  0x02045088  arm
 *   func_020450C8  0x020450C8  arm
 */

void func_021B6524(void)
{
    void func_0203F9B4(void);
    func_0203F9B4();
}

typedef unsigned short u16;
void func_021B652C(void)
{
    void func_02045088(u16 heapId);
    func_02045088(0x61);
}

void func_021B6538(void)
{
    void func_020450C8(void);
    func_020450C8();
}
