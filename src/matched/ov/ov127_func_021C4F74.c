/*
 * function: WF2DMAP_OBJCMD_StartCmd6
 * address: 0x021C4F74
 * packet: pkt_ov127_021C4F74
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * start: corrected from second label at initial push plus two bytes.
 * symbols:
 *   WF2DMAP_OBJ_SetPos 0x021C4B7C thumb ov127
 *   WF2DMAP_OBJ_SetDestPos 0x021C4B90 thumb ov127
 *   WF2DMAP_OBJ_SetSlot 0x021C4A00 thumb ov127
 *   WF2DMAP_OBJCMD_OffsetPos 0x021C52CC thumb ov127
 */
typedef unsigned short u16;
struct pair { u16 a, b; };
extern void WF2DMAP_OBJ_SetPos(char *, struct pair);
extern void WF2DMAP_OBJ_SetDestPos(char *, struct pair);
extern void WF2DMAP_OBJ_SetSlot(void *, int, int);
extern struct pair WF2DMAP_OBJCMD_OffsetPos(struct pair, int);
void WF2DMAP_OBJCMD_StartCmd6(char *p, struct pair v, int n)
{
    struct pair x = WF2DMAP_OBJCMD_OffsetPos(v, n);
    WF2DMAP_OBJ_SetDestPos(p, v);
    WF2DMAP_OBJ_SetPos(p, x);
    WF2DMAP_OBJ_SetSlot(p, 6, n);
    WF2DMAP_OBJ_SetSlot(p, 5, 6);
    WF2DMAP_OBJ_SetSlot(p, 8, 0);
    WF2DMAP_OBJ_SetSlot(p, 9, 16);
}
