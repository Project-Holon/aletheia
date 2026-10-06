/*
 * function: func_021BEE1C
 * address: 0x021BEE1C
 * packet: pkt_ov203_021BEE1C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005E30 0x02005E30 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern int func_021BF7AC(char *,int);
extern void func_02005DF8(u32 a);
extern void func_02005E30(u32 a);
void func_021BEE1C(char *p,int unused,int *s) { int x;x=func_021BF7AC(p,s[1]);if(s[0]==0)func_02005DF8((u16)x);else func_02005E30((u16)x); }
