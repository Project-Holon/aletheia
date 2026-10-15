/*
 * function: WF2DMAP_OBJCMD_StartCmd0
 * address: 0x021C4CE4
 * packet: pkt_ov127_021C4CE4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: next larger wrapper starts at 0x021C4D34, its initial push
 *         is included by the stale label extent; filed separately.
 * symbols:
 *   WF2DMAP_OBJ_SetPos 0x021C4B7C thumb ov127
 *   WF2DMAP_OBJ_SetDestPos 0x021C4B90 thumb ov127
 *   WF2DMAP_OBJ_SetSlot 0x021C4A00 thumb ov127
 */
typedef unsigned short u16;
struct pair { u16 a, b; };
extern void WF2DMAP_OBJ_SetPos(char *, struct pair);
extern void WF2DMAP_OBJ_SetDestPos(char *, struct pair);
extern void WF2DMAP_OBJ_SetSlot(void *, int, int);
void WF2DMAP_OBJCMD_StartCmd0(char *p, struct pair v, int n)
{
    WF2DMAP_OBJ_SetPos(p, v);
    WF2DMAP_OBJ_SetDestPos(p, v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 0);
}
