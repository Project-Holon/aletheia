/*
 * function: func_0200C52C
 * address:  0x0200C52C
 * packet:   pkt_0200C52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   g_020A71D4     0x020A71D4  data  a1
 *
 * musical_dist_save.c constructor: allocate the 0x2C-byte control block and
 * a 0x20000-byte buffer, load save block 6 into the buffer through the save
 * system, record heap/system, then attach the loaded block.
 *
 * Closed in wave 15.  The residue since wave 11 (image homes sys to the
 * stack and keeps sv in r6 and the id 6 in r7; every earlier shape did the
 * reverse) was not an allocation tie: the func_020073D8 call is written in
 * BOTH arms of the `r == 1` test and the compiler tail-merges the two
 * copies.  The merged call is what keeps 6 live in a callee-saved register
 * and lets the shared zero land in r2 as the third argument.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct DistHdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
};

struct MusicalDist {
    u16 unk00;
    u32 unk04;
    u32 unk08;
    struct DistHdr unk0C;
    void *unk1C;
    void *unk20;
    u8   *unk24;
    void *unk28;
};

extern const char g_020A71D4[];
extern void *func_02012EBC(void *sys);
extern void *func_02030734(u32 heap, u32 size, u32 flag, const char *file, u32 line);
extern u32   func_020072CC(void *sv, u32 id, u32 heap, void *buf, u32 size);
extern u8   *func_020073D8(void *sv, u32 id, u32 c);

struct MusicalDist *func_0200C52C(void *sys, u32 heap)
{
    void *sv;
    struct MusicalDist *p;
    u32 r;
    u8 *z;

    sv = func_02012EBC(sys);
    p = func_02030734(heap, 0x2C, 1, g_020A71D4, 0x4A);
    p->unk1C = func_02030734(heap, 0x20000, 1, g_020A71D4, 0x4C);
    r = func_020072CC(sv, 6, heap, p->unk1C, 0x20000);
    p->unk00 = heap;
    p->unk28 = sys;
    p->unk08 = 0;
    if (r == 1) {
        p->unk04 = 1;
        z = func_020073D8(sv, 6, 0);
    } else {
        p->unk04 = 0;
        z = func_020073D8(sv, 6, 0);
    }
    p->unk1C = z;
    p->unk20 = z;
    p->unk24 = z + 0x10;
    return p;
}
