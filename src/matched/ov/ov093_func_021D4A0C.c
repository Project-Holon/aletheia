/*
 * function: BTL_NET_BuildPlayerInfoPacket
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
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   gBtlNetSourceName     0x021F3A98  data  ov093  a1
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

extern const char gBtlNetSourceName[];
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 STRBUF_GetEosChar(void);
extern void MIi_CpuClear16(u16 data, void *dst, u32 size);
struct U16Vec;
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);

Out *BTL_NET_BuildPlayerInfoPacket(In *a, u32 heap)
{
    Out *o = GFL_HEAP_Alloc(heap, 0x6c, 1, gBtlNetSourceName, 0x349);

    MI_CpuCopy8(a, o, 0x28);
    MIi_CpuClear16(STRBUF_GetEosChar(), o->f28, 0x40);
    if (a->f14 != 0) {
        o->f68 = STRBUF_GetLength(a->f14);
        sub_0201F41C(STRBUF_GetChars(a->f14), (u16 *)o->f28, 0x20);
    }
    return o;
}
