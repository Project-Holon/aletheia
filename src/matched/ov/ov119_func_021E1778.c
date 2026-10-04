/*
 * function: func_021E1778
 * address: 0x021E1778
 * packet: pkt_ov119_021E1778
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 */
typedef signed short s16;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern unsigned int func_02017E1C(void *p, unsigned int id, unsigned int v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E1778(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(*(int *)(p+0x720)),43,(void *)(*(int *)(p+0x734)));
    v=func_02017E1C((void *)a,6,0);
    if(v) {
        func_0201EF40((struct WordSet *)(*(int *)(p+0x724)),0,v);
        func_0201F250((struct WordSet *)(*(int *)(p+0x724)),(void *)(*(int *)(p+0x730)),(void *)(*(int *)(p+0x734)));
        func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
    }
}
