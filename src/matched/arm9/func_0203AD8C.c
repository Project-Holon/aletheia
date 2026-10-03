/*
 * function: func_0203AD8C
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
 *   g_021469DC     0x021469DC  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   func_02030734  0x02030734  arm
 *   func_02034714  0x02034714  arm
 *   func_0203A494  0x0203A494  arm
 *   func_0203AE20  0x0203AE20  arm
 *
 * One-shot constructor: the singleton must still be NULL (otherwise
 * func_02034714(__FILE__, 0xb8, __FILE__)), 0x64 bytes are allocated with
 * the debug allocator, a halfword 0x32 and a byte 1 are set at +0x46 and
 * +0x4c, the embedded object at +0xc is initialised, and the 5-argument
 * delegate func_0203A494 is called with four zeros.
 *
 * The fields are written through the global every time -- the second and
 * third uses reload `[r1]` (`ldr r0, [r1]` twice after the store) while the
 * first reuses the allocator's return value in r0 -- which is what
 * `g_021469DC->f46 = ...` spells and what a local pointer would not.
 *
 * Parked at MATCH, blocking class: label.  The only unresolved relocation is
 * the call at +0x68
 *   +0068 PC24 func_0203AE20 -> unresolved: 0203AE20 (arm, from header) has
 *                                            no witness outside
 *                                            0203AD8C..0203AE20
 * -- the callee 0x0203AE20 sits at the very end of this function's listing
 * extent and this call is its only branch anywhere in the image, so the
 * `label` class has no outside witness.  It graduates for free, with no
 * change to this C, as soon as src/matched/ holds a func_0203AE20 entry:
 * the `matched` class then witnesses the site.  func_0203AE20 itself is
 * chain-capped on 0x0203F0A8 (see docs/notes/func_0203F0A8.c.txt), which is
 * why the pair is parked rather than finished here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8  *g_021469DC;
extern char g_020A7BA8[];
extern char g_020A7BB4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void  func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void  func_0203AE20(u8 *p);

void func_0203AD8C(u32 a0)
{
    if (g_021469DC != 0) {
        func_02034714(g_020A7BA8, 0xb8, g_020A7BB4);
    }
    g_021469DC = (u8 *)func_02030734(a0, 0x64, 1, g_020A7BA8, 0xb9);
    *(u16 *)(g_021469DC + 0x46) = 0x32;
    *(u8 *)(g_021469DC + 0x4c) = 1;
    func_0203AE20(g_021469DC + 0xc);
    func_0203A494(0, 0, 0, 0, a0);
}
