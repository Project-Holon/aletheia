/*
 * function: WF2DMAP_OBJCMD_SpawnIfFreeThunk
 * address:  0x021C5478
 * packet:   pkt_021C5478
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJCMD_SpawnIfFree  0x021C5404  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern int WF2DMAP_OBJCMD_SpawnIfFree(void *p, void *q, void *r, const u8 *s, void *t);

void WF2DMAP_OBJCMD_SpawnIfFreeThunk(int a, int b, int c, int d, int e)
{
    WF2DMAP_OBJCMD_SpawnIfFree((void *)a, (void *)b, (void *)c, (const u8 *)d, (void *)e);
}
