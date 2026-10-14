/*
 * function: BTLV_EFFVM_ResolveSlotKey
 * address:  0x021FCF2C
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetUserData  0x02011324  thumb
 *   BTLV_EFFECT_IsPokeSpriteLoaded  0x021F7F1C  thumb  ov094
 *   BTLV_EFFVM_ResolveSideFromVm  0x021FD070  thumb  ov094
 */
typedef struct {
    unsigned int word0;
    char pad[0xd8];
    int dc;
    int e0;
} Unit;

struct ScriptVm;
extern void *VM_GetUserData(struct ScriptVm *vm);
extern int BTLV_EFFECT_IsPokeSpriteLoaded(int i);
extern int BTLV_EFFVM_ResolveSideFromVm(int a, int b);

int BTLV_EFFVM_ResolveSlotKey(int a, int idx)
{
    Unit *s = VM_GetUserData((struct ScriptVm *)a);
    int v;

    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        v = idx;
        break;
    case 14:
        v = s->dc;
        if (v == 0xff) {
            if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1)
                return 2;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1)
                return 4;
            if (BTLV_EFFECT_IsPokeSpriteLoaded(6) == 1)
                return 6;
            return 0;
        }
        break;
    case 15:
        if (s->dc > 1)
            v = s->dc ^ 2;
        else
            v = 0xff;
        break;
    case 16:
        v = s->e0;
        if (v == 0xff) {
            if (s->dc & 1) {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(2) == 1)
                    return 2;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(4) == 1)
                    return 4;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(6) == 1)
                    return 6;
                return 0;
            } else {
                if (BTLV_EFFECT_IsPokeSpriteLoaded(3) == 1)
                    return 3;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(5) == 1)
                    return 5;
                if (BTLV_EFFECT_IsPokeSpriteLoaded(7) == 1)
                    return 7;
                return 1;
            }
        }
        break;
    case 17:
        if (s->e0 > 1)
            v = s->e0 ^ 2;
        else
            v = 0xff;
        break;
    }
    return BTLV_EFFVM_ResolveSideFromVm(a, v);
}
