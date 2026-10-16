/*
 * function: C_GEAR_StartSelectedRipple
 * address: 0x021F3098
 * packet: pkt_ov029_021F3098
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_GetCellKind 0x021F2B9C thumb ov029
 *   C_GEAR_SpawnRippleActor 0x021EFF58 thumb ov029
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 C_GEAR_GetCellKind(u8 *p, int row, int col);
extern void C_GEAR_SpawnRippleActor(u8 *, int, int);
void C_GEAR_StartSelectedRipple(u8 *p)
{
    p[0x414] = C_GEAR_GetCellKind(p, p[0x452], p[0x453]);
    p[0x415] = 0;
    C_GEAR_SpawnRippleActor(p, p[0x452], p[0x453]);
}
