/*
 * function: MUSICAL_MCSS_CreateActorPool
 * address: 0x021F48C0
 * packet: pkt_ov112_021F48C0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MUSICAL_MCSS_LoadActorData 0x021F4F14 thumb ov112
 *   d_021F83A4 0x021F83A4 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Record { u16 active:1; u16 enabled:1; u16 rest:14; u8 data[34]; } Record;
typedef struct Object { u16 heap; u16 pad; u32 owner; Record *records; void *resource; u16 count; u16 slots[16]; } Object;
extern char d_021F83A4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 *MUSICAL_MCSS_LoadActorData(int heap);
Object *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap)
{
    int i=0;
    Object *p;
    int j;
    p=func_02030734(heap,0x34,0,d_021F83A4,0x55);
    p->records=func_02030734(heap,count*0x24,0,d_021F83A4,0x57);
    p->heap=heap;
    p->count=count;
    p->owner=owner;
    for(;i<p->count;i++) {
        p->records[i].active=0;
        p->records[i].enabled=0;
    }
    p->resource=MUSICAL_MCSS_LoadActorData(heap);
    for(j=0;j<16;j++) p->slots[j]=0x5a56;
    return p;
}
