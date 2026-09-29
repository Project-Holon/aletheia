/*
 * function: func_02161378
 * address:  0x02161378
 * packet:   pkt_ov010_02161378
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Allocate an 8-byte record and store the save handle at +0.
 * The extent also holds the unlabelled leaf at 0x021613A4.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const char d_02172978[];

extern void *func_020120F4(void *p);
extern u32 *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);

u32 *func_02161378(char *c)
{
    u32 *r;

    r = func_02030734(4, 8, 1, d_02172978, 0x74C);
    r[0] = (u32)func_020120F4(**(void ***)(c + 0x18));
    return r;
}
