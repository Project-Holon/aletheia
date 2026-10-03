/*
 * function: func_021C42C4
 * address: 0x021C42C4
 * packet: pkt_ov127_021C42C4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4634 0x021C4634 thumb ov127
 *   d_021C5FB0 0x021C5FB0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u8 d_021C5FB0[];
extern void func_021C4634(u8 *);
void func_021C42C4(u8 *p) { int flag; int n; flag=0; n=d_021C5FB0[*(u32 *)(p+12)]; if(n==255) flag=1; else if(n>=*(s16 *)(p+20)+1) flag=1; if(flag==1) { func_021C4634(p); *(s16 *)(p+20)+=1; } }
