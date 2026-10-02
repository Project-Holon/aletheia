/*
 * function: func_021F39BC
 * address: 0x021F39BC
 * packet: pkt_ov048_021F39BC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   d_021F50D2 0x021F50D2 data a2
 */
typedef unsigned short u16;
extern int func_02188D2C(int p);
extern void func_021BE700(int a,int b,int c,u16 d,int e);
extern const u16 d_021F50D2[];
void func_021F39BC(int *p) { func_021BE700(func_02188D2C(p[1]),1,0,d_021F50D2[((int *)p[7])[0x1d]],1); }
