/*
 * function: func_0203CBAC
 * address:  0x0203CBAC
 * packet:   pkt_0203CBAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (199 concrete bytes at 488 against 492; note only, not filed)
 *
 * symbols:
 *   g_021469E0     0x021469E0  data
 *   file_020A7CA0  0x020A7CA0  data
 *   str_020A7CA8   0x020A7CA8  data
 *   str_020A7CB8   0x020A7CB8  data
 *   str_020A7CE8   0x020A7CE8  data
 *   func_0203064C  0x0203064C  arm
 *   func_02030734  0x02030734  arm
 *   func_0200F17C  0x0200F17C  thumb
 *   func_02034714  0x02034714  arm
 *   func_0203D8F0  0x0203D8F0  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203AFCC  0x0203AFCC  arm
 *   func_02039834  0x02039834  arm
 *   func_0203A494  0x0203A494  arm
 *   func_02037010  0x02037010  arm
 *
 * Start one network session.  The 0x354-byte session record is allocated on
 * the heap named by the request's +0x56 halfword ("net.c" at 0x020A7CA0,
 * line 0x6a), published into the module block's +8 slot, marked live at
 * +0x352, and seeded with the vtable that func_0200F17C returns for the
 * request's +0x65 mode byte.
 *
 * The mode byte then drives a seven-way dense switch
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md; here the
 * table is the `addls pc, pc, r0, lsl #2` branch run at 0x0203CC6C, so the
 * displacements name the cases directly).  Modes 2 and 3 share the
 * indirect-call arm, modes 4 and 5 share the beacon arm, mode 1 and mode 6
 * fall through to the common tail, and mode 0 is the error case.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CBAC.c \
 *       --func func_0203CBAC --addr 0x0203CBAC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Req {
    u32 f00;
    u32 f04;
    u8  pad_08[0x40];
    u32 f48;
    u8  pad_4c[8];
    u16 f54;
    u16 f56;
    u16 f58;
    u16 f5a;
    u16 f5c;
    u16 f5e;
    u8  pad_60[1];
    u8  f61;
    u8  pad_62[3];
    u8  f65;
    u8  pad_66[1];
    u8  f67;
};

struct Sess {
    u8  pad_000[0x340];
    u32 (**f340)(void);
    u8  pad_344[8];
    u32 f34c;
    u8  pad_350[2];
    u8  f352;
};

struct Mod {
    u8  pad_00[8];
    struct Sess *f08;
};

extern const char file_020A7CA0[];
extern const char str_020A7CA8[];
extern const char str_020A7CB8[];
extern const char str_020A7CE8[];
extern struct Mod g_021469E0;

extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);
extern void *func_0200F17C(u32 mode);
extern void  func_02034714(const char *file, u32 line, const char *msg);
extern struct Req *func_0203D8F0(struct Req *req, u32 a);
extern void  func_02082D44(void *dst, void *src, u32 n);
extern void  func_0203AFCC(u32 heap, u32 a);
extern void  func_02039834(struct Sess *s);
extern void  func_0203A494(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void  func_02037010(u32 a, u32 b, u32 c, u32 d);

void func_0203CBAC(struct Req *req, u32 a2, u32 a3)
{
    struct Sess *s;

    if (*(u16 *)&g_021469E0 == 0)
        func_0203064C(req->f54, req->f56, 0x7800);
    else
        func_0203064C(*(u16 *)&g_021469E0, req->f56, 0x7800);

    s = (struct Sess *)func_02030734(req->f56, 0x354, 1, file_020A7CA0, 0x6a);
    g_021469E0.f08 = s;
    s->f352 = 1;
    s->f340 = (u32 (**)(void))func_0200F17C(req->f65);
    if (s->f340 == 0)
        func_02034714(file_020A7CA0, 0x6f, str_020A7CA8);

    if (req->f65 == 4)
        req = func_0203D8F0(req, a3);

    func_02082D44(req, s, 0x70);

    switch (req->f65) {
    case 1:
    case 2:
    case 6:
        ((void (*)(u32, u32))(*s->f340))(req->f54, 0);
        func_0203064C(req->f54, (u16)(req->f58 | 0x8000), req->f48);
        return;
    case 3:
    case 4:
        if (req->f61 > 0x80)
            func_02034714(file_020A7CA0, 0x84, str_020A7CB8);
        {
            u32 v = *(u16 *)&g_021469E0;

            if (v == 0)
                v = req->f54;
            func_0203064C(v, req->f5a, 0x1b00);
        }
        return;
    case 0:
    case 5:
        break;
    default:
        func_02034714(file_020A7CA0, 0x8e, str_020A7CE8);
        return;
    }

    s->f34c = a3;
    func_0203AFCC(req->f56, a2);
    func_02039834(s);
    func_0203A494(req->f67 << 8, req->f00, req->f04, s->f34c, req->f56);
    {
        u8 m = req->f65;

        if (m == 3 || m == 4)
            return;
        func_02037010(req->f5c, req->f5e, (u8)(m + 0xff) <= 1, req->f56);
    }
}
