/*
 * function: VCT_SESSION_CheckCommandAllowed
 * address: 0x021B29A4
 * packet: pkt_ov013_021B29A4
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: Calling the indexed inline in each table-selection arm restores the MLA register and independent -1/-2 constants.
 * checks: Per-arm inline lookup is EXACT; one data table in each arm preserves the original dispatch.
 * symbols:
 *   gVctSession 0x021B60D8 data ov013 a4
 *   gVctHostAllowTable 0x021B3B40 data ov013 a1
 *   gVctClientAllowTable 0x021B3B84 data ov013 a1

 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern int gVctSession[];
extern s8 gVctHostAllowTable[],gVctClientAllowTable[];
static inline s8 lookup(u32 t,int row,u32 col) { return *(s8 *)(row*11+t+col); }
int VCT_SESSION_CheckCommandAllowed(int *obj,const u8 *q) {
 u32 i; int v; u32 t;
 i=q[6]; if(q[4]==0)i+=5; if(i>=11)i=-1; if((int)i<0)return -1;
 if(gVctSession[4]==1) v=lookup((u32)gVctHostAllowTable,obj[3],i);
 else v=lookup((u32)gVctClientAllowTable,obj[3],i);
 if(v==-1)return 1; if(v==-2)return 0; obj[3]=v; return 1;
}
