/*
 * function: func_021B9968
 * address:  0x021B9968
 * packet:   pkt_ov099_021B9968
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021BA168  0x021BA168  thumb
 *   func_021BA04C  0x021BA04C  thumb
 *   func_021BA1C4  0x021BA1C4  thumb
 *   func_021BA248  0x021BA248  thumb
 *   func_021BA190  0x021BA190  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
} Work;

extern Pos func_021C4AC4(void *v);
typedef unsigned int   u32;
extern u8 *func_021BA168(u8 *p);
extern void func_021BA04C(char *p, u16 *out, u32 c);
extern void func_021BA1C4(u8 *p, void **out, short *xy, int a, u16 d, u8 c, int b);
extern void func_021BA248(void *o, void *e);
extern void func_021BA190(u8 *p, u8 *s, int n);

void *func_021B9968(Work *o, int a, int b)
{
    void *e;
    Pos t;
    Pos d;

    e = func_021BA168((u8 *)o);
    func_021BA04C((char *)o, (u16 *)(&t), b - 1);
    if (o->f570 != 0) {
        d = func_021C4AC4(*o->f570);
        if (d.x == t.x && d.y == t.y)
            return 0;
    }
    func_021BA1C4((u8 *)o, e, (short int *)(&t), b, a, 1, 4);
    func_021BA248(o, e);
    func_021BA190((u8 *)o, e, 0);
    return e;
}
