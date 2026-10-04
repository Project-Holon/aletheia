/*
 * function: func_021D75E8
 * address: 0x021D75E8
 * packet: pkt_ov125_021D75E8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0214616C 0x0214616C data a4
 */
typedef unsigned short u16;
extern char *d_0214616C;
typedef unsigned int   u32;
struct BattleRec;
extern u32 func_0200B67C(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e);
int func_021D75E8(int a, int x, int y, u16 *state, int b, u16 c)
{
    char *p;
    switch (*state) {
    case 0:
        p = d_0214616C;
        *(int *)(p + 0xb8) = x;
        *(int *)(p + 0xbc) = y;
        ++*state;
        break;
    case 1:
        return func_0200B67C((void *)a, (struct BattleRec *)d_0214616C, 0, (u16 *)b, c);
    }
    return 0;
}
