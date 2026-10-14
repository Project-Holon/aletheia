/*
 * function: BTLV_EFFVM_WaitVoiceTaskMain
 * address:  0x021FE8D8
 * packet:   pkt_ov094_021FE8D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PM_VOICE_IsActive  0x02006BD0  thumb
 *   BTLV_EFFVM_StartSeVolumeTweenTask  0x021FE410  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags;
typedef struct {
    Flags fl;
    char pad04[0x268];
    int tbl[6];
} Obj;

typedef unsigned int   u32;
extern u32 PM_VOICE_IsActive(u32 i);
extern void BTLV_EFFVM_StartSeVolumeTweenTask(Obj *o, int a, int b, int n);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFVM_WaitVoiceTaskMain(void *h, Obj **pp)
{
    int i;

    for (i = 0; i < 6; i++) {
        if ((*pp)->tbl[i] != -1) {
            if (PM_VOICE_IsActive((*pp)->tbl[i]) != 0)
                return;
            (*pp)->tbl[i] = -1;
        }
    }
    BTLV_EFFVM_StartSeVolumeTweenTask(*pp, 0x6b000, 0x7f000, 10);
    (*pp)->fl.f10 = 0;
    BTLV_EFFECT_DeleteTask(h);
}
