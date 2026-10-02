/*
 * function: func_021D6EAC
 * address:  0x021D6EAC
 * packet:   pkt_ov093_021D6EAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021D74BC  0x021D74BC  thumb  ov093
 *   func_021D74C8  0x021D74C8  thumb  ov093
 *   d_021F4470  0x021F4470  data  a4
 *   d_021F3CBC  0x021F3CBC  data  a4
 *   g_021F3CB0  0x021F3CB0  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[0x3c]; } Node;
extern Node d_021F4470[0x84];
extern Node *d_021F3CBC[0x84];
extern struct { u32 a; u32 b; u32 c; } g_021F3CB0;
extern void func_021D74BC(Node *);
extern void func_021D74C8(void);
void func_021D6EAC(void)
{
    u32 i;
    for (i = 0; i < 0x84; i++) {
        Node *n = &d_021F4470[i];
        func_021D74BC(n);
        d_021F3CBC[i] = n;
    }
    g_021F3CB0.b = 0;
    g_021F3CB0.c = 0;
    g_021F3CB0.a = 0;
    func_021D74C8();
}
