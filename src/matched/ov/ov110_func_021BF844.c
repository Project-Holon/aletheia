/*
 * function: func_021BF844
 * address: 0x021BF844
 * packet: pkt_ov110_021BF844
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3C84 0x021C3C84 data a1
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021C3C84[];
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern u8 *func_021BF6D4(u8 *);
u8 *func_021BF844(void *a,void *b,void *c) {
    u8 *p=func_02030734(42,160,0,d_021C3C84,154);
    *(void **)p=a; *(void **)(p+4)=b; *(void **)(p+8)=c;
    *(void **)(p+72)=func_020457B0(32,42);
    *(void **)(p+12)=func_020450F0(2,3,0,26,32,13,1);
    *(void **)(p+16)=func_020450F0(2,0,0,12,4,13,1);
    *(void **)(p+20)=0; *(void **)(p+24)=0;
    *(void **)(p+156)=func_021BF6D4(*(u8 **)(p+4));
    return p;
}
