/*
 * function: UN_SELECT_DrawFrameListRow
 * address:  0x021B9AE4
 * packet:   pkt_ov218_021B9AE4
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (user decision): the u64 parameter is accepted as real source (a 64-bit value passed in r2:r3).
 * note 2026-10-05 (wD9r lane02): EXACT. The last two parameters are one u64 split across r3 and the
 *   first stack word (old ATPCS does not align a doubleword argument). c is its low word, d its high word.
 *   The high word is a fresh value, not a u32 parameter in its home slot, so mwcc keeps d in r7 and spills t.
 *   Caller UN_SELECT_UpdateFrameList stores two separate words (r3 and [sp]), which fits this signature. r is declared
 *   before t (that orders the t spill store after the two constants).
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_0201D2C8 0x0201D2C8 thumb
  * note 2026-10-05 (integrator): parked in pending although it verifies EXACT. It closes only with
 * the last two parameters as one unsigned long long; the matched caller ov218 021B9C8C passes
 * two separate words (a pointer and a u32). Waiting for the user to accept or reject that form.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct StrObj;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D2C8(struct StrObj *s);
void UN_SELECT_DrawFrameListRow(u8 *p, u8 *a, void *b, unsigned long long cd)
{
    u32 c = (u32)cd; u32 d = (u32)(cd >> 32);
    u32 r = 12;
    u32 t = 0x83 - d;
    MSGDATA_ReadString(*(void **)(p + 8), (t == 2) ? 0xF0 : 0xED, *(void **)(p + 0x18));
    WORDSET_SetSlotNumber(*(void **)(p + 0x14), 2, t, 3, 0, 1);
    WORDSET_CopyTaggedText(*(void **)(p + 0x14), *(void **)(p + 0x1C), *(void **)(p + 0x18));
    TOUCHBAR_PrintAligned(a, b, 0, 12, *(u32 *)(p + 0x1C), c, 0x39E0, 0);
    p += 0x2C;
    if (func_0201D2C8((struct StrObj *)(*(u32 *)(p + d * 4))) > 1) r = 4;
    TOUCHBAR_PrintAligned(a, b, 0x1E, r, *(u32 *)(p + d * 4), c, 0x39E0, 0);
}
