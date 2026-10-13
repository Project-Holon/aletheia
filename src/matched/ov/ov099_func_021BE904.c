/*
 * function: WIFICLUB_StateWaitIntroMessage
 * address:  0x021BE904
 * packet:   pkt_ov099_021BE904
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 */
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int WIFICLUB_DeleteWindow(void *p);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);

int WIFICLUB_StateWaitIntroMessage(char *p, int v)
{
    int n = *(int *)(p + 0x1E0);
    if (n > 0) {
        *(int *)(p + 0x1E0) = n - 1;
        return v;
    }
    if (KEY_GetTrg() & 3) {
        *(int *)(p + 0x19C) = WIFICLUB_DeleteWindow((void *)(*(int *)(p + 0x19C)));
        WIFICLUB_ShowStreamedMessage(p, 0x37, 0);
        *(int *)(p + 0x1CC) = 2;
    }
    return v;
}
