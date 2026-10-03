/*
 * unit: yes
 * function: func_021DD39C, func_021DD474
 * address: 0x021DD39C
 * packet: pkt_ov093_021DD39C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021DD338 0x021DD338 thumb ov093
 *   func_021DD368 0x021DD368 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F1BB4 0x021F1BB4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct QG;
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021DD338(void *a, int b);
extern u8 func_021DD368(void *a, int b);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D554C(void *p, u8 i);
extern u16 func_021D54C0(u8 *p, int i);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
int func_021DD39C(int a, void *b, u8 c, int d, int e)
{
    void *m;
    u32 i;
    u32 n;
    u8 slot;
    u8 *r;
    m = func_021C7CF4(b, c);
    slot = func_021DD338(b, c);
    if (slot == 4) {
        slot = func_021DD368(b, c);
        if (slot == 4 && e) {
            n = func_021D5448(m);
            for (i = 0; i < n; i++) {
                if (func_021D554C(m, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != 4) {
        r = (u8 *)func_021C88A4(b, 9, c);
        r[4] = 10;
        r[5] = c;
        r[6] = slot;
        r[7] = (r[7] & ~1) | 1;
        func_021C8838(r + 8, 2, 0x38f);
        func_021C8860(r + 8, c);
        func_021C8860(r + 8, func_021D70A8((void *)a));
        func_021C8860(r + 8, func_021D54C0(m, slot));
        func_021C88C8(b, r);
        return 1;
    }
    return 0;
}
extern u8 d_021F1BB4[];
void *func_021DD474(int *p) { *p = 5; return d_021F1BB4; }
