/*
 * function: func_02029D8C
 * address:  0x02029D8C
 * packet:   pkt_02029D8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012984  0x02012984  thumb
 *   func_02029EB4  0x02029EB4  thumb
 *   func_020289F8  0x020289F8  thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
struct BigObj;
struct Sys;
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_02029EB4(void *a, u32 id, u32 which);
extern void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

void func_02029D8C(u32 a0, u32 a1, u32 a2)
{
    u32 temp = func_02012984((const struct BigObj *)a1);
    u32 res = func_02029EB4((void *)a1, a2, temp);
    func_020289F8((struct Sys *)a0, 5, res, 0x1e, 0);
}
