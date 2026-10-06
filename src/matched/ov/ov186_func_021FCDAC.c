/*
 * function: func_021FCDAC
 * address: 0x021FCDAC
 * packet: pkt_ov186_021FCDAC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D68 0x02200D68 data a4
 */
/* 2026-10-05: twin ov186 021FCDE8 (same bounds assert); second assert is a taken-slot check. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02034714(const char *,u32,const char *);
extern const char d_02200D68[];
void func_021FCDAC(u8 *p, u16 i, u32 v)
{
    if(i>=*(u32 *)(p+4))func_02034714(d_02200D68,0,d_02200D68);
    if(*(u32 *)(*(u32 *)p+i*8)!=0)func_02034714(d_02200D68,0,d_02200D68);
    *(u32 *)((u32)p+i*4+0x8c)=v;
}
