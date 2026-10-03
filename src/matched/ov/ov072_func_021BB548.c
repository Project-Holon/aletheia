/*
 * function: func_021BB548
 * address:  0x021BB548
 * packet:   pkt_ov072_021BB548
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *   func_0204B95C  0x0204B95C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021BB49C  0x021BB49C  thumb  ov072
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA774  0x021BA774  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   func_021BB448  0x021BB448  thumb  ov072
 *   func_0204B974  0x0204B974  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B95C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021BB49C(void *p);
extern u32  func_0204B98C(u32 v);
extern u32  func_021BA774(u32 a, u32 b);
extern u32  func_02013E4C(u16 a);
extern void func_021BB448(u32 *p, u32 a, int x, int y);
extern void func_0204B974(struct Actor *a);

void func_021BB548(u32 *p)
{
    if (p[7] != 0) {
        p[7] = 0;
        func_0204B878((void *)p[4], 0);
        func_0204B95C((void *)p[4]);
        func_0204B3DC((void *)p[4], 1);
        func_021BB49C(p);
        p[6] = 1;
    }
    if (p[6] != 0 && func_0204B98C(p[4]) == 0) {
        func_021BB448(p, func_02013E4C(func_021BA774(p[5], 0)), 0x10, 2);
        func_0204B974((void *)p[4]);
        p[6] = 0;
    }
}
