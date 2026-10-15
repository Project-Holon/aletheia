/*
 * function: BR_PROC_SYS_FlushWindows
 * address:  0x021F9C6C
 * packet:   pkt_021F9C6C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_PROC_SYS_PopEntry  0x021F9BA0  thumb  ov186
 */

typedef struct {
    char pad_00[0x64];
    int  unk_64;
} S;

extern void BR_PROC_SYS_PopEntry(unsigned *ctx);

void BR_PROC_SYS_FlushWindows(S *p)
{
    while (p->unk_64 != 0)
        BR_PROC_SYS_PopEntry((unsigned int *)p);
}
