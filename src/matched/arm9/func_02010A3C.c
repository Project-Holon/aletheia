/*
 * function: GFL_NET_SAVE_StepFinish
 * address:  0x02010A3C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepFinish.c \
 *       --func GFL_NET_SAVE_StepFinish --addr 0x02010A3C --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);

void GFL_NET_SAVE_StepFinish(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8) != 0) {
        GFL_NET_SAVE_SetStep(p, 0);
    }
}
