/*
 * function: func_021B8A38
 * address: 0x021B8A38
 * packet: pkt_ov071_021B8A38
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020435F4 0x020435F4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_021B8ED0 0x021B8ED0 thumb ov071
 *   func_021B8BF4 0x021B8BF4 thumb ov071
 *   func_021B8ABC 0x021B8ABC thumb ov071
 */

extern int func_0201C6B4(void *);
extern void func_020435F4(unsigned int);
extern void func_020315D4(void *);
extern void func_021B8ED0(void *);
extern void func_021B8BF4(void **);
extern void func_021B8ABC(void);
int func_021B8A38(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(*(void **)(*(char **)(c+4)+8)) == 0) return 0;
    func_020435F4(8);
    func_021B8ED0(d);
    func_021B8BF4(d);
    func_021B8ABC();
    func_020315D4(a);
    return 1;
}
