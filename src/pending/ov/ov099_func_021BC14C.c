/*
 * function: func_021BC14C
 * address:  0x021BC14C
 * packet:   pkt_ov099_021BC14C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04): DIFF, 124 vs 120 bytes. Original pushes r3-r7 (v in r6, zero local in r7), loads the 0x242 pool offset into r5 inside each arm and reuses it at the join as subs r5,#0x76 for the 0x1CC store; ours reads 0x242 into r1 (dies at the ldrh), builds 0x1CC separately, and uses only r4-r6. Semantics are right; the open question is what keeps the 0x242 constant live to the join.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
extern struct Link *func_020399A8(void);
extern void func_0203D1E8(struct Link *a, void *arg);
extern u32 func_0203D378(void);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern void func_021BA874(char *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);

int func_021BC14C(char *p, int v)
{
    int z;
    int r;
    func_0203D1E8(func_020399A8(), 0);
    z = 0;
    if (func_0203D378() == 0) {
        *(int *)(p + 0x135C) = 3;
        func_021BA874(p, *(u16 *)(p + 0x242) - 1);
        func_021BAAB8(p, 0x5F, z);
        r = 0x42;
    } else {
        *(int *)(p + 0x135C) = 4;
        func_021BA874(p, *(u16 *)(p + 0x242) - 1);
        func_021BAAB8(p, 0x7E, z);
        func_021BC090(p);
        func_02039C68(func_020399A8(), 0x1B, 0xA);
        r = 0x49;
    }
    *(int *)(p + 0x1CC) = r;
    return v;
}
