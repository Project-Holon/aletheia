/*
 * function: BTL_CLIENT_CmdChangeForm
 * address:  0x021D35C8
 * packet:   pkt_ov093_021D35C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_ChangeForm  0x021D66D8  thumb  ov093
 *   BTLV_CORE_StartMonSpriteChange  0x021EA888  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteChange  0x021EA8A4  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_ChangeForm(u8 *m, u8 v);
extern void BTLV_CORE_StartMonSpriteChange(char *ctx, int a);
extern int BTLV_CORE_WaitMonSpriteChange(u32 *p);

int BTL_CLIENT_CmdChangeForm(u32 *a, int *b, u32 *c)
{
    int x;

    switch (*b) {
    case 0:
        x = BTL_MAIN_GetViewPosOfSlot((u8 *)a[0], BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], (u8)c[0]));
        BTL_POKEPARAM_ChangeForm(BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]), (u8)c[1]);
        BTLV_CORE_StartMonSpriteChange((char *)a[0x15], x);
        (*b)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteChange((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
