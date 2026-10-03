/*
 * function: func_021E1594
 * address: 0x021E1594
 * packet: pkt_ov119_021E1594
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
typedef unsigned int u32;
extern void func_02045CAC(int,int,int);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(int,int,int);
extern void func_0201C7A4(void *,short,short,int,int);
void func_021E1594(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {func_02045CAC(*(int *)(p+0x720),28,*(int *)(p+0x734));func_0201EE84(*(void **)(p+0x724),0,a);func_0201F250(*(int *)(p+0x724),*(int *)(p+0x730),*(int *)(p+0x734));func_0201C7A4(b,x,y,*(int *)(p+0x730),*(int *)(p+0x728));}}
