/*
 * function: MONOLITH_TOOL_LIST_FreeEntryBitmaps
 * address: 0x021B9A18
 * packet: pkt_ov071_021B9A18
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_Delete 0x020437AC arm
 */
#include "../include/Obj20755.h"

typedef unsigned char u8;
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
void MONOLITH_TOOL_LIST_FreeEntryBitmaps(char *p) { int i; for (i = 0; i < ((struct Obj20755 *)p)->f27C; i++) BMP_Delete(*(void **)(p + i * 4 + 0x24)); }
