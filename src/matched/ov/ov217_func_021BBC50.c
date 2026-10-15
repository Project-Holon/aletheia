/*
 * function: RESEARCH_LIST_FindSaveIndex
 * address: 0x021BBC50
 * packet: pkt_ov217_021BBC50
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring the loop counter before data restores their original register colours.
 * arity: E44C reads only r0/r1, no calls/forwarding; legacy p2/p3 omitted. BC628 and E394 returns used live by this caller.
 * symbols:
 *   RESEARCH_LIST_GetAppResource 0x021BC628 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   MISC_SAVEDATA_GetStatusByte 0x0200E44C thumb
 *   d_021C308A 0x021C308A data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C30A8 0x021C30A8 data a1
 */
typedef unsigned char u8;
struct Big;
extern unsigned RESEARCH_LIST_GetAppResource(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern int MISC_SAVEDATA_GetStatusByte(int p0, int p1);
extern const u8 d_021C308A[], d_021C3080[], d_021C30A8[];
u8 RESEARCH_LIST_FindSaveIndex(u8 *p)
{
    u8 values[3];
    int i;
    void *data;
    u8 a, b, c, index;
    data = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_LIST_GetAppResource(p)));
    for (i = 0; i < 3; i++) values[i] = MISC_SAVEDATA_GetStatusByte((int)data, i);
    a = values[0];
    b = values[1];
    c = values[2];
    for (index = 0; index < 10; index++)
        if (a == d_021C30A8[index] && b == d_021C3080[index] && c == d_021C308A[index]) return index;
    return 0;
}
