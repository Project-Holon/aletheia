/*
 * function: DWC_RAP_OnSendComplete
 * address:  0x02155D80
 * packet:   pkt_ov009_02155D80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, so disasm.py prints it as .word data); its
 * address is taken as a callback by DWC_RAP_StartFriendMatch / DWC_RAP_StartMatchWithKey.
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    char pad[0x760];
    int f760;           /* 0x760 */
    char pad1[0x784 - 0x764];
    int cnt[2];         /* 0x784 */
} G;

extern G *_pRapWork;

void DWC_RAP_OnSendComplete(int a, u32 i)
{
    if (i < 2) {
        _pRapWork->f760 = 0;
        _pRapWork->cnt[i] = 0;
    }
}
