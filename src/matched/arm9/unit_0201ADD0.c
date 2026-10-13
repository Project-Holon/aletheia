/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201ADD0
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_PERSONAL_LoadDataDirect, POKE_PERSONAL_Create
 *
 * symbols:
 *   poke_personal_File  0x020A7310  data
 *   POKE_PERSONAL_LoadData  0x0201ADA4  thumb
 *   POKE_PERSONAL_GetFormDataId  0x0201AFD4  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *
 * POKE_PERSONAL_LoadDataDirect is a second, smaller wrapper around POKE_PERSONAL_GetFormDataId (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * POKE_PERSONAL_Create constructs an object from the debug allocator,
 * func_02030734(heap, size, zero, file, tag), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to POKE_PERSONAL_LoadData (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 POKE_PERSONAL_GetFormDataId(u32 a, int b);
extern void  ARC_TOOL_ReadMember(void *c, u32 id, u32 arg);

void POKE_PERSONAL_LoadDataDirect(u32 a, int b, void *c)
{
    u32 r = POKE_PERSONAL_GetFormDataId(a, b);

    ARC_TOOL_ReadMember(c, 0x12, r);
}

extern void *func_02030734(u32 heap, u32 size, int zero, const char *file, u16 tag);
extern void POKE_PERSONAL_LoadData(u32 a, int b, void *c);
extern const char poke_personal_File[];

void *POKE_PERSONAL_Create(u32 a, int b, u32 c)
{
    void *obj = func_02030734(c, 0x3C, 0, poke_personal_File, 0x76);

    POKE_PERSONAL_LoadData(a, b, obj);
    return obj;
}
