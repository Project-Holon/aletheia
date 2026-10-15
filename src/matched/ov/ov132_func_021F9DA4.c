/*
 * function: STA_ACTING_GetActor
 * address: 0x021F9DA4
 * packet: pkt_ov132_021F9DA4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned int u32;
void *STA_ACTING_GetActor(char *p,u32 i){return *(void **)((u32)p+4*i+0x44);}
