/*
 * function: func_0219B120
 * address:  0x0219B120
 * packet:   pkt_ov021_0219B120
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D50F8  0x021D50F8  data  a4
 *
 * The first key is the literal 0 held in a local (row 0 of the table has
 * key 0), then the walk reloads it at the loop bottom.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 id; u32 *tbl; } Ent;
extern Ent d_021D50F8[];

u32 *func_0219B120(u32 id)
{
    Ent *p = d_021D50F8;
    u32 k = 0;
    do {
        if (k == id) {
            return p->tbl;
        }
        p++;
        k = p->id;
    } while (k != 0x27);
    return 0;
}
