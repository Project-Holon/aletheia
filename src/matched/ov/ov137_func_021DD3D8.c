/*
 * function: func_021DD3D8
 * address: 0x021DD3D8
 * packet: pkt_ov137_021DD3D8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02049624: unit_0204961C.c defines it but omits function:;
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 func_0204A1BC(void *,void *,u32,u16);
 * extern u32 func_0204968C(u32,void *,void *,u32,u32);
 * u32 func_02049624(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=func_0204A1BC(a,b,f,g); return func_0204968C(r,c,d,e,f);
 * }
 * Blocker symbols: func_0204A1BC 0x0204A1BC arm; func_0204968C 0x0204968C arm.
 * symbols:
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049B40 0x02049B40 arm
 * func_02049624 0x02049624 arm
 * func_0204989C 0x0204989C arm
 * func_02040588 0x02040588 arm
 * func_0201F5BC 0x0201F5BC thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049658(void *,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02049624(u32,u32,u32,u32,u32,u32,u16);
extern void func_0204989C(u32,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040588(u32 which, u32 enable);
void func_021DD3D8(void *p,void *arc)
{
    func_02049B68(arc,1,0,0,512,114);
    func_02049658(arc,7,1,0,8192,0,114);
    func_020498F4(arc,13,1,0,1536,0,114);
    func_02049B40(23,5,0,416,32,114);
    func_02049B40(30,13,4,0,352,114);
    func_02049624(30,14,6,0,0,0,114);
    func_0204989C(30,3,6,0,0,0,114);
    func_0201F5BC(0,1,10,0,114);
    func_0201F5BC(0,31,11,0,114);
    func_02040588(0,1);
    func_02040588(1,1);
    func_02040588(6,1);
}
