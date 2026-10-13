/*
 * function: func_021BF03C
 * address:  0x021BF03C
 * packet:   pkt_021BF03C
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *
 * True when GFL_NET_STATE_GetWifiState() reports 1: `push {r3, lr}; blx; cmp r0, #1; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * Now EXACT*.  0x0203C3EC was matched in arm9 (src/matched/GFL_NET_STATE_GetWifiState.c,
 * shard pkt_0203C3EC), so `attest_matched` resolves the BLX field; all 18
 * compiled bytes agree.  The inferred extent ran to 20 because the next
 * function (0x021BF04E) has no func_ label.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BF03C.c \
 *       --func func_021BF03C --addr 0x021BF03C --region ov099 --thumb --cc 1.1p1
 */

typedef unsigned long u32;
typedef int BOOL;

extern int GFL_NET_STATE_GetWifiState(void);

BOOL func_021BF03C(char *a0)
{
    if (GFL_NET_STATE_GetWifiState() == 1) {
        return 1;
    }

    return 0;
}
