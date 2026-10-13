/*
 * function: FIELD_PLACE_NAME_StatePrepare
 * address:  0x021BCC80
 * packet:   pkt_ov021_021BCC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLACE_NAME_GetStep  0x021BD0C0  thumb  ov021
 *   FIELD_PLACE_NAME_LoadMessage  0x021BCAB0  thumb  ov021
 *   FIELD_PLACE_NAME_IncrementStep  0x021BD0D0  thumb  ov021
 *   func_020414C4  0x020414C4  arm
 *   func_020414EC  0x020414EC  arm
 *   FIELD_PLACE_NAME_TransferPalette  0x021BC6D0  thumb  ov021
 *   FIELD_PLACE_NAME_ClearWindow  0x021BC720  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   FIELD_PLACE_NAME_ResetSpawnCounts  0x021BC838  thumb  ov021
 *   FIELD_PLACE_NAME_SpawnNextLetter  0x021BC848  thumb  ov021
 *   FIELD_PLACE_NAME_IsAllSpawned  0x021BC910  thumb  ov021
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */
#include "../include/Obj00183.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 FIELD_PLACE_NAME_GetStep(u8 *p);
extern void FIELD_PLACE_NAME_LoadMessage(int *p);
extern void FIELD_PLACE_NAME_IncrementStep(char *p);
extern void func_020414C4(u32 idx);
extern void func_020414EC(u32 i);
extern void FIELD_PLACE_NAME_TransferPalette(char *p);
extern void FIELD_PLACE_NAME_ClearWindow(char *p);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(int, int, int, int, int);
extern void FIELD_PLACE_NAME_ResetSpawnCounts(char *p);
extern void FIELD_PLACE_NAME_SpawnNextLetter(char *p);
extern int FIELD_PLACE_NAME_IsAllSpawned(char *p);
extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

void FIELD_PLACE_NAME_StatePrepare(char *p)
{
    u32 w;

    switch (FIELD_PLACE_NAME_GetStep((u8 *)p)) {
    case 0:
        FIELD_PLACE_NAME_LoadMessage((int *)p);
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 1:
        func_020414C4(3);
        func_020414EC(3);
        FIELD_PLACE_NAME_TransferPalette(p);
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 2:
        FIELD_PLACE_NAME_ClearWindow(p);
        w = *(u32 *)&((struct Obj00183 *)p)->f24;
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        func_0204047C(3, 1);
        func_02040588(3, 0);
        func_0207D63C(0x04000050, 8, 0x11, 0x10, 4);
        FIELD_PLACE_NAME_ResetSpawnCounts(p);
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 3:
        FIELD_PLACE_NAME_SpawnNextLetter(p);
        if (FIELD_PLACE_NAME_IsAllSpawned(p)) {
            FIELD_PLACE_NAME_SetState(p, 2);
        }
        break;
    }
}
