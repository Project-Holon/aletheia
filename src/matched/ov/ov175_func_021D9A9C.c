/*
 * function: func_021D9A9C
 * address:  0x021D9A9C
 * packet:   pkt_ov175_021D9A9C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
#include "../include/Obj00013.h"
#include "../include/Obj01067.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Save {
    u8  pad_00[8];
    u32 *sav;
    u8  pad_0c[0x28];
    u32 *blk;
};

typedef signed int     s32;
struct Big;
struct BigObj;
struct Rec0200E6FC;
struct Reg2;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *src, void *dst);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 func_021DC194(char *obj);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009CC0(void *a0);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern u16 func_0200B1C4(struct Reg2 *p);

void func_021D9A9C(char *dst, char *obj)
{
    u32 st = (u32)func_02012EBC((struct Big *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav));
    u32 h;

    func_02008494(func_02012944((void *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)), dst);
    func_0200E6FC(func_0200E6E8(st), 0, (struct Rec0200E6FC *)(dst + 0x38));
    {
        const struct Save *s = *(struct Save * *)&((struct Obj00013 *)obj)->f104;
        ((struct Obj01067 *)dst)->f28 = s->blk[2];
        ((struct Obj01067 *)dst)->f2C = s->blk[3];
        ((struct Obj01067 *)dst)->f34 = s->blk[4];
    }
    ((struct Obj01067 *)dst)->f4C = func_021DC194((char *)(*(u32 *)&((struct Obj00013 *)obj)->f34));
    ((struct Obj01067 *)dst)->f48 = func_02009CC0((void *)func_0201283C((const struct BigObj *)(*(*(struct Save * *)&((struct Obj00013 *)obj)->f104)->sav)));
    h = ((struct Obj00013 *)obj)->f108;
    ((struct Obj01067 *)dst)->f40 = func_0200B078((struct Reg2 *)h, 2);
    ((struct Obj01067 *)dst)->f50 = func_0200B1C4((struct Reg2 *)h);
}
