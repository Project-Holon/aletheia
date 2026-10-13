/*
 * function: func_0220B904
 * address:  0x0220B904
 * packet:   pkt_0220B904
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0220B928 0x0220B928 thumb
 */
#include "../include/Obj14543.h"

extern void func_0201F73C(void *, int, int, int);
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0220B928(char *p);

void func_0220B904(char *p)
{
    func_0201F73C(((struct Obj14543 *)p)->f24, 2, 1, 0xb);
    BMP_Clear(func_02045770(((struct Obj14543 *)p)->f24), 0xf);
    func_0220B928(p);
}
