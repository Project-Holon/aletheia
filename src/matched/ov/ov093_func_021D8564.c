/*
 * function: func_021D8564
 * address:  0x021D8564
 * packet:   pkt_ov093_021D8564
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D8484  0x021D8484  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 func_021D5440(u8 *p);
struct Node;
struct Node *func_021D732C(int id, int sub);
void func_021D7040(struct Node *n);
int func_021D8484(int m);

void func_021D8564(int a, int b)
{
    int sa = func_021D5440((u8 *)a);
    int sb = func_021D5440((u8 *)b);
    void *x = func_021D732C(4, sa);
    void *y = func_021D732C(4, sb);

    if (x != 0)
        func_021D7040(x);
    if (y != 0)
        func_021D7040(y);
    func_021D8484(a);
    func_021D8484(b);
}
