/*
 * file:     unit_02198D3C_p14.c
 * unit:     yes
 * function: func_0219A1E8, func_0219A24C, func_0219A250
 * address:  0x0219A1E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D5074  0x021D5074  data  a4
 *   func_0219A290  0x0219A290  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_0219A290(u32 a1, u32 a2, u32 a3, u32 a4);
u16 func_0219A1E8(u16 key, u16 v);
void func_0219A24C(void);
void func_0219A250(u32 a1);
extern u16 d_021D5074[][6];


static inline u16 NextInRow(u16 *row, u16 v)
{
    int i;
    u16 *p;

    for (i = 1, p = row; p[i] != 9; i++) {
        if (v == p[i]) {
            i++;
            if (p[i] == 9) i = 1;
            return p[i];
        }
    }
    return 9;
}


/*
 * Row lookup: find the 6-halfword record whose key matches, then return the
 * entry after v in its 9-terminated list (wrapping to entry 1).  The row is
 * an inline argument formed through a (u8 *) byte offset, so the add stays
 * after the key compare; the helper's `for (i = 1, p = row; ...)` local copy
 * of the row gives the image's colours (row r0, index r3, v copied to r4).
 */
u16 func_0219A1E8(u16 key, u16 v)
{
    int i = 0;

    do {
        if (key == d_021D5074[i][0]) {
            return NextInRow((u16 *)((u8 *)d_021D5074 + i * 12), v);
        }
        i++;
    } while (d_021D5074[i][0] != 0xFF);
    return 9;
}

/*
 * Empty callback: its address 0x0219A24D is stored in ov021 data at 0x021D5738.
 */
void func_0219A24C(void)
{
}


/*
 * Calls func_0219A290(its own argument 1, 0xc, 0xb, 0x0) and returns nothing.
 */
void func_0219A250(u32 a1)
{
    func_0219A290(a1, 0xc, 0xb, 0x0);
}
