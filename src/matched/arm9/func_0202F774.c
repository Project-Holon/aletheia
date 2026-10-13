/*
 * function: func_0202F774
 * address:  0x0202F774
 * packet:   pkt_0202F768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202F788  0x0202F788  thumb
 *
 * time_icon.c.  The second unlabelled tail-call leaf of the callback pair
 * GFL_USE_InitSystem hands to BACKUP_SYSTEM_Init: a flag mapped to mode 2 (clear) or
 * 1 (set) for func_0202F788.  Filed apart from func_0202F768 so each pool
 * word witnesses the other (see that file).  Seed 0x0202F774.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F774.c \
 *       --func func_0202F774 --addr 0x0202F774 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_0202F788(u32 mode);

void func_0202F774(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    func_0202F788(mode);
}
