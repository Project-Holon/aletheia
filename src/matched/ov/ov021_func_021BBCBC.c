/*
 * function: func_021BBCBC
 * address:  0x021BBCBC
 * packet:   pkt_ov021_021BBCBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_021BBD0C  0x021BBD0C  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef unsigned char  u8;
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C88(u8 *p);
extern void func_021BBD0C(void *p);
extern const char d_021DE30C[];

typedef struct {
    void *owner;
    void *res;
    char pad[0x34];
    int f3c;
} Obj;

Obj *func_021BBCBC(void *owner, u32 heap)
{
    Obj *o;

    o = func_02030734(heap, 0x40, 1, d_021DE30C, 0x9d);
    o->owner = owner;
    o->res = (void *)func_02188C88((u8 *)func_021ABE14(owner));
    func_021BBD0C(o);
    o->f3c = 0x2000;
    return o;
}
