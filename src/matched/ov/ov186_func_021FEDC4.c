/*
 * function: func_021FEDC4
 * address: 0x021FEDC4
 * packet: pkt_ov186_021FEDC4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF028 0x021FF028 thumb ov186
 *   func_021FF004 0x021FF004 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021FF028(char *); extern void func_021FF004(char *); extern void func_021FC0C8(char *,u32); extern void func_020307B0(void *);
void func_021FEDC4(char *p,char *ctx) { int i; for(i=0;i<12;i++) if(func_021FF028((char *)((u32)p+i*0x4c))) func_021FF004((char *)((u32)p+i*0x4c)); func_021FC0C8(ctx,4); func_021FC0C8(ctx,5); func_020307B0(p); }
