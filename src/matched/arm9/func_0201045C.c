/*
 * function: func_0201045C
 * address:  0x0201045C
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021461E0     0x021461E0  data
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * wih_dwc.c: append one 0xC0-byte record to the four-slot table at the head
 * of the object behind 0x021461E0, guarded on the capacity at +0x310 and the
 * fill index at +0x316.  The object is the one func_02010360 allocates
 * (0x328 bytes) and stores into the global; func_02010360 also hands this
 * function's address (pool word 0x0201045D) to the ov014 setter 0x0217963C,
 * so it is a receive callback.
 *
 * The closing fact was the callee: 0x02082D44 is MI_CpuCopy8(src, dest,
 * size) (layout/symbols_sdk.txt), so the call takes THREE arguments and the
 * `movs r2, #0xc0` is the size argument shared with the index multiply.
 * With a two-argument prototype (docs/notes/unit_0201045C.c.txt) the
 * compiler folds the index copy `adds r3, r6, #0` away and the index lands
 * in a scratch register; with r2 pinned to the size, the product needs its
 * own register and the copy reappears.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201045C.c \
 *       --func func_0201045C --addr 0x0201045C --thumb
 */
#include "../include/Obj05697.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021461E0;
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void func_0201045C(const void *src)
{
    u8 *o = g_021461E0;

    if (((struct Obj05697 *)o)->f310 != 0 && ((struct Obj05697 *)o)->f316 < ((struct Obj05697 *)o)->f310 && ((struct Obj05697 *)o)->f316 < 4) {
        MI_CpuCopy8(src, o + ((struct Obj05697 *)o)->f316 * 0xC0, 0xC0);
        *(u16 *)(g_021461E0 + 0x316) = *(u16 *)(g_021461E0 + 0x316) + 1;
    }
}
