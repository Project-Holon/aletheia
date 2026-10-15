/*
 * function: WF2DMAP_OBJCMD_Dispatch
 * address: 0x021C5370
 * packet: pkt_ov127_021C5370
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_FindById2 0x021C4994 thumb ov127
 *   sWf2dmapSpawnCmdTable 0x021C607C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int (*Callback)(void *,void *,void *,const u8 *,void *);
extern const Callback sWf2dmapSpawnCmdTable[];
extern char *WF2DMAP_OBJ_FindById2(unsigned *p, unsigned id);
int WF2DMAP_OBJCMD_Dispatch(void *a, void *b, const u8 *desc, int *out) { return sWf2dmapSpawnCmdTable[*(u16 *)desc](WF2DMAP_OBJ_FindById2(b,desc[3]),a,b,desc,out); }
