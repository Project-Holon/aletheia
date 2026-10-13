/*
 * function: func_021DE238
 * address: 0x021DE238
 * packet: pkt_ov171_021DE238
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void CLACT_ReleaseCellAnim(u32);
void func_021DE238(char *p,int i)
{
    if(*(u32 *)((u32)p+0xc1c+(u32)i*4)!=(u32)-1) {
        CLACT_ReleaseCellAnim(*(u32 *)((u32)p+0xc1c+(u32)i*4));
        *(u32 *)((u32)p+0xc1c+(u32)i*4)=(u32)-1;
    }
}
