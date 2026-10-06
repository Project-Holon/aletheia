/*
 * function: func_021FEEC0
 * address: 0x021FEEC0
 * packet: pkt_ov186_021FEEC0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF02C 0x021FF02C thumb ov186
 *   d_02200B74 0x02200B74 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FF02C(u8 *p, u32 v); extern const char d_02200B74[];
void func_021FEEC0(char *p,int mode,u32 value) { int i; for(i=0;i<12;i++) if(mode==*(int *)((u32)d_02200B74+i*24+16)) func_021FF02C((u8 *)((u32)p+i*0x4c),value); }
