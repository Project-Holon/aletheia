/*
 * function: func_021F69E4
 * address: 0x021F69E4
 * packet: pkt_ov112_021F69E4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F83F8 0x021F83F8 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern const char d_021F83F8[];
typedef struct { u32 a,b,c,d,e,f,g; } Entry;
typedef struct { u16 heap,n; void *p; Entry entries[5]; } Object;
Object *func_021F69E4(u16 heap, void *p)
{
    Object *o;
    u8 i;
    i=0;
    o=func_02030734(heap,148,0,d_021F83F8,79);
    o->heap=heap;
    o->p=p;
    o->n=0;
    for (;i<5;i++) { o->entries[i].a=0; o->entries[i].b=0; }
    return o;
}
