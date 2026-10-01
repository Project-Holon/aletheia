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
extern void func_0204A48C(const void *,void *,int);
extern void *func_0204B100(int,int,int);
extern void *func_0204B034(const void *,int,int);
extern void func_0204B0F4(void *,int);
extern void func_0204B258(void *,void *);
extern void func_020434DC(int,int);
extern void func_02043598(int,int);
void func_021BCAFC(void **p,void *a,int heap)
{
    struct Block b;
    func_02082BCC(p,0,8);
    func_0204A48C(d_021BDBBC,a,heap);
    p[0]=func_0204B100(128,0,heap);
    b=d_021BDC08;
    p[1]=func_0204B034(&b,2,heap);
    func_0204B0F4(p[1],1);
    func_0204B258(p[0],p[1]);
    func_020434DC(16,1);
    func_02043598(16,1);
}
