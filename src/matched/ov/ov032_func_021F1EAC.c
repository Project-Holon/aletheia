/*
 * function: func_021F1EAC
 * address:  0x021F1EAC
 * packet:   pkt_ov032_021F1EAC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1EAC 0x021F1EAC thumb
 *   func_021F1080 0x021F1080 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_02031194 0x02031194 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F1080(u32 a, u32 b, int c, int d);
extern void func_021F0ED0(char *q, int a);
struct TcblNode;
extern void func_02031194(struct TcblNode *n);

void func_021F1EAC(void *task, u8 *s)
{
    if (s[0] == 0) {
        u8 c = s[1];
        s[1] = c - 1;
        if (c != 0)
            return;
        if (*(u32 *)(s + 0xc) == 1 || *(u32 *)(s + 0xc) == 0x18 || *(u32 *)(s + 0xc) == 0x31) {
            func_021F1080(*(u32 *)(s + 0x10), *(u32 *)(s + 8), 1, 0);
            s[0]++;
            return;
        }
    } else {
        if (*(u32 *)(*(char **)(s + 8) + 0x2c) != 0)
            return;
    }
    *(u32 *)(*(char **)(s + 8) + 0x30) = 0;
    func_021F0ED0(*(char **)(s + 8), 0);
    func_02031194(task);
}
