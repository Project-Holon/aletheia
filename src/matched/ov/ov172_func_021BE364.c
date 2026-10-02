/*
 * function: func_021BE364
 * address: 0x021BE364
 * packet: pkt_ov172_021BE364
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_021BD1AC 0x021BD1AC thumb ov172
 *   d_021C724C 0x021C724C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(int,int,u32);
extern u8 *func_0203159C(u32,u32,int);
extern u8 *func_02030734(int,int,int,void *,int);
extern u32 func_020124F4(int);
extern unsigned int func_0203630C(void);
extern void func_021BD1AC(u8 *);
extern u8 d_021C724C[];
int func_021BE364(u32 obj,int unused,u8 *arg)
{
    u8 *p;
    if (arg && *(u32 *)(arg+4)==3) func_0203064C(1,109,0xd0000);
    else func_0203064C(1,109,0xe8000);
    p=func_0203159C(obj,0x1fc,109);
    *(u16 *)p=109;
    if (arg==0) {
        *(u8 **)(p+0x1f8)=func_02030734(1,16,1,d_021C724C,1357);
        **(u32 **)(p+0x1f8)=func_020124F4(1);
        *(u32 *)(*(u8 **)(p+0x1f8)+4)=0;
        if (func_0203630C() & 0x100) *(u32 *)(*(u8 **)(p+0x1f8)+4)=1;
        if (func_0203630C() & 0x400) *(u32 *)(*(u8 **)(p+0x1f8)+4)=2;
    } else *(u8 **)(p+0x1f8)=arg;
    *(u32 *)(p+0x14)=0;
    func_021BD1AC(p);
    return 1;
}
