/*
 * function: WIFICLUBACTOR_IsCursorOnExit
 * address:  0x021B9FDC
 * packet:   pkt_ov099_021B9FDC
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
typedef unsigned int   u32;
extern u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y);

int WIFICLUBACTOR_IsCursorOnExit(Work *w)
{
    Pos b;
    int n;

    if (w->f570 == 0)
        return 0;
    b = WF2DMAP_OBJ_GetPos(*w->f570);
    n = WF2DMAP_OBJ_GetSlot(*w->f570, 6);
    if (WF2DMAP_MAP_GetCellValue(w->f588, b.x / 16, b.y / 16) == 15 && n == 1)
        return 1;
    return 0;
}
