/*
 * function: BTLV_EFFECT_AddPokeSprite
 * address:  0x021F7F58
 * packet:   pkt_ov094_021F7F58
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094  a4
 *   d_02209D0C     0x02209D0C  data   ov094  a1
 *   BTLV_EFFECT_IsRecordEnabledInComm  0x021F88F4  thumb  ov094
 *   BTLV_MCSS_AddTrainer  0x021FF088  thumb  ov094
 *   BTLV_MCSS_SetPosition  0x021FF144  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern char *gBtlvEff;
extern u8 d_02209D0C[];
extern int BTLV_EFFECT_IsRecordEnabledInComm(void);
extern void BTLV_MCSS_AddTrainer(u32 obj, int a, u32 b);
extern void BTLV_MCSS_SetPosition(u32 obj, u32 b, u32 c, u32 d, u32 e);

void BTLV_EFFECT_AddPokeSprite(int a, u32 b, u32 c, u32 d, u32 e)
{
    if (!(b & 1)) {
        switch (a) {
        case 0:
        case 1:
            if (BTLV_EFFECT_IsRecordEnabledInComm())
                a += 4;
            break;
        case 0x3D:
            a = 2;
            break;
        case 0x25:
            a = 3;
            break;
        default:
            if (d_02209D0C[a] == 0)
                a = 0;
            else
                a = 1;
            break;
        }
    } else {
        switch (a) {
        case 0:
        case 1:
            if (BTLV_EFFECT_IsRecordEnabledInComm())
                a += 0x67;
            break;
        }
    }
    BTLV_MCSS_AddTrainer(*(u32 *)(gBtlvEff + 0x190), a, b);
    if (c != 0 || d != 0 || e != 0)
        BTLV_MCSS_SetPosition(*(u32 *)(gBtlvEff + 0x190), b, c, d, e);
    *(u32 *)(gBtlvEff + (b - 8) * 4 + 0x1F8) = b;
}
