/*
 * function: ENCEFF_LoadOverlay
 * address:  0x021CF564
 * packet:   pkt_ov021_021CF564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res021CF {
    u8 pad0[0xc];
    u32 ids[3];
    int n;
} Res021CF;

typedef signed int     s32;
extern int func_02034AC4(s32 handle);

void ENCEFF_LoadOverlay(Res021CF *r, u32 id)
{
    func_02034AC4(id);
    r->ids[r->n++] = id;
}
