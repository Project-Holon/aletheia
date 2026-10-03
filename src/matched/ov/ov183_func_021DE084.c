/*
 * function: func_021DE084
 * address: 0x021DE084
 * packet: pkt_ov183_021DE084
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021DE15C 0x021DE15C thumb ov183
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct Position { s16 x, y, z; u8 a, b; } Position;
extern void func_02082BCC(void *, int, unsigned int);
extern void *func_0204B294(void *, void *, void *, void *, Position *, u16, u16);
typedef unsigned int   u32;
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021DE15C(char *, unsigned int);
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap)
{
    Position pos;
    int base;
    int i;
    func_02082BCC(p, 0, 0x14);
    func_02082BCC(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    *(void **)p = func_0204B294(manager, *(void **)(q + 4), *(void **)(q + 8), *(void **)q, &pos, 0, heap);
    func_0204B688(*(void **)p, 1);
    pos.z = 0;
    base = x;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = p + i * 4;
        *(void **)(slot + 4) = func_0204B294(manager, *(void **)(q + 4), *(void **)(q + 8), *(void **)q, &pos, 0, heap);
        func_0204B688(*(void **)(slot + 4), 1);
    }
    func_021DE15C(p, value);
}
