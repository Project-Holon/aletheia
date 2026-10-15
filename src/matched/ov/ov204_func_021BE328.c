/*
 * function: INTRO_CMD_CmdFade
 * address: 0x021BE328
 * packet: pkt_ov204_021BE328
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
int INTRO_CMD_CmdFade(char *p,int *state,int *q){switch(*state){case 0:FADE_Start(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(FADE_IsActive()==0)return 1;break;}return 0;}
