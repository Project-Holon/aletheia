/*
 * function: POKETRADE_2D_DrawBoxGridScreen
 * address: 0x021E42B4
 * packet: pkt_ov119_021E42B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb ov119
 *   POKETRADE_2D_HitTestBoxGrid 0x021E421C thumb ov119
 *   POKETRADE_2D_GetBoxScreenEntry 0x021E41A0 thumb ov119
 *   func_02042FB0 0x02042FB0 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
extern int POKETRADE_2D_GetScrollColumn(char *);
extern int POKETRADE_2D_HitTestBoxGrid(char *, int, int);
extern unsigned short POKETRADE_2D_GetBoxScreenEntry(int, int, char *, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void func_02041B6C(u32 bit);
void POKETRADE_2D_DrawBoxGridScreen(char *p)
{
    int x, y, n, mode;
    n = ((struct Obj00001 *)p)->f107C / 8;
    POKETRADE_2D_GetScrollColumn(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = POKETRADE_2D_HitTestBoxGrid(p, x, y);
            func_02042FB0(7, x, y, POKETRADE_2D_GetBoxScreenEntry(n + x, y, p, mode));
        }
    }
    ((struct Obj00001 *)p)->f108C = ((struct Obj00001 *)p)->f107C % 8;
    ((struct Obj00001 *)p)->f1084 = 1;
    func_02041B6C(7);
}
