/*
 * function: func_021F0C44
 * address:  0x021F0C44
 * packet:   pkt_ov033_021F0C44
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202173C 0x0202173C thumb
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B974 0x0204B974 arm
 */
#include "../include/Obj00323.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;

struct Actor;
struct Ctx;
extern void func_02030D28(struct Ctx *c);
extern u32 func_02021ED8(const char *ptr);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void func_0204B95C(struct Actor *a);
extern void func_0204B974(struct Actor *a);

void func_021F0C44(char *p)
{
    u16 m;
    u8 i;

    func_02030D28(((struct Obj00323 *)p)->fB4);
    if (((struct Obj00323 *)p)->fC0 == 0 || func_02021ED8(((struct Obj00323 *)p)->fBC) != 0)
        return;
    switch (((struct Obj00323 *)p)->fC0) {
    case 1:
        if (((struct Obj00323 *)p)->fC4 != 0) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            func_0202173C(((struct Obj00323 *)p)->fBC, 2, m, 0, 0, 0, 0, ((struct Obj00323 *)p)->fB4);
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            func_0202173C(((struct Obj00323 *)p)->fBC, 8, m, 0, 0, 0, 0, ((struct Obj00323 *)p)->fB4);
            ((struct Obj00323 *)p)->fC4 = 0;
            for (i = 0; i < 4; i++)
                func_0204B95C(*(void **)(p + i * 12 + 0x38));
        }
        break;
    case 2:
        if (((struct Obj00323 *)p)->fC4 != 1) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            func_0202173C(((struct Obj00323 *)p)->fBC, 2, m, 0, 8, 8, 0, ((struct Obj00323 *)p)->fB4);
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            func_0202173C(((struct Obj00323 *)p)->fBC, 8, m, 0, 8, 8, 0, ((struct Obj00323 *)p)->fB4);
            ((struct Obj00323 *)p)->fC4 = 1;
            for (i = 0; i < 4; i++)
                func_0204B974(*(void **)(p + i * 12 + 0x38));
        }
        break;
    }
    ((struct Obj00323 *)p)->fC0 = 0;
}
