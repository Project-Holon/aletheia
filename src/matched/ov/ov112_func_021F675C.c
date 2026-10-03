/*
 * function: func_021F675C
 * address: 0x021F675C
 * packet: pkt_ov112_021F675C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02017EAC(void *);
extern const char d_021F83E4[];
char *func_021F675C(void *a,u16 heap)
{
    char *p;
    int i;
    p=func_02030734(heap,124,1,d_021F83E4,141);
    *(u32 *)p=4;
    *(void **)(p+4)=a;
    *(u16 *)(p+74)=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    *(u16 *)(p+8)=func_02017E1C(a,5,0);
    p[10]=func_02017E1C(a,110,0);
    p[11]=func_02017E1C(a,111,0);
    p[12]=func_02017EAC(a);
    *(u32 *)(p+16)=func_02017E1C(a,0,0);
    return p;
}
