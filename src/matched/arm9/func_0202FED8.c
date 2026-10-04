/*
 * function: func_0202FED8
 * address:  0x0202FED8
 * packet:   pkt_0202FED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02060C5C  0x02060C5C  arm
 *   g_02146954     0x02146954  data
 *
 * Scans the 0x02146954 table for the first free 16-byte slot: a slot whose
 * first word is NULL is claimed with func_02060C5C(a2, a3, 0); a failed
 * claim sets the status halfword at +0xe to 5 and moves on, a success fills
 * the slot, records the slot index in the byte map at +4 and returns 1.
 * Falling off the end sets the status to 4 and returns 0.
 *
 * The table address is a declared symbol, not a cast constant: the image
 * reloads it from its own pool slot after the claim call (two pool words for
 * the same address at 0x0202FF94 and 0x0202FFBC), which a plain constant
 * would let mwcc keep in a callee-saved register.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
} Ent0202FED8;

typedef struct {
    Ent0202FED8 *f00;
    u8          *f04;
    u16          f08;
    u16          f0a;
    u16          f0c;
    u16          f0e;
} Ctx0202FED8;

extern Ctx0202FED8 g_02146954;
extern void *func_02060C5C(void *start, u32 size, u32 attr);

int func_0202FED8(u32 a0, u32 a1, u32 a2, u32 a3)
{
    int i;

    for (i = g_02146954.f0a; i < g_02146954.f0c; i++) {
        if (g_02146954.f00[i].f0 != 0) {
            continue;
        }
        g_02146954.f00[i].f0 = (u32)func_02060C5C((void *)a2, a3, 0);
        if (g_02146954.f00[i].f0 == 0) {
            g_02146954.f0e = 5;
            continue;
        }
        g_02146954.f00[i].f4 = a0;
        g_02146954.f00[i].f8 = a2;
        g_02146954.f04[a1] = (u8)i;
        g_02146954.f0e = 0;
        return 1;
    }
    g_02146954.f0e = 4;
    return 0;
}
