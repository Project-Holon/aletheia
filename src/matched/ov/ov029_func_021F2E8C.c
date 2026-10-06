/*
 * function: func_021F2E8C
 * address:  0x021F2E8C
 * packet:   pkt_ov029_021F2E8C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B918  0x0204B918  arm
 *   func_0202173C  0x0202173C  thumb
 *   d_021F3224     0x021F3224  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);
struct Obj;
extern u16 func_0204B918(struct Obj *p);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern const unsigned int d_021F3224[];

int func_021F2E8C(char *p)
{
    if (*(int *)(p + 0) == 0)
        return 1;
    if (func_0204B98C(*(void **)(p + 8)) == 0) {
        *(int *)(p + 0) = 0;
        return 1;
    }
    func_0202173C(*(void **)(p + 0xC), 8, *(int *)(p + 4), -0x78, 0,
                  (u8)d_021F3224[func_0204B918(*(void **)(p + 8))], 0,
                  *(void **)(p + 0x10));
    return 0;
}
