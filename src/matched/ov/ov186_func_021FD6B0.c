/*
 * function: func_021FD6B0
 * address: 0x021FD6B0
 * packet: pkt_ov186_021FD6B0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_0202DBC4 0x0202DBC4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021FC830(void *);
extern void func_0202DBC4(u8 *);
int func_021FD6B0(u8 *p)
{
    int result=1;
    int i;
    for(i=0;i<7;i++)if(*(void **)((u32)p+(u32)i*4)!=0)result &=func_021FC830(*(void **)((u32)p+(u32)i*4));
    func_0202DBC4(*(u8 **)(p+32));
    return result;
}
