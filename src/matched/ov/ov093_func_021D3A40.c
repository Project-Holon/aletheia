/*
 * function: BTL_CLIENT_StepRecordMoveUse
 * address: 0x021D3A40
 * packet: pkt_ov093_021D3A40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_RecordMoveUse 0x021D6744 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_RecordMoveUse(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
int BTL_CLIENT_StepRecordMoveUse(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    BTL_POKEPARAM_RecordMoveUse(x, c[1], c[2], c[3], c[4], c[5]);
    return 1;
}
