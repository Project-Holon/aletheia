/*
 * function: IRCBATTLEMATCH_RecvModeHandler
 * address: 0x021B9888
 * packet: pkt_ov100_021B9888
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
void IRCBATTLEMATCH_RecvModeHandler(unsigned a,int b,int *c,unsigned d,void *e)
{
 if(e==GFL_NET_HANDLE_GetCurrentHandle()) *(int *)(d+a*4+0x250)=*c;
}
