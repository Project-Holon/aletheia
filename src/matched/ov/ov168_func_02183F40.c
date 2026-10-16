/*
 * function: MICTEST_VBlank
 * address:  0x02183F40
 * packet:   pkt_02183F40
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NNS_GfdDoVramTransfer  0x02061C44  arm
 *   MICTEST_ActorVBlank  0x02184144  thumb  ov168
 *   MICTEST_UpdateBg  0x021842B4  thumb  ov168
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void NNS_GfdDoVramTransfer(void);
extern void MICTEST_ActorVBlank(void *p);
extern void MICTEST_UpdateBg(void *p);
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

void MICTEST_VBlank(void *unused, char *p)
{
    NNS_GfdDoVramTransfer();
    MICTEST_ActorVBlank(p);
    MICTEST_UpdateBg(p + 0xe4);
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}
