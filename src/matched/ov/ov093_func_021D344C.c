/*
 * function: BTL_CLIENT_StepClearIllusion
 * address:  0x021D344C
 * packet:   pkt_ov093_021D344C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_POKEPARAM_ClearIllusion  0x021D6C2C  thumb  ov093
 *   BTLV_CORE_StartMonSpriteLoad  0x021EA868  thumb  ov093
 *   BTLV_CORE_WaitMonSpriteLoad  0x021EA878  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
struct Unk021D6C2C;
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern void BTLV_CORE_StartMonSpriteLoad(u32 *p, u32 a2, u32 a3);
extern int BTLV_CORE_WaitMonSpriteLoad(u32 *p);

int BTL_CLIENT_StepClearIllusion(u32 *a, int *b, u32 *c)
{
    u32 u;
    int s;
    u8 *m;
    int f;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        s = BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], u);
        m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], u);
        f = BTL_CLIENT_IsMainStepActive((u8 *)a);
        BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)m);
        BTLV_CORE_StartMonSpriteLoad((u32 *)a[0x15], s, f);
        (*b)++;
        break;
    case 1:
        if (BTLV_CORE_WaitMonSpriteLoad((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}
