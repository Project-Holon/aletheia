/*
 * function: BTL_CLIENT_StepThrowBall
 * address: 0x021D2FD8
 * packet: pkt_ov093_021D2FD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const on the read-only descriptor schedules c[1] before the
 * stack-argument store in the first arm.
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot 0x021B8E70 thumb ov093
 *   BTLV_EFFECT_StartEffectWithColor 0x021F7CFC thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTLV_EFFECT_StopLowHpBgmAndSuppress 0x021F883C thumb ov094
 *   gCatchShakeMessages 0x021EFF80 data a2
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTL_MAIN_NotifyCapture 0x021BA2D4 thumb ov093
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   BTLV_EFFECT_ResumeVm 0x021F7C0C thumb ov094
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BTL_MAIN_SetKeepBgm 0x021B92A0 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *, u32);
extern void BTLV_EFFECT_StartEffectWithColor(u32, u16, u8, int, int);
extern int BTLV_EFFECT_IsBusy(void);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct L;
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTLV_EFFECT_StopLowHpBgmAndSuppress(u32);
extern const u16 gCatchShakeMessages[];
struct H;
extern int BTLV_CORE_WaitMessage(u32 *p);
extern void BTL_MAIN_NotifyCapture(u32 p, u32 *q);
extern int GFL_USE_IsBgmPlaying(void);
extern void BTLV_EFFECT_ResumeVm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void BTL_MAIN_SetKeepBgm(u8 *p);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
int BTL_CLIENT_StepThrowBall(u32 *a, int *b, const u32 *c)
{
    switch (*b) {
    case 0:
        BTLV_EFFECT_StartEffectWithColor(BTL_MAIN_GetViewPosOfSlot((u8 *)a[0], (u8)c[0]), (u16)c[5], (u8)c[1], c[2], c[4]);
        (*b)++;
        break;
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            if (c[2]) {
                u8 *p = BTL_SIDE_GetPokeAtPos((char *const *)a[1], (u8)c[0]);
                BTLV_SCU_InitMessage((struct L *)((u8 *)a + 0x58), 1, 0x41);
                BTLV_SCU_AppendMessageArg((struct L *)((u8 *)a + 0x58), BTL_POKEPARAM_GetPokeId(p));
                BTLV_EFFECT_StopLowHpBgmAndSuppress(0x518);
            } else {
                int msg;
                if (c[1] < 4) msg = gCatchShakeMessages[c[1]];
                else msg = 0x3d;
                BTLV_SCU_InitMessage((struct L *)((u8 *)a + 0x58), 1, msg);
            }
            BTLV_CORE_BuildAndPrintMessage((char *)a[21], (struct H *)((u8 *)a + 0x58));
            (*b)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage((u32 *)a[21])) {
            if (c[2]) {
                BTL_MAIN_NotifyCapture((u32)((void *)a[0]), (u32 *)BTL_SIDE_GetPokeAtPos((char *const *)a[1], (u8)c[0]));
                (*b)++;
            } else return 1;
        }
        break;
    case 3:
        if (!GFL_USE_IsBgmPlaying()) {
            BTLV_EFFECT_ResumeVm();
            GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            BTL_MAIN_SetKeepBgm((u8 *)a[0]);
            if (c[3]) {
                u8 *p = BTL_SIDE_GetPokeAtPos((char *const *)a[1], (u8)c[0]);
                BTLV_SCU_InitMessage((struct L *)((u8 *)a + 0x58), 1, 0x42);
                BTLV_SCU_AppendMessageArg((struct L *)((u8 *)a + 0x58), BTL_POKEPARAM_GetPokeId(p));
                BTLV_CORE_BuildAndPrintMessage((char *)a[21], (struct H *)((u8 *)a + 0x58));
                (*b)++;
            } else return 1;
        }
        break;
    case 4:
        if (BTLV_CORE_WaitMessage((u32 *)a[21])) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}
