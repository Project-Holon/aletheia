/*
 * function: func_021C0450
 * address: 0x021C0450
 * packet: pkt_ov093_021C0450
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 * symbols:
 *   func_021C63D0 0x021C63D0 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021C0520 0x021C0520 thumb ov093
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C6564 0x021C6564 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
union Slot { u32 raw; struct { u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17; } s; };
struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };
extern u32 func_021C63D0(u8 *, u8 *);
extern int func_021C4F64(u8 *, u8 *);
extern int func_021BC2B0(u8 *);
extern void func_021C0520(u8 *, u8 *, u16, u32);
extern union Slot func_021D7D18(int);
extern u8 func_021D5440(u8 *);
extern void func_021CD4B0(void *, u32, ...);
extern void func_021C5C1C(u8 *, u8 *, int, union Slot);
extern void func_021C5480(u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern void func_021C6564(u8 *, u8 *, u32, u32);
extern void func_021CC95C(void *, u32, int);
void func_021C0450(u8 *p, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        func_021C63D0(p, q);
        if (func_021C4F64(p, q) && func_021BC2B0(p)) return;
    } else {
        func_021C0520(p, q, c, k);
        switch (k) {
        case 2: func_021C5480(p, q, 598); break;
        case 3: func_021C5480(p, q, 602); break;
        case 4: func_021C5480(p, q, 601); break;
        case 23: {
            union Slot s = func_021D7D18(2);
            func_021CD4B0(*(void **)(p + 12), 49, func_021D5440(q), 0);
            func_021C5C1C(p, q, 2, s);
            func_021C5480(p, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(p + 0x1d74, 5728);
    func_021C6564(p, q, c, k);
    func_021CC95C(p + 0x1d74, old, 5730);
}
