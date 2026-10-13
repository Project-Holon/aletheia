/*
 * function: ACTOR_TOOL_LoadCharSimple
 * address:  0x02025440
 * packet:   pkt_020251FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   ACTOR_TOOL_AllocRun  0x02025360  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct ActorTool;
extern int ACTOR_TOOL_AllocRun(struct ActorTool *p, int len, u32 bank);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

int ACTOR_TOOL_LoadCharSimple(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 v = ACTOR_TOOL_AllocRun((struct ActorTool *)a0, a4, a3);

    return CLACT_RegisterPaletteCompressed((void *)a1, a2, a3, (v & 0x7ff) << 5, (u16)a5);
}
