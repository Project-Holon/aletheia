/*
 * function: func_02164480
 * address:  0x02164480
 * packet:   pkt_ov010_02164480
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021644C4  0x021644C4  thumb  ov010
 *   func_02028748  0x02028748  thumb
 *   func_02012B28  0x02012B28  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

struct Ctx;
struct Rec44;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern int func_021644C4(int i, void *a, void *b);
extern void func_02028748(Flags *f, int i, int v);
extern u32 func_02012B28(const struct Rec44 *p);

void func_02164480(Flags *f, void *a, void *b)
{
    void *save;
    int i;

    save = func_020127A4(func_020120F4(a));
    MI_CpuFill8(f, 0, sizeof(Flags));
    for (i = 0; i < 10; i++)
        func_02028748(f, i, func_021644C4(i, a, b));
    f->f04 = func_02012B28(save);
}
