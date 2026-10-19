/*
 * function: WIFI_BSUBWAY_SaveTrainers
 * address: 0x021D6AF0
 * packet: pkt_ov116_021D6AF0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave D6 lane18): blocker closed. arm9 0x0200DD28 is 100 bytes (not 104) and is now EXACT in
 * src/matched/arm9/BSUBWAY_WIFIDATA_SetTrainerBit.c (u8 mask = 1 at the top, `mask <<= (u8)(idx % 8)`). This draft is byte-equal;
 * it becomes EXACT once the integrator registers the new arm9 file (manifest), then move it to src/matched/ov/.
 * 2026-10-05 (wave D5 lane 02): fresh tries on arm9 0x0200DD28, all DIFF (98..102 bytes vs 104): mask as u8 local
 * initialised before the guards (movs r3,#1 at the top), u32 mask with (u8) cast at the OR, bit-set via mask <<=,
 * index as named u8, slot as u32 with (u16) cast, stamp as u32[4] and as a struct, first OR operands swapped.
 * Residue: the original saves only r4..r6 (push {r3,r4,r5,r6} is alignment padding) and keeps p in r0; every
 * spelling saves four registers and moves p to r4 because the pack expression uses r0 as scratch. Not filed.
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by arm9 0x0200DD28 (no label); not re-tested further.
 * blocker: ARM9 0x0200DD28 has no outside code witness. Blocker C attempted
 * in scratch blocker-DD28.c; best run DD28-r3.log is DIFF (102 bytes vs 100).
 * The existing ARM9 unit_0200DD10.c also records this function's near miss.
 * blocker: 0x0200DD28 best attempted C below is DIFF, not verified EXACT:
 *   typedef unsigned char B_u8;
 *   typedef unsigned short B_u16;
 *   typedef unsigned int B_u32;
 *   void BSUBWAY_WIFIDATA_SetTrainerBit(B_u8 *p,B_u32 a,B_u32 b,B_u32 *date) {
 *       B_u16 slot; B_u8 mask=1; B_u8 bit;
 *       if(b != 0 && b <= 200 && a != 0 && a <= 10) {
 *           slot=(b-1)+(a-1)*200; bit=slot%8; mask=mask<<bit;
 *           (p+4)[(B_u8)(slot/8)] |= mask;
 *           *(B_u32 *)p=(date[0]<<24)|((date[1]<<24)>>8)
 *                       |((date[2]<<24)>>16)|date[3];
 *       }
 *   }
 * symbols:
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   BSUBWAY_WIFIDATA_SetTrainerBit 0x0200DD28 thumb
 *   BSUBWAY_SAVEDATA_SetTrainers  0x0200DE6C  thumb  arm9
 */

/*
 * 2026-10-04 (wave D2 lane05): MATCH, rechecked: bytes equal, one relocation unresolved: arm9 BSUBWAY_WIFIDATA_SetTrainerBit has no witness (104-byte save-bitmap setter, 16 spellings already recorded in unit_0200DD10.c). Blocked on that arm9 leaf only.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int DWC_GetDateTime(void *, void *);
struct RecSlot;
extern void BSUBWAY_SAVEDATA_SetTrainers(struct RecSlot *p, const void *src, u8 a, u8 b);
extern void BSUBWAY_WIFIDATA_SetTrainerBit(u8 *p, u8 a, u8 b, u32 *q);
void WIFI_BSUBWAY_SaveTrainers(u8 *p, void *q) {
    u32 time[3];
    u32 date[4];
    DWC_GetDateTime(date, time);
    BSUBWAY_SAVEDATA_SetTrainers(q, p + 14, *(u16 *)(p + 8), *(u16 *)(p + 10));
    BSUBWAY_WIFIDATA_SetTrainerBit(q, *(u16 *)(p + 8), *(u16 *)(p + 10), date);
}
