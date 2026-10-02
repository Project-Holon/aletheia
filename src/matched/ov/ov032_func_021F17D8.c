/*
 * function: func_021F17D8
 * address: 0x021F17D8
 * packet: pkt_ov032_021F17D8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_02031194 0x02031194 arm
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040618(u32 layer, u32 a, u32 b, u32 c);
extern void func_02031194(void *task);
void func_021F17D8(void *task, u8 *q)
{
    u32 old;
    int x;
    old = q[2];
    q[2] = old + 1;
    if (old < q[1]) {
        x = *(s8 *)(q + 3);
        q[3] = x + *(s8 *)(q + 4);
        func_02040618(6, 3, *(s8 *)(q + 3), x);
        return;
    }
    (**(int **)(q + 8))--;
    func_02031194(task);
}
