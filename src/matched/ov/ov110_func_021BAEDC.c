/*
 * function: func_021BAEDC
 * address: 0x021BAEDC
 * packet: pkt_ov110_021BAEDC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: int index declared before allocation pointer; table has no region hint.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BAFE4 0x021BAFE4 thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_021B6C74 0x021B6C74 thumb ov067
 *   func_020457B0 0x020457B0 arm
 *   d_021C3C34 0x021C3C34 data ov110 a1
 *   d_021C3770 0x021C3770 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021BAFE4(u8 *);
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_021B6C74(void **,u32,u16);
extern void *func_020457B0(u32,u32);
extern const char d_021C3C34[];
extern const u16 d_021C3770[];
u8 *func_021BAEDC(void *p,void *q,u16 heap) {
    int i;
    u8 *result;
    result=func_02030734(heap,0xaf4,1,d_021C3C34,137);
    *(void **)result=p;
    *(void **)(result+4)=q;
    *(u16 *)(result+8)=heap;
    func_021BAFE4(result);
    for(i=0;i<27;i++) *(void **)(result+12+i*4)=func_02045B38(1,2,d_021C3770[i],heap);
    *(void **)(result+0x78)=func_021B6C74((void **)(result+12),27,*(u16 *)(result+8));
    *(void **)(result+0xad0)=func_020457B0(27,heap);
    return result;
}
