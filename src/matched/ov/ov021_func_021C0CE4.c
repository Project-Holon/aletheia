/*
 * function: FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags
 * address:  0x021C0CE4
 * packet:   pkt_ov021_021C0CE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs FIELD_PLAYER_GRID_EVENT_StartBoulderDrop when bit 0 of the flags is set.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetDirChangeKind  0x021A448C  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_StartBoulderDrop  0x021C0DDC  thumb  ov021
 */

typedef unsigned int u32;

extern int FIELD_PLAYER_GRID_GetDirChangeKind(u32 *p, int a);
typedef unsigned char  u8;
extern int FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(u8 *a, u32 b, int c);

int FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(u8 *a, u32 b, u32 flags)
{
    int r = 0;
    int h = FIELD_PLAYER_GRID_GetDirChangeKind((u32 *)a, b);

    if (flags & 1)
        r = FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(a, b, h);
    return r;
}
