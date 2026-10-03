/*
 * function: func_021DFDC0
 * address: 0x021DFDC0
 * packet: pkt_ov228_021DFDC0
 * region: ov228
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original stores live r0 after F1FC despite its legacy void return; keep returned low halfword.
 * symbols:
 *   func_0203F1FC 0x0203F1FC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_0203F1FC(const u8 *src, u32 len);
void func_021DFDC0(u8 *p)
{
    p[0x379]=0;
    if(*(u32 *)(p+0x374)==2)p[0x37A]=1;
    else p[0x37A]=0;
    *(u32 *)p=0xA10F49AE;
    *(u32 *)(p+4)+=1;
    *(u16 *)(p+8)=func_0203F1FC(p+12,0x368);
}
