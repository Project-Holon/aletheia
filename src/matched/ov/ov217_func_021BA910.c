/*
 * function: func_021BA910
 * address: 0x021BA910
 * packet: pkt_ov217_021BA910
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA95E..021BA960 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 * ABF0 forwards AC18's returned r0; caller stores it at +0x6c.
 */
typedef unsigned short u16;
struct Context {void *owner;u16 heap,pad6;char gap8[0x54];int slots[6];};
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021BA910(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,1,heap);
    int b=func_0204ABF0((void *)arc,16,1,0,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[3]=a;p->slots[4]=b;p->slots[5]=c;
    func_02049238(arc);
}
