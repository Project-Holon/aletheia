/*
 * function: func_021E194C
 * address: 0x021E194C
 * packet: pkt_ov119_021E194C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 */
typedef signed short s16;
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
void func_021E194C(int a,int b,int x,int y,char *p)
{
    func_02045CAC((struct MsgBank *)(*(int *)(p+0x720)),44,(void *)(*(int *)(p+0x730)));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
}
