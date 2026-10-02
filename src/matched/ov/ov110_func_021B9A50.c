/*
 * function: func_021B9A50
 * address: 0x021B9A50
 * packet: pkt_ov110_021B9A50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: 9BA4 tail-forwards three live arguments to ARM9 056A0, whose full
 *   body calls 30DA8 and returns its pointer; original 9ABA consumes r0.
 * symbols:
 *   d_021C3C20 0x021C3C20 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021C3714 0x021C3714 data a4
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021BF7D0 0x021BF7D0 thumb ov110
 *   func_021B9BAC 0x021B9BAC thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 *   func_021B9BD0 0x021B9BD0 thumb ov110
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   func_020490F4 0x020490F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C3C20[];
extern const u8 d_020A1448[];
extern const u8 d_021C3714[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204A48C(const void *,u32,u32);
extern void *func_0204B100(int,u8,u32);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0207D534(void *,int);
extern u32 func_021BF7D0(u8 *);
extern void func_021B9BAC(void *,u8 *);
extern void *func_02030DA8(u32,u32,void *,int);
extern void func_021B9BD0(void *,u8 *);
extern void *func_021B9BA4(void (*)(void *,u8 *),u8 *,int);
extern void *func_020490F4(unsigned int id, u16 heap);
void *func_021B9A50(u8 *context,void *arg) {
    u8 *p;
    int i;
    p=func_02030734(42,0x90,0,d_021C3C20,0xdf);
    if(p!=0) {
        *(u32 *)(p+0x64)=0;
        *(u32 *)(p+0x7c)=0;
        *(u8 **)(p+0x18)=context;
        *(void **)(p+0x1c)=arg;
        *(u8 **)(p+0x78)=func_021BF6D4(context);
        func_0204A48C(d_020A1448,(u32)d_021C3714,42);
        *(void **)(p+0x20)=func_0204B100(128,0,42);
        func_0203F8F4(42);
        func_02045088(42);
        func_0207D534((void *)0x0400006c,-16);
        func_0207D534((void *)0x0400106c,-16);
        *(void **)p=func_02030DA8(func_021BF7D0(context),(u32)func_021B9BAC,p,2);
        *(void **)(p+4)=func_021B9BA4(func_021B9BD0,p,1);
        for(i=0;i<4;++i) *(void **)(p+8+i*4)=0;
        *(u32 *)(p+0x70)=0;
        p[0x74]=0;
        *(u32 *)(p+0x84)=0;
        *(u32 *)(p+0x88)=0;
        *(void **)(p+0x8c)=func_020490F4(43,42);
    }
    return p;
}
