/*
 * function: WIFICLUB_StateViolationListKey
 * address:  0x021BCDB0
 * packet:   pkt_ov099_021BCDB0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_DeleteRuleWindow  0x021BC06C  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 *   WIFICLUB_CheckSavedRegulation  0x021BCBBC  thumb  ov099
 *   WIFICLUB_ShowRuleWindow  0x021BBEB4  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void WIFICLUB_DeleteRuleWindow(char *p);
extern int WIFICLUB_CheckSavedRegulation(int a, int b, int *out);
struct O;
extern void WIFICLUB_ShowRuleWindow(struct O *p, int mask, u32 a, int mode);

int WIFICLUB_StateViolationListKey(char *p, int v)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(p);
        if (*(int *)(p + 0xCC) != 0) {
            int out;
            WIFICLUB_CheckSavedRegulation(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out);
            WIFICLUB_ShowRuleWindow((struct O *)p, out, *(u8 *)(*(char **)(p + 0x248) + 0x48), 3);
            *(int *)(p + 0x1CC) = 0x78;
        } else {
            switch (*(int *)(p + 0x135C)) {
            case 3:
                *(int *)(p + 0x1CC) = 0x4E;
                break;
            case 2:
                *(u8 *)(p + 0x1353) = 0x97;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            case 4:
                *(u8 *)(p + 0x1353) = 0x90;
                *(int *)(p + 0x1CC) = 0x8A;
                break;
            default:
                *(int *)(p + 0x1CC) = 0x72;
                break;
            }
        }
    }
    return v;
}
