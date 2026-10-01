/*
 * function: func_021DEADC
 * address: 0x021DEADC
 * packet: pkt_ov183_021DEADC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 */
extern int func_021FF88C(void *);
extern void func_021F9C6C(void *);
extern void func_021FD71C(void *);
extern int func_021FD72C(void *);
extern void func_021FD854(void *);
extern void func_0201C4E4(void *);
extern void func_021FC830(void *);
extern void func_021FD1BC(void *);
int func_021DEADC(int a, int b, int c, char *p)
{
    int i;
    if (func_021FF88C(*(void **)(*(char **)(p + 0x108) + 0x18)) == 2) {
        func_021F9C6C(*(void **)(*(char **)(p + 0x108) + 0x14));
        return 1;
    }
    func_021FD71C(*(void **)(p + 0x10));
    if (func_021FD72C(*(void **)(p + 0x10)) != 0) return 1;
    for (i = 0; i < 2; i++) func_021FD854(*(void **)(p + 0x1C + i * 4));
    func_0201C4E4(*(void **)(p + 0x14));
    if (*(void **)(p + 8) != 0) func_021FC830(*(void **)(p + 8));
    if (*(void **)(p + 0xC) != 0) func_021FC830(*(void **)(p + 0xC));
    if (*(void **)(p + 0x24) != 0) func_021FD1BC(*(void **)(p + 0x24));
    return 0;
}
