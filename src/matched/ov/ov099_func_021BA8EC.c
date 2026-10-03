/*
 * function: func_021BA8EC
 * address: 0x021BA8EC
 * packet: pkt_ov099_021BA8EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA8D4 0x021BA8D4 thumb ov099
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 */
typedef unsigned int u32;
struct PrintSys;
extern void func_021BA8D4(void *);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201CE48(void *);
extern int func_021BA8BC(void *);
void func_021BA8EC(char *p)
{
    func_021BA8D4(p);
    if (func_0201C6B4(*(struct PrintSys **)(p + 0x1B8)) == 0)
        func_0201C6EC(*(struct PrintSys **)(p + 0x1B8));
    if (*(void **)(p + 0x1BC) != 0) {
        func_0201CE48(*(void **)(p + 0x1BC));
        *(int *)(p + 0x1BC) = 0;
    }
    *(int *)(p + 0x190) = func_021BA8BC(*(void **)(p + 0x190));
}
