/*
 * function: func_021B6458
 * address:  0x021B6458
 * packet:   pkt_ov071_021B6458
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Blocker: func_02010F8C (arm9 unlabelled tail-call stub,
 * Ilias's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: func_020307B0 0x020307B0 arm):
 *   void func_02010F8C(void *p) { void func_020307B0(void *); func_020307B0(p); }
 *
 * symbols:
 *   func_0203133C  0x0203133C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02010F8C  0x02010F8C  thumb
 *   func_021B6960  0x021B6960  thumb  ov071
 *   func_021B68B4  0x021B68B4  thumb  ov071
 *   func_021B6808  0x021B6808  thumb  ov071
 *   func_021B677C  0x021B677C  thumb  ov071
 *   func_021B6624  0x021B6624  thumb  ov071
 *   func_021B6588  0x021B6588  thumb  ov071
 *   func_021B6538  0x021B6538  thumb  ov071
 *   func_021B6524  0x021B6524  thumb  ov071
 *   func_02049238  0x02049238  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct S020315D4;
int func_021B6458(int a, int b, int c, int *w)
{
    void func_0203133C(struct S020314B8 *p);
    void func_02030EAC(struct Node *n);
    void func_02010F8C(void *p);
    void func_021B6960(u32 *p);
    void func_021B68B4(void **p);
    void func_021B6808(void **p);
    void func_021B677C(u32 *p);
    void func_021B6624(void);
    void func_021B6588(struct PalAnmSlot **p);
    void func_021B6538(void);
    void func_021B6524(void);
    void func_02049238(int);
    void func_020315D4(struct S020315D4 *p);
    void func_020306F0(u32 heap);

    func_0203133C((struct S020314B8 *)w[0x12c / 4]);
    func_0203133C((struct S020314B8 *)w[0x130 / 4]);
    func_02030EAC((struct Node *)w[0x128 / 4]);
    func_02010F8C((void *)w[0x34 / 4]);
    func_021B6960((u32 *)w);
    func_021B68B4((void **)w);
    func_021B6808((void **)w);
    func_021B677C((u32 *)w);
    func_021B6624();
    func_021B6588((struct PalAnmSlot **)w);
    func_021B6538();
    func_021B6524();
    func_02049238(w[0x30 / 4]);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x61);
    return 1;
}
