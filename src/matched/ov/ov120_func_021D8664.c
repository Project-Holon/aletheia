/*
 * function: func_021D8664
 * address: 0x021D8664
 * packet: pkt_ov120_021D8664
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_02028230 0x02028230 thumb
 *   func_021D8648 0x021D8648 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02028230(u8 *p);
extern void func_021D8648(u8 *p);
int func_021D8664(u8 *p)
{
    if(func_02028230(*(void **)(p+0xc4))){
        func_021D8648((u8 *)((int)p));
        return 1;
    }
    return 0;
}
