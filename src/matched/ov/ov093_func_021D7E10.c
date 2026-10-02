/*
 * function: func_021D7E10
 * address: 0x021D7E10
 * packet: pkt_ov093_021D7E10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: declare n before i; both exits return n to retain r0 on the zero path.
 * extent: trailing two-byte alignment before Thumb-to-ARM veneer 021D7E34.
 * symbols:
 *   func_021D7E34 0x021D7E34 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D7E34(int);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *,int);
int func_021D7E10(struct Unk021D62A8 *p) { int n; int i=0; for (;;) { n=func_021D7E34(i++); if(n==0) return n; if(func_021D62C4(p,n)) return n; } }
