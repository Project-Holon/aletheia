/*
 * function: func_021FAEA8
 * address: 0x021FAEA8
 * packet: pkt_ov132_021FAEA8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: extent ends with two bytes of zero alignment padding.
 * symbols:
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 */
typedef unsigned short u16;
extern void *func_021F9DA0(char *p);
extern void func_021F8044(void *, int, void *);
extern void func_0207C9D0(void *, void *, void *);
int func_021FAEA8(char *p, void *out)
{
    int v[3];
    func_021F8044(func_021F9DA0(*(void **)p), *(int *)(p + 4), v);
    func_0207C9D0(v, p + 8, out);
    (*(u16 *)(p + 0x16))++;
    if (*(u16 *)(p + 0x16) >= *(u16 *)(p + 0x14)) return 1;
    return 0;
}
