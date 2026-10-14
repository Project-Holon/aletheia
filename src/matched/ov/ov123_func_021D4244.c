/*
 * function: GSYNC_MENU_ChangeState
 * address: 0x021D4244
 * packet: pkt_ov123_021D4244
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MENU_SetStateFunc 0x021D4240 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_MENU_SetStateFunc(void **p, void *f);
void GSYNC_MENU_ChangeState(char *p,void *f,int line) { GSYNC_MENU_SetStateFunc((void **)p,f); }
