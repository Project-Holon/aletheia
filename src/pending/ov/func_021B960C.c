/*
 * function: func_021B960C
 * address:  0x021B960C
 * packet:   pkt_021B960C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * near miss: logic byte-correct; compiles 44 vs 48.  The original spills the
 * *byte offset* i*4 to [sp] and reuses it across the 87FC call (ldr r1,[r5,r1]
 * then adds r0,r5,r0 / ldr [r0,#0x10]); 1.1p1 folds base+i*4 into a spilled
 * pointer and rematerialises the +4 index on the return path.  Same allocator
 * artefact family as func_021B8514 / func_021B9280.
 *
 * symbols:
 *   func_021B87FC  0x021B87FC  thumb
 * Addresses are Black-image addresses.
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
u8 *func_021B87FC(u8 *p, u32 idx);
/*
 * symbols:
 *   func_021B87FC  0x021B87FC  thumb  ov021
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
u8 *func_021B87FC(u8 *p, u32 idx);
u32 func_021B960C(u32 *p, u8 *v, u8 *q)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021B87FC(q, *(u32 *)((u8 *)p + i * 4)) == v)
            return *(u32 *)((u8 *)p + i * 4 + 0x10);
    }
    return 0;
}

