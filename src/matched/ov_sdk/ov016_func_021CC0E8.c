/*
 * function: button
 * address:  0x021CC0E8
 * packet:   pkt_ov016_021CC0E8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes: EXACT at 288 bytes, 23/23 relocations.  The park's 2-line residue
 *        (+00B8/+00C0: the image computes the last call argument `add ip, r5,
 *        #1` before the `mov r2, r4` third argument, the park after it)
 *        closes on the message-index table: declaring it `extern const s8
 *        sSceneSetSelectApMessageByLanguage[7]` instead of plain s8 makes the front end read it as a
 *        const table and the last argument's add is scheduled first.  The
 *        function name, `lang` local and all statements are unchanged.
 *
 * sdk:      button (libdwcutil.TWL.HYB.a scenesetselectap)
 * symbols:
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_Entry                       0x021C0ED8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_SETTINGlGetSetType          0x021CF7F4  arm
 *   DWCi_BTNlSetForce                0x021BCB44  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   dispPushClear                    0x021CC6AC  arm   ov016
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   dispPush                         0x021CC8C4  arm   ov016
 *   g_021DE60C                       0x021DE60C  data
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   sSceneSetSelectApMessageByLanguage                       0x021DA724  data
 *   procErase                        0x021CC740  arm   ov016
 *   endScene                         0x021CC208  arm   ov016
 */

#include "../include/G_SCENESETSELECTAP_BSS.h"

typedef _Bool bool;
typedef unsigned char u8;
typedef signed char s8;

struct SelApObj {
    u8 pad0[0x1d];
    u8 state;
};
extern struct SCENESETSELECTAP_BSS g_021DE60C;
extern const s8 sSceneSetSelectApMessageByLanguage[7];

extern int DWCi_BTNlGet(void);
extern int DWCi_Entry(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern int DWCi_SETTINGlGetSetType(int idx);
extern void DWCi_BTNlSetForce(int idx);
extern int DWCi_Language(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SceneEnd(void);

static void dispPushClear(void);
static void dispPush(void);
static void procErase(void);
static void endScene(void);

static void button(void)
{
    int idx;
    int lang;

    switch (DWCi_BTNlGet()) {
    case 0:
        switch (DWCi_Entry()) {
        case 0:
            DWCi_SNDlPlay(7);
            ((struct SelApObj *)g_021DE60C.MemSssa)->state = 2;
            break;
        case 1:
            DWCi_BTNlDisable();
            DWCi_ChangeScene(DWCi_SceneEnd);
            return;
        }
        break;
    case 1:
        ((struct SelApObj *)g_021DE60C.MemSssa)->state = 1;
        if (g_021DE60C.FocusPos >= 4) {
            idx = g_021DE60C.FocusPos - 4;
            if (DWCi_SETTINGlGetSetType(idx) == 0xff) {
                DWCi_SNDlPlay(9);
                DWCi_BTNlSetForce(-1);
                return;
            }
            DWCi_SNDlPlay(6);
            lang = sSceneSetSelectApMessageByLanguage[DWCi_Language()];
            DWCi_WINlInitEx(0x46, 0, 1, lang, idx + 1);

            dispPushClear();
            DWCi_BTNlDisable();
            DWCi_ChangeScene(procErase);
            return;
        }
        if (g_021DE60C.FocusPos <= 2)
            DWCi_SETTINGlSetSetting(g_021DE60C.FocusPos);
        DWCi_SNDlPlay(6);
        dispPush();
        break;
    default:
        return;
    }
    DWCi_ChangeScene(endScene);
}
