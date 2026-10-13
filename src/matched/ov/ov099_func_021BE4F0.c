/*
 * function: WIFICLUB_BeginIdle
 * address:  0x021BE4F0
 * packet:   pkt_ov099_021BE4F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIFICLUB_SetStatusSeatFlag  0x021C27E8  thumb  ov099
 *   WIFICLUB_SetStatusModeFlag  0x021C2864  thumb  ov099
 *   WIFICLUB_DisableVoiceChat  0x021C0C7C  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void WIFICLUB_SetStatusSeatFlag(void *, u8);
extern void WIFICLUB_SetStatusModeFlag(void *, u8);
extern void WIFICLUB_DisableVoiceChat(void);

int WIFICLUB_BeginIdle(char *p, int v)
{
    if (v != 0)
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x21);
    WIFICLUB_SetStatusSeatFlag(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    WIFICLUB_SetStatusModeFlag(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    WIFICLUB_DisableVoiceChat();
    return 9;
}
