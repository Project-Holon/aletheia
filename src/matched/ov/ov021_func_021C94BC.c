/*
 * function: FLDEFF_IAIGIRI_Create
 * address:  0x021C94BC
 * packet:   pkt_ov021_021C94BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldeffIaigiriFileName  0x021DE578  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FLDEFF_IAIGIRI_LoadResources  0x021C94F4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern char sFldeffIaigiriFileName[];
extern void FLDEFF_IAIGIRI_LoadResources(u32 *q);
u32 *FLDEFF_IAIGIRI_Create(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x1c, 1, sFldeffIaigiriFileName, 0x66);
    q[0] = a;
    FLDEFF_IAIGIRI_LoadResources(q);
    return q;
}
