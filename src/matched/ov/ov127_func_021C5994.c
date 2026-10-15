/*
 * unit: yes
 * function: WF2DMAP_OBJDRAW_SetPosFromOwner, WF2DMAP_OBJDRAW_ClearPos
 * address: 0x021C5994
 * packet: pkt_ov127_021C5994
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetCurrentPos 0x021C4ADC thumb ov127
 *   WF2DMAP_SCRDRAW_SetPoint 0x021C59DC thumb ov127
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef signed short s16;
typedef struct { s16 x, y; } Pos;
extern Pos WF2DMAP_OBJ_GetCurrentPos(void *);
extern void WF2DMAP_SCRDRAW_SetPoint(s16 *p, s16 a, s16 b);
extern void MI_CpuFill8(void *, int, int);
void WF2DMAP_OBJDRAW_SetPosFromOwner(void *p, void *q)
{
    Pos v = WF2DMAP_OBJ_GetCurrentPos(q);
    WF2DMAP_SCRDRAW_SetPoint(p, v.y - 96, v.x - 112);
}
void WF2DMAP_OBJDRAW_ClearPos(void *p) { MI_CpuFill8(p, 0, 4); }
