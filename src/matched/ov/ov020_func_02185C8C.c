/*
 * function: EVENT_MAPCHANGE_RunIntrudeArriveEvent
 * address:  0x02185C8C
 * packet:   pkt_ov020_02185C8C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_MAPCHANGE_InitWork  0x02184CEC  thumb  ov020
 *   EVENT_MAPCHANGE_DetachedTailEvent  0x02184504  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore  0x021BE9F0  thumb  ov021
 */

typedef struct { int f[7]; } S7;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
void GFL_USE_PlaySeDefaultVolume(u32 a);
struct Ctx;
struct Evt;
int FIELDMAP_GetEncEff(unsigned char *p);
void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void EVENT_MAPCHANGE_InitWork(void **o, void *p);
int EVENT_MAPCHANGE_DetachedTailEvent(int a, int *state, u8 *p);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void *EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(void *p, int a1, int a2, int a3, int a4);

int EVENT_MAPCHANGE_RunIntrudeArriveEvent(int a0, int *st, int *p)
{
    int r7 = p[7];
    int r6 = p[9];
    void *h;
    int *n;

    switch (st[0]) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x773);
        ENCEFF_Start((struct Ctx *)FIELDMAP_GetEncEff((unsigned char *)r6), a0, 0x24);
        st[0]++;
        break;
    case 1:
        h = func_020122C0((void *)r7, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
        n = func_020124E8(h);
        EVENT_MAPCHANGE_InitWork((void **)n, (void *)r7);
        *(S7 *)(n + 4) = *(S7 *)p;
        n[0xb] = 0;
        n[0x10] = 0;
        GAME_EVENT_CallEvent((struct Evt *)a0, h);
        st[0]++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)a0, EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore((void *)r7, r6, 0, 0, 2));
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
