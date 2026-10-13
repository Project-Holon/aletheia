/*
 * function: IRC_COMPATIBLE_HandleHelp
 * address: 0x021B6BA8
 * packet: pkt_ov101_021B6BA8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_StepRunnerRun 0x021B6C20 thumb ov101
 *   IRC_COMPATIBLE_SetHandler 0x021B6A3C thumb ov101
 *   IRC_COMPATIBLE_HandleMenu 0x021B6A7C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int IRC_COMPATIBLE_StepRunnerRun(int *,int,int,int);
extern void IRC_COMPATIBLE_SetHandler(u8 *,u32);
extern void IRC_COMPATIBLE_HandleMenu(u8 *,u16 *);
void IRC_COMPATIBLE_HandleHelp(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(IRC_COMPATIBLE_StepRunnerRun((int *)(p+4),4,58,(int)p)) *state=2; break; case 2: IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleMenu); break; } }
