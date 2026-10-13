/*
 * function: REPORT_EVENT_UpdatePrintStream
 * address:  0x02169F34
 * packet:   pkt_ov010_02169F34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 v);

#define Q (*(u8 **)(p + 0x18))
#define H (*(u32 *)(Q + 0x10))
#define ST (*(u32 *)(Q + 0x20))

int REPORT_EVENT_UpdatePrintStream(u8 *p)
{
    switch (PRINTSYS_PrintStreamGetState((void *)H)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3) != 0)
            PRINTSYS_PrintStreamShortWait((struct Rec *)H, 0);
        ST = 0;
        break;
    case 1:
        if (ST == 0) {
            if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause((void *)H);
                ST = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete((struct Rec3 *)H);
        ST = 0;
        return 0;
    }
    return 1;
}
