/*
 * function: WF2DMAP_OBJCMD_StartCmd10
 * address: 0x021C5164
 * packet: pkt_ov127_021C5164
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * start: corrected from second label at initial push plus two bytes.
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
void WF2DMAP_OBJCMD_StartCmd10(char *p, struct pair v, int n)
{
    WF2DMAP_OBJ_SetDestPos(p, v);
    WF2DMAP_OBJ_SetPos(p, v);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 10);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 8);
}
