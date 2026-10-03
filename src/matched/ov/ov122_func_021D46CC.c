/*
 * function: func_021D46CC
 * address: 0x021D46CC
 * packet: pkt_ov122_021D46CC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: duplicate literal assignments preserve the seven spilled offset homes.
 * ABI: 0204B294 fifth input is the request address, forwarded unchanged; r0 result is stored.
 * paired: Request* and u32 fifth-argument spellings both produce EXACT 524 bytes.
 * symbols:
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 v[3]; } Triple;
typedef struct { u16 f00, f02, f04; u8 f06, f07; } Request;
extern const Triple data_021D5708, data_021D5704, data_021D570C;
extern void *func_0204B294(u32, u32, u32, u32, Request *, u16, u16);
struct Actor;
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021D46CC(char *p)
{
    Triple x = data_021D5708;
    Triple y = data_021D5704;
    Triple z = data_021D570C;
    Request req;
    int i, a, b, c, d, e, f, g;
    i = 0;
    a = 0x30c; a = 0x37c;
    b = 0x30c; b = 0x378;
    c = 0x30c; c = 0x380;
    d = 0x30c; d = 0x390;
    e = 0x30c; e = 0x390;
    f = 0x30c; f = 0x390;
    g = 0x30c; g = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.f00 = x.v[i]; req.f02 = y.v[i]; req.f04 = z.v[i];
        req.f06 = 1; req.f07 = 2;
        q = p + 4 * i;
        *(void **)(q + d) = func_0204B294(*(u32 *)(p + 0x30c), *(u32 *)(p + a), *(u32 *)(p + b), *(u32 *)(p + c), &req, 1, *(u16 *)(p + 0xc));
        func_0204B92C(*(void **)(q + e), 0);
        func_0204B3DC(*(void **)(q + f), 1);
        func_0204B688(*(void **)(q + g), 1);
    }
    req.f00 = 128; req.f02 = 96; req.f04 = 15; req.f06 = 0; req.f07 = 2;
    *(void **)(p + 0x39c) = func_0204B294(*(u32 *)(p + 0x30c), *(u32 *)(p + 0x37c), *(u32 *)(p + 0x378), *(u32 *)(p + 0x380), &req, 1, *(u16 *)(p + 0xc));
    func_0204B92C(*(void **)(p + 0x39c), 1);
    func_0204B3DC(*(void **)(p + 0x39c), 1);
    func_0204B688(*(void **)(p + 0x39c), 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 18; req.f06 = 0; req.f07 = 2;
    *(void **)(p + 0x3a0) = func_0204B294(*(u32 *)(p + 0x30c), *(u32 *)(p + 0x37c), *(u32 *)(p + 0x378), *(u32 *)(p + 0x380), &req, 1, *(u16 *)(p + 0xc));
    func_0204B92C(*(void **)(p + 0x3a0), 1);
    func_0204B3DC(*(void **)(p + 0x3a0), 0);
    func_0204B688(*(void **)(p + 0x3a0), 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 25; req.f06 = 0; req.f07 = 2;
    *(void **)(p + 0x3a4) = func_0204B294(*(u32 *)(p + 0x30c), *(u32 *)(p + 0x37c), *(u32 *)(p + 0x378), *(u32 *)(p + 0x380), &req, 1, *(u16 *)(p + 0xc));
    func_0204B92C(*(void **)(p + 0x3a4), 1);
    func_0204B3DC(*(void **)(p + 0x3a4), 0);
    func_0204B688(*(void **)(p + 0x3a4), 1);
}
