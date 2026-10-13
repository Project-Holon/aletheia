/*
 * function: FIELDSKILL_MAPEFF_Create
 * address:  0x021C7F70
 * packet:   pkt_ov021_021C7F70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldSkillMapEffFileName  0x021DE50C  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELDSKILL_MAPEFF_InitFlash  0x021C7FC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char gFieldSkillMapEffFileName[];
extern void FIELDSKILL_MAPEFF_InitFlash(M **pp, u32 flags, u32 heap);
M **FIELDSKILL_MAPEFF_Create(u32 flags, u32 heap)
{
    M **pp = func_02030734(heap, 4, 1, gFieldSkillMapEffFileName, 0x49);
    FIELDSKILL_MAPEFF_InitFlash(pp, flags, heap);
    return pp;
}
