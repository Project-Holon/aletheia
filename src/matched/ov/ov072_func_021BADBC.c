/*
 * function: func_021BADBC
 * address: 0x021BADBC
 * packet: pkt_ov072_021BADBC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
extern void func_0204B3DC(int obj, int v);
extern void func_0204B878(int obj, int v);
void func_021BADBC(char *p, int v) { *(u8 *)(p+50)=v; if(*(u8 *)(p+50)!=255) { if(*(int *)p) { func_0204B3DC(*(int *)p,1); func_0204B878(*(int *)p,*(u8 *)(p+50)); } } else { if(*(int *)p) func_0204B3DC(*(int *)p,0); } }
