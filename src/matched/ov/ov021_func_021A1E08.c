/*
 * function: WEATHER_TASK_Update
 * address:  0x021A1E08
 * packet:   pkt_ov021_021A1E08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_HasFogChange  0x021A2CF8  thumb  ov021
 *   FIELD_FOG_FADE_IsFade  0x021A0244  thumb  ov021
 *   WEATHER_TASK_ApplyFogChange  0x021A2D04  thumb  ov021
 *   WEATHER_TASK_ClearFogChange  0x021A2CEC  thumb  ov021
 *   WEATHER_TASK_LoadResources  0x021A282C  thumb  ov021
 *   WEATHER_TASK_InitBillboards  0x021A2860  thumb  ov021
 *   WEATHER_TASK_AllocParticles  0x021A28CC  thumb  ov021
 *   WEATHER_TASK_MarkStarted  0x021A2968  thumb  ov021
 *   WEATHER_TASK_CallStageFunc  0x021A2724  thumb  ov021
 *   WEATHER_TASK_ResumeSound  0x021A2C98  thumb  ov021
 *   WEATHER_TASK_UpdateParticles  0x021A27F8  thumb  ov021
 *   WEATHER_TASK_IsStarted  0x021A2970  thumb  ov021
 *   WEATHER_TASK_FreeParticles  0x021A2924  thumb  ov021
 *   WEATHER_TASK_FreeBillboards  0x021A28A0  thumb  ov021
 *   WEATHER_TASK_UnloadResources  0x021A284C  thumb  ov021
 *   WEATHER_TASK_Reset  0x021A26D8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 *f20;
    u8 lo24 : 4;
    u8 hi24 : 4;
    u8 pad25;
    u8 state;
    u8 flag;
    u8 pad28[0x18];
    u8 sub40[4];
} Obj;

extern u8 WEATHER_TASK_HasFogChange(char *p);
extern int FIELD_FOG_FADE_IsFade(u8 *p);
extern void WEATHER_TASK_ApplyFogChange(Obj *o);
extern void WEATHER_TASK_ClearFogChange(char *p);
extern void WEATHER_TASK_LoadResources(Obj *o, s32 x);
extern void WEATHER_TASK_InitBillboards(Obj *o, s32 x);
extern void WEATHER_TASK_AllocParticles(Obj *o, s32 x);
extern void WEATHER_TASK_MarkStarted(u8 *p);
extern s32 WEATHER_TASK_CallStageFunc(Obj *o, u32 a, s32 x);
extern void WEATHER_TASK_ResumeSound(void *p, u32 a);
extern void WEATHER_TASK_UpdateParticles(Obj *o);
extern u8 WEATHER_TASK_IsStarted(u8 *p);
extern void WEATHER_TASK_FreeParticles(Obj *o);
extern void WEATHER_TASK_FreeBillboards(Obj *o);
extern void WEATHER_TASK_UnloadResources(Obj *o);
extern void WEATHER_TASK_Reset(int *p);

void WEATHER_TASK_Update(Obj *o, s32 x)
{
    if (WEATHER_TASK_HasFogChange((char *)o) != 0 && FIELD_FOG_FADE_IsFade((u8 *)o->f4) == 0) {
        WEATHER_TASK_ApplyFogChange(o);
        WEATHER_TASK_ClearFogChange((char *)o);
    }
    switch (((u8 *)o)[0x26]) {
    case 0:
        break;
    case 1:
        WEATHER_TASK_LoadResources(o, x);
        WEATHER_TASK_InitBillboards(o, x);
        WEATHER_TASK_AllocParticles(o, x);
        WEATHER_TASK_MarkStarted((u8 *)o);
        ((u8 *)o)[0x26] = 5;
        break;
    case 2:
        WEATHER_TASK_LoadResources(o, x);
        ((u8 *)o)[0x26] = 3;
        break;
    case 3:
        WEATHER_TASK_InitBillboards(o, x);
        ((u8 *)o)[0x26] = 4;
        break;
    case 4:
        WEATHER_TASK_AllocParticles(o, x);
        ((u8 *)o)[0x26] = 5;
        break;
    case 5:
        if (WEATHER_TASK_CallStageFunc(o, o->f20[11], x) != 0) {
            ((u8 *)o)[0x26] = o->hi24 != 0 ? 6 : 7;
        }
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        WEATHER_TASK_MarkStarted((u8 *)o);
        break;
    case 6:
        if (WEATHER_TASK_CallStageFunc(o, o->f20[12], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        WEATHER_TASK_UpdateParticles(o);
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        break;
    case 7:
        if (WEATHER_TASK_CallStageFunc(o, o->f20[13], x) != 0) {
            ((u8 *)o)[0x26] = 8;
        }
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        break;
    case 8:
        WEATHER_TASK_CallStageFunc(o, o->f20[14], x);
        WEATHER_TASK_UpdateParticles(o);
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        break;
    case 9:
        if (WEATHER_TASK_CallStageFunc(o, o->f20[15], x) != 0) {
            ((u8 *)o)[0x26] = 10;
        }
        WEATHER_TASK_UpdateParticles(o);
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        break;
    case 10:
        if (WEATHER_TASK_CallStageFunc(o, o->f20[16], x) != 0) {
            ((u8 *)o)[0x26] = 11;
        }
        WEATHER_TASK_UpdateParticles(o);
        WEATHER_TASK_ResumeSound(o->sub40, o->fC);
        break;
    case 11:
        if (WEATHER_TASK_IsStarted((u8 *)o) != 0) {
            WEATHER_TASK_CallStageFunc(o, o->f20[17], x);
        }
        ((u8 *)o)[0x26] = 12;
        break;
    case 12:
        WEATHER_TASK_FreeParticles(o);
        WEATHER_TASK_FreeBillboards(o);
        WEATHER_TASK_UnloadResources(o);
        WEATHER_TASK_Reset((int *)o);
        ((u8 *)o)[0x26] = 0;
        break;
    }
}
