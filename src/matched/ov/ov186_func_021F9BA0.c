/*
 * function: BR_PROC_SYS_PopEntry
 * address: 0x021F9BA0
 * packet: pkt_ov186_021F9BA0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_PROC_SYS_InitEntry 0x021F9C84 thumb
 *   BR_PROC_SYS_ClearEntry 0x021F9CA4 thumb
 */
typedef unsigned int u32;
typedef struct { u32 words[4]; } Info;
extern void BR_PROC_SYS_InitEntry(char *p, int a, int b);
extern void BR_PROC_SYS_ClearEntry(void *);
void BR_PROC_SYS_PopEntry(unsigned *ctx)
{
    Info info;
    if (ctx[25] != 0) {
        ctx[25]--;
        if (ctx[25] != 0) {
            unsigned idx = (unsigned short)((unsigned *)((char *)ctx + 0x48))[ctx[25]];
            BR_PROC_SYS_InitEntry((char *)(&info), idx, (int)((char *)ctx[1] + idx * 20));
            *(Info *)((char *)ctx + 0x3c) = info;
        } else {
            BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
        }
    } else {
        BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
    }
}
