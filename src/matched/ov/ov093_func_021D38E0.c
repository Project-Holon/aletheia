/*
 * function: BTL_CLIENT_CmdSetSick
 * address: 0x021D38E0
 * packet: pkt_ov093_021D38E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A declared one-word S local assigned from c[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast S lvalue at
 * c+2 compiled 30 bytes with the wrong frame and redundant address add.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetSickCont 0x021D6034 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
typedef struct { int x; } S;
extern void BTL_POKEPARAM_SetSickCont(u8 *, int, S);
int BTL_CLIENT_CmdSetSick(u32 *a, int b, u32 *c)
{
    u8 *m;
    S s;

    m = BTL_SIDE_GetPokeByIdThunk((char *)a[1], (u8)c[0]);
    s.x = c[2];
    BTL_POKEPARAM_SetSickCont(m, c[1], s);
    return 1;
}
