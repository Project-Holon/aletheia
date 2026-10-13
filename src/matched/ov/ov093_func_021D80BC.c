/*
 * function: BTL_CALC_DecideMoveTarget
 * address:  0x021D80BC
 * packet:   pkt_ov093_021D80BC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePosFromWork  0x021B8C50  thumb  ov093
 *   BTL_MAIN_CollectLivingPokeIds  0x021B8D38  thumb  ov093
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021B8CB0;
extern u32 BTL_MAIN_GetRule(void **p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_CALC_GetCurseTargetKind(void *p);
extern u8 BTL_MAIN_GetEnemyLanePosFromWork(char **p, u32 v, int k);
extern u8 BTL_MAIN_CollectLivingPokeIds(void *p, int a, int k, u8 *out);
extern u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out);
extern u32 BTL_CALC_Random(u32 range);

int BTL_CALC_DecideMoveTarget(void *p, int a, int m, u16 move)
{
    u32 mode;
    int t;
    u32 kind;
    u8 b;
    u8 buf[8];
    u8 n;

    mode = BTL_MAIN_GetRule(p);
    t = BTL_MAIN_GetTrainerSlotOfPoke(p, (void *)a, BTL_POKEPARAM_GetPokeId((u8 *)m));
    kind = WAZA_TOOL_GetParam(move, 0x1B);
    if (move == 0xAE) kind = BTL_CALC_GetCurseTargetKind((void *)m);

    if (mode == 0) {
        switch (kind) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 9:
            return BTL_MAIN_GetEnemyLanePosFromWork(p, t, 0);
        case 1:
        case 7:
            return t;
        case 13:
        default:
            return 6;
        }
    }

    b = 0;
    if (mode == 2) b = WAZA_TOOL_GetFlag(move, 0xB);

    switch (kind) {
    case 0:
    case 3:
    case 9:
        if (b) t = (u16)(t | (6 << 8));
        else t = (u16)(t | (1 << 8));
        break;
    case 1:
        t = (u16)(t | (3 << 8));
        break;
    case 2:
        if (b) t = (u16)(t | (7 << 8));
        else t = (u16)(t | (4 << 8));
        break;
    case 7:
        return t;
    default:
        return 6;
    }

    n = BTL_MAIN_CollectLivingPokeIds(p, a, t, buf);
    if (n) {
        n = BTL_CALC_Random(n);
        return BTL_MAIN_GetTrainerSlotOfPoke(p, (void *)a, buf[n]);
    }
    n = BTL_MAIN_DecodeMessageCode(p, t, buf);
    if (n) return buf[(u8)BTL_CALC_Random(n)];
    return 6;
}
