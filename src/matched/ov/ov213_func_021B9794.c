/*
 * function: func_021B9794
 * address: 0x021B9794
 * packet: pkt_ov213_021B9794
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021BAF14 0x021BAF14 data a4
 * prototype: 49238 asm body saves entry r0 and forwards it to destructors; retain caller's resource argument.
 */
typedef unsigned short u16;
typedef struct {unsigned a,b,c;} Entry;
extern const Entry d_021BAF14[];
extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02049238(void *);
void func_021B9794(int a,u16 heap,int index)
{
    void *p;
    p=func_020490F4(181,heap);
    func_02049B68(p,d_021BAF14[index].a,0,0,0,heap);
    func_02049658(p,d_021BAF14[index].b,3,0,0,0,heap);
    func_020498F4(p,d_021BAF14[index].c,3,0,0,0,heap);
    func_02049B68(p,4,4,0,0,heap);
    func_02049658(p,3,6,0,0,0,heap);
    func_020498F4(p,5,6,0,0,0,heap);
    func_02049238(p);
}
