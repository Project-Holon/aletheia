/*
 * function: func_021F1C0C
 * address:  0x021F1C0C
 * packet:   pkt_ov029_021F1C0C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 */
#include "../include/Obj00709.h"

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
typedef unsigned int   u32;
struct Actor;
extern void func_0204BA20(struct Actor *a, u32 v);

void func_021F1C0C(char *p)
{
    S13Rec s;

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x28;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f164 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f164, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f164), 0);

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x27;
    s.a = 0x14;
    s.b = 2;
    ((struct Obj00709 *)p)->f168 = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f168, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f168), 0);

    s.x = 0x22;
    s.y = 0xaa;
    s.z = 0x10;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f16C = (int)func_0204B294((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    func_0204B3DC((struct Obj *)((struct Obj00709 *)p)->f16C, 0);
    func_0204BA20((struct Actor *)(((struct Obj00709 *)p)->f16C), 0);
}
