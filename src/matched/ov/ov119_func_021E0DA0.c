/*
 * function: func_021E0DA0
 * address: 0x021E0DA0
 * packet: pkt_ov119_021E0DA0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(void *);
void func_021E0DA0(char *p)
{
    if (*(void **)(p + 0x10)) {
        func_0204B3B4(*(void **)(p + 0x10));
        *(int *)(p + 0x10) = 0;
        func_021B6284(p);
    }
}
