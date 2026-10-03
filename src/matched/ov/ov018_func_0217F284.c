/*
 * function: func_0217F284
 * address: 0x0217F284
 * packet: pkt_ov018_0217F284
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_02158590 0x02158590 thumb ov010
 */
typedef unsigned char u8;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02158590(void *);
int func_0217F284(u8 *p)
{
    void *q = func_020120F4(*(void **)p);
    if (*(int *)(p + 0xe4) == 0 && func_02012B58(q) == 0 && func_02158590(q) == 0) return 1;
    return 0;
}
