/*
 * function: func_021B7530
 * address: 0x021B7530
 * packet: pkt_ov180_021B7530
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void CLACT_ReleasePalette(u32);
void func_021B7530(char *p,int n) { if(*(u32 *)(p+0x90e4+n*4)!=~0u) { CLACT_ReleasePalette(*(u32 *)(p+0x90e4+n*4)); *(u32 *)(p+0x90e4+n*4)=~0u; } }
