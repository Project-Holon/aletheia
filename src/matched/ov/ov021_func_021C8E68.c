/*
 * function: FLDEFF_D06DENKI_Create
 * address:  0x021C8E68
 * packet:   pkt_ov021_021C8E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldeffD06DenkiFileName  0x021DE544  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   FLDEFF_D06DENKI_LoadResources  0x021C8EA0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sFldeffD06DenkiFileName[];
extern void FLDEFF_D06DENKI_LoadResources(u32 *q);
u32 *FLDEFF_D06DENKI_Create(u32 a, u32 heap)
{
    u32 *q = func_02030734(heap, 0x34, 1, sFldeffD06DenkiFileName, 0xa9);
    q[0] = a;
    FLDEFF_D06DENKI_LoadResources(q);
    return q;
}
