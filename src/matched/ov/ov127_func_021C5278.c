/*
 * unit: yes
 * function: WF2DMAP_OBJCMD_StepAdvanceSnap2, WF2DMAP_OBJCMD_StepNoop2, WF2DMAP_OBJCMD_StepAdvance2, WF2DMAP_OBJCMD_StepAdvance3
 * address: 0x021C5278
 * packet: pkt_ov127_021C5278
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJCMD_AdvanceTimer 0x021C5300 thumb ov127
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_SetDestPos 0x021C4B90 thumb ov127
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
typedef unsigned char  u8;
extern int WF2DMAP_OBJCMD_AdvanceTimer(u8 *p);
extern Pos WF2DMAP_OBJ_GetPos(void *);
extern void WF2DMAP_OBJ_SetDestPos(void *, Pos);
int WF2DMAP_OBJCMD_StepAdvanceSnap2(void *p)
{
    int r = WF2DMAP_OBJCMD_AdvanceTimer(p);
    if (r == 1) {
        Pos v = WF2DMAP_OBJ_GetPos(p);
        WF2DMAP_OBJ_SetDestPos(p, v);
    }
    return r;
}
int WF2DMAP_OBJCMD_StepNoop2(void) { return 0; }
int WF2DMAP_OBJCMD_StepAdvance2(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }
int WF2DMAP_OBJCMD_StepAdvance3(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }
