/*
 * function: func_021F3214
 * address:  0x021F3214
 * packet:   pkt_ov032_021F3214
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA20 0x0204BA20 arm
 */

typedef struct {
    short x;
    short y;
    unsigned short w;
    unsigned char z;
    unsigned char h;
} Rect;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA20(struct Actor *a, u32 v);

void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z)
{
    Rect r;
    void *res;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    r.z = z;
    res = func_0204B294((void *)*(unsigned *)(p + 0x128), a, b, c, &r, 0, *(unsigned short *)(p + 0x94));
    func_0204B92C(res, 1);
    func_0204BA20(res, 0);
    return res;
}
