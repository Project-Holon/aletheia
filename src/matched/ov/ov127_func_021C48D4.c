/*
 * function: WF2DMAP_OBJ_DispatchById
 * address:  0x021C48D4
 * packet:   pkt_021C48D4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WF2DMAP_OBJ_FindById  0x021C4954  thumb
 *   WF2DMAP_OBJ_ApplyCommand  0x021C4C88  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern char *WF2DMAP_OBJ_FindById(unsigned *p, unsigned id);
extern void WF2DMAP_OBJ_ApplyCommand(char *p, char *q);

void WF2DMAP_OBJ_DispatchById(void *a, u8 *q)
{
    WF2DMAP_OBJ_ApplyCommand(WF2DMAP_OBJ_FindById(a, q[7]), (char *)q);
}
