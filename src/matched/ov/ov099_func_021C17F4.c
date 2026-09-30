/*
 * function: func_021C17F4
 * address: 0x021C17F4
 * packet: pkt_ov099_021C17F4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: func_021C27E0 returns u8, eliminating the redundant narrowing at 021C1848.
 * symbols:
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021C27E8 0x021C27E8 thumb ov099
 *   func_021C2864 0x021C2864 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
typedef unsigned char u8;
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *, int);
extern void func_0201DD68(void);
extern int func_021BA858(char *);
extern u8 func_021C27E0(void *);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern void func_021C18C8(char *, int, int);
extern void func_021B9AE0(char *, void *);
extern void func_021C19A8(char *);
extern void func_021BAEDC(char *);
extern void func_021BA8EC(char *);
int func_021C17F4(char *p, int state)
{
    void *selection;
    int result;
    selection = func_021BE2A8(p, func_021B97F4(p + 0x274));
    func_0201DD68();
    result = func_021BA858(p);
    if (result == -1) return state;
    if (result == 0) {
        func_021C27E8(*(void **)(p + 8), 1 - func_021C27E0(*(void **)(p + 8)));
        func_021C2864(*(void **)(p + 8), func_021C27E0(*(void **)(p + 8)));
        *(u8 *)(p + 0x1356) = 2 - *(u8 *)(*(char **)(p + 0x248) + 0x46);
        *(int *)(p + 0x1cc) = 118;
    } else {
        *(int *)(p + 0x135c) = 0;
        func_021C18C8(p, 1, 2);
        *(int *)(p + 0x1f0) = -1;
        if (selection != 0) func_021B9AE0(p + 0x274, selection);
        func_021C19A8(p);
        func_021BAEDC(p);
        *(int *)(p + 0x1cc) = 11;
    }
    func_021BA8EC(p);
    return state;
}
