/*
 * function: func_021DA3C0
 * address: 0x021DA3C0
 * packet: pkt_ov121_021DA3C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020437AC 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020437AC(void *);
extern void func_020307B0(void *);
void func_021DA3C0(u8 *p) { u32 i; for(i=0;i<*(u32 *)(*(u8 **)(p+4)+4);i++) func_020437AC(*(void **)(p+8+i*4)); func_020307B0(p); }
