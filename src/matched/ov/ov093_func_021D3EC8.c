/*
 * function: func_021D3EC8
 * address: 0x021D3EC8
 * packet: pkt_ov093_021D3EC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFFA0 0x021EFFA0 data a1
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a,b; } Pair;
extern Pair d_021EFFA0[];
extern u32 func_021D805C(void *,u32);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *,int);
int func_021D3EC8(void *s,struct Unk021D62A8 *m) { u32 i; for(i=0;i<7;i++) if(func_021D805C(s,d_021EFFA0[i].a) && func_021D62C4(m,d_021EFFA0[i].b)) return 1; return 0; }
