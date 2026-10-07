/*
 * file:     colosseum_p06.c
 * unit:     yes
 * function: func_02175094, func_021750B0, func_021750C0, func_021750C8, func_021750D0
 * address:  0x02175094
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef struct {
    u8 pad00[0xc8];
    u8 bc8 : 1;
} Obj;

void func_02175094(Obj *p, int v);
void func_021750B0(u8 *p, int v);
u8 func_021750C0(char *p);
void func_021750C8(u8 *p, int v);
u8 func_021750D0(u8 *p);


void func_02175094(Obj *p, int v)
{
    p->bc8 = (u8)v;
}


void func_021750B0(u8 *p, int v)
{
    p[0xdc] = v;
    p[0xdd] = 0xff;
}


u8 func_021750C0(char *p)
{
    return p[0xdc];
}

/*
 * Extent follower 021750D0 is already filed separately.
 */
void func_021750C8(u8 *p, int v) { p[0xdd] = v; }


u8 func_021750D0(u8 *p)
{
    return p[0xdd];
}
