/*
 * function: func_021C3AA8
 * address: 0x021C3AA8
 * packet: pkt_ov208_021C3AA8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Actor;
extern void func_0204B688(struct Actor *p,u32 value);
extern void func_0207D63C(u32 reg,int p1,int p2,int ev1,int ev2);
void func_021C3AA8(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(struct Actor **)(p+i*4+0x54))
            func_0204B688(*(struct Actor **)(p+i*4+0x54),0);
    }
    for(i=0;i<6;i++)
        func_0204B688(*(struct Actor **)(p+i*4+0x9c),0);
    func_0207D63C(0x04000050,4,0x3f,0x10,8);
    func_0207D63C(0x04001050,0,0x3f,0xc,4);
}
