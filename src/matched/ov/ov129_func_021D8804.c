/*
 * function: func_021D8804
 * address: 0x021D8804
 * packet: pkt_ov129_021D8804
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020434CC 0x020434CC arm
 *   func_020433E0 0x020433E0 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204363C 0x0204363C arm
 *   d_021DA800 0x021DA800 data a4
 *   d_021DA638 0x021DA638 data a4
 *   d_021DA698 0x021DA698 data a4
 */
typedef unsigned u32;
typedef struct { u32 words[8]; } BgTemplate;
typedef struct { BgTemplate rows[3]; } MainTemplates;
typedef struct { BgTemplate rows[4]; } SubTemplates;
extern const u32 d_021DA800[];
extern const MainTemplates d_021DA638;
extern const SubTemplates d_021DA698;
extern void func_020434CC(void);
extern void func_020433E0(const void *);
extern void func_02082A7C(u32,void *,u32);
extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void func_0204363C(u32);
void func_021D8804(void)
{
    MainTemplates main;
    SubTemplates sub;
    func_020434CC();
    func_020433E0(d_021DA800);
    func_02082A7C(0,(void *)0x06000000,0x80000);
    func_02082A7C(0,(void *)0x06200000,0x20000);
    func_02082A7C(0,(void *)0x06400000,0x40000);
    func_02082A7C(0,(void *)0x06600000,0x20000);
    main=d_021DA638;
    func_0203FCA0(1,&main.rows[0],0);
    func_0203FCA0(2,&main.rows[1],0);
    func_0203FCA0(3,&main.rows[2],0);
    func_020414EC(1); func_020414EC(2); func_020414EC(3);
    func_020434DC(1,0); func_020434DC(2,1); func_020434DC(4,0); func_020434DC(8,0);
    sub=d_021DA698;
    func_0203FCA0(4,&sub.rows[0],0);
    func_0203FCA0(5,&sub.rows[1],0);
    func_0203FCA0(6,&sub.rows[2],0);
    func_0203FCA0(7,&sub.rows[3],0);
    func_020414EC(4); func_020414EC(5); func_020414EC(6); func_020414EC(7);
    func_02043598(1,1); func_02043598(2,1); func_02043598(4,0); func_02043598(8,0);
    func_0204363C(0);
    func_020434DC(16,1); func_02043598(16,1);
}
