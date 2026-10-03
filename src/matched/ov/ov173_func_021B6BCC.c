/*
 * function: func_021B6BCC
 * address: 0x021B6BCC
 * packet: pkt_ov173_021B6BCC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B7968 0x021B7968 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void func_021B7968(char *);
void func_021B6BCC(char *p) { int n; n=func_021B7438((char **)p); if(n!=65535) func_021B71C4(p,n); else func_021B71C4(p,-2); func_021B7968(p); }
