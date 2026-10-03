/*
 * function: func_021B9970
 * address: 0x021B9970
 * packet: pkt_ov205_021B9970
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02045088 0x02045088 arm
 *   func_020111E8 0x020111E8 thumb
 *   d_021B9E90 0x021B9E90 data a4
 *   d_021B9E60 0x021B9E60 data a4
 *   d_021B9E70 0x021B9E70 data a4
 */
typedef unsigned short u16;
extern void func_0203F8F4(u16);
extern void func_020433E0(const void *);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(unsigned,const void *,unsigned);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02040EBC(unsigned,unsigned);
extern void func_02045088(u16);
extern unsigned func_020111E8(void);
extern const unsigned d_021B9E90[],d_021B9E60[],d_021B9E70[];
void func_021B9970(u16 heap)
{
    unsigned zero;
    func_0203F8F4(heap);
    func_020433E0(d_021B9E90);
    func_0203FC28((void *)d_021B9E60);
    zero=0;
    func_0203FCA0(0,d_021B9E70,0);
    func_02049B40(23,7,0,416,32,heap);
    if(func_020111E8()==20) func_02040EBC(zero,65535);
    else func_02040EBC(zero,zero);
    func_02045088(heap);
}
