/*
 * function: func_021B45A0
 * address:  0x021B45A0
 * packet:   pkt_ov021_021B45A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 *
 * symbols:
 *   func_02020D0C 0x02020D0C thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_021B44CC 0x021B44CC thumb ov021
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 id;
    u16 pad;
    u32 v;
} Ent;

struct Bmp;
struct StrObj;
struct WordSet;
extern u32 func_02020D0C(u8 *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_021B44CC(u32 a, u32 b, int c, int d, u32 e, u32 f, u16 g);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void func_021B45A0(u32 ctx, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C((void *)ctx);
    if (a != -2) {
        if (func_02007F68((u8 *)(*(u32 *)(w + 0x10)), ((Ent *)(w + 0x20))[a].id, 1, *(u16 *)(w + 4)) != 0) {
            lo = func_0201D304((struct StrObj *)(*(u32 *)(w + 0x1A0)), *(u32 *)(w + 8), 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x16C))));
            func_021B44CC(*(u32 *)(w + 0x1B0), (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x16C)), hi - lo, b,
                          *(u32 *)(w + 0x1A0), *(u32 *)(w + 8), 0x31A0);
        } else {
            func_0201EFA4((struct WordSet *)(*(u32 *)(w + 0x190)), 1, ((Ent *)(w + 0x20))[a].v, 5, 1, 1);
            func_0201F250((struct WordSet *)(*(u32 *)(w + 0x190)), (void *)(*(u32 *)(w + 0x198)), (void *)(*(u32 *)(w + 0x194)));
            lo = func_0201D304((struct StrObj *)(*(u32 *)(w + 0x198)), *(u32 *)(w + 8), 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x16C))));
            func_021B44CC(*(u32 *)(w + 0x1B0), (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x16C)), hi - lo, b,
                          *(u32 *)(w + 0x198), *(u32 *)(w + 8), 0x31A0);
        }
    }
}
