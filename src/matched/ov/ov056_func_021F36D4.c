/*
 * function: func_021F36D4
 * address:  0x021F36D4
 * packet:   pkt_ov056_021F36D4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047674  0x02047674  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { char pad[4]; u16 f4; } Inner;
typedef struct { char pad[8]; Inner *f8; } Outer;

extern Outer *func_02047674(u32 a);

int func_021F36D4(u32 a)
{
    return func_02047674(a)->f8->f4 << 12;
}
