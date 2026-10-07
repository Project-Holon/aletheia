/*
 * file:     btl_net_p09.c
 * unit:     yes
 * function: func_021D49CC, func_021D49E0, func_021D4A0C
 * address:  0x021D49CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_020307B0 0x020307B0 arm
 *   func_021D4A6C 0x021D4A6C thumb ov093
 *   sub_02030734   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02045A98  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   sub_020458F8   0x020458F8  arm
 *   sub_02045A90   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 */
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    u8 pad00[0x14];
    void *f14;
} In;

typedef struct {
    u8 pad00[0x28];
    u8 f28[0x40];
    u32 f68;
} Out;

extern u32 func_020307B0(void *p);
extern void func_021D4A6C(void);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 func_02045A98(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
extern u16 sub_020458F8(struct U16Vec *vec);
extern u16 *sub_02045A90(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
void *func_021D49CC(void);
void func_021D49E0(void);
void func_021D4A04(void);
Out *func_021D4A0C(In *a, u32 heap);
extern u8 *d_021F3B88;
extern const char d_021F3A98[];

/*
 * Unlabelled leaf called by func_021B7968 (+0x1EC): returns the object
 * word at +0x3b14 of the d_021F3B88 block (the word func_021D49E0 frees).
 */
void *func_021D49CC(void)
{
    return *(void **)(d_021F3B88 + 0x3b14);
}

/*
 * Extent follower 021D4A04 is a tail-call stub; function_start seed.
 */
void func_021D49E0(void)
{
    func_020307B0(*(void **)(d_021F3B88 + 0x3b14));
    *(void **)(d_021F3B88 + 0x3b14) = 0;
    *(void **)(d_021F3B88 + 0x3b18) = 0;
}

void func_021D4A04(void)
{
    func_021D4A6C();
}


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
