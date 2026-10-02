/*
 * function: func_021DCF24
 * address:  0x021DCF24
 * packet:   pkt_ov093_021DCF24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node Node;
extern u8 func_021D5440(u8 *);
extern Node *func_021D732C(int, int);
extern Node *func_021D7360(Node *);
extern u32 func_021D70B4(Node *, int);
extern void func_021D7040(Node *);
void func_021DCF24(u8 *p)
{
    Node *n = func_021D732C(5, func_021D5440(p));
    while (n != 0) {
        Node *next = func_021D7360(n);
        if (func_021D70B4(n, 6) == 0)
            func_021D7040(n);
        n = next;
    }
}
