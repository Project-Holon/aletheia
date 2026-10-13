/*
 * function: MONOLITH_TOOL_LoadActorResources
 * address:  0x021B68E0
 * packet:   pkt_ov071_021B68E0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ACTOR_TOOL_LoadCharPalAnm  0x02025470  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ACTOR_TOOL_LoadCharSimplePalAnm  0x020254BC  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
typedef signed int     s32;
void MONOLITH_TOOL_LoadActorResources(int *p)
{
    void *func_020490F4(u32 id, u32 heap);
    u32 ACTOR_TOOL_LoadCharPalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
    s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
    s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
    u32 ACTOR_TOOL_LoadCharSimplePalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
    void ARC_TOOL_DeleteHandle(void *);
    void *tmp;
    int i;
    int flag;
    int *e;

    tmp = func_020490F4(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        e[16] = ACTOR_TOOL_LoadCharPalAnm(p[0], p[1], p[12], 3, flag, 3, 0x61);
        e[17] = CLACT_RegisterCharacter((void *)p[12], 0, 1, flag, 0x61);
        e[18] = CLACT_RegisterCellAnim((void *)p[12], 1, 2, 0x61);
        e[19] = ACTOR_TOOL_LoadCharSimplePalAnm(p[0], p[1], (u32)tmp, 5, flag, 1, 0x61);
    }
    ARC_TOOL_DeleteHandle(tmp);
}
