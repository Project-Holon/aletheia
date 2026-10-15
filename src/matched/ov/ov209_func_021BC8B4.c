/*
 * function: ZUKAN_LIST_MoveScrollBarActorsIn
 * address: 0x021BC8B4
 * packet: pkt_ov209_021BC8B4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding
 * symbols:
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   ZUKAN_LIST_GetActorPos 0x021BD958 thumb ov209
 *   ZUKAN_LIST_AddActorPos 0x021BD934 thumb ov209
 */
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void ZUKAN_LIST_GetActorPos(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern void ZUKAN_LIST_AddActorPos(char *p, int idx, short a, short b, unsigned short c);
void ZUKAN_LIST_MoveScrollBarActorsIn(char *p)
{
    unsigned i;
    s16 pair[2];
    BG_SYS_ResetSlot(5, 3, 48);
    BG_SYS_ResetSlot(1, 3, -48);
    for (i = 3; i <= 9; i++) {
        ZUKAN_LIST_GetActorPos(p, i, &pair[1], &pair[0], 0);
        pair[0] += 48;
        ZUKAN_LIST_AddActorPos(p, i, pair[1], pair[0], 0);
    }
}
