/*
 * function: sub_0203499C
 * address:  0x0203499C
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   unk_021469B8    0x021469B8  data
 *   s_FileName      0x020A7970  data
 *
 * gf_overlay.c's constructor: allocate the singleton sub_02034CBC and
 * sub_02034D08 read, one 0x10-byte header followed by the three
 * registration tables laid end to end, zero it, then record the three table
 * lengths at +0/+1/+2 and the three table bases at +4/+8/+0xc.
 *
 * Every store to the singleton is preceded by a fresh `ldr r0, [r7]` because
 * the object being written is reached through the global pointer itself: the
 * compiler cannot prove `p->t0 = ...` does not land on `unk_021469B8`, so it
 * reloads the pointer before each store.  The allocation size is spelled out
 * twice rather than kept in a local, which is why only the `<< 3` is common
 * subexpression eliminated and the `+ 0x10` is recomputed for the clear.
 *
 * The file string is "gf_overlay.c" and the debug line is 108.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203499C.c \
 *       --func sub_0203499C --addr 0x0203499C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

struct Registration {
    s32 handle;
    s32 state;
};

struct AreaMan {
    u8 n0;
    u8 n1;
    u8 n2;
    u8 pad03;
    struct Registration *t0;
    struct Registration *t1;
    struct Registration *t2;
};

extern struct AreaMan *unk_021469B8;
extern const char s_FileName[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void  MIi_CpuClear32(u32 data, void *dest, u32 size);

void sub_0203499C(u32 heap, int n0, int n1, int n2)
{
    struct AreaMan *p;
    int count;

    count = n0 + n1 + n2;

    p = func_02030734(heap, count * sizeof(struct Registration) + sizeof(struct AreaMan), 0,
                      s_FileName, 108);
    unk_021469B8 = p;
    MIi_CpuClear32(0, p, count * sizeof(struct Registration) + sizeof(struct AreaMan));

    unk_021469B8->n0 = n0;
    unk_021469B8->n1 = n1;
    unk_021469B8->n2 = n2;
    unk_021469B8->t0 = (struct Registration *)(unk_021469B8 + 1);
    unk_021469B8->t1 = unk_021469B8->t0 + n0;
    unk_021469B8->t2 = unk_021469B8->t1 + n1;
}
