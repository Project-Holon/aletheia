/*
 * function: BSUBWAY_RECORD_LIST_Main
 * address: 0x021B9658
 * packet: pkt_ov069_021B9658
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding before next labelled function.
 * symbols:
 *   BSUBWAY_RECORD_LIST_RunInputState 0x021B9E44 thumb ov069
 *   BSUBWAY_RECORD_LIST_UpdateText 0x021B9DFC thumb ov069
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 */
#include "../include/Obj06172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern int BSUBWAY_RECORD_LIST_RunInputState(u8 *p);
extern void BSUBWAY_RECORD_LIST_UpdateText(u8 *p);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void CLACT_DrawSystem(void);
int BSUBWAY_RECORD_LIST_Main(u32 a,u32 b,u32 c,u8 *p) { if(BSUBWAY_RECORD_LIST_RunInputState(p)==0) return 1; BSUBWAY_RECORD_LIST_UpdateText(p); BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj06172 *)p)->f4); CLACT_DrawSystem(); return 0; }
