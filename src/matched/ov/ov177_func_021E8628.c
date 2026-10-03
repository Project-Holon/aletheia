/*
 * function: func_021E8628
 * address: 0x021E8628
 * packet: pkt_ov177_021E8628
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020307B0 0x020307B0 arm
 */
struct Descriptor;
struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(unsigned char *p);
extern int func_02028604(int p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020307B0(void *p);
void func_021E8628(char *p)
{
    if (*(void **)(p + 8) != 0) {
        func_0201CE48(*(void **)(p + 8));
        *(void **)(p + 8) = 0;
    }
    if (*(unsigned char **)(p + 0x10) != 0) {
        func_0202F038(*(unsigned char **)(p + 0x10));
        *(void **)(p + 0x10) = 0;
    }
    if (*(int *)(p + 0x34) != 0)
        func_02028604(*(int *)(p + 0x34));
    func_02031140(*(void **)(p + 0xC));
    func_0201F7A8(*(void **)(p + 0x14), 0);
    func_020452E8(*(void **)(p + 0x14));
    func_02045808(*(void **)(p + 0x18));
    func_0201C4C0(*(void **)(p + 0x28));
    func_020307B0(p);
}
