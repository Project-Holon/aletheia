/*
 * function: func_0217F958
 * address: 0x0217F958
 * packet: pkt_ov019_0217F958
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0217FCA4 0x0217FCA4 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0217FCA4(char *p);
void func_0217F958(char *p,u32 key) { char *base=p+0x20; int i; for(i=0;i<10;i++) { u32 value=*(u32 *)(base+i*20); if(value==key) { func_0217FCA4(base+i*20); return; } } }
