/*
 * function: func_021C48E8
 * address: 0x021C48E8
 * packet: pkt_ov127_021C48E8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4914 0x021C4914 thumb ov127
 *   func_021C4980 0x021C4980 thumb ov127
 *   func_021C4CB4 0x021C4CB4 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_021C4914(u8 *);
extern char *func_021C4980(char **p, int i);
extern void func_021C4CB4(u8 *p);
void func_021C48E8(u8 *p) { u32 i,n; char *q; n=func_021C4914(p);for(i=0;i<n;i++){q=func_021C4980((char **)p,(u16)i);if(q)func_021C4CB4((u8 *)q);} }
