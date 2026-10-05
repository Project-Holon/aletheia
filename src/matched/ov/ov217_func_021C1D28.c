/*
 * function: func_021C1D28
 * address:  0x021C1D28
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Small dense switch on the word at offset 8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 a;
    u32 b;
    u32 type;
} Rec;

s32 func_021C1D28(Rec *p)
{
    switch (p->type) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 0;
    case 5:
        return 1;
    }
    return 0;
}
