/*
 * function: func_02212740
 * address: 0x02212740
 * packet: pkt_ov199_02212740
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: allocator tag is u16; passing symbolic tag_2740 directly avoids truncating
 * the live offset variable and preserves the original instruction shape.
 * lever: enum tag 0x24F remains live and becomes offset 0x1B4.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02213804 0x02213804 thumb ov199
 *   func_02034714 0x02034714 arm
 *   func_02005C44 0x02005C44 thumb
 *   func_02005D90 0x02005D90 thumb
 *   d_02213D00 0x02213D00 data a1 ov199
 *   d_02213D04 0x02213D04 data a1 ov199
 */
#include "../include/Obj08368.h"
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern unsigned char func_02213804(char *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16 func_02005C44(void);
extern void func_02005D90(unsigned, unsigned);
extern const char d_02213D00[], d_02213D04[];
typedef enum { tag_2740 = 0x24f } Offset2740;
int *func_02212740(void *obj, unsigned heap, char *ctx)
{
    Offset2740 offset = tag_2740;
    int *p = func_02030734(heap, 0x18, 0, d_02213D04, tag_2740);
    func_02082BCC(p, 0, 0x18);
    p[0] = ((struct Obj08368 *)ctx)->f4;
    offset -= 0x9b;
    p[3] = ((struct Obj08368 *)ctx)->f28;
    p[4] = ((struct Obj08368 *)ctx)->f2C;
    p[5] = (int)(ctx + offset);
    switch (func_02213804(obj)) {
    case 4: case 7: p[1] = 1; break;
    case 8: p[1] = 6; break;
    case 3: p[1] = 4; break;
    case 6: p[1] = 5; break;
    case 0: p[1] = 0; break;
    case 1: case 2: case 5:
    default:
        if (((struct Obj08368 *)ctx)->f1C0) p[1] = 6;
        else func_02034714(d_02213D00, 0, d_02213D00);
        break;
    }
    if (func_02005C44() != 0x487) func_02005D90(0x487, 0xffff);
    return p;
}
