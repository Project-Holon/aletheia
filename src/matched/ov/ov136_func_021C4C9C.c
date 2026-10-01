/*
 * function: func_021C4C9C
 * address: 0x021C4C9C
 * packet: pkt_ov136_021C4C9C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021EE4 0x02021EE4 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021C4B88 0x021C4B88 thumb ov136
 *   d_021C7EF8 0x021C7EF8 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02021FD8(void *, u32, u32, u32, u8, u16);
extern void func_02021EE4(void *, int);
extern void func_02021D50(void *);
extern u32 func_02030CB0(int);
extern void *func_02030734(u32, u32, u32, const char *, u32);
extern void *func_02030CBC(int, void *);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), u8 *, int);
extern void func_021C4B88(void *, u8 *);
extern char d_021C7EF8[];
void func_021C4C9C(u8 *p)
{
    void *q;
    func_02021FD8(*(void **)(p + 0x38), 0, 0, 112, 16, 0);
    func_02021EE4(*(void **)(p + 0x38), 1);
    func_02021D50(*(void **)(p + 0x38));
    p[0x18] = 0;
    p[0x19] = 0;
    q = func_02030734((u16)*(u32 *)p, func_02030CB0(3), 0, d_021C7EF8, 0x4F3);
    *(void **)(p + 0xF4) = q;
    *(void **)(p + 0xF8) = func_02030CBC(3, q);
    *(void **)(p + 0xFC) = func_02030DA8(*(void **)(p + 0xF8), func_021C4B88, p, 0);
}
