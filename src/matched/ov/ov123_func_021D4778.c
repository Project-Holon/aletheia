/*
 * function: GSYNC_MENU_RunButtonCallback
 * address: 0x021D4778
 * packet: pkt_ov123_021D4778
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Callback Callback;
struct Callback { u32 first; int (*run)(void *,Callback *); };
void GSYNC_MENU_RunButtonCallback(void *p,int flag,Callback *q) { if(flag) return; if(!q->run) return; if(q->run(p,q)) return; }
