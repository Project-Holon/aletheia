/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_02035D5C, sub_02035D98, sub_02035DC8, sub_02035DD8,
 *           sub_02035E08, sub_02035E18
 * address:  0x02035D5C
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_02035750  0x02035750  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208AD14  0x0208AD14  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *
 * The open/close pair of the 0x02035000 block's link layer, plus their
 * no-context wrappers.  sub_02035DD8 brings the link up (state word at +0x5a
 * goes to 1) and sub_02035D98 takes it down (state word goes back to 0);
 * both refuse to act unless the handle at +0x58 is live and the state is not
 * already where they would leave it.
 *
 * The four workers are kept in one unit deliberately: sub_02035D5C,
 * sub_02035D98, sub_02035DD8 and sub_02035E18 are each reached by exactly
 * one branch in the image, the one in this same file, so as separate files
 * every wrapper would cap at MATCH.  Inside one range each site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035D5C.c \
 *       --addr 0x02035D5C --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sio {
    u8 pad_00[0x0c];
    u8 buf[0x4c];
    u16 unk58;
    u16 unk5a;
    u8 pad_5c[0x19];
    u8 unk75;
};

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int func_02035750(void);
extern void func_0208AC0C(u32 a, u32 b, void *c, u32 d);
extern void func_0208AD14(void);
extern void func_0208B220(u32 slot);
extern u32 func_0208B238(u32 slot);

u32 sub_02035D5C(struct Sio *p);
u32 sub_02035E18(struct Sio *p);
void sub_02035D98(struct Sio *p);
void sub_02035DD8(struct Sio *p);

u32 sub_02035D5C(struct Sio *p)
{
    if (p->unk58 == 0) {
        return 1;
    }
    func_0208AD14();
    func_0208B220(4);
    if (func_0208B238(4) != 0) {
        return 2;
    }
    return 1;
}

void sub_02035D98(struct Sio *p)
{
    struct Sio *sio = (struct Sio *)func_02035750();

    if (sio != 0 && sio->unk5a != 0 && sio->unk58 != 0) {
        sub_02035E18(sio);
        sio->unk5a = 0;
    }
}

void sub_02035DC8(void)
{
    sub_02035D98((struct Sio *)func_02035224());
}

void sub_02035DD8(struct Sio *p)
{
    struct Sio *sio = (struct Sio *)func_02035750();

    if (sio != 0 && sio->unk5a != 1 && sio->unk58 != 0) {
        sub_02035D5C(sio);
        sio->unk5a = 1;
    }
}

void sub_02035E08(void)
{
    sub_02035DD8((struct Sio *)func_02035224());
}

u32 sub_02035E18(struct Sio *p)
{
    u32 ret;

    func_0208AC0C(0, p->unk75, p->buf, 9);
    ret = 2;
    func_0208B220(2);
    if (func_0208B238(2) == 0) {
        ret = 1;
    }
    return ret;
}
