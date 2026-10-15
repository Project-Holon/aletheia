/*
 * function: RESEARCH_LIST_CreateUnits
 * address: 0x021BCF68
 * packet: pkt_ov217_021BCF68
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { char pad0[8]; u16 h8; char pad[0x10a]; int arr[3]; };
extern const u8 d_021C305C[];
extern const u16 d_021C3060[];
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

void RESEARCH_LIST_CreateUnits(struct S *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->arr[i] = (int)CLACT_CreateUnit(d_021C3060[i], d_021C305C[i], p->h8);
    }
}
