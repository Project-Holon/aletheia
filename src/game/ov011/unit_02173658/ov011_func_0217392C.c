/*
 * function: func_0217392C
 * address:  0x0217392C
 * packet:   pkt_ov011_0217392C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020264B4  0x020264B4  thumb
 *   func_02174F54  0x02174F54  thumb ov011
 */
#include "../../../matched/include/Obj00269.h"

struct Entry;
struct Entry *func_020399A8(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Link;
u32 func_0203D1A4(struct Link *p);
void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
struct Ent;
void func_02174F54(u8 *p, int idx, const struct Ent *src, int arg);

typedef struct C {
    char pad[0x14];
    unsigned short w14;
    unsigned short f : 3;
} C;

void func_0217392C(int a, int b, const C *c, unsigned char *d)
{
    if (a == func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        func_020264B4((void *)(((struct Obj00269 *)d)->f4), a, c->w14, c->f, 0x15, 0);
    } else if ((d[0x8FB] & (1 << a)) != 0) {
        func_02174F54(d, a, (const struct Ent *)c, 0);
    }
}
