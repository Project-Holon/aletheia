/*
 * function: func_021C64B4
 * address:  0x021C64B4
 * packet:   pkt_ov093_021C64B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is the integrator's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 *
 * symbols:
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u16 func_021D57FC(void *p);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x16, sub_0201C1C8((void *)q));
    func_021D75A8(0x1C, func_021D57FC(a));
    func_021D75A8(0x1A, sub_0201C1E8(q));
    func_021D75A8(0x1B, sub_0201BD28(q, 0x1B));
    func_021D7630(0x4B, 0);
    func_021D70F0(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = func_021D775C(0x16);
    out->h4 = func_021D775C(0x1C);
    out->w8 = func_021D775C(0x1A);
    out->wC = func_021D775C(0x1B);
    out->w10 = 0;
    if (func_021D775C(0x4B) != 0) {
        out->b6 = 0x11;
    }
    func_021D7540(11493);
}
