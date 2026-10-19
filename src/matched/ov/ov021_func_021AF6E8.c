/*
 * function: SCRCMD_GetItemPocket
 * address:  0x021AF6E8
 * packet:   pkt_ov021_021AF6E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FILE_UTIL_GetItemParam  0x02020FE4  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);

int SCRCMD_GetItemPocket(u32 a, u32 b)
{
    u32 y = SCRCMD_WORK_GetHeapId((void *)b);
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = FILE_UTIL_GetItemParam((void *)x, 5, y);
    return 0;
}
