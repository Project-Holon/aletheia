/*
 * function: FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe
 * address: 0x021F3B30
 * packet: pkt_ov053_021F3B30
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MIi_CpuClear32 0x02082A7C arm
 */

extern void MIi_CpuClear32(int, void *, unsigned int);
void FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(void *p) { MIi_CpuClear32(0,p,0x90); }
