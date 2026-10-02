/*
 * function: func_021E6BF4
 * address: 0x021E6BF4
 * packet: pkt_ov093_021E6BF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Both loop bounds and their accessor returns are u8; u32 n loses
 * its pre-loop reload, and u32 count schedules its reload before i's spill.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7FCC 0x021C7FCC thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021E6CC0 0x021E6CC0 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C8030 0x021C8030 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7FCC(void *, int);
extern void *func_021C8120(void *, int);
extern u8 func_021B9B94(void *);
extern void *func_021B9C00(void *, int);
extern u8 func_021D5440(void *);
extern u8 func_021D5448(void *);
extern u16 func_021D54C0(void *, int);
extern int func_021E6CC0(u16);
extern u32 func_021D78AC(u32);
extern int func_021C8030(void *, int, u16);
extern int func_021D76BC(int, u32);
void func_021E6BF4(void *x, void *a, int c)
{
    void *party;
    u16 *moves;
    u8 count;
    u8 i;
    u8 n;
    u8 used, j;
    void *mon;
    u16 move;
    u8 pick;
    int slot;
    if (c == func_021D775C(2)) {
        party = func_021C7FCC(a, c);
        moves = func_021C8120(a, 48);
        used = 0;
        count = func_021B9B94(party);
        for (i = 0; i < count; i++) {
            mon = func_021B9C00(party, i);
            if (c != func_021D5440(mon)) {
                n = func_021D5448(mon);
                for (j = 0; j < n; j++) {
                    move = func_021D54C0(mon, j);
                    if (func_021E6CC0(move) == 0) {
                        moves[used++] = move;
                    }
                }
            }
        }
        if (used != 0) {
            pick = func_021D78AC(used);
            slot = func_021C8030(a, c, moves[pick]);
            func_021D76BC(18, moves[pick]);
            func_021D76BC(13, slot);
        }
    }
}
