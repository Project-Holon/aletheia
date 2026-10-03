/*
 * unit: no
 * function: func_0220D988
 * address: 0x0220D988
 * packet: pkt_ov198_0220D988
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220C0D0 0x0220C0D0 thumb ov198
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
typedef struct {u8 lo:7,hi:1;} Bits;
extern int func_022110D4(u8 *,int);extern void func_0220C0D0(u8 *,int,int,u16,u8);
void func_0220D988(u8 *p,int a){if(((Bits *)(p+(u32)func_022110D4(p,a)*76+0x1b))->hi==0)func_0220C0D0(p,a,a,8,32);}
