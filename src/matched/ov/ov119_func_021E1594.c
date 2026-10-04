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
typedef signed short   s16;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
void func_021E1594(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {func_02045CAC((struct MsgBank *)(*(int *)(p+0x720)),28,(void *)(*(int *)(p+0x734)));func_0201EE84(*(void **)(p+0x724),0,a);func_0201F250((struct WordSet *)(*(int *)(p+0x724)),(void *)(*(int *)(p+0x730)),(void *)(*(int *)(p+0x734)));func_0201C7A4(b,x,y,(void *)(*(int *)(p+0x730)),(void *)(*(int *)(p+0x728)));}}
