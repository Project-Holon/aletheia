/*
 * function: FIELD_TASK_Create
 * address:  0x021C6C70
 * packet:   pkt_ov021_021C6C70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE4D4  0x021DE4D4  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef struct { u32 f0; u32 *f4; u32 f8; } Q;
extern char d_021DE4D4[];
Q *FIELD_TASK_Create(u32 heap, u32 size, u32 v)
{
    Q *q = func_02030734(heap, 0xc, 0, d_021DE4D4, 0x3b);
    q->f0 = 0;
    q->f4 = func_02030734(heap, size, 1, d_021DE4D4, 0x3d);
    q->f8 = v;
    return q;
}
