/*
 * function: BTLV_EFFVM_EmitterInitCallback
 * address:  0x021FD9F0
 * packet:   pkt_ov094_021FD9F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_GetCallbackArg  0x02051774  arm
 *   BUTTON_MAN_SetAngle  0x0205189C  arm
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm
 *   BUTTON_MAN_SetCallback  0x02051A24  arm
 *   BTLV_EFFVM_EmitterMoveCallbackB  0x021FDA28  thumb  ov094
 */
typedef struct {
    char pad00[0x0c];
    int k0c;                /* 0x0c */
    char pad10[0x2c];
    int k3c;                /* 0x3c */
} State;

extern unsigned int PARTICLE_GetCallbackArg(void);
typedef unsigned int   u32;
struct Obj;
extern void BUTTON_MAN_SetAngle(struct Obj *o, u32 v);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void BTLV_EFFVM_EmitterMoveCallbackB(void *p, int active);

void BTLV_EFFVM_EmitterInitCallback(void *p)
{
    State *s = (State *)PARTICLE_GetCallbackArg();

    if (s->k3c != 0 && s->k0c < 0)
        BUTTON_MAN_SetAngle(p, 0x800);
    BUTTON_MAN_SetUserData(p, (int)s);
    BUTTON_MAN_SetCallback(p, (int)BTLV_EFFVM_EmitterMoveCallbackB);
}
