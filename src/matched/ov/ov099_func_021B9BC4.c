/*
 * function: WIFICLUBACTOR_IsFacingEntrance
 * address:  0x021B9BC4
 * packet:   pkt_ov099_021B9BC4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJ_GetPos  0x021C4AC4  thumb  ov127
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   WF2DMAP_OBJ_OffsetPos  0x021C4A54  thumb  ov127
 *   WF2DMAP_MAP_GetCellValue  0x021C4864  thumb  ov127
 */
typedef unsigned short u16;
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work;

extern Pos WF2DMAP_OBJ_GetPos(void *v);
typedef unsigned char  u8;
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern Pos WF2DMAP_OBJ_OffsetPos(Pos p, int n);
typedef unsigned int   u32;
extern u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y);

int WIFICLUBACTOR_IsFacingEntrance(Work *w)
{
    Pos b;
    Pos d;
    int n;
    int r;

    b = WF2DMAP_OBJ_GetPos(*w->f570);
    n = WF2DMAP_OBJ_GetSlot(*w->f570, 6);
    d = WF2DMAP_OBJ_OffsetPos(b, n);
    r = WF2DMAP_MAP_GetCellValue(w->f588, d.x / 16, d.y / 16);
    if (n == 0 && r == 2)
        return 1;
    return 0;
}
