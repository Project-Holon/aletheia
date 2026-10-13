/*
 * function: FIELD_WFBC_DATA_LOCAL_IsDataComplete
 * address: 0x0218625C
 * packet: pkt_ov020_0218625C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_IsFullyPopulated 0x021861BC thumb ov020
 */
extern int FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(unsigned short *);
int FIELD_WFBC_DATA_LOCAL_IsDataComplete(unsigned short *p) { if (p[0]==0) return 0; if (FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(p)!=0) return 1; return 0; }
