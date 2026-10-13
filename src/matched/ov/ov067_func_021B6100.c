/*
 * function: UI_SCENE_Create
 * address:  0x021B6100
 * packet:   pkt_ov067_021B6100
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the 0x10-byte record UI_SCENE_Step steps (fields named there).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_021B9540     0x021B9540  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *f4;
    u16 idx;
    u16 fA;
    u8 fC;
    u8 pad[3];
} S;

extern const char d_021B9540[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

S *UI_SCENE_Create(u32 heap, void *arr, u8 c, u16 idx, void *f4)
{
    S *p;

    p = func_02030734(heap, 0x10, 0, d_021B9540, 0x4e);
    MI_CpuFill8(p, 0, 0x10);
    p->arr = arr;
    p->fC = c;
    p->f4 = f4;
    p->idx = idx;
    p->fA = 0xFFFF;
    return p;
}
