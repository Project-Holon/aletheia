/*
 * function: WF2DMAP_OBJCMD_Restart
 * address: 0x021C5334
 * packet: pkt_ov127_021C5334
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetPos 0x021C4AC4 thumb ov127
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJCMD_StartCmd0 0x021C4CE4 thumb ov127
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct pair {u16 a,b;};
extern struct pair WF2DMAP_OBJ_GetPos(char *);
extern int WF2DMAP_OBJ_GetSlot(u8 *,unsigned);
extern void WF2DMAP_OBJCMD_StartCmd0(char *,struct pair,int);
void WF2DMAP_OBJCMD_Restart(char *p) { struct pair v=WF2DMAP_OBJ_GetPos(p); WF2DMAP_OBJCMD_StartCmd0(p,v,WF2DMAP_OBJ_GetSlot((u8 *)p,6)); }
