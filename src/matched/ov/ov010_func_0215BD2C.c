/*
 * function: func_0215BD2C
 * address:  0x0215BD2C
 * packet:   pkt_ov010_0215BD2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to func_020180F4 (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise func_020181F4 sets the move into the slot.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017D30  0x02017D30  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017D70  0x02017D70  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02159B10(void *c, void *vm);
struct Sav;
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017D30(struct Sav *p);
extern void func_020180F4(void *p, u16 move);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u8 slot);
extern u32 func_02017D70(struct Sav *p, u32 f);

int func_0215BD2C(void *c, void *vm)
{
    u16 slot;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    slot = func_02159B10(c, vm);
    moveSlot = func_02159B10(c, vm);
    move = func_02159B10(c, vm);
    if (func_0215B4AC(vm, slot, &mon) == 0) {
        return 0;
    }
    saved = func_02017D30(mon);
    if (moveSlot > 4) {
        func_020180F4(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = func_02017E1C(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = func_02017E1C(mon, i + 0x3F, 0);
                pp = func_02017E1C(mon, i + 0x3B, 0);
                func_02017E40(mon, i + 0x36, m);
                func_02017E40(mon, i + 0x3E, ppUp);
                func_02017E40(mon, i + 0x3A, pp);
            }
        }
        func_02017E40(mon, i + 0x36, 0);
        func_02017E40(mon, i + 0x3E, 0);
        func_02017E40(mon, i + 0x3A, 0);
    } else {
        func_020181F4(mon, move, moveSlot);
    }
    func_02017D70(mon, saved);
    return 0;
}
