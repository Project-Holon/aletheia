/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005B04
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005B04
 *
 * symbols:
 *   sub_02005B04_Cur  0x020AA1AC  data
 *   sub_02005834      0x02005834  thumb
 *   sub_02005858      0x02005858  thumb
 *   func_020748E0     0x020748E0  arm
 *
 * Close the current connection slot with a status word taken from the
 * second word of the argument block.  Its own byte range because the
 * function immediately before it, 0x02005A98, cannot be attested: the only
 * `blx` to func_02074A6C anywhere in the image is the one inside it.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005B04Cur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

extern struct Sub02005B04Cur sub_02005B04_Cur;

extern void sub_02005834(u32 v);
extern void sub_02005858(void);
extern void func_020748E0(u32 *a, u32 b);

void sub_02005B04(const u32 *arg)
{
    u32 v = arg[1];

    sub_02005858();
    func_020748E0(*sub_02005B04_Cur.unk08, v);
    sub_02005834(v);
}
