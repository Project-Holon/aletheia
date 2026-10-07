/*
 * file:     field_msgbg_p13.c
 * unit:     yes
 * function: func_0218BCB0, func_0218BCE4
 * address:  0x0218BCB0
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
 *   d_021D3DC4     0x021D3DC4  data  a4
 *   func_0218BCF4  0x0218BCF4  thumb  ov021
 */
typedef struct {
    unsigned char b[16];
} Tbl;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0218BCF4(u32 *p, u32 v, u32 tag);
unsigned char func_0218BCB0(unsigned short *p);
void func_0218BCE4(u32 *p, u8 v);
extern const Tbl d_021D3DC4;


unsigned char func_0218BCB0(unsigned short *p)
{
    Tbl t = d_021D3DC4;
    if (p[1] >= 16)
        return 0;
    return t.b[p[1]];
}


/*
 * Stores a tag and a byte, then tail calls with the same operands.
 *
 * Addresses are Black-image addresses.
 */
void func_0218BCE4(u32 *p, u8 v)
{
    p[0] = 5;
    *((u8 *)p + 0xd) = v;
    func_0218BCF4(p, v, 5);
}
