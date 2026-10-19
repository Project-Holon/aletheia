/*
 * function: MUSICAL_MCSS_ResumeRenderAnim
 * address: 0x021F539C
 * packet: pkt_ov112_021F539C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MUSICAL_MCSS_ResumeMCAnim 0x021F62A0 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_ResumeMCAnim(char *p);
void MUSICAL_MCSS_ResumeRenderAnim(void **p) {MUSICAL_MCSS_ResumeMCAnim(p[3]); if(p[4])MUSICAL_MCSS_ResumeMCAnim(p[4]); }
