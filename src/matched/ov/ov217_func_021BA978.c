/*
 * function: func_021BA978
 * address: 0x021BA978
 * packet: pkt_ov217_021BA978
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA9CE..021BA9D0 zero alignment padding.
 * lever: acquisition-order a,b,c stores hoist spilled b reload before c store.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
struct Context {void *owner;u16 heap,pad6;char gap8[0x54];int slots[6];};
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021BA978(struct Context *p)
{
    u16 heap=p->heap;
    void *arc=func_020490F4(192,heap);
    int a=func_0204A6C8((void *)((unsigned)arc),15,0,0,heap);
    int b=func_0204AC18((void *)((unsigned)arc),16,0,192,0,4,heap);
    int c=func_0204AF28((void *)((unsigned)arc),14,17,heap);
    p->slots[0]=a;p->slots[1]=b;p->slots[2]=c;
    func_02049238(arc);
}
