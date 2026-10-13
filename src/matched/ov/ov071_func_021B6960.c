/*
 * function: func_021B6960
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
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned int u32;
typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;
extern void ACTOR_TOOL_FreeChar(u32, u32, u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021B6960(u32 *p)
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
        func_0204A8D4(e[17]);
        func_0204AFD8(e[18]);
        ACTOR_TOOL_FreeChar(p[1], e[19], flag);
        i++;
    } while (i < SLOT_COUNT);
}
