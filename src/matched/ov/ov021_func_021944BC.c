/*
 * function: FIELD_COMM_ACTOR_MoveInit
 * address: 0x021944BC
 * packet: pkt_ov021_021944BC
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_wfbc_p04.c and filed here.
 *
 * symbols:
 *   FLDMMDL_InitMoveProcWork 0x0216D684 thumb ov010
 */

void *FLDMMDL_InitMoveProcWork(int a0, int a1);
void *FIELD_COMM_ACTOR_MoveInit(int a);

void *FIELD_COMM_ACTOR_MoveInit(int a)
{
    return FLDMMDL_InitMoveProcWork(a, 0x10);
}
