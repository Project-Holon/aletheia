/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_SetMode1
 * address:  0x02028F18
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_SOUND_SYSTEM_IsKindAllowedInState  0x02028FD0  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct SoundParam2 {
    unsigned char pad00[4];
    u32 group;    /* +0x04 */
    unsigned char pad08[4];
    u32 valC;     /* +0x0c */
    unsigned char pad10[8];
    u16 val18;    /* +0x18 */
    u16 val1a;    /* +0x1a */
    u32 kind;     /* +0x1c */
};

struct SoundParam;
extern u32 FIELD_SOUND_SYSTEM_IsKindAllowedInState(struct SoundParam *obj, u32 kind);

void FIELD_SOUND_SYSTEM_SetMode1(struct SoundParam2 *obj, u16 a1)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 1)) {
        obj->kind = 1;
        obj->val18 = a1;
    }
}

void FIELD_SOUND_SYSTEM_SetMode2(struct SoundParam2 *obj, u16 a1)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 2)) {
        obj->kind = 2;
        obj->val1a = a1;
    }
}

void FIELD_SOUND_SYSTEM_SetMode3(struct SoundParam2 *obj, u16 a1)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 3)) {
        obj->kind = 3;
        obj->val1a = a1;
    }
}

void FIELD_SOUND_SYSTEM_SetMode4(struct SoundParam2 *obj, u16 a1, u16 a2)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 4)) {
        obj->kind = 4;
        obj->val18 = a2;
        obj->val1a = a1;
    }
}

void FIELD_SOUND_SYSTEM_SetMode5(struct SoundParam2 *obj, u32 a1, u16 a2, u16 a3)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 5)) {
        obj->kind = 5;
        obj->valC = a1;
        obj->val18 = a3;
        obj->val1a = a2;
    }
}

void FIELD_SOUND_SYSTEM_SetMode6(struct SoundParam2 *obj, u32 a1, u16 a2)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 6)) {
        obj->kind = 6;
        obj->valC = a1;
        obj->val1a = a2;
    }
}

void FIELD_SOUND_SYSTEM_SetMode7(struct SoundParam2 *obj, u32 a1)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)obj, 7)) {
        obj->kind = 7;
        obj->valC = a1;
    }
}
