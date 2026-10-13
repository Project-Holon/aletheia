/*
 * function: SCRCMD_POKEMON_FLD_SetWarpTable
 * address:  0x021B6AE0
 * packet:   pkt_ov021_021B6AE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   SCRCMD_WORK_SetFadeState  0x0215A6D0  thumb ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void SCRCMD_WORK_SetFadeState(void *p, u32 v);

int SCRCMD_POKEMON_FLD_SetWarpTable(Ctx *c, void *b)
{
    SCRCMD_WORK_SetFadeState(b, (u32)(c->p + VM_GetU32((struct Cursor *)c)));
    return 0;
}
