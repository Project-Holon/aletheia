/*
 * unit: yes
 * function: STA_ACT_LIGHT_CallElemB, STA_ACT_LIGHT_CallElemC
 * address: 0x021F80B0
 * packet: pkt_ov112_021F80B0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 * symbols:
 *   MUSICAL_MCSS_PauseRenderAnim 0x021F53B4 thumb ov112
 *   MUSICAL_MCSS_SetRenderDrawOffset 0x021F5424 thumb ov112
 *   MUSICAL_MCSS_SetRenderAnim 0x021F53CC thumb ov112
 */
typedef unsigned char u8;
typedef struct { u8 pad0[0x4c]; int zero; u8 pad50[8]; int target; } Obj;
extern void MUSICAL_MCSS_PauseRenderAnim(int);
extern void MUSICAL_MCSS_SetRenderDrawOffset(int, int);
extern void MUSICAL_MCSS_SetRenderAnim(int, unsigned int);
void STA_ACT_LIGHT_CallElemB(int a, Obj *b)
{
    MUSICAL_MCSS_PauseRenderAnim(b->target);
    b->zero = 0;
    MUSICAL_MCSS_SetRenderDrawOffset(b->target, 0);
}
void STA_ACT_LIGHT_CallElemC(int a, Obj *b, unsigned int c)
{
    MUSICAL_MCSS_SetRenderAnim(b->target, c);
}
