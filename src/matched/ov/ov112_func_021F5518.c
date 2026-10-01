/*
 * function: func_021F5518
 * address: 0x021F5518
 * packet: pkt_ov112_021F5518
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at021F55F6 before existing021F55F8.
 * lever: keep D30 result wide until the byte-width D58 call argument.
 * prototype: empty hook185F4 retains original r0 input; D58 byte second argument is original result truncation at5518+1e/+20.
 * symbols:
 *   func_020185F4 0x020185F4 thumb
 *   func_02019D30 0x02019D30 thumb
 *   func_02019D58 0x02019D58 thumb
 *   func_0202D09C 0x0202D09C thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_0202D110 0x0202D110 thumb
 *   func_0202D144 0x0202D144 thumb
 *   func_0202D178 0x0202D178 thumb
 *   func_0202D1AC 0x0202D1AC thumb
 *   func_0202D1E0 0x0202D1E0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020185F4(void *);
extern u32 func_02019D30(u32, u32);
extern int func_02019D58(u16, u8);
extern int func_0202D09C(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D0D4(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D110(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D144(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D178(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D1AC(u32,u32,u32,u32,u32,u32,u32);
extern int func_0202D1E0(u32,u32,u32,u32,u32,u32,u32);
void func_021F5518(u8 *p, u32 *out, u32 k)
{
    u32 a, c, d, flag;
    int b;
    u32 n;
    func_020185F4(*(void **)(p + 4));
    a = *(u16 *)(p + 8);
    n = func_02019D30(a, p[11]);
    c = p[10];
    d = p[12];
    flag = 0;
    b = func_02019D58(*(u16 *)(p + 8), n);
    if (k == 1) flag = 1;
    out[0] = 52;
    out[1] = func_0202D09C(out[0],a,b,c,d,flag,0);
    out[2] = func_0202D0D4(out[0],a,b,c,d,flag,0);
    out[3] = func_0202D110(out[0],a,b,c,d,flag,0);
    out[4] = func_0202D144(out[0],a,b,c,d,flag,0);
    out[5] = func_0202D178(out[0],a,b,c,d,flag,0);
    out[6] = func_0202D1AC(out[0],a,b,c,d,flag,0);
    out[7] = func_0202D1E0(out[0],a,b,c,d,flag,0);
    out[8] = *(u32 *)(p + 16);
}
