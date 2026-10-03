/*
 * function: func_021BEC84
 * address: 0x021BEC84
 * packet: pkt_ov203_021BEC84
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BECA8 0x021BECA8 thumb ov203
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern void func_021BECA8(struct Owner *,u8,u16,int,int,int,int);
void func_021BEC84(struct Owner *p,int unused,int *s) { func_021BECA8(p,2,s[0],s[1],s[2],s[3],s[4]); }
