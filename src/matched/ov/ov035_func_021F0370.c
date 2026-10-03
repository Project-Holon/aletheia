/*
 * function: func_021F0370
 * address:  0x021F0370
 * packet:   pkt_ov035_021F0370
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf of func_021F0468 (reads the menu handle at +0x44).
 *
 * symbols:
 *   func_021F0370 0x021F0370 thumb
 *   func_020279E8 0x020279E8 thumb
 */

typedef unsigned int u32;

struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);

u32 func_021F0370(char *p)
{
    return func_020279E8(*(void **)(p + 0x44));
}
