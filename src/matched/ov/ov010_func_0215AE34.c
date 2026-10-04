/*
 * function: func_0215AE34
 * address:  0x0215AE34
 * packet:   pkt_ov010_0215AE34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159F28  0x02159F28  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013B44  0x02013B44  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern void func_02159F28(int a, int b, int flag);
struct BigObj;
struct Rec44;
extern int func_02159B94(int a0, int a1, int a2, int a3);
extern void func_02159CC4(u32 *a, int b, int c);
extern u32 func_02012974(const struct BigObj *p);
struct SaveBlock;
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013B44(u32 id);

int func_0215AE34(int a0, int a1)
{
    void *v0 = func_0215A5DC((void *)a1);
    void *p = func_0215A5E4((void *)a1);
    int x = func_02159B10((void *)a0, (void *)a1);
    int y = func_02159B10((void *)a0, (void *)a1);
    int flag = func_02159B10((void *)a0, (void *)a1);
    int q, r, s, t;
    func_02159F28((int)p, x, y);
    if (flag != 0) {
        q = func_02012974(p);
        r = func_02012AC8(func_020127A4((struct SaveBlock *)p));
        s = func_02013B44(r);
        t = func_0215A5CC((void *)a1);
        func_02159B94(q, s, r, t);
        func_02159CC4((u32 *)q, (int)v0, t);
    }
    return 0;
}
