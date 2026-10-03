/*
 * function: func_0215BE24
 * address:  0x0215BE24
 * packet:   pkt_ov010_0215BE24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (func_0204589C answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_020457B0  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   func_0204589C  0x0204589C  arm
 *   func_02045808  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *c, void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern void *func_0215A5E4(void *vm);
struct Buf;
struct Sub0200852CObj;
struct U16Vec;
extern u8 *func_02012944(void *p);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u16 func_0215A5CC(void *a0);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 g0209DF08;

int func_0215BE24(void *c, void *vm)
{
    void *player;
    void *mon;
    u16 *res;
    u16 slot;
    u32 heap;
    void *a;
    void *b;
    u32 ver;

    res = func_02159AE8(c, vm);
    slot = func_02159B10(c, vm);
    player = func_02012944(func_0215A5E4(vm));
    mon = 0;
    if (!func_0215B4AC(vm, slot, &mon)) {
        *res = 0;
        return 0;
    }
    if (func_02017E1C(mon, 7, 0) != func_02008530(player)) {
        *res = 0;
        return 0;
    }
    heap = func_0215A5CC(vm);
    a = func_020457B0(16, heap);
    b = func_020457B0(16, heap);
    if (a != 0 && b != 0) {
        func_02017E1C(mon, 0x8D, (u32)a);
        func_02008500(player, b);
        if (func_0204589C(a, b) == 0) {
            func_02045808(a);
            func_02045808(b);
            *res = 0;
            return 0;
        }
    } else {
        *res = 0;
        return 0;
    }
    func_02045808(a);
    func_02045808(b);
    if (func_02017E1C(mon, 0x9A, 0) != func_02008550(player)) {
        *res = 0;
        return 0;
    }
    ver = func_02017E1C(mon, 0x77, 0);
    if (ver != g0209DF08) {
        *res = 0;
        return 0;
    }
    *res = 1;
    return 0;
}
