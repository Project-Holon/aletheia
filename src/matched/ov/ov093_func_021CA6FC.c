/*
 * function: func_021CA6FC
 * address: 0x021CA6FC
 * packet: pkt_ov093_021CA6FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C70E4 0x021C70E4 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C70E4(u8 *, int, int, int, int, u32);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA6FC(u8 *p, const u8 *q)
{
    if (q[11]) func_021CD4B0(*(void **)(p + 12), 86, 0);
    func_021C70E4(p, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(p, (const struct Msg *)(q + 12));
    return 1;
}
