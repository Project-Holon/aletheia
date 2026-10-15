/*
 * function: NAMEIN_GRAPHIC_CreateMembers
 * address: 0x021F4D3C
 * packet: pkt_ov194_021F4D3C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: caller consumes 021F4D20 r0; full forwarder leaves 0204A1BC allocation result live despite own void declaration.
 * symbols:
 *   d_021F5798 0x021F5798 data a4
 *   NAMEIN_GRAPHIC_LoadArcMember 0x021F4D20 thumb ov194
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021F5798[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MI_CpuFill8(void *, u32, u32);
extern int NAMEIN_GRAPHIC_LoadArcMember(u32 a, u32 b);
u32 *NAMEIN_GRAPHIC_CreateMembers(u32 heap)
{
    u32 *p;
    int i = 0;
    p = func_02030734(heap, 20, 0, d_021F5798, 147);
    MI_CpuFill8(p, 0, 20);
    for (; i < 5; i++)
        p[i] = NAMEIN_GRAPHIC_LoadArcMember(i, heap);
    return p;
}
