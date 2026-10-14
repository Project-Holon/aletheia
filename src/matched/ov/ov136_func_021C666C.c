/*
 * function: MB_SEQ_DeleteActor
 * address:  0x021C666C
 * packet:   pkt_021C666C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void MB_SEQ_DeleteActor(u8 *p, int i)
{
    if (*(u32 *)(p + 0x1f0 + i * 4)) {
        CLACT_DeleteActor(*(void **)(p + 0x1f0 + i * 4));
        *(u32 *)(p + 0x1f0 + i * 4) = 0;
    }
}
