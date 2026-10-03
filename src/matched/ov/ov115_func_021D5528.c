/*
 * function: func_021D5528
 * address: 0x021D5528
 * packet: pkt_ov115_021D5528
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 02040618 has three explicitly prepared argument registers here;
 *       there is no r3 setup after the two SDK copy calls.
 * symbols:
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef short s16;
extern void func_0207E3D0(void *, int, int);
extern void func_0207E468(void *, int, int);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021D5528(void *unused, u8 *p) {
    if (*(int *)(p + 4) == 0) return;
    *(u8 *)(p + 0x96b) ^= 1;
    if (*(u8 *)(p + 0x96b) & 1) return;
    func_0207E3D0(p + 0x1f0 + *(s16 *)(p + 0x968) * 32, 40, 14);
    func_0207E468(p + 0x1f0 + *(s16 *)(p + 0x968) * 32, 40, 14);
    ++*(s16 *)(p + 0x968);
    if (*(s16 *)(p + 0x968) >= 60) *(s16 *)(p + 0x968) = 0;
    func_02040618(*(u8 *)(p + 0x96c), 2, 7);
}
