/*
 * function: ZKNSEARCH_MAIN_InitBlinkPalette
 * address:  0x021BC9D0
 * packet:   pkt_021BC9D0
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14671.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CodeIn;
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void ARC_TOOL_DeleteHandle(void *);

void ZKNSEARCH_MAIN_InitBlinkPalette(int p)
{
    void *h = func_020490F4(0x9f, 0x807b);

    ((struct Obj14671 *)p)->f2B4 = (int)BLINK_PALANM_Create(0x30, 0x10, 1, 0x7b);
    BLINK_PALANM_LoadPalettes((struct CodeIn *)(((struct Obj14671 *)p)->f2B4), h, 0x49, 0x20, 0x30);
    ARC_TOOL_DeleteHandle(h);
}
