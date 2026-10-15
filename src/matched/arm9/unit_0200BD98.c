/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BD98
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: DAYCARE_GetSize, DAYCARE_Init, DAYCARE_GetFromSave
 *
 * 36 bytes, 0x0200BD98..0x0200BDBC, 3 functions, none of which carries a
 * label in the generated listing.
 *
 * The size, constructor and lookup of the save block with id 0x32.  0x1CC is
 * exactly 2 * 0xE4 + 4, which is the two-slot record the accessors of
 * src/matched/unit_0200BBC8.c reach through a slot stride of 0xE4 and a flag
 * word at +0x1C8, so this is that object's header and the range immediately
 * before it is its accessor set.
 *
 * Both of the last two functions are bare tail calls, which is why neither
 * has a prologue and why each spends a literal pool word on its callee: see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  The constructor does
 * nothing but clear the block, so there is no field this file pins.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

struct Blk32 {
    u8 unk000[0x1CC];
};

u32 DAYCARE_GetSize(void)
{
    return sizeof(struct Blk32);
}

void DAYCARE_Init(struct Blk32 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk32));
}

void *DAYCARE_GetFromSave(void *sys)
{
    return func_020071CC(sys, 0x32);
}
