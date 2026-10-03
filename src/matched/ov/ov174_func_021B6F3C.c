/*
 * function: func_021B6F3C
 * address: 0x021B6F3C
 * packet: pkt_ov174_021B6F3C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049BDC 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021B7484 0x021B7484 data a1
 *   d_021B7480 0x021B7480 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_020413B0(unsigned,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern const u8 d_021B7484[],d_021B7480[];
void func_021B6F3C(char *p,u8 *q)
{
    u8 height=24;
    if(*(int *)(p+8)!=2) height=12;
    func_02049BDC(*(void **)(p+0x18),d_021B7484[q[2]*3],2,0,0x4000+q[0]*0x200,0x200,*(u16 *)p);
    func_02049BDC(*(void **)(p+0x18),*(int *)(p+0x10)+d_021B7480[q[3]*2],2,0,0x6000+q[0]*0x200,0x200,*(u16 *)p);
    func_020413B0(2,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_020413B0(3,(q[0]%2)*16,(q[0]/2)*height,16,height,q[0]);
    func_02041B6C(3);
    func_02041B6C(2);
}
