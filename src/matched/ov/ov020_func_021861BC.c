/*
 * function: FIELD_WFBC_DATA_LOCAL_IsFullyPopulated
 * address: 0x021861BC
 * packet: pkt_ov020_021861BC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryAllowed 0x02161E84 thumb ov010
 */
extern int EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(char *);
int FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(unsigned short *p) { char *q; int i; if(p[0]==1 && p[1]>=2) return 0; q=(char *)p; i=0; q+=8; for(;i<10;i++) if(EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(q+i*0x18)==0) return 0; return 1; }
