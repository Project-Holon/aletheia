/*
 * function: FIELD_GIMMICK_D06_FindPanelTable
 * address: 0x021F36F8
 * packet: pkt_ov051_021F36F8
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGimmickD06PanelTable 0x021F3DFC data a4
 */

typedef struct { int id; int n; int *ptr; } Entry;
extern const Entry gGimmickD06PanelTable[];
const Entry *FIELD_GIMMICK_D06_FindPanelTable(int id) { unsigned int i; const Entry *p=gGimmickD06PanelTable; for(i=0;i<3;i++,p++) if(p->id==id) return p; return gGimmickD06PanelTable; }
