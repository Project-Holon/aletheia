/*
 * function: func_021C5EEC
 * address: 0x021C5EEC
 * packet: pkt_ov127_021C5EEC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C6158 0x021C6158 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { void *entries; u32 count; u16 used, capacity; } Container;
extern void *func_02030734(u16,u32,int,const char *,u16);
extern const char d_021C6158[];
Container *func_021C5EEC(int n, int heap)
{
    Container *p;
    p=func_02030734(heap,12,1,d_021C6158,211);
    p->count=n+1;
    p->entries=func_02030734(heap,p->count*4,1,d_021C6158,216);
    p->used=0;
    p->capacity=0;
    return p;
}
