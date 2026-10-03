/*
 * function: func_021FCDE8
 * address: 0x021FCDE8
 * packet: pkt_ov186_021FCDE8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D68 0x02200D68 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02034714(const char *,u32,const char *);
extern const char d_02200D68[];
u32 func_021FCDE8(u8 *p,u32 i)
{
    if(i>=*(u32 *)(p+4))func_02034714(d_02200D68,0,d_02200D68);
    return *(u32 *)((u32)p+i*4+0x8c);
}
