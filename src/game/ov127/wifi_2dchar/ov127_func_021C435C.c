/*
 * function: func_021C435C
 * address: 0x021C435C
 * packet: pkt_ov127_021C435C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_021C4380 0x021C4380 thumb ov127
 *   func_021C43E4 0x021C43E4 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C4380(char *,int,u32,u32,u32);
extern void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c);
void func_021C435C(char *p, int i, int a, int b, int c, int mode) { if(mode==0) func_021C4380(p,i,a,b,c); else func_021C43E4((u8 *)p,i,a,b,c); }
