/*
 * function: func_021C6CF4
 * address:  0x021C6CF4
 * packet:   pkt_ov021_021C6CF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021C6CEC  0x021C6CEC  thumb  ov021
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
extern void func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef struct { u32 f0; u32 *f4; int (*f8)(u32 *); } Q;
extern void func_021C6CEC(Q *q);
void func_021C6CF4(Q *q)
{
    if (q->f0 == 1) {
        if (q->f8(q->f4) == 1)
            func_021C6CEC(q);
    }
}
