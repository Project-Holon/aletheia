/*
 * function: func_021B69F8
 * address: 0x021B69F8
 * packet: pkt_ov173_021B69F8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05: TOUCHPANEL_GetTrg is declared int here (as in ov173 func_021B68C8): the listing tests r0 after it,
 * but its matched arm9 definition is void (tail call of TOUCHPANEL_GetTrgSys, which returns a value).
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 */
typedef unsigned int u32;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);

int func_021B69F8(char *p)
{
    u32 r = PRINTSYS_PrintStreamGetState(*(void **)(p + 0x6c));
    APP_KEYCURSOR_Update(*(void **)(p + 0x21c), *(void **)(p + 0x6c), *(void **)(p + 0x20));
    if (r == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(*(void **)(p + 0x6c), 0);
    } else if (r == 2) {
        PRINTSYS_PrintStreamDelete(*(void **)(p + 0x6c));
        return *(int *)(p + 0x1b0);
    } else if (r == 1) {
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) {
            PRINTSYS_PrintStreamReleasePause(*(void **)(p + 0x6c));
            GFL_USE_PlaySeDefaultVolume(0x547);
        }
    }
    return 2;
}
