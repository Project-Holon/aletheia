/*
 * unit: yes
 * function: func_021F00F8, func_021F0114
 * address: 0x021F00F8
 * packet: pkt_ov030_021F00F8
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: empty follower func_021F0114 then two-byte zero padding.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 */
typedef unsigned int u32;
extern void *func_020120F4(void *);
extern u32 func_0201283C(const void *);
extern u32 func_0201058C(u32);
void func_021F00F8(char *p)
{
    if (*(void (**)(char *))p != 0) {
        (*(void (**)(char *))p)(p);
    }
    func_0201058C(func_0201283C(func_020120F4(*(void **)(p + 24))));
}
void func_021F0114(void)
{
}
