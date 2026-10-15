/*
 * function: WF2DMAP_SCRDRAW_UpdatePosition
 * address: 0x021C5A60
 * packet: pkt_ov127_021C5A60
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 0x0204B09C has no outside witness; the integrator owns it.
 * blocker: verified EXACT ARM leaf, 44 bytes (scratch blocker-r1.log):
 *   typedef unsigned char u8; typedef unsigned int u32; typedef signed short s16;
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { s16 x; s16 y; };
 *   void CLACT_SetSurfacePos(struct Owner *owner,u32 index,struct Pt *in) {
 *       int x=in->x; int y=in->y; struct Item *it=owner->items; struct Item *p;
 *       it[index].x=x<<12; p=&it[index]; p->y=y<<12;
 *   }
 * symbols:
 *   WF2DMAP_SCRDRAW_GetPointY 0x021C59E4 thumb ov127
 *   WF2DMAP_SCRDRAW_GetPointX 0x021C59EC thumb ov127
 *   WF2DMAP_SCRDRAW_SetScroll 0x021C5B0C thumb ov127
 *   CLACT_SetSurfacePos 0x0204B09C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern int WF2DMAP_SCRDRAW_GetPointY(const s16 *p);
extern int WF2DMAP_SCRDRAW_GetPointX(const s16 *p);
extern void CLACT_SetSurfacePos(void *,int,void *);
extern void WF2DMAP_SCRDRAW_SetScroll(char *p, int x, int y);
void WF2DMAP_SCRDRAW_UpdatePosition(char *p,void *q)
{
    int y,x;
    struct { s16 x,y; } pos;
    y=WF2DMAP_SCRDRAW_GetPointY(q);
    x=WF2DMAP_SCRDRAW_GetPointX(q);
    pos.x=x;
    pos.y=y;
    if(*(int *)(p+16)==0) CLACT_SetSurfacePos(*(void **)p,0,&pos);
    else { pos.y+=192; CLACT_SetSurfacePos(*(void **)p,1,&pos); }
    WF2DMAP_SCRDRAW_SetScroll(p,x,y);
}
