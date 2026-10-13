/*
 * function: FIELDSKILL_MAPEFF_FreeFlash
 * address:  0x021C7FF0
 * packet:   pkt_021C7FF0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TwlDWC libdwcgsgp gpipeer.o: frees the buffer the message owns and clears
 * the message's pointer (gsifree is FIELD_FLASH_Delete here).
 *
 * symbols:
 *   FIELD_FLASH_Delete  0x021C7DE0  thumb
 */

typedef unsigned int u32;

extern void FIELD_FLASH_Delete(void *p);

void FIELDSKILL_MAPEFF_FreeFlash(void *msg)
{
    FIELD_FLASH_Delete(*(void **)msg);
    *(u32 *)msg = 0;
}
