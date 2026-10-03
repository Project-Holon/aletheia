/*
 * function: func_021BA19C
 * address: 0x021BA19C
 * packet: pkt_ov133_021BA19C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021BA610 0x021BA610 data a4
 *   func_021F4C1C 0x021F4C1C thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Object;struct Entry;
extern struct Entry *func_021F4C1C(struct Object*,int,u32,int*);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern const char d_021BA610[];
u8 *func_021BA19C(u32 heap,struct Object*q,u8*r,int*v){u8*p;p=func_02030734(heap,52,0,d_021BA610,204);*(u32*)(p+48)=0;*(u8**)(p+4)=r;*(struct Entry**)(p+12)=func_021F4C1C(q,*(u16*)r,*(u32*)(r+4),v);*(u16*)(p+28)=0;*(u32*)(p+32)=10;return p;}
