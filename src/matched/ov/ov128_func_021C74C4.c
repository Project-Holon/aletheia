/*
 * function: func_021C74C4, func_021C74E8
 * unit: yes
 * address: 0x021C74C4
 * packet: pkt_ov128_021C74C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6438 0x021C6438 thumb ov128
 *   d_021CA51C 0x021CA51C data a4
 *   func_021C7460 0x021C7460 thumb ov128
 *   func_021C734C 0x021C734C thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u8 d_021CA51C[];
extern void func_021C6438(u8 *,u8,u8);
extern int func_021C7460(int *,int *,u8 *);
extern int func_021C734C(u32 *,int *,u8 *);
int func_021C74C4(int *p,int *q,u8 *r) {if(func_021C7460(p,q,r)!=-1) return 1;return func_021C734C((u32 *)p,q,r);}
void func_021C74E8(u32 *p,u8 *q) {func_021C6438(q,d_021CA51C[*p],0);}
