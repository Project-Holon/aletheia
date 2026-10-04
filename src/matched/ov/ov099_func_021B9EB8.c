/*
 * function: func_021B9EB8
 * address:  0x021B9EB8
 * packet:   pkt_ov099_021B9EB8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
} Obj;

typedef struct {
    u16 a, b, c;
    u8 d, e;
} Rec;

struct Obj;
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, u16 f, u16 g);
extern void func_0204B3DC(u32 a, int b);
extern void func_0204B92C(struct Obj *a, u32 b);

void func_021B9EB8(Obj *o, int a)
{
    Rec r;

    r.a = 1;
    r.b = 1;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    o->f14 = (u32)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    r.c = 2;
    r.d = 0xfe;
    r.e = 3;
    o->f18 = (u32)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    func_0204B3DC(o->f14, 0);
    func_0204B3DC(o->f18, 0);
    func_0204B92C((struct Obj *)o->f14, 1);
    func_0204B92C((struct Obj *)o->f18, 1);
}
