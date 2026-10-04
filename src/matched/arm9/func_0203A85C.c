/*
 * function: func_0203A85C
 * address:  0x0203A85C
 * packet:   pkt_0203A85C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203A770  0x0203A770  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021469D8     0x021469D8  data
 *
 * One slot of a network table: index 0xff aliases to slot 8, the incoming
 * tag must match func_020399A8(), and the entry is swept copy-then-count.
 * The global pointer at 0x021469D8 is re-read after every call, so the C
 * dereferences it afresh in each statement rather than keeping a local.
 *
 * The fifth parameter is volatile: every use re-reads its incoming stack
 * slot (ldr r1,[sp,#0x20] after the tag call, ldr r0,[sp,#0x20] again for
 * func_0203A770) instead of living in a callee-saved register, which is what
 * keeps the saved set at r4-r8 rather than adding sb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A85C.c \
 *       --func func_0203A85C --addr 0x0203A85C --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u8  unk12;
} Ent0203A85C;

typedef struct {
    u8          unk000[0xb8];
    Ent0203A85C ent[9];
} Obj0203A85C;

extern Obj0203A85C *d_021469D8;
extern void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void MI_CpuCopy8(void *dst, const void *src, u32 size);

void func_0203A85C(int a0, u32 a1, void *a2, int a3, volatile int a4)
{
    int idx = a0;

    if (a0 == 0xff) {
        idx = 8;
    }
    if (a4 != (u32)func_020399A8()) {
        return;
    }
    if (d_021469D8->ent[idx].unk12 == 0) {
        return;
    }
    if (d_021469D8->ent[idx].unk04 != 0) {
        MI_CpuCopy8(a2,
                    (void *)(d_021469D8->ent[idx].unk04
                             + d_021469D8->ent[idx].unk0C
                                   * d_021469D8->ent[idx].unk0A),
                    a1);
    }
    d_021469D8->ent[idx].unk0C++;
    if (d_021469D8->ent[idx].unk0C != d_021469D8->ent[idx].unk0E) {
        return;
    }
    if (d_021469D8->ent[idx].unk04 != 0) {
        func_0203A770(a0, d_021469D8->ent[idx].unk10,
                      d_021469D8->ent[idx].unk08, d_021469D8->ent[idx].unk00,
                      d_021469D8->ent[idx].unk04, a4);
    }
    d_021469D8->ent[idx].unk12 = 0;
}
