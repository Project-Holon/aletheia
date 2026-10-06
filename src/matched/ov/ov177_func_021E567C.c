/*
 * function: func_021E567C
 * address: 0x021E567C
 * packet: pkt_ov177_021E567C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wP4 S8): EXACT first compile. Twin shape from ov177 021E58A4 (same heap-id mask) and ov172 021BBA94. 0x85 kept in a local (reused as k + 0x9b), 02030734 heap parameter u32 (no halfword truncate before the call).
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040618 0x02040618 arm
 *   func_021E58A4 0x021E58A4 thumb ov177
 */
typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;
extern const char d_021E8DBC[];
typedef signed int     s32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, u32, u32);
extern void func_02082D44(const void *, void *, u32);
extern void *func_020490F4(u32, u16);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0204ABF0(void *, u32, u32, u32, u16);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0204AF28(void *, u32, u32, u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020307B0(void *);
extern void func_02049238(void *);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_021E58A4(int unused, int mode, unsigned color);

u32 *func_021E567C(int unused, int mode, int heap)
{
    u32 *w;
    u32 c;
    u32 k;
    void *h;
    void *hd;
    u32 *out;
    u8 *data;
    u32 l, m;
    w = func_02030734(heap, 0x7c, 0, d_021E8DBC, 0x7d);
    func_02082BCC(w, 0, 0x7c);
    k = 0x85;
    c = (heap & 0x7fff) | 0x8000;
    h = func_020490F4(k, c);
    func_02049B68(h, 0, 0, 0, 0, c);
    func_02049B68(h, 0, 4, 0, 0, c);
    func_02049658(h, 2, 3, 0, 0, 0, c);
    func_02049658(h, 2, 7, 0, 0, 0, c);
    func_021E58A4((int)w, mode, heap);
    w[0] = func_0204ABF0(h, 1, 0, 0, c);
    w[2] = func_0204A6C8(h, 3, 0, 0, c);
    w[4] = func_0204AF28(h, 4, 0xb, c);
    w[1] = func_0204ABF0(h, 1, 1, 0, c);
    w[3] = func_0204A6C8(h, 3, 0, 1, c);
    w[5] = func_0204AF28(h, 4, 0xb, c);
    hd = func_02049F78(h, 0, (u32)&out, heap);
    data = (u8 *)out[3];
    func_02082D44(data, (u8 *)w + 0x38, 0x20);
    k += 0x9b;
    func_02082D44(data + k, (u8 *)w + 0x58, 0x20);
    func_020307B0(hd);
    func_02049238(h);
    l = 0x17;
    m = 5;
    func_02049B40(l, m, 0, 0x1e0, 0x20, c);
    func_02049B40(l, m, 4, 0x1e0, 0x20, c);
    func_02040C14(0, 0, 1, 0);
    func_0201F5BC(0, 1, 0xd, 0, c);
    func_0201F5BC(0, 0xa, 0xe, 0, c);
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_02040618(6, 0, -256);
    func_02040618(m, 0, -256);
    return w;
}
