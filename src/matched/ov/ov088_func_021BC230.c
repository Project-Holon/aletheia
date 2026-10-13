/*
 * function: STARTMENU_NewGameIntroMain
 * address:  0x021BC230
 * packet:   pkt_ov088_021BC230
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case bodies are laid out in source order, and the original places
 * case 6 before case 5 (jump table at 0x021BC254).
 *
 * symbols:
 *   SAVE_CONTROL_INTR_Update  0x021BD2F4  thumb  ov088
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   func_02008550  0x02008550  thumb
 *   STARTMENU_SetNewPlayerNameAndGender  0x021BC4A4  thumb  ov088
 *   ov204_id       0x000000CC  data
 *   ov194_id       0x000000C2  data
 *   d_021BFD24     0x021BFD24  data  ov204  a4
 *   d_021F5580     0x021F5580  data  ov194  a4
 */
#include "../include/Obj01518.h"
#include "../include/Obj20826.h"
#include "../include/Obj20827.h"
#include "../include/Obj20828.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 SAVE_CONTROL_INTR_Update(void *p);
extern unsigned int PROCSYS_Main(void *p);
extern void PROCSYS_Push(u32 h, void *id, void *proc, void *arg);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void STARTMENU_SetNewPlayerNameAndGender(int a, int b, int c);
extern u8 ov204_id[];
extern u8 ov194_id[];
extern char d_021BFD24[];
extern char d_021F5580[];

int STARTMENU_NewGameIntroMain(void *a0, int *seq, void *a2, char *w)
{
    int busy;

    SAVE_CONTROL_INTR_Update(((struct Obj01518 *)w)->f2C);
    busy = PROCSYS_Main((void *)((struct Obj01518 *)w)->f30);
    switch (*seq) {
    case 0:
        PROCSYS_Push(((struct Obj01518 *)w)->f30, ov204_id, d_021BFD24, w + 0x10);
        *seq = 1;
        break;
    case 1:
        if (busy != 1)
            *seq = 2;
        break;
    case 2:
        ((struct Obj20826 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f4 = func_02008550((const struct Sub0200852CObj *)(((struct Obj01518 *)w)->f8));
        ((struct Obj20827 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f24 = *(u32 *)&((struct Obj01518 *)w)->f2C;
        PROCSYS_Push(((struct Obj01518 *)w)->f30, ov194_id, d_021F5580, ((struct Obj01518 *)w)->f28);
        *seq = 3;
        break;
    case 3:
        if (busy != 1)
            *seq = 4;
        break;
    case 4:
        STARTMENU_SetNewPlayerNameAndGender(((struct Obj01518 *)w)->f54, ((struct Obj20828 *)(*(char * *)&((struct Obj01518 *)w)->f28))->f20,
                      func_02008550((const struct Sub0200852CObj *)(((struct Obj01518 *)w)->f54)));
        ((struct Obj01518 *)w)->f18 = 7;
        PROCSYS_Push(((struct Obj01518 *)w)->f30, ov204_id, d_021BFD24, w + 0x10);
        *seq = 6;
        break;
    case 6:
        if (busy != 1)
            *seq = 5;
        break;
    case 5:
        if (((struct Obj01518 *)w)->f24 == 0)
            *seq = 7;
        else
            *seq = 2;
        break;
    case 7:
        return 1;
    }
    return 0;
}
