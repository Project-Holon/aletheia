/*
 * function: IRCBATTLEMATCH_StepWipeEnd
 * address: 0x021B95D8
 * packet: pkt_ov100_021B95D8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
void IRCBATTLEMATCH_StepWipeEnd(u8 *p) { if(WIPE_SYS_EndCheck()) IRCBATTLEMATCH_SetStep(p,0); }
