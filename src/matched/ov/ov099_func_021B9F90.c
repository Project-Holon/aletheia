/*
 * function: func_021B9F90
 * address:  0x021B9F90
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B528  0x0204B528  arm
 *   func_0204B800  0x0204B800  arm
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x2c];
    void *f2c;              /* 0x2c */
} Obj;

extern void func_0204B528(void *o, Pos *p);
extern void func_0204B800(void *o, int v);
extern void func_0204B3DC(void *o, int v);

void func_021B9F90(Obj *o, Pos pos, int c)
{
    Pos t;

    t.x = pos.x + 8;
    t.y = pos.y;
    func_0204B528(o->f2c, &t);
    func_0204B800(o->f2c, (unsigned char)c);
    func_0204B3DC(o->f2c, 1);
}
