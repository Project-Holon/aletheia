/*
 * function: GURU2_MAIN_RotateAll
 * address: 0x021E1604
 * packet: pkt_ov137_021E1604
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_MAIN_AddAngle 0x021E0634 thumb ov137
 *   GURU2_MAIN_RotatePlayerRecords 0x021E0980 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_MAIN_AddAngle(u8 *p, int a);
extern void GURU2_MAIN_RotatePlayerRecords(char *, int);
void GURU2_MAIN_RotateAll(char *p, int v)
{
    GURU2_MAIN_AddAngle((u8 *)(p + 0xe0), v);
    GURU2_MAIN_RotatePlayerRecords(p, v);
}
