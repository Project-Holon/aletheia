/*
 * function: GIMMICK51_Init
 * address: 0x021F36C0
 * packet: pkt_ov051_021F36C0
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGimmickD06StoneTable 0x021F3DB4 data a4
 */

typedef struct { int id; int n; int *ptr; } Entry;
extern const Entry gGimmickD06StoneTable[];
const Entry *GIMMICK51_Init(int id) { unsigned int i; const Entry *p=gGimmickD06StoneTable; for(i=0;i<3;i++,p++) if(p->id==id) return p; return gGimmickD06StoneTable; }
