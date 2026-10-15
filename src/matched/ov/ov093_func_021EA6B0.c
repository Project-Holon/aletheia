/*
 * function: BTLV_CORE_PrintTrainerMessage
 * address:  0x021EA6B0
 * packet:   pkt_ov093_021EA6B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TPOKE_DATA_FindRecord  0x0202A298  thumb
 *   TPOKE_DATA_ReadRecordString  0x0202A310  thumb
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj07846.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 TPOKE_DATA_FindRecord(u32 key, u32 want, u32 heap);
extern void TPOKE_DATA_ReadRecordString(int key, int want, void *dest, u32 heap);
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

int BTLV_CORE_PrintTrainerMessage(char *p, u16 a, u16 b)
{
    if (TPOKE_DATA_FindRecord(a, b, ((struct Obj07846 *)p)->f184) != 0) {
        TPOKE_DATA_ReadRecordString(a, b, ((struct Obj07846 *)p)->fAC, ((struct Obj07846 *)p)->f184);
        BTLV_CORE_StartPrintMessage(p, *(int *)&((struct Obj07846 *)p)->fAC, 0x50, 0);
    } else {
        return 0;
    }
    return 1;
}
