/*
 * function: BR_SIDEBAR_Create
 * address: 0x021FED50
 * packet: pkt_ov186_021FED50
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_SIDEBAR_InitSlot 0x021FEEF4 thumb ov186
 *   gBrSidebarSourceFile 0x02200D78 data a1
 *   gBrSidebarConfigTable 0x02200B74 data a4
 */
extern const char gBrSidebarSourceFile[];
extern const char gBrSidebarConfigTable[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BR_RES_LoadSprite(char *, unsigned, unsigned);
extern void BR_SIDEBAR_InitSlot(char *, int, char *, const char *, unsigned);
char *BR_SIDEBAR_Create(int a, int unused, char *resources, unsigned heap)
{
    char *p = func_02030734(heap, 0x390, 0, gBrSidebarSourceFile, 0x132);
    int i;
    MI_CpuFill8(p, 0, 0x390);
    BR_RES_LoadSprite(resources, 4, heap);
    BR_RES_LoadSprite(resources, 5, heap);
    for (i = 0; i < 12; i++)
        BR_SIDEBAR_InitSlot(p + i * 0x4C, a, resources, gBrSidebarConfigTable + i * 24, heap);
    return p;
}
