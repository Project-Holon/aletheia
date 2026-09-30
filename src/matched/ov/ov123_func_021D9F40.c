/*
 * function: func_021D9F40
 * address: 0x021D9F40
 * packet: pkt_ov123_021D9F40
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021D9F54 re-reads the byte stored at 021D9F52; 021D9F8C re-reads the halfword stored at 021D9F8A.
 * symbols:
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef short s16;
extern void func_0207E3D0(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
extern void func_02040618(int, int, int);
void func_021D9F40(void *unused, char *p)
{
    if (*(int *)(p+4)) {
        *(u8 *)(p+0x96b)^=1;
        if (!(*(volatile u8 *)(p+0x96b)&1)) {
            func_0207E3D0(p+0x1f0+*(s16 *)(p+0x968)*32,40,14);
            func_0207E468(p+0x1f0+*(s16 *)(p+0x968)*32,40,14);
            ++*(s16 *)(p+0x968);
            if (*(volatile s16 *)(p+0x968)>=60) *(s16 *)(p+0x968)=0;
            func_02040618(*(u8 *)(p+0x96c),2,7);
        }
    }
}
