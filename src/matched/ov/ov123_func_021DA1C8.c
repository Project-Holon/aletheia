/*
 * function: PDWACC_STATE_StateWaitInput
 * address: 0x021DA1C8
 * packet: pkt_ov123_021DA1C8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PDWACC_STATE_StateFadeOutBgm 0x021DA054 thumb ov123
 *   PDWACC_STATE_ChangeState 0x021DA034 thumb ov123
 */
typedef unsigned char u8;
extern unsigned int KEY_GetTrg(void);
extern void PDWACC_STATE_StateFadeOutBgm(char *);
extern void PDWACC_STATE_ChangeState(char *,int,int);
void PDWACC_STATE_StateWaitInput(char *p) { if(KEY_GetTrg() & 3) PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StateFadeOutBgm,0x14b); }
