/*
 * function: func_021BCAFC
 * address: 0x021BCAFC
 * packet: pkt_ov216_021BCAFC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B0F4 0x0204B0F4 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021BDBBC 0x021BDBBC data a4
 *   d_021BDC08 0x021BDC08 data a4
 */
struct Block { unsigned w[8]; };
extern const unsigned d_021BDBBC[];
extern const struct Block d_021BDC08;
extern void func_02082BCC(void *,int,int);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B0F4(void *,int);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
void func_021BCAFC(void **p,void *a,int heap)
{
    struct Block b;
    func_02082BCC(p,0,8);
    func_0204A48C((const struct Cfg *)d_021BDBBC,(unsigned int)a,heap);
    p[0]=func_0204B100(128,0,heap);
    b=d_021BDC08;
    p[1]=func_0204B034((u8 *)(&b),2,heap);
    func_0204B0F4(p[1],1);
    func_0204B258(p[0],p[1]);
    func_020434DC(16,1);
    func_02043598(16,1);
}
