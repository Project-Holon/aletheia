/*
 * function: WF2DMAP_OBJ_UpdateList
 * address: 0x021C48E8
 * packet: pkt_ov127_021C48E8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetCount 0x021C4914 thumb ov127
 *   WF2DMAP_OBJ_GetByIndex 0x021C4980 thumb ov127
 *   WF2DMAP_OBJCMD_Update 0x021C4CB4 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 WF2DMAP_OBJ_GetCount(u8 *);
extern char *WF2DMAP_OBJ_GetByIndex(char **p, int i);
extern void WF2DMAP_OBJCMD_Update(u8 *p);
void WF2DMAP_OBJ_UpdateList(u8 *p) { u32 i,n; char *q; n=WF2DMAP_OBJ_GetCount(p);for(i=0;i<n;i++){q=WF2DMAP_OBJ_GetByIndex((char **)p,(u16)i);if(q)WF2DMAP_OBJCMD_Update((u8 *)q);} }
