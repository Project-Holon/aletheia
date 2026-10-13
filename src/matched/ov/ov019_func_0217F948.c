/*
 * function: UNION_EFF_AddIcon
 * address: 0x0217F948
 * packet: pkt_ov019_0217F948
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_EFF_AddIconObj 0x0217FC08 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UNION_EFF_AddIconObj(char *p,u32 a,u32 b);
void UNION_EFF_AddIcon(char *p,u32 a,u32 b) { if(p) UNION_EFF_AddIconObj(p+0x20,a,b); }
