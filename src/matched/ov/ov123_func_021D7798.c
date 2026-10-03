/*
 * function: func_021D7798
 * address: 0x021D7798
 * packet: pkt_ov123_021D7798
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200C5F8 0x0200C5F8 thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D751C 0x021D751C thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MusicalDist;
extern u32 func_0200C5F8(struct MusicalDist *p);
extern void func_021D6EE0(char *,int,int);
extern void func_021D751C(int a);
void func_021D7798(u8 *p) { if(func_0200C5F8(*(void **)(p+48))) { p[174]=0; *(void **)(p+48)=0; func_021D6EE0((char *)p,(int)func_021D751C,0x38e); } }
