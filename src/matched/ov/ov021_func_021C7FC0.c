/*
 * function: FIELDSKILL_MAPEFF_InitFlash
 * address:  0x021C7FC0
 * packet:   pkt_ov021_021C7FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   FIELD_FLASH_Create  0x021C7DAC  thumb  ov021
 *   FIELD_FLASH_SetPendingCommand  0x021C7E50  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern M *FIELD_FLASH_Create(u32 heap);
extern void FIELD_FLASH_SetPendingCommand(u8 *p, u16 v);
void FIELDSKILL_MAPEFF_InitFlash(M **pp, u32 flags, u32 heap)
{
    if (flags & 3) {
        *pp = FIELD_FLASH_Create(heap);
        if (flags & 2)
            FIELD_FLASH_SetPendingCommand((u8 *)(*pp), 2);
        else
            FIELD_FLASH_SetPendingCommand((u8 *)(*pp), 0);
    } else {
        *pp = 0;
    }
}
