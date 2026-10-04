/*
 * function: func_021F408C
 * address:  0x021F408C
 * packet:   pkt_ov056_021F408C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * extent:   EXACT* covers only the 2-byte alignment pad at 0x021F409E;
 *           the follower 0x021F40A0 is separately matched (pkt_021F40A0).
 *
 * symbols:
 *   func_02011558  0x02011558  thumb
 *   sub_020307B0   0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime;

extern void func_02011558(struct IcaAnime *p);
extern void sub_020307B0(void *p);

void func_021F408C(struct IcaAnime **pp)
{
    func_02011558(*pp);
    sub_020307B0(pp);
}
