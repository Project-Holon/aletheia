/*
 * function: func_021C6B8C
 * address:  0x021C6B8C
 * packet:   pkt_ov021_021C6B8C
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
 *   func_021C6BB4  0x021C6BB4  thumb  ov021
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
typedef struct { u32 f0; u16 f4; u16 f6; } P;
extern void func_021C6BB4(u8 *p);
void func_021C6B8C(void *task, P *p)
{
    func_021C6BB4((u8 *)p);
    p->f4++;
    if (p->f6 < p->f4) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}
