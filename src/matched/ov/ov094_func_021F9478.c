/*
 * function: BTLV_EFFVM_Main
 * address:  0x021F9478
 * packet:   pkt_ov094_021F9478
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_Control  0x02011298  thumb
 *   VM_GetUserData  0x02011324  thumb
 *   BTLV_EFFECT_GaugeSetSideVisible  0x021F8198  thumb  ov094
 *   BTLV_EFFVM_StartSeVolumeTweenTask  0x021FE410  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
    char pad[0x1E4];
    void *h;            /* 0x1E8 */
} T;

struct ScriptVm;
extern int VM_Control(struct ScriptVm *vm);
extern void *VM_GetUserData(struct ScriptVm *vm);
extern void BTLV_EFFECT_GaugeSetSideVisible(int a, int b);
extern void BTLV_EFFVM_StartSeVolumeTweenTask(T *t, int a, int b, int c);
extern u32 func_020307B0(void *p);

int BTLV_EFFVM_Main(void *vm)
{
    int r;
    T *t;

    r = VM_Control(vm);
    t = VM_GetUserData(vm);
    if (t->b7)
        return 0;
    if (r == 0 && t->h != 0) {
        BTLV_EFFECT_GaugeSetSideVisible(1, 2);
        if (t->b6 == 0)
            BTLV_EFFVM_StartSeVolumeTweenTask(t, 0x6B000, 0x7F000, 0x14);
        func_020307B0(t->h);
        t->h = 0;
    }
    return r;
}
