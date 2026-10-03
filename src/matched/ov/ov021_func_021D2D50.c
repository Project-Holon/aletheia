/*
 * function: func_021D2D50
 * address:  0x021D2D50
 * packet:   pkt_ov021_021D2D50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021D2D7C  0x021D2D7C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Blk021D2D50 {
    u32 w[6];
} Blk021D2D50;

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern Blk021D2D50 *func_020124E8(void *task);
extern int func_021D2D7C(void *task, int *state);

void *func_021D2D50(void *a, Blk021D2D50 *src)
{
    void *task = func_020122C0(a, 0, func_021D2D7C, 0x1c);

    *func_020124E8(task) = *src;
    return task;
}
