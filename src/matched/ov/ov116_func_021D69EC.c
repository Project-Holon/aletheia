/*
 * function: func_021D69EC
 * address: 0x021D69EC
 * packet: pkt_ov116_021D69EC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DPW_BT_DownloadPlayerAsync 0x021C94A0 arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 */
#include "../include/Obj10337.h"
extern void DPW_BT_DownloadPlayerAsync(unsigned x, unsigned y, unsigned z);
extern void func_021D70E4(unsigned char *);
void func_021D69EC(unsigned char *a,unsigned char *b,unsigned short c) { ((struct Obj10337 *)a)->fA=c; DPW_BT_DownloadPlayerAsync((unsigned char)(((struct Obj10337 *)a)->f8),(unsigned char)(((struct Obj10337 *)a)->fA),(unsigned int)(a+14)); func_021D70E4(b); }
