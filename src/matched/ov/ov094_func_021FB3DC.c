/*
 * function: func_021FB3DC
 * address:  0x021FB3DC
 * packet:   pkt_ov094_021FB3DC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0204047C  0x0204047C  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_020215EC  0x020215EC  thumb
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_021F8700  0x021F8700  thumb  ov094
 *   func_02209784  0x02209784  thumb  ov094
 */
typedef unsigned short u16;

extern int func_0201134C(int a);
extern void func_0204047C(int a, int b);
extern void func_02049624(int a, int b, int c, int d, int e, int f, u16 g);
extern void func_0204989C(int a, int b, int c, int d, int e, int f, u16 g);
extern void func_020215EC(int a, int b, int c, u16 d, int e, int f, int g, int h);
extern int func_020407E8(int a);
extern int func_02040804(int a);
extern int func_021F86E0(void);
extern int func_021F8700(void);
extern void func_02209784(int a, int b, int c);

int func_021FB3DC(int a, char *b)
{
    int t;

    t = func_0201134C(a);
    func_0204047C(3, 1);
    func_02049624(0x5f, t + 1, 3, 0, 0, 0, (*(u16 *)(b + 0x238) & 0x7fff) | 0x8000);
    func_0204989C(0x5f, t, 3, 0, 0, 0, (*(u16 *)(b + 0x238) & 0x7fff) | 0x8000);
    func_020215EC(func_021F86E0(), 0x5f, t + 2, (*(u16 *)(b + 0x238) & 0x7fff) | 0x8000, 0, 0, 0x80, 0);
    *(int *)(b + 0x264) = func_020407E8(3);
    *(int *)(b + 0x268) = func_02040804(3);
    func_02209784(func_021F8700(), 0, 0);
    *(unsigned int *)b |= 0x10;
    return *(int *)(b + 0x23c);
}
