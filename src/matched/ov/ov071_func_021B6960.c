/*
 * function: MONOLITH_TOOL_FreeActorResources
 * address: 0x021B6960
 * packet: pkt_ov071_021B6960
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 * symbols:
 *   ACTOR_TOOL_FreeChar 0x02025518 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
typedef unsigned int u32;
typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;
extern void ACTOR_TOOL_FreeChar(u32, u32, u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
void MONOLITH_TOOL_FreeActorResources(u32 *p)
{
    Slot i;
    int flag;
    u32 *e;
    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        ACTOR_TOOL_FreeChar(p[1], e[16], flag);
        CLACT_ReleaseCharacter(e[17]);
        CLACT_ReleaseCellAnim(e[18]);
        ACTOR_TOOL_FreeChar(p[1], e[19], flag);
        i++;
    } while (i < SLOT_COUNT);
}
