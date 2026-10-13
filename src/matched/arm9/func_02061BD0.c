/*
 * function: NNSi_GfdPopVramTransferTask
 * address:  0x02061BD0
 * packet:   pkt_02061BD0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The load/store interleave tell of the 2.0 front end (docs/FRONTEND-PINS.md):
 * the image stores the call result (`strh r0, [r4, #8]` at 0x02061BF4) before
 * loading the counter (`ldrh r1, [r4, #0xc]` at 0x02061BF8); 1.1p1 hoists the
 * load above the store (6 bytes out).  Under ../2.0/sp2 the same C is 60
 * bytes, 0 mismatches.
 *
 * symbols:
 *   NNSi_GfdRingIsEmpty  0x02061878  arm
 *   NNSi_GfdRingNextIndex  0x02061840  arm
 */

typedef unsigned short u16;

struct Obj02061BD0 {
    char pad0[8];
    u16 f8;
    char padA[2];
    u16 fC;
};

extern int NNSi_GfdRingIsEmpty(struct Obj02061BD0 *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 NNSi_GfdRingNextIndex(u8 *p, u32 v);

u32 NNSi_GfdPopVramTransferTask(struct Obj02061BD0 *p)
{
    if (NNSi_GfdRingIsEmpty(p) != 0) {
        return 0;
    }
    p->f8 = NNSi_GfdRingNextIndex((u8 *)p, p->f8);
    p->fC -= 1;
    return 1;
}
