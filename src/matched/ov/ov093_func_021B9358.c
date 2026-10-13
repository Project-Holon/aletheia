/*
 * function: BTL_MAIN_CopyLiveToSnapshotPoke
 * address: 0x021B9358
 * packet: pkt_ov093_021B9358
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_CopyMoves 0x021D54F4 thumb ov093
 */
struct Work;
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_CopyMoves(struct Work *, struct Work *);
void BTL_MAIN_CopyLiveToSnapshotPoke(char *p, int i)
{
    u8 *dst = BTL_SIDE_GetPokeByIdThunk(p + 0x1b0, i);
    u8 *src = BTL_SIDE_GetPokeByIdThunk(p + 0xc8, i);
    BTL_POKEPARAM_CopyMoves((struct Work *)src, (struct Work *)dst);
}
