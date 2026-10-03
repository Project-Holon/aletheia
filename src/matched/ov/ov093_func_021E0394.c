/*
 * function: func_021E0394
 * address:  0x021E0394
 * packet:   pkt_ov093_021E0394
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021D5440(u8 *p);
typedef unsigned int   u32;
struct Node;
struct QQ;
extern struct Node *func_021D732C(int id, int sub);
extern struct Node *func_021D7360(struct Node *n);
extern u16 func_021D70A8(struct QQ *p);
extern u32 func_021D70B4(u8 *p, int i);
extern void func_021D7040(struct Node *n);

void func_021E0394(u8 *a, int b)
{
    void *n;
    void *next;

    n = func_021D732C(0, func_021D5440(a));
    while (n != 0) {
        next = func_021D7360(n);
        if (b == func_021D70A8(n) && func_021D70B4(n, 6) == 0) {
            func_021D7040(n);
        }
        n = next;
    }
}
