/*
 * function: func_021B7438
 * address: 0x021B7438
 * packet: pkt_ov180_021B7438
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Plain halfword assignment preserves the required promotion and late truncation.
 * symbols:
 *   func_021B7408 0x021B7408 thumb ov180
 *   func_021B73E4 0x021B73E4 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 y,x; } Pair;
extern void func_021B7408(u8 *,int,s16 *,s16 *);
extern void func_021B73E4(char *p, int i, short x, short y);
void func_021B7438(u8 *p,int n,int x,int y) { Pair s; func_021B7408(p,n,&s.x,&s.y); s.x=s.x+x; s.y=s.y+y; func_021B73E4((char *)p,n,s.x,s.y); }
