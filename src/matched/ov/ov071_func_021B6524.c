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
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 */

void func_021B6524(void)
{
    void func_0203F9B4(void);
    func_0203F9B4();
}

typedef unsigned short u16;
void func_021B652C(void)
{
    void BMP_WIN_Init(u16 heapId);
    BMP_WIN_Init(0x61);
}

void func_021B6538(void)
{
    void BMP_WIN_Exit(void);
    BMP_WIN_Exit();
}
