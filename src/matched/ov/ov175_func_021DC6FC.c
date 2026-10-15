/*
 * function: WIFIBATTLEMATCH_NET_NdSetError
 * address: 0x021DC6FC
 * packet: pkt_ov175_021DC6FC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FA84 0x0200FA84 thumb
 *   d_021E4B80 0x021E4B80 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0200FA84(void);
extern u8 d_021E4B80[];
void WIFIBATTLEMATCH_NET_NdSetError(void *p,u32 kind) { switch(kind) { case 0:case 1:case 2:case 3:case 4:case 5:case 7: break; case 6:case 8: func_0200FA84(); break; } d_021E4B80[0]=1; *(u32 *)(d_021E4B80+4)=kind; d_021E4B80[1]=1; }
