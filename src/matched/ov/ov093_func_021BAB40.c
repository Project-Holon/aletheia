/*
 * function: BTL_SERVER_Restart
 * address: 0x021BAB40
 * packet: pkt_ov093_021BAB40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_SetHandler 0x021BABEC thumb ov093
 *   BTL_SERVER_StepStart 0x021BAC04 thumb ov093
 *   BTL_SERVER_ResetClientCommands 0x021BB7FC thumb ov093
 *   BTL_SERVER_FLOW_Reset 0x021BB9D0 thumb ov093
 */
#include "../include/Obj21025.h"

extern void BTL_SERVER_SetHandler(int *p, void *f);
typedef unsigned char  u8;
extern int BTL_SERVER_StepStart(char *p, int *st);
extern void BTL_SERVER_ResetClientCommands(const u8 *p);
extern void BTL_SERVER_FLOW_Reset(u8 *p);
void BTL_SERVER_Restart(char *p)
{
 BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepStart);
 BTL_SERVER_ResetClientCommands((const u8 *)p);
 BTL_SERVER_FLOW_Reset(((struct Obj21025 *)p)->f44);
}
