/*
 * function: ZUKAN_DETAIL_MAIN_Main
 * address: 0x021BCBB4
 * packet: pkt_ov208_021BCBB4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_DETAIL_PROCSYS_RunStateCallbacks 0x021BC274 thumb
 *   ZUKAN_DETAIL_MAIN_SwitchScreen 0x021BCC84 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate 0x021BC2F0 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Update 0x021BD974 thumb
 *   ZUKAN_DETAIL_HEADBAR_Update 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ZUKAN_DETAIL_GRAPHIC_DrawFrame 0x021BCF18 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ApplyCamera 0x021BCF2C thumb
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerHook 0x021BC310 thumb
 *   ZUKAN_DETAIL_GRAPHIC_EndDraw3d 0x021BCF3C thumb
 * tail: 4 bytes at 0x021BCC80 are the unlabelled stub ZUKAN_DETAIL_MAIN_NoOp and its padding (listing extent runs to 0x021BCC84).
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };
struct Ov208Main {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    void *obj; int f24; int f28;
};
struct State;
extern int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct State *p, int arg);
struct Ov208Mode;
struct Ov208Slot;
extern void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Mode *m, struct Ov208Slot *s);
struct Ov208Fade;
struct Ov208Icon;
struct PrintSys;
struct State;
extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct State *p);
extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct State *p);
extern void ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(char *p, int a, int b);
extern void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Fade *m);
extern void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);
extern void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);
extern void ZUKAN_DETAIL_PROCSYS_CallOwnerHook(char *p, int v);
extern void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);
int ZUKAN_DETAIL_MAIN_Main(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main *m)
{
    int done = 0;
    u32 v;
    if (*cnt <= 8)
        *cnt = *cnt + 1;
    if (ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(m->obj, (int)m->fsm) != 0) {
        if (m->f28 != 0) {
            a->f4 = m->f28;
            ZUKAN_DETAIL_MAIN_SwitchScreen((struct Ov208Mode *)a, (struct Ov208Slot *)m);
            m->f28 = 0;
            done = 1;
        } else {
            return 1;
        }
    }
    if (done == 0) {
        v = ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(m->f14);
        if (v == 0)
            v = ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(m->f14);
        ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(m->obj, (int)m->fsm, v);
        switch (v) {
        case 1: a->f10 = 0; break;
        case 2: a->f10 = 1; break;
        case 6: m->f28 = 1; break;
        case 7: m->f28 = 2; break;
        case 8: m->f28 = 3; break;
        case 9: m->f28 = 4; break;
        }
    }
    ZUKAN_DETAIL_TOUCHBAR_Update(m->f14);
    ZUKAN_DETAIL_HEADBAR_Update(m->f18);
    PRINTSYS_QUE_Main(m->gfx);
    ZUKAN_DETAIL_GRAPHIC_DrawFrame(m->disp);
    ZUKAN_DETAIL_GRAPHIC_ApplyCamera(m->disp);
    if (done == 0)
        ZUKAN_DETAIL_PROCSYS_CallOwnerHook(m->obj, (int)m->fsm);
    ZUKAN_DETAIL_GRAPHIC_EndDraw3d(m->disp);
    return 0;
}
