/*
 * function: func_021B9AC8
 * address: 0x021B9AC8
 * packet: pkt_ov091_021B9AC8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: arm9 0x020188AC, unfiled Thumb forwarding stub; verified EXACT
 *   with one --thumb, no region (scratch blocker188AC.log).
 *   extern unsigned int func_020188B4(void *, int);
 *   unsigned int func_020188AC(void *p, int n) { return func_020188B4(p, n); }
 * lever: u8 bit pins the prologue spill; explicit zero-initialized result
 *   locals keep the two final empty-slot tests zero-first.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`b = a;` before `b = a - 0x1f;`; `c = a;` before `c = a - 0x1e;`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202130C 0x0202130C thumb
 *   func_020188AC 0x020188AC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
int func_021B9AC8(u8 *p, void *mon, u8 bit)
{
    int empty = 0;
    u8 i;
    u32 a, b, c;
    u32 v;
    if (*(int *)(p + 0x18) == 1) {
        a = *(u16 *)(*(u8 **)(p + 0x280) + 0x46);
        if (a == 0xfffe) {
            a = 0x152;
            b = a - 0x1f;
            c = a - 0x1e;
        } else if (a == 0xfffd) {
            a = 0x280;
            a = a - 0x78;
            b = 0x280;
            b = b - 0x79;
            c = 0x280 - 0x7a;
        } else {
            b = a;
            c = a;
        }
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == a || v == b || v == c) return 3;
            if (v == 0) empty = 1;
        }
        if ((*(u8 *)(*(u8 **)(p + 0x280) + 0x5e) & (1 << bit)) != 0) {
            if (empty == 1) return 0;
            return 1;
        } else return 2;
    } else {
        for (i = 0; i < 4; i++) {
            v = func_02017E1C(mon, i + 0x36, 0);
            if (v == *(u16 *)(*(u8 **)(p + 0x280) + 0x46)) return 3;
            if (v == 0) empty = 1;
        }
        if (*(u16 *)(*(u8 **)(p + 0x280) + 0x44) != 0) {
            u32 id = func_0202130C(*(u16 *)(*(u8 **)(p + 0x280) + 0x44));
            if (id != 0xff && func_020188AC(mon, id) == 1) {
                int result = 0;
                if (empty != 1) result = 1;
                return result;
            } else return 2;
        } else {
            int result = 0;
            if (empty != 1) result = 1;
            return result;
        }
    }
}
