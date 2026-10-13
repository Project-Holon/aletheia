/*
 * function: func_021BF450
 * address: 0x021BF450
 * packet: pkt_ov208_021BF450
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Byte-based state indexing preserves the shared 20-byte stride; u32 indexing changes it to shift/add.
 * symbols:
 *   func_021BC3B4 0x021BC3B4 thumb ov208
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021BDC48 0x021BDC48 thumb ov208
 */
#include "../include/Obj10901.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Actor;
struct Obj;
struct Ov208Scene;
extern int func_021BC3B4(int *p);
extern unsigned CLACT_IsActorAnimActive(struct Actor *);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern void func_021BDC48(struct Ov208Scene *, unsigned);
void func_021BF450(void *unused, char *p, int key)
{
    void *scene = (void *)func_021BC3B4((int *)key);
    if (((struct Obj10901 *)p)->f94 != 6) {
        u8 i = ((struct Obj10901 *)p)->f94;
        char *states = p + 0x2c;
        switch (*(unsigned *)(states + i * 20)) {
        case 0: break;
        case 1: *(unsigned *)(states + i * 20) = 2; break;
        case 2:
            if (CLACT_IsActorAnimActive(*(struct Actor **)(p + i * 20 + 0x1c)) == 0)
                *(unsigned *)(states + i * 20) = 3;
            break;
        case 3:
            CLACT_SetActorAnimSeq(*(struct Obj **)(p + i * 20 + 0x1c), *(u16 *)(p + i * 20 + 0x24));
            *(unsigned *)(states + i * 20) = 0;
            ((struct Obj10901 *)p)->f94 = 6;
            func_021BDC48(scene, 1);
            break;
        }
    }
}
