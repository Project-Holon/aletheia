/*
 * function: func_021C25D0
 * address: 0x021C25D0
 * packet: pkt_ov217_021C25D0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C2612, not a follower.
 * ABI: 0204B294's legacy source says void; original caller stores returned
 *      r0 at 021C2608. Preserve that observable return and its seven inputs.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arg { u16 a,b,c; u8 d,e; };
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
void func_021C25D0(u8 *p)
{
    struct Arg arg;
    u32 *q=(u32 *)(p+8);
    int i=0;
    arg.a=0;
    arg.b=0;
    arg.c=0;
    arg.d=0;
    arg.e=0;
    for (;i<26;i++) {
        *(u32 *)(p+i*24+0x3c)=func_0204B294(*(u32 *)(p+4),q[0],q[1],q[2],(u32)&arg,*(u16 *)((u8 *)q+0xc),*(u16 *)p);
    }
}
