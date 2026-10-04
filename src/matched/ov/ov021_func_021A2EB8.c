/*
 * function: func_021A2EB8
 * address:  0x021A2EB8
 * packet:   pkt_ov021_021A2EB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: relocation evidence, func_02012AD4 (0x02012AD4, arm9 thumb leaf,
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --thumb --region arm9 (symbols: data_0209DFA8
 * 0x0209DFA8 data a2):
 *   extern const u16 data_0209DFA8[];
 *   void func_02012AD4(u8 *p, int i) { *(u16 *)(p + 0x18) = data_0209DFA8[i]; }
 *
 * symbols:
 *   func_021A3994  0x021A3994  thumb
 *   func_021A3960  0x021A3960  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012A90  0x02012A90  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02012AD4  0x02012AD4  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02012AA4  0x02012AA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct H4;
struct Rec44;
struct Vec12;
extern u32 func_021A3994(u8 *p);
extern void *func_021A3960(unsigned char *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
extern u16 func_0216D5F8(void *p);
extern void func_02012AD4(u8 *p, int i);
extern u32 func_02188CFC(u8 *p);
extern void func_02012ABC(struct Rec44 *p, u8 v);
extern void func_0219E2F4(void *o, void *out);
extern void func_02012AA4(struct Rec44 *p, const struct H4 *src);

void func_021A2EB8(u32 *a)
{
    u8 b[12];
    u8 c[8];
    u32 d = func_021A3994((u8 *)a[1]);
    void *e = func_021A3960((u8 *)a[1]);

    func_0216D88C(e, (struct VecFx32 *)b);
    func_02012A90((struct Rec44 *)d, (const struct Vec12 *)b);
    func_02012AD4((u8 *)d, func_0216D5F8(e));
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_02012ABC((struct Rec44 *)d, 0);
        return;
    }
    func_0219E2F4(e, c);
    func_02012AA4((struct Rec44 *)d, (const struct H4 *)c);
    func_02012ABC((struct Rec44 *)d, 1);
}
