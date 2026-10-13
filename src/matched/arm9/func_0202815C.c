/*
 * function: APP_TASKMENU_WIN_DeleteNoClear
 * address:  0x0202815C
 * packet:   pkt_0202815C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x02028164, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   APP_TASKMENU_WIN_Free  0x02028164  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/APP_TASKMENU_WIN_DeleteNoClear.c \
 *       --func APP_TASKMENU_WIN_DeleteNoClear --addr 0x0202815C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void APP_TASKMENU_WIN_Free(u8 *p);

void APP_TASKMENU_WIN_DeleteNoClear(u8 *a0)
{
    APP_TASKMENU_WIN_Free(a0);
}
