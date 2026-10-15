/*
 * function: RESEARCH_TOP_RegisterVBlank
 * address:  0x021BAB58
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both blockers now resolved.  0x02005654 was matched in arm9 (src/matched/
 * func_02005654.c, shard pkt_02005654); it is Thumb.  0x021BAB50 is the
 * 8-byte tail-call thunk `ldr r3,[pc]; bx r3; .word 0x0204A648` in ov217,
 * matched as C (src/matched/ov217_func_021BAB50.c, shard
 * pkt_ov217_021BAB50); its own pool target 0x0204A648 is an EXACT arm9
 * entry, so the ABS32 site attests as `matched` in ov217.
 *
 * symbols:
 *   RESEARCH_TOP_UpdateVBlank  0x021BAB50  thumb  ov217
 *   func_02005654  0x02005654  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int func_02005654(int a, int b);
extern void RESEARCH_TOP_UpdateVBlank();
void RESEARCH_TOP_RegisterVBlank(void *a0)
{
    func_02005654((int)RESEARCH_TOP_UpdateVBlank, 0);
}

