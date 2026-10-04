/*
 * unit: yes
 * function: func_021BB9AC,func_021BB9BC
 * address: 0x021BB9AC
 * packet: pkt_ov091_021BB9AC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 */
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
void func_021BB9AC(int a,int b,int c,int d) {func_0201EF40((struct WordSet *)(*(int *)(b+0x2c)),c,d);}
void func_021BB9BC(int a,int b,int c,int d) {func_0201EF4C((struct WordSet *)(*(int *)(b+0x2c)),c,d);}
