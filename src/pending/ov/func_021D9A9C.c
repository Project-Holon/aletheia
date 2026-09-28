/*
 * function: func_021D9A9C
 * address:  0x021D9A9C
 * packet:   pkt_021D9A9C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_021DC194  0x021DC194  thumb  ov175
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CC0  0x02009CC0  thumb
 *   func_0200B078  0x0200B078  thumb
 *   func_0200B1C4  0x0200B1C4  thumb
 *
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 * Blocker: byte-correct (MATCH*); 0x02008494 is an unlabelled arm9 Thumb thunk
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Save {
    u8  pad_00[8];
    u32 *sav;
    u8  pad_0c[0x28];
    u32 *blk;
};

extern u32 func_02012EBC(u32 sav);
extern u32 func_02012944(u32 sav);
extern void func_02008494(u32 name, char *dst);
extern u32 func_0200E6E8(u32 p);
extern void func_0200E6FC(u32 src, int idx, char *dst);
extern u32 func_021DC194(u32 p);
extern u32 func_0201283C(u32 sav);
extern u32 func_02009CC0(u32 p);
extern u32 func_0200B078(u32 id, u32 kind);
extern u32 func_0200B1C4(u32 id);

void func_021D9A9C(char *dst, char *obj)
{
    u32 st = func_02012EBC(*(*(struct Save **)(obj + 0x104))->sav);
    u32 h;

    func_02008494(func_02012944(*(*(struct Save **)(obj + 0x104))->sav), dst);
    func_0200E6FC(func_0200E6E8(st), 0, dst + 0x38);
    {
        const struct Save *s = *(struct Save **)(obj + 0x104);
        *(u32 *)(dst + 0x28) = s->blk[2];
        *(u32 *)(dst + 0x2c) = s->blk[3];
        *(u32 *)(dst + 0x34) = s->blk[4];
    }
    *(u32 *)(dst + 0x4c) = func_021DC194(*(u32 *)(obj + 0x34));
    *(u32 *)(dst + 0x48) = func_02009CC0(func_0201283C(*(*(struct Save **)(obj + 0x104))->sav));
    h = *(u32 *)(obj + 0x108);
    *(u32 *)(dst + 0x40) = func_0200B078(h, 2);
    *(u32 *)(dst + 0x50) = func_0200B1C4(h);
}
