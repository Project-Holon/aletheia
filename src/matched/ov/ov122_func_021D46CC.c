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
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`a = 0x30c;` before `a = 0x37c;`; `b = 0x30c;` before `b = 0x378;` and 5
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT in --lang c99 and --lang c: the output bytes
 * do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 */
#include "../include/Obj00073.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 v[3]; } Triple;
typedef struct { u16 f00, f02, f04; u8 f06, f07; } Request;
extern const Triple data_021D5708, data_021D5704, data_021D570C;
struct Obj;
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
struct Actor;
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
    a = 0x37c;
    b = 0x378;
    c = 0x380;
    d = 0x390;
    e = 0x390;
    f = 0x390;
    g = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.f00 = x.v[i]; req.f02 = y.v[i]; req.f04 = z.v[i];
        req.f06 = 1; req.f07 = 2;
        q = p + 4 * i;
        *(void **)(q + d) = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, *(u32 *)(p + a), *(u32 *)(p + b), *(u32 *)(p + c), &req, 1, ((struct Obj00073 *)p)->fC);
        func_0204B92C(*(void **)(q + e), 0);
        func_0204B3DC(*(void **)(q + f), 1);
        func_0204B688(*(void **)(q + g), 1);
    }
    req.f00 = 128; req.f02 = 96; req.f04 = 15; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f39C = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f39C, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f39C, 1);
    func_0204B688(((struct Obj00073 *)p)->f39C, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 18; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A0 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A0, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A0, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A0, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 25; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A4 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A4, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A4, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A4, 1);
}
