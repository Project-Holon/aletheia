/*
 * function: WF2DMAP_OBJCMD_IsTileOccupied
 * address: 0x021C54EC
 * packet: pkt_ov127_021C54EC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_OffsetPos 0x021C4A54 thumb ov127
 *   WF2DMAP_MAP_IsCellBlocked 0x021C4844 thumb ov127
 */
typedef unsigned short u16;
typedef struct { short x, y; } Pos;
extern Pos WF2DMAP_OBJ_GetPos(void *);
extern Pos WF2DMAP_OBJ_OffsetPos(Pos, int);
typedef unsigned char  u8;
extern int WF2DMAP_MAP_IsCellBlocked(u8 *p, u16 x, u16 y);
int WF2DMAP_OBJCMD_IsTileOccupied(void *p, void *q, int n)
{
    Pos b = WF2DMAP_OBJ_GetPos(p);
    Pos d = WF2DMAP_OBJ_OffsetPos(b, n);
    return WF2DMAP_MAP_IsCellBlocked(q, d.x / 16, d.y / 16);
}
