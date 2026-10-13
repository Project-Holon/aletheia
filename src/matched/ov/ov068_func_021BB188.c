/*
 * function: OPTION_MENU_StateFadeOut
 * address: 0x021BB188
 * packet: pkt_ov068_021BB188
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   OPTION_MENU_FinishRunner 0x021BB140 thumb ov068
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void OPTION_MENU_FinishRunner(void *p);
void OPTION_MENU_StateFadeOut(void *p,u32 *state) { switch(*state) { case 0: FADE_Start(3,0,16,0); *state=1; break; case 1: if(FADE_IsActive()==0) *state=2; break; case 2: OPTION_MENU_FinishRunner(p); break; } }
