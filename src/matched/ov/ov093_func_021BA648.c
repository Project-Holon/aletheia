/*
 * function: BTL_MAIN_CopyClientParty
 * address: 0x021BA648
 * packet: pkt_ov093_021BA648
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetRelativeClientIndex 0x021BA710 thumb ov093
 *   POKEPARTY_Copy  0x0201AC2C  thumb  arm9
 */
#include "../include/Obj13286.h"

typedef unsigned char u8;
extern u8 BTL_MAIN_GetRelativeClientIndex(int, int);
struct Rec534;
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
void BTL_MAIN_CopyClientParty(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = BTL_MAIN_GetRelativeClientIndex(((struct Obj13286 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13286 *)p)->f0 + i * 4 + 0x24);
 if (q != 0) POKEPARTY_Copy(dst, q);
}
