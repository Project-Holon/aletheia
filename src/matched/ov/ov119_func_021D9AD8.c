/*
 * function: func_021D9AD8
 * address: 0x021D9AD8
 * packet: pkt_ov119_021D9AD8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9B34 0x021D9B34 thumb ov119
 */
typedef unsigned int u32;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_021D8FA4(void *,int);
struct WordSet;
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021E1024(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9B34(char *p);
void func_021D9AD8(char *p) { int i; func_02045CAC((struct MsgBank *)(*(int *)(p+0x720)),17,(void *)(*(int *)(p+0x73c)));for(i=0;i<2;i++) func_0201EEF4(*(void **)(p+0x724),i,func_021D8FA4(p,i));func_0201F250((struct WordSet *)(*(int *)(p+0x724)),(void *)(*(int *)(p+0x738)),(void *)(*(int *)(p+0x73c)));func_021E1024(p);func_021D8E84(p,(int)func_021D9B34); }
