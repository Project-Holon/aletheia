/*
 * function: BTL_SERVER_CMD_WriteU8
 * address: 0x021CCAA8
 * packet: pkt_ov093_021CCAA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlEmptyString 0x021F3A84 data
 *   func_02034714 0x02034714 arm
 */
typedef unsigned char u8; typedef unsigned int u32;
typedef struct { u32 wpos,rpos; u8 buf[3000]; } Buf;
extern char gBtlEmptyString[];
extern void func_02034714(const char *expr, u32 line, const char *file);
void BTL_SERVER_CMD_WriteU8(Buf *p,int v) {if(p->wpos>=3000)func_02034714(gBtlEmptyString,0,gBtlEmptyString);p->buf[p->wpos++]=v;}
