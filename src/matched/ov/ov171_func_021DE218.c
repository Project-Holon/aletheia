/*
 * function: DENDOU_VIEW_ReleasePalette
 * address: 0x021DE218
 * packet: pkt_ov171_021DE218
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void CLACT_ReleasePalette(u32);
void DENDOU_VIEW_ReleasePalette(char *p,int i)
{
    if(*(u32 *)((u32)p+0xbe8+(u32)i*4)!=(u32)-1) {
        CLACT_ReleasePalette(*(u32 *)((u32)p+0xbe8+(u32)i*4));
        *(u32 *)((u32)p+0xbe8+(u32)i*4)=(u32)-1;
    }
}
