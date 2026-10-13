/*
 * function: BTL_SERVER_FLOW_Create
 * address: 0x021BB968
 * packet: pkt_ov093_021BB968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   SHINKA_CHECK_OpenHandle 0x0201B70C thumb
 *   BTL_SERVER_FLOW_InitState 0x021BB9D8 thumb ov093
 *   gFlowSourceFileName 0x021F3A70 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 gFlowSourceFileName[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *SHINKA_CHECK_OpenHandle(u16 heap);
extern void BTL_SERVER_FLOW_InitState(u8 *p);

u8 *BTL_SERVER_FLOW_Create(void *a, void *b, void *c, void *d, int e, u16 heap)
{
    u8 *p;
    p = func_02030734(heap, 0x212c, 1, (const char *)gFlowSourceFileName, 0x245);
    *(void **)(p + 0) = a;
    *(void **)(p + 8) = c;
    *(void **)(p + 4) = b;
    p[0x782] = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(void **)(p + 0xc) = d;
    *(u16 *)(p + 0x780) = heap;
    *(int *)(p + 0x18) = e;
    *(void **)(p + 0x4a4) = SHINKA_CHECK_OpenHandle(heap);
    BTL_SERVER_FLOW_InitState(p);
    return p;
}
