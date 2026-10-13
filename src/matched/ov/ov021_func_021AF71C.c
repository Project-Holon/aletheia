/*
 * function: SCRCMD_GetItemParam15
 * address:  0x021AF71C
 * packet:   pkt_ov021_021AF71C
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
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);

int SCRCMD_GetItemParam15(u32 a, u32 b)
{
    u32 y = SCRCMD_WORK_GetHeapId((void *)b);
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = func_02020FE4((void *)x, 0xf, y);
    return 0;
}
