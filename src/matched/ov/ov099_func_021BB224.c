/*
 * function: func_021BB224
 * address:  0x021BB224
 * packet:   pkt_ov099_021BB224
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB4D0  0x021BB4D0  thumb  ov099
 *   func_021BB42C  0x021BB42C  thumb  ov099
 *   func_02028604  0x02028604  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 */

struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_021BB4D0(char *p);
extern void func_021BB42C(void *p);
extern void func_02028604(void *a);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);

void func_021BB224(char *p)
{
    func_021BB4D0(p);
    func_021BB42C(p);
    func_02028604(*(void **)(p + 0x9B0));
    func_02045808(*(void **)(p + 0xF8));
    func_02045808(*(void **)(p + 0xF4));
    func_02045808(*(void **)(p + 0xFC));
    if (*(void **)(p + 0x1BC) != 0) {
        func_0201CE48(*(void **)(p + 0x1BC));
        *(void **)(p + 0x1BC) = 0;
    }
    func_02045808(*(void **)(p + 0xF0));
    func_02031140(*(void **)(p + 0x1C0));
    func_0201C6EC(*(void **)(p + 0x1B8));
    func_0201C6EC(*(void **)(p + 0x1B4));
    func_0201C4C0(*(void **)(p + 0x1B8));
    func_0201C4C0(*(void **)(p + 0x1B4));
    *(void **)(p + 0x1B8) = 0;
}
