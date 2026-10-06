/*
 * function: func_0215841C
 * address:  0x0215841C
 * packet:   pkt_0215841C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte out of the arm9 reader, zero-extended.
 *
 * symbols:
 *   func_02012B80   0x02012B80  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u8 func_02012B80(const struct BigObj *p);

int func_0215841C(void *p)
{
    return (u8)(unsigned)func_02012B80(p);
}

