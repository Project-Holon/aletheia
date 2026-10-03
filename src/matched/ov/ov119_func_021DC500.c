/*
 * function: func_021DC500
 * address: 0x021DC500
 * packet: pkt_ov119_021DC500
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 */
extern void func_0204A648(int);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021DC500(int a, char *p)
{
    func_0204A648(a);
    if (*(int *)(p + 0x1084)) {
        func_02040618(7, 0, *(int *)(p + 0x108C));
        func_02040618(5, 0, *(int *)(p + 0x108C));
        *(int *)(p + 0x1084) = 0;
    }
}
