/*
 * function: DWC_RAP_AttemptCallback
 * address:  0x02155678
 * packet:   pkt_ov009_02155678
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
    char pad[0x7a5];
    u8 b7a5;
} G;

extern G *_pRapWork;

u8 DWC_RAP_AttemptCallback(void)
{
    return _pRapWork->b7a5;
}
