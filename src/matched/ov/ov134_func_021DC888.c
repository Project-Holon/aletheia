/*
 * function: func_021DC888
 * address: 0x021DC888
 * packet: pkt_ov134_021DC888
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_0203A574 0x0203A574 arm
 *   func_021DCB48 0x021DCB48 thumb ov134
 *   func_021DCC48 0x021DCC48 thumb ov134
 *   tbl_021DCC9C 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[11]; } Args;
extern u8 *func_0203159C(void *, u32, u32);
extern void func_02082BCC(void *, int, u32);
extern void *func_02031324(u16);
extern void func_0203A574(u32, const void *, u32, void *);
extern void func_021DCB48(const Args *, void *, void *);
extern void func_021DCC48(const Args *, void *, void *);
extern const u32 tbl_021DCC9C[];
extern u32 g_02FFFC3C;
int func_021DC888(void *ctx, int unused, const Args *args)
{
    u8 *p;
    p = func_0203159C(ctx, 0x100, 4);
    func_02082BCC(p, 0, 0x100);
    *(Args *)(p + 0xd0) = *args;
    *(u16 *)(p + 0xfc) = 4;
    *(void **)(p + 0xcc) = func_02031324(*(u16 *)(p + 0xfc));
    func_0203A574(0x2f00, tbl_021DCC9C, 1, p);
    func_021DCB48(args, p, p + 4);
    func_021DCC48(args, p, p + 0x9c);
    p[0xc4] = 0;
    *(u32 *)(p + 0xc8) = g_02FFFC3C;
    *(u32 *)p = 0;
    return 1;
}
