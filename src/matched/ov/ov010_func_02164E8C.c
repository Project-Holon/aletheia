/*
 * function: func_02164E8C
 * address: 0x02164E8C
 * packet: pkt_ov010_02164E8C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: ARM9 020267E4 unlabelled Thumb tail-call wrapper; no outside witness.
 * diagnostic: tu --suggest-split found one image-wide witness, at 02164E9C inside this caller; no viable partition.
 * extent: trailing two zero alignment bytes at 02164EB2; next labelled function 02164EB4.
 * symbols:
 *   func_02164EB4 0x02164EB4 thumb ov010
 *   GAME_BEACON_GetMyInfo 0x020267E4 thumb
 
 * 2026-10-05 (D8 lane 15): 020267E4 now filed EXACT as src/matched/arm9/GAME_BEACON_GetMyInfo.c (MI_CpuCopy8(GAME_BEACON_Work+4, p, 0x5C)).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Hdr { u8 x[2]; u8 b0:1; u8 b1:5; u8 b6:1; u8 b7:1; } Hdr;
extern void func_02164EB4(Hdr *,void *);
extern void GAME_BEACON_GetMyInfo(void *);
typedef struct Obj { void *src; u8 gap[12]; Hdr hdr; } Obj;
void *func_02164E8C(Obj *p) { func_02164EB4(&p->hdr,p->src); GAME_BEACON_GetMyInfo((u8 *)p+0x18); p->hdr.b1=2; return &p->hdr; }
