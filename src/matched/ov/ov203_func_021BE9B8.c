/*
 * function: func_021BE9B8
 * address: 0x021BE9B8
 * packet: pkt_ov203_021BE9B8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE9F8 0x021BE9F8 thumb ov203
 *   d_021C3B98 0x021C3B98 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern void *func_021BE9F8(void *,const Config *);
extern const Config d_021C3B98;
void * func_021BE9B8(void *p,unsigned a,unsigned b) { Config c;c=d_021C3B98;c.words[8]=a;c.words[9]=b;return func_021BE9F8(p,&c); }
