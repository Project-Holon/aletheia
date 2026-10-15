/*
 * function: SCRCMD_MUSICAL_WaitEntryMenuChild
 * address:  0x0215E010
 * packet:   pkt_ov010_0215E010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb  ov021
 *   MUS_COMM_FUNC_SetHostFlag  0x021FC804  thumb  ov132
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    u8 pad00[4];
    void *f4;
    void *f8;
    u8 pad0c[0x24];
    u16 *f30;
};

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *p);
extern int GAME_DATA_GetExternalWork(char *base);
extern u32 COMM_ENTRY_MENU_Main(u8 *p);
extern void MUS_COMM_FUNC_SetHostFlag(char *p);
extern u32 COMM_ENTRY_MENU_Delete(u32 *p);

int SCRCMD_MUSICAL_WaitEntryMenuChild(void *a, void *b)
{
    struct W *w;
    int r;
    int v;

    SCRCMD_WORK_GetScriptWork(b);
    w = (struct W *)GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(b));
    r = 0;
    switch (COMM_ENTRY_MENU_Main(w->f8)) {
    case 1:
        *w->f30 = 3;
        MUS_COMM_FUNC_SetHostFlag(w->f4);
        r = 1;
        break;
    case 2:
        v = 4;
        *w->f30 = v;
        r = 1;
        break;
    case 4:
        v = 2;
        *w->f30 = v;
        r = 1;
        break;
    }
    if (r == 1) {
        COMM_ENTRY_MENU_Delete(w->f8);
        w->f8 = 0;
    }
    return r;
}
