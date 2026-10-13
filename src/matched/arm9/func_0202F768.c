/*
 * function: func_0202F768
 * address:  0x0202F768
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
 * time_icon.c.  An unlabelled tail-call leaf (it saves nothing, so
 * disasm.py prints it as .word data): func_0202F788(0).  With
 * func_0202F774 it is the callback pair GFL_USE_InitSystem (gfl_use.c boot)
 * hands to BACKUP_SYSTEM_Init(7, ...).  Filed apart from func_0202F774 on
 * purpose: the only pool words naming 0x0202F789 that are outside a
 * two-function range are each other's, so as one unit neither site has a
 * witness (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * Seed 0x0202F768 in layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F768.c \
 *       --func func_0202F768 --addr 0x0202F768 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_0202F788(u32 mode);

void func_0202F768(void)
{
    func_0202F788(0);
}
