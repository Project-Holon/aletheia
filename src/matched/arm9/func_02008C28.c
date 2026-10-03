/*
 * function: func_02008C28
 * address:  0x02008C28
 * packet:   pkt_02008C28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082A7C  0x02082A7C  arm
 *   func_02008C64  0x02008C64  thumb
 *
 * The block constructor: MIi_CpuClear32 wipes 0x1E0 bytes, then the checksum
 * high half (+0x1DE) is seeded from the word at 0x02FFFC3C in the shared
 * region, then sub_02008C64 commits.  This is the block whose layout
 * src/matched/unit_02008C58.c describes; that file called it a "NEAR MISS, 48
 * bytes, 3 concrete bytes wrong" and blamed the register numbering of the three
 * loads.  The three bytes are in fact the operand order of the combine, and the
 * spelling that reproduces them is two named u32 locals assigned in order (a
 * first, then b) and combined as `a << 8 | b`, which puts the pool address in r1
 * and the first value in r0 as the original does.  The two reads must not be
 * commoned up, so the 0x02FFFC3C cast constant is `volatile`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02008C28.c \
 *       --func func_02008C28 --addr 0x02008C28 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082A7C(u32 fill, void *dst, u32 size);
struct Sub02008C20Obj;
extern void func_02008C64(struct Sub02008C20Obj *obj, int commit);

#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)

void func_02008C28(void *obj)
{
    u32 a;
    u32 b;

    func_02082A7C(0, obj, 0x1e0);
    a = unk_02FFFC3C;
    b = unk_02FFFC3C;
    *(u16 *)((u8 *)obj + 0x1de) = a << 8 | b;
    func_02008C64(obj, 1);
}
