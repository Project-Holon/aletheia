/*
 * function: UNION_EFF_DeleteIcon
 * address: 0x0217F958
 * packet: pkt_ov019_0217F958
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UNION_EFF_DeleteIconObj 0x0217FCA4 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UNION_EFF_DeleteIconObj(u32 *p);
void UNION_EFF_DeleteIcon(char *p,u32 key) { char *base=p+0x20; int i; for(i=0;i<10;i++) { u32 value=*(u32 *)(base+i*20); if(value==key) { UNION_EFF_DeleteIconObj((u32 *)(base+i*20)); return; } } }
