/*
 * function: func_021F0114
 * address: 0x021F0114
 * packet: pkt_ov032_021F0114
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F07D4 0x021F07D4 thumb ov032
 *   sub_02010EA0 0x02010EA0 thumb
 *   func_021F1A18 0x021F1A18 thumb ov032
 */
typedef unsigned char u8;
extern unsigned func_021F07D4(u8 *);
extern u8 sub_02010EA0(int,u8 *);
extern void func_021F1A18(u8 *,int);
int func_021F0114(u8 *p) { unsigned n; n=func_021F07D4(p); if(n==0x30) return 0; if(n==sub_02010EA0(n,*(u8 **)(p+0x24))) return 0; func_021F1A18(p,n); return 1; }
