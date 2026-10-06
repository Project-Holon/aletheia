/*
 * function: func_021D4A0C
 * address:  0x021D4A0C
 * packet:   pkt_ov093_021D4A0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02045A98  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   sub_020458F8   0x020458F8  arm
 *   sub_02045A90   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x14];
    void *f14;
} In;

typedef struct {
    u8 pad00[0x28];
    u8 f28[0x40];
    u32 f68;
} Out;

extern const char d_021F3A98[];
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
struct U16Vec;
extern u16 sub_020458F8(struct U16Vec *vec);
extern u16 *sub_02045A90(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);

Out *func_021D4A0C(In *a, u32 heap)
{
    Out *o = sub_02030734(heap, 0x6c, 1, d_021F3A98, 0x349);

    MI_CpuCopy8(a, o, 0x28);
    MIi_CpuClear16(func_02045A98(), o->f28, 0x40);
    if (a->f14 != 0) {
        o->f68 = sub_020458F8(a->f14);
        sub_0201F41C(sub_02045A90(a->f14), (u16 *)o->f28, 0x20);
    }
    return o;
}
