/*
 * function: func_021BF910
 * address: 0x021BF910
 * packet: pkt_ov217_021BF910
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF740 0x021BF740 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E3A0 0x0200E3A0 thumb
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   func_021BF968 0x021BF968 thumb ov217
 *   func_0200E3A4 0x0200E3A4 thumb
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Big;
extern u32 func_021BF740(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *func_0200E394(void *a0);
extern void *func_0200E3A0(void *a);
extern u32 func_021BF7CC(void *);
extern u32 func_021BF968(u8 *);
extern u32 func_0200E3A4(const u8 *, int);
extern u32 GRAPHTABLE_GetEntryId(void *, u32, u8);
u32 func_021BF910(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = func_0200E3A0(func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BF740(p))));
    index = func_021BF7CC(p);
    if (index == 29) return func_021BF968(p);
    n = func_0200E3A4((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)GRAPHTABLE_GetEntryId(p + 0x38, p[0x2b8], n);
}
