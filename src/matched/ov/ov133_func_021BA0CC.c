/*
 * function: func_021BA0CC
 * address: 0x021BA0CC
 * packet: pkt_ov133_021BA0CC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021BA610 0x021BA610 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char*,u16);
extern const char d_021BA610[];
u8 *func_021BA0CC(u16 heap,u16 n){u8 *p;p=func_02030734(heap,16,0,d_021BA610,76);*(u16*)p=heap;*(u16*)(p+4)=0;*(u16*)(p+6)=n;*(u32*)(p+8)=0;*(u32*)(p+12)=0;return p;}
