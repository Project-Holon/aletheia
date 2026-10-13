/*
 * function: BSUBWAY_RECORD_LIST_StateFadeIn
 * address: 0x021B9E5C
 * packet: pkt_ov069_021B9E5C
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj20656.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);
int BSUBWAY_RECORD_LIST_StateFadeIn(u8 *p) { if (WIPE_SYS_EndCheck()) ((struct Obj20656 *)p)->f158=1; return 1; }
