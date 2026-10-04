/*
 * function: func_021B6850
 * address:  0x021B6850
 * packet:   pkt_ov021_021B6850
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scan a 24 x 30 grid, starting the row at func_02007698()'s offset, for
 * the first cell whose four func_020079BC properties match.
 *
 * b is u16: with a u32 b the bytes are the same except that the third
 * call's stack-argument store (`str r7,[sp]`, the hoisted zero) moves
 * after the register arguments, as in the other three calls.  The width
 * leaves no instruction of its own (the spill and reload stay full words
 * and the compare needs no extension); it only moves that store.
 * Stack slots need the declaration order base, i, t10, j.
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02007698  0x02007698  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020079BC  0x020079BC  thumb
 *   _s32_div_f     0x0209C0A4  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern void *func_02012934(const struct BigObj *p);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_02007698(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);

int func_021B6850(u32 a, u16 b, u16 *c, u16 *d)
{
    int base;
    int i;
    u32 t10;
    int j;
    int m;
    u32 r4;
    u32 r6;

    func_02012934((void *)a);
    r4 = (u32)func_02012944((void *)a);
    r6 = func_0201293C((const struct BigObj *)a);
    base = func_02007698();
    t10 = func_02008530((const struct Sub0200852CObj *)r4);
    for (i = 0; i < 24; i++) {
        m = (i + base) % 24;
        for (j = 0; j < 30; j++) {
            if (func_020079BC((void **)r6, m, j, 0xa9, 0) != 0
                && t10 == func_020079BC((void **)r6, m, j, 7, 0)
                && b == func_020079BC((void **)r6, m, j, 5, 0)
                && func_020079BC((void **)r6, m, j, 0x4c, 0) == 0) {
                *c = m;
                *d = j;
                return 1;
            }
        }
    }
    return 0;
}
