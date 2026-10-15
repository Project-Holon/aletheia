/*
 * function: WIFICLUBACTOR_ShowMarkerAtActor
 * address:  0x021B989C
 * packet:   pkt_ov099_021B989C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJ_GetPos  0x021C4AC4  thumb  ov127
 *   WF2DMAP_OBJDRAW_GetActorValue2  0x021C5858  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorValue2  0x021C584C  thumb  ov127
 *   WIFICLUBACTOR_ShowMarker  0x021B9F90  thumb
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    void *f0;
    void *f4;
} Rec;

extern Pos WF2DMAP_OBJ_GetPos(void *v);
typedef unsigned char  u8;
extern int WF2DMAP_OBJDRAW_GetActorValue2(u8 *p);
extern void WF2DMAP_OBJDRAW_SetActorValue2(u8 *p, int a);
extern void WIFICLUBACTOR_ShowMarker(void *o, Pos pos, int c);

void WIFICLUBACTOR_ShowMarkerAtActor(void *o, Rec *r)
{
    Pos p = WF2DMAP_OBJ_GetPos(r->f0);

    WIFICLUBACTOR_ShowMarker(o, p, WF2DMAP_OBJDRAW_GetActorValue2(r->f4) - 2);
    WF2DMAP_OBJDRAW_SetActorValue2(r->f4, 0);
}
