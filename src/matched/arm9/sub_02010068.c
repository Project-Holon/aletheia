/*
 * unit:     no
 * function: GFL_NET_ERR_LoadScreenGraphics
 * address:  0x02010068
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g0209DEA0      0x0209DEA0  data
 *
 * blocked: literal.  Every concrete byte matches; the only four unresolved
 * sites are the four ABS32 pool words for g0209DEA0 (base+0/+2/+4/+6, the
 * four u16 fields of an 8-byte-stride table indexed by a0).  The word
 * 0x0209DEA0 appears in exactly one literal pool image-wide, at 0x02010148,
 * which is inside this function's own extent, so no witness exists outside
 * the compared range and no cut can free it.  Needs a second referrer of
 * the table, or a matched neighbour that pools the same address.
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ent {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct res0 {
    u8  pad[0x10];
    u32 len;
    void *ptr;
};

struct res1 {
    u32 pad0;
    u32 pad4;
    u32 len;
    u8  buf[4];
};

struct res2 {
    u8  pad[0xc];
    void *ptr;
};

extern struct ent g0209DEA0[];

extern void *func_0207E24C(void);
extern void *func_0207DFB4(void);
extern void func_02082A7C(u32 val, void *dst, u32 n);
typedef signed int     s32;
struct NitroFileHeader;
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void DWCi_ScreenDC_FlushRange(void *p, u32 n);
extern void MIi_CpuCopy16(void *dst, const void *src, u32 n);
extern u32 func_020307B0(void *p);
extern int func_02062B30(void *file, void **out);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

void GFL_NET_ERR_LoadScreenGraphics(u32 a0)
{
    void *h;
    struct res0 *r0p;
    struct res1 *r1p;
    struct res2 *r2p;
    u32 sp0;
    u16 id;

    func_02082A7C(0, func_0207E24C(), 0x4000);

    id = g0209DEA0[a0].f0;
    h = (void *)ARC_UTIL_LoadMember(id, g0209DEA0[a0].f2, 0, 1);
    if (func_02062A4C(h, (void **)(&r0p)) != 0) {
        u32 n;
        void *src;
        DWCi_ScreenDC_FlushRange(r0p->ptr, r0p->len);
        n = r0p->len;
        src = func_0207E24C();
        MIi_CpuCopy16(r0p->ptr, src, n);
    }
    func_020307B0(h);

    h = (void *)ARC_UTIL_LoadMember(id, g0209DEA0[a0].f4, 0, 1);
    if (func_02062B30(h, (void **)(&r1p)) != 0) {
        u32 n;
        void *src;
        DWCi_ScreenDC_FlushRange(r1p->buf, r1p->len);
        n = r1p->len;
        src = func_0207DFB4();
        MIi_CpuCopy16(r1p->buf, src, n);
    }
    func_020307B0(h);

    h = (void *)ARC_UTIL_LoadMember(id, g0209DEA0[a0].f6, 0, 1);
    func_02062AD4(h, (void **)(&sp0));
    if (func_02062A98(h, (void **)(&r2p)) != 0) {
        DWCi_ScreenDC_FlushRange(r2p->ptr, 0x20);
        MIi_CpuCopy16(r2p->ptr, (void *)0x05000000, 0x20);
    }
    func_020307B0(h);
}
