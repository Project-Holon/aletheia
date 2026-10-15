/*
 * function: GTSNEGO_MSG_ScrollAllRows
 * address: 0x021D70C8
 * packet: pkt_ov120_021D70C8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * matching: initialize i before calculating step to schedule the zero before mul.
 * symbols:
 *   GTSNEGO_MSG_MoveListActor 0x021D71E8 thumb ov120
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern void GTSNEGO_MSG_MoveListActor(u8 *, int, int);
void GTSNEGO_MSG_ScrollAllRows(u8 *p, int flag)
{
    int i;
    int direction = 1;
    int step;
    if (flag != 0) direction -= 2;
    i = 0;
    step = direction * 48;
    for (; i < 6; i++) GTSNEGO_MSG_MoveListActor(p, i, step);
}
