/*
 * function: BR_CODEIN_ProfileCreateOamObjects
 * address: 0x021E10F4
 * packet: pkt_ov183_021E10F4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_CODEIN_ProfileDeleteBgHandle 0x021E10DC thumb ov183
 *   BR_CODEIN_ProfilePrintOamObject 0x021E111C thumb ov183
 */
extern void BR_CODEIN_ProfileDeleteBgHandle(char *);
extern void BR_CODEIN_ProfilePrintOamObject(const void *,int,int,int,int);
void BR_CODEIN_ProfileCreateOamObjects(char *p){ BR_CODEIN_ProfileDeleteBgHandle(p);BR_CODEIN_ProfilePrintOamObject(p,0,32,8,0);BR_CODEIN_ProfilePrintOamObject(p,1,32,8,0); }
