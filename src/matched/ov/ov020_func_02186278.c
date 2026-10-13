/*
 * function: FIELD_WFBC_DATA_LOCAL_CountPeople
 * address: 0x02186278
 * packet: pkt_ov020_02186278
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 */
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(char *);
int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p,int which) { char *q; int i; int count; if (which==0) q=p+8; else q=p+0xf8; count=0; for(i=0;i<10;i++) if(EVENT_FIELD_PROCLINK_IsReturnEntryValid(q+i*0x18)) count++; return count; }
