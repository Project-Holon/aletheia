/*
 * function: BTLV_EFFVM_EvalCondition
 * address: 0x021FDBB0
 * packet: pkt_ov094_021FDBB0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaves: parent-cleared ov094 getters 0x021F8730 and 0x021F8740 filed separately.
 * domain: selector values 0..57; out-of-range result is unspecified.
 * symbols:
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_GetSpriteWeight 0x021FFF0C thumb ov094
 *   BTLV_MCSS_GetSpriteAttrFlags 0x021FFF38 thumb ov094
 *   BTLV_MCSS_HasPersonalParam10 0x021FFF68 thumb ov094
 *   BTLV_MCSS_GetStopCellFlags 0x021FFFAC thumb ov094
 *   BTLV_MCSS_IsVanished 0x021FF348 thumb ov094
 *   BTLV_EFFECT_IsMultiMode 0x021F8730 thumb ov094
 *   BTLV_EFFECT_GetMode 0x021F8710 thumb ov094
 *   BTLV_EFFECT_GetTrainerType 0x021F8740 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    unsigned int pad0:13;
    unsigned int f13:1;
    unsigned int pad14:1;
    unsigned int f15:1;
    unsigned int pad16:16;
    int f4;
    char pad8[0xd4];
    int dc, e0;
    char pade4[0x164];
    u8 b248, b249, b24a, b24b;
    int f24c, f250;
    u16 f254;
    char pad256[0x2e];
    int f284;
    char pad288[0x18];
    int f2a0;
} State;
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_GetSpriteWeight(char *p, int key);
extern int BTLV_MCSS_GetSpriteAttrFlags(char *p, int key);
extern int BTLV_MCSS_HasPersonalParam10(void *, int);
extern int BTLV_MCSS_GetStopCellFlags(void *, int);
extern int BTLV_MCSS_IsVanished(void *, int);
extern int BTLV_EFFECT_IsMultiMode(void);
extern int BTLV_EFFECT_GetMode(void);
extern unsigned short BTLV_EFFECT_GetTrainerType(int a);
int BTLV_EFFVM_EvalCondition(State *s, unsigned int key)
{
    switch (key) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return BTLV_MCSS_GetSpriteWeight((char *)BTLV_EFFECT_GetMcss(), key);
    case 8: return BTLV_MCSS_GetSpriteWeight((char *)BTLV_EFFECT_GetMcss(), s->dc);
    case 9: return s->b248;
    case 10: return s->b249;
    case 11: return s->b24a;
    case 12: return s->b24b;
    case 13: return s->f24c;
    case 14: return s->f250;
    case 15: return s->f254;
    case 16: return s->f4;
    case 17: return s->dc;
    case 18: return BTLV_MCSS_IsVanished((void *)BTLV_EFFECT_GetMcss(), s->dc);
    case 19: return s->dc & 1;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        if (BTLV_MCSS_GetSpriteAttrFlags((char *)BTLV_EFFECT_GetMcss(), key - 20) & 2)
            return 1;
        return 0;
    case 28:
        if (BTLV_MCSS_GetSpriteAttrFlags((char *)BTLV_EFFECT_GetMcss(), s->dc) & 2)
            return 1;
        return 0;
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
        return BTLV_MCSS_HasPersonalParam10((void *)BTLV_EFFECT_GetMcss(), key - 29);
    case 37: return BTLV_MCSS_HasPersonalParam10((void *)BTLV_EFFECT_GetMcss(), s->dc);
    case 38: return BTLV_EFFECT_IsMultiMode();
    case 39: return BTLV_EFFECT_GetMode();
    case 40: case 41: case 42: case 43: return BTLV_EFFECT_GetTrainerType(key - 40);
    case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        return BTLV_MCSS_GetStopCellFlags((void *)BTLV_EFFECT_GetMcss(), key - 44);
    case 52: return BTLV_MCSS_GetStopCellFlags((void *)BTLV_EFFECT_GetMcss(), s->dc);
    case 53: return s->f13;
    case 54: return s->f284;
    case 55: return s->f2a0;
    case 56: return s->f15;
    case 57: return s->e0;
    }
}
