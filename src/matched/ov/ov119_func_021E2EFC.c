/*
 * function: func_021E2EFC
 * address: 0x021E2EFC
 * packet: pkt_ov119_021E2EFC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 46-byte body followed by 2-byte alignment padding.
 * symbols:
 *   func_02011510 0x02011510 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02011510(u32,u32,u32,u32);
void func_021E2EFC(char *p)
{
    *(void **)(p+0x90)=func_02011510(*(u16 *)(p+0xba),0x68,0xb,10);
    *(void **)(p+0x94)=func_02011510(*(u16 *)(p+0xba),0x68,0xc,10);
}
