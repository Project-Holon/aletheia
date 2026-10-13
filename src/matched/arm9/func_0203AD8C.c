/*
 * function: GFL_NET_STATE_InitWork
 * address:  0x0203AD8C
 * packet:   pkt_0203AD8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   func_02030734  0x02030734  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_COMMAND_Init  0x0203A494  arm
 *   GFL_NET_STATE_InitRandom  0x0203AE20  arm
 *
 * One-shot constructor: the singleton must still be NULL (otherwise
 * func_02034714(__FILE__, 0xb8, __FILE__)), 0x64 bytes are allocated with
 * the debug allocator, a halfword 0x32 and a byte 1 are set at +0x46 and
 * +0x4c, the embedded object at +0xc is initialised, and the 5-argument
 * delegate GFL_NET_COMMAND_Init is called with four zeros.
 *
 * The fields are written through the global every time -- the second and
 * third uses reload `[r1]` (`ldr r0, [r1]` twice after the store) while the
 * first reuses the allocator's return value in r0 -- which is what
 * `_pNetState->f46 = ...` spells and what a local pointer would not.
 *
 * Parked at MATCH, blocking class: label.  The only unresolved relocation is
 * the call at +0x68
 *   +0068 PC24 GFL_NET_STATE_InitRandom -> unresolved: 0203AE20 (arm, from header) has
 *                                            no witness outside
 *                                            0203AD8C..0203AE20
 * -- the callee 0x0203AE20 sits at the very end of this function's listing
 * extent and this call is its only branch anywhere in the image, so the
 * `label` class has no outside witness.  It graduates for free, with no
 * change to this C, as soon as src/matched/ holds a GFL_NET_STATE_InitRandom entry:
 * the `matched` class then witnesses the site.  GFL_NET_STATE_InitRandom itself is
 * chain-capped on 0x0203F0A8 (see docs/notes/func_0203F0A8.c.txt), which is
 * why the pair is parked rather than finished here.
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Sys *_pNetState;
extern char g_020A7BA8[];
extern char g_020A7BB4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void  GFL_NET_COMMAND_Init(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void  GFL_NET_STATE_InitRandom(u8 *p);

void GFL_NET_STATE_InitWork(u32 a0)
{
    if (((u8 *)_pNetState) != 0) {
        func_02034714(g_020A7BA8, 0xb8, g_020A7BB4);
    }
    _pNetState = (struct Sys *)((u8 *)func_02030734(a0, 0x64, 1, g_020A7BA8, 0xb9));
    *(u16 *)(((u8 *)_pNetState) + 0x46) = 0x32;
    *(u8 *)(((u8 *)_pNetState) + 0x4c) = 1;
    GFL_NET_STATE_InitRandom(((u8 *)_pNetState) + 0xc);
    GFL_NET_COMMAND_Init(0, 0, 0, 0, a0);
}
