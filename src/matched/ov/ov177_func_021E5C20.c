/*
 * function: func_021E5C20
 * address: 0x021E5C20
 * packet: pkt_ov177_021E5C20
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (recoup R4): EXACT. Lever: heap parameter u16 with u16 heap parameters on every callee (02030734 first, 021E6718 last, 021E72FC fourth, 021E7464 fifth), no heapId local. u8 also gives EXACT; u16 chosen to match the sibling constructors 5D68/6118/7520. The earlier u16-only try changed only this function and gave 264 B.
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_021E6718 0x021E6718 thumb ov177
 *   func_021E72FC 0x021E72FC thumb ov177
 *   func_0204B404 0x0204B404 arm
 *   func_021E7464 0x021E7464 thumb ov177
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y; } Point;
typedef struct {
    u32 f0; u16 h4, pad6; u32 f8; void *fC; u16 h10, h12;
} Info;
typedef struct {
    char pad0[0x188];
    void *f188;
    char pad18c[0x230 - 0x18c];
    u8 c230, c231, c232, c233;
    u32 f234;
    char pad238[0x244 - 0x238];
} Work;
extern const char d_021E8DBC[];
struct Obj;
struct Vec2;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern u32 func_021E7CF0(void *, u16, u16);
extern void func_021E6718(Work *, u32, const Info *, void *, int, void *, void *, void *, int, u16);
extern void func_021E72FC(u8 *, u32, u32, u16);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021E7464(char *, char *, u32, void *, u16);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern void func_020409B4(u32);
Work *func_021E5C20(const Info *info, u32 a1, void *a2, int owner,
                    void *table, int a5, void *a6, void *a7, void *a8, u16 heap)
{
    Work *w;
    u32 kind;
    u32 size;
    int alt;
    Point pos;
    size = 0x229 + 0x1b;
    w = func_02030734(heap, size, 0, d_021E8DBC, 0x229);
    func_02082BCC(w, 0, size);
    w->c230 = 5;
    w->c231 = 15;
    w->c232 = 3;
    w->c233 = 7;
    w->f234 = 1;
    alt = 1;
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    kind = func_021E7CF0(info->fC, info->h10, info->h12);
    if (kind != 5) alt = 0;
    func_021E6718(w, a1, info, a2, a5, a6, a7, a8, alt, heap);
    func_021E72FC((u8 *)w, info->f8, owner, heap);
    pos.x = 0x120;
    pos.y = 0x44;
    func_0204B404(w->f188, (const struct Vec2 *)(&pos), 1);
    func_021E7464((char *)w, (char *)info, owner, table, heap);
    func_020413B0(6, 0, 0, 0x20, 6, 1);
    func_020413B0(6, 0, 6, 0x20, 18, kind + 3);
    func_020409B4(6);
    func_0207D63C((void *)0x04001050, 4, 8, 15, 3);
    return w;
}
