/*
 * function: POKEGRA_RegisterCellAnim
 * address:  0x0202D898
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds a record out of an argument struct passed by value in the caller's
 * frame: both cursors come from func_02027710/func_02027714 on the same +8
 * word, the handle from func_020490F4 keyed on the +0x10 halfword with the
 * mode word from func_020275E4, and CLACT_RegisterCellAnim assembles the pair into
 * it; the handle is released before the assembled record is returned.
 *
 * The `volatile` on the by-value struct parameter is load-bearing, not
 * decoration: without it this front end proves the two callees cannot touch
 * the caller's frame, keeps args.w2 live in r5 across the first call and
 * drops the second `ldr r0,[sp,#0x20]`, and it also hoists the `ldrh` of
 * args.key above the inline func_020275E4() call. Qualifying the whole
 * parameter (rather than aliasing it through a volatile pointer, which
 * turns the two w2 loads into `[r5,#8]` and loses the `add r7,sp,#0x18`)
 * reproduces the reload, the argument scheduling and both `ldrh`s exactly.
 * See docs/notes/POKEGRA_RegisterCellAnim.c.txt for the DIFF this replaces.
 *
 * EXACT* only: the follower at 0x0202D8D0 is unlabelled, so the inferred
 * extent runs 2 bytes long over the alignment halfword. Never a byte
 * difference.
 * symbols:
 *   func_02027710   0x02027710  thumb
 *   func_02027714   0x02027714  thumb
 *   func_020275E4   0x020275E4  thumb
 *   func_020490F4   0x020490F4  arm
 *   CLACT_RegisterCellAnim   0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle   0x02049238  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct Args { u32 w0; u32 w1; u32 w2; u32 w3; u16 key; u16 pad; };

typedef signed int     s32;
extern int func_02027710(int a);
extern int func_02027714(int a);
extern u32   func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void  ARC_TOOL_DeleteHandle(void *h);

u32 POKEGRA_RegisterCellAnim(u32 a0, u32 a1, u32 a2, u32 a3, volatile struct Args args)
{
    u32 p;
    u32 q;
    void *h;
    u32 r;

    p = func_02027710(args.w2);
    q = func_02027714(args.w2);
    h = func_020490F4(func_020275E4(), args.key);
    r = CLACT_RegisterCellAnim(h, p, q, args.key);
    ARC_TOOL_DeleteHandle(h);
    return r;
}
