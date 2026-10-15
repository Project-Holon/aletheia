/*
 * function: UNION_ONESELF_ColosseumTrainerCardMain
 * address:  0x0217EAD8
 * packet:   pkt_ov019_0217EAD8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   UNION_MSG_SetupTalkWindow  0x0217F098  thumb  ov019
 *   UNION_MSG_PrintTalkMsg  0x0217F188  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_MAIN_RequestScene  0x0217422C  thumb  ov012
 *   UNION_MAIN_IsScenePending  0x02174268  thumb  ov012
 *   TRCARD_SYS_CreateEditWork  0x0216F7F4  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   KEY_GetTrg  0x020362DC  arm
 */
#include "../include/Obj05956.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    int f8;
} Sys;

void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
void UNION_MSG_SetupTalkWindow(unsigned char *base, u8 *x);
void UNION_MSG_PrintTalkMsg(char *p, u32 arg);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
void UNION_MSG_CloseAllWindows(void *p);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
struct Sub0200852CObj;
struct WordSet;
void UNION_MAIN_RequestScene(u8 *p, int a, int b);
int UNION_MAIN_IsScenePending(u8 *w);
void *TRCARD_SYS_CreateEditWork(int a, u8 *e, int b);
u8 func_0200855C(const struct Sub0200852CObj *obj);
void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
u32 KEY_GetTrg(void);

int UNION_ONESELF_ColosseumTrainerCardMain(u8 *w, void *obj, u8 *a2, u8 *state)
{
    u8 *p;
    int t;
    int v;
    int msg;
    void *q;

    p = *(u8 * *)&((struct Obj05956 *)w)->f355C;
    switch (*state) {
    case 0:
        UNION_ONESELF_SetFieldBusy((char *)w, (int)a2, 1);
        t = func_0200855C((const struct Sub0200852CObj *)(p + 0x18 + p[0x16c] * 0x2c));
        if (t == 0x14 || t == 0x15) {
            v = (*(u8 **)(p + 0x134 + p[0x16c] * 4))[3];
            if (v < 5) {
                msg = 0x156 + v;
            } else if (v == 5) {
                switch (t) {
                case 0x15:
                    msg = 0x15c;
                    break;
                case 0x14:
                    msg = 0x15b;
                    break;
                default:
                    msg = 0x15d;
                    break;
                }
            } else {
                msg = 0x15d;
            }
        } else {
            msg = 0x15d;
        }
        UNION_MSG_SetupTalkWindow(w, a2);
        WORDSET_SetSlotMyStatus((struct WordSet *)(((struct Obj05956 *)w)->f2804), 0, p + 0x18 + p[0x16c] * 0x2c);
        UNION_MSG_PrintTalkMsg((char *)w, msg);
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1 && (KEY_GetTrg() & 3)) {
            UNION_MSG_CloseAllWindows(w);
            (*(u8 **)(p + 0x134 + p[0x16c] * 4))[4] |= 0x20;
            q = TRCARD_SYS_CreateEditWork((*(Sys * *)&((struct Obj05956 *)w)->f0)->f8, *(u8 **)(p + 0x134 + p[0x16c] * 4), 0x41);
            ((struct Obj05956 *)w)->f3558 = q;
            UNION_MAIN_RequestScene(w, 0x1c, (int)q);
            (*state)++;
        }
        break;
    case 2:
        if (UNION_MAIN_IsScenePending(w) == 0) {
            ((struct Obj05956 *)w)->f3558 = 0;
            (*state)++;
        }
        break;
    case 3:
        UNION_ONESELF_SetNextPlayCategory((char *)w, 0x2a);
        return 1;
    }
    return 0;
}
