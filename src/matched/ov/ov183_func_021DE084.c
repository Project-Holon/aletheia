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
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021DE15C 0x021DE15C thumb ov183
 */
#include "../include/Obj05472.h"
#include "../include/Obj14427.h"
#include "../include/Obj14428.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct Position { s16 x, y, z; u8 a, b; } Position;
extern void func_02082BCC(void *, int, unsigned int);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
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
    ((struct Obj14427 *)p)->f0 = CLACT_CreateActor(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
    func_0204B688(((struct Obj14427 *)p)->f0, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = p + i * 4;
        ((struct Obj14428 *)slot)->f4 = CLACT_CreateActor(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
        func_0204B688(((struct Obj14428 *)slot)->f4, 1);
    }
    func_021DE15C(p, value);
}
