/*
 * unit: yes
 * function: WF2DMAP_OBJCMD_StartCmd11, WF2DMAP_OBJCMD_StepNoop, WF2DMAP_OBJCMD_StepAdvance
 * address: 0x021C51C8
 * packet: pkt_ov127_021C51C8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: handed 021C51CA is the second push after 0F B4 at 021C51C8.
 * symbols:
 *   WF2DMAP_OBJ_SetDestPos 0x021C4B90 thumb ov127
 *   WF2DMAP_OBJ_SetPos 0x021C4B7C thumb ov127
 *   WF2DMAP_OBJ_SetSlot 0x021C4A00 thumb ov127
 *   WF2DMAP_OBJCMD_AdvanceTimer 0x021C5300 thumb ov127
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
extern void WF2DMAP_OBJ_SetDestPos(void *, Pos);
extern void WF2DMAP_OBJ_SetPos(void *, Pos);
typedef unsigned char  u8;
extern void WF2DMAP_OBJ_SetSlot(void *p, int i, int v);
extern int WF2DMAP_OBJCMD_AdvanceTimer(u8 *p);
void WF2DMAP_OBJCMD_StartCmd11(void *p, Pos v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, v);
    WF2DMAP_OBJ_SetPos(p, v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 11);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 16);
}
int WF2DMAP_OBJCMD_StepNoop(void) { return 0; }
int WF2DMAP_OBJCMD_StepAdvance(void *p) { return WF2DMAP_OBJCMD_AdvanceTimer(p); }
