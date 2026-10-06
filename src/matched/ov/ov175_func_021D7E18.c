/*
 * function: func_021D7E18
 * address:  0x021D7E18
 * packet:   pkt_021D7E18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm  ov009
 *   func_021E8738  0x021E8738  thumb  ov177
 *   func_021E8AA0  0x021E8AA0  thumb  ov177
 *   func_021E8AA8  0x021E8AA8  thumb  ov177
 *   func_021E8AB4  0x021E8AB4  thumb  ov177
 *   func_021E8AB8  0x021E8AB8  thumb  ov177
 *   func_021E8844  0x021E8844  thumb  ov177
 *   func_021E7E0C  0x021E7E0C  thumb  ov177
 *   func_020061E4  0x020061E4  thumb
 *   func_02009EC8  0x02009EC8  thumb
 *   func_0200AE14  0x0200AE14  thumb
 *   func_0200B078  0x0200B078  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201A090  0x0201A090  thumb
 *   func_0201A918  0x0201A918  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020242A4  0x020242A4  thumb
 *   func_020245D4  0x020245D4  thumb
 *   func_02025BEC  0x02025BEC  thumb
 *   func_0203064C  0x0203064C  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_02040588  0x02040588  arm
 *   func_02045808  0x02045808  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02052274  0x02052274  arm
 *   func_02156E30  0x02156E30  thumb
 *   func_02156ED0  0x02156ED0  thumb
 *   func_02156F50  0x02156F50  thumb
 *   func_021D965C  0x021D965C  thumb
 *   func_021D97A4  0x021D97A4  thumb
 *   func_021D97B8  0x021D97B8  thumb
 *   func_021D97C4  0x021D97C4  thumb
 *   func_021D9804  0x021D9804  thumb
 *   func_021D9868  0x021D9868  thumb
 *   func_021D98E4  0x021D98E4  thumb
 *   func_021D99F4  0x021D99F4  thumb
 *   func_021D9A08  0x021D9A08  thumb
 *   func_021D9A1C  0x021D9A1C  thumb
 *   func_021D9A30  0x021D9A30  thumb
 *   func_021D9A9C  0x021D9A9C  thumb
 *   func_021D9B2C  0x021D9B2C  thumb
 *   func_021D9BC4  0x021D9BC4  thumb
 *   func_021D9C34  0x021D9C34  thumb
 *   func_021D9D40  0x021D9D40  thumb
 *   func_021D9D50  0x021D9D50  thumb
 *   func_021D9ED4  0x021D9ED4  thumb
 *   func_021D9EEC  0x021D9EEC  thumb
 *   func_021D9F04  0x021D9F04  thumb
 *   func_021DA0D4  0x021DA0D4  thumb
 *   func_021DA1E4  0x021DA1E4  thumb
 *   func_021DA36C  0x021DA36C  thumb
 *   func_021DA384  0x021DA384  thumb
 *   func_021DA390  0x021DA390  thumb
 *   func_021DA434  0x021DA434  thumb
 *   func_021DA45C  0x021DA45C  thumb
 *   func_021DA5B0  0x021DA5B0  thumb
 *   func_021DA6B8  0x021DA6B8  thumb
 *   func_021DB3A4  0x021DB3A4  thumb
 *   func_021DB478  0x021DB478  thumb
 *   func_021DC1A0  0x021DC1A0  thumb
 *   func_021DC1E4  0x021DC1E4  thumb
 *   func_021DC268  0x021DC268  thumb
 *   func_021DC2A0  0x021DC2A0  thumb
 *   func_021DCA28  0x021DCA28  thumb
 *   func_021DCAEC  0x021DCAEC  thumb
 *   func_021D7BE4  0x021D7BE4  thumb
 *   func_021D9064  0x021D9064  thumb
 *   func_021D9090  0x021D9090  thumb
 *   func_021D8EC8  0x021D8EC8  thumb
 *   func_021D8CF0  0x021D8CF0  thumb
 *   func_021D8904  0x021D8904  thumb
 *   func_021D8FA8  0x021D8FA8  thumb
 *
 * The ov175 link-battle main sequence: one step of a 54-state machine over
 *     *state (0..0x35) on the object in r2, with the frame's sys handle in r0.
 *     The listing cuts it at 0x021D885C, a bl-minted label on its own shared
 *     tail (the timeout and disconnect check); the real extent is
 *     0x021D7E18..0x021D8904, 2796 bytes.
 *
 * The six leaf calls that kept it at MATCH* (0x021E8AB4 x3, 0x021E8AB8,
 *     0x02156F50, 0x02009EC8) resolve since seeds_2 labelled and matched them.
 */
#include "../include/Obj24253.h"
#include "../include/Obj24254.h"
#include "../include/Obj24255.h"
#include "../include/Obj24256.h"
#include "../include/Obj24260.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct Sub {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
};

struct W {
    u32 f00;
    u32 f04;
    u32 *f08;
    u32 f0c;
    u32 f10;
    u8 *f14;
    u8 *f18;
    u32 f1c;
    u32 *f20;
    u32 f24;
    u32 *f28;
    u32 f2c;
    u32 f30;
    struct Sub *f34;
    u32 f38;
    u32 f3c;
    u32 *f40;
};

struct Obj {
    u8 pad00[0x14];
    u32 f14;
    u8 pad18[0x10];
    u32 f28;
    u32 f2c;
    u32 pad30;
    void *f34;
    u8 pad38[0xa8];
    u32 fe0;
    u32 fe4;
    u32 fe8;
    u32 fec;
    u32 ff0;
    u32 ff4;
    u32 ff8;
    u32 ffc;
    u32 f100;
    struct W *f104;
    u32 f108;
};

struct Buf16 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void DWC_CloseAllConnectionsHard(void);

extern void func_020061E4(u32 id);
typedef signed int     s32;
struct Big;
struct Reg2;
extern void *func_02009EC8(void *sys);
extern int func_0200AE14(u32 a);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
struct MsgBank;
struct Rec;
struct T;
struct U16Vec;
extern u32 func_0200FB24(void);
extern void *func_02012EBC(struct Big *p);
extern int func_0201A090(void *rules, void *party, u32 *mask);
extern int func_0201A918(void);
extern unsigned int func_0201AA18(void *list);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_020242A4(void *obj, u32 id);
extern u32 func_020245D4(struct T *p, u32 a1);
extern u32 func_02025BEC(u32 a, u32 b, u32 c);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern int func_0203CD98(void);
extern void func_02040588(u32 which, u32 enable);
extern void func_02045808(struct U16Vec *vec);
struct U16Vec;
extern void func_02045A38(struct U16Vec *a, u16 *dst, unsigned int n);
extern u16 func_02045A98(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02052274(u8 *a, u8 *b, u32 n);
extern void func_02156E30(int a, int b, int c, int d);
extern void func_02156ED0(void);
extern void func_02156F50(int a);

extern void func_021D7BE4(u32 sys, int *state, char *p);
extern void func_021D9064(void *obj, int unused, u8 *p);
extern void func_021D9090(u32 sys, int *state, char *p);
extern void func_021D8EC8(u32 sys, int *state, char *p);
extern void func_021D8CF0(u32 sys, int *state, char *p);
extern void func_021D8904(u32 sys, int *state, char *p);
extern void func_021D8FA8(u32 sys, int *state, char *ctx);

extern void func_021D965C(struct Obj *obj);
extern void func_021D97A4(char *obj);
extern u32 func_021D97B8(char *obj);
extern int func_021D97C4(char *obj);
extern void func_021D9804(u32 *obj, u32 arg);
extern u32 func_021D9868(char *obj);
extern void func_021D98E4(u32 *p, int mode);
extern void func_021D99F4(char *obj);
extern int func_021D9A08(char *obj);
extern void func_021D9A1C(char *obj, void *fn);
extern u32 func_021D9A30(char *obj);
extern void func_021D9A9C(char *dst, char *obj);
extern u32 func_021D9B2C(char *obj, void *list, u32 heapId);
extern int func_021D9BC4(u32 a, u32 b);
extern int func_021D9C34(char *obj, int trigger, int go);
extern void func_021D9D40(char *obj);
extern int func_021D9D50(char *obj, u32 *rec);
extern void func_021D9ED4(char *obj, u32 v);
extern int func_021D9EEC(void *ctx);
extern int func_021D9F04(char *ctx, void *a, void *b);
extern void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec);
extern int func_021DA1E4(char *obj);
extern void func_021DA36C(void *ctx);
extern void func_021DA384(char *obj);
extern int func_021DA390(char *obj);
extern int func_021DA434(void *ctx);
extern u32 func_021DA45C(char *obj);
extern void func_021DA5B0(char *obj, int mode, int kind, u32 a3, u32 *rec, u32 slot);
extern int func_021DA6B8(char *p, u32 *out);
extern void func_021DB3A4(char *obj, u32 target, int kind, u32 arg);
extern int func_021DB478(char *obj);
extern u32 func_021DC1A0(char *obj, u32 data);
extern u32 func_021DC1E4(char *obj, char **out);
extern int func_021DC268(void *ctx, u32 *data);
extern u32 func_021DC2A0(char *obj, u32 arg);
extern void func_021DCA28(char *obj, u32 win, u16 tag);
extern int func_021DCAEC(char *obj, int *out);

extern void func_021E7E0C(void **p, int on);
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AA8(int a);
extern void func_021E8AB4(u32 sys, u32 v);
extern void func_021E8AB8(u32 sys);
extern int func_021E8844(const int *p);

static inline void TouchParty(u8 *rec, u8 *buf)
{
    int i;

    func_02052274(rec, buf, 8);
    {
        void *p = rec + 0xd4;

        for (i = 0; i < (int)func_0201AA18(p); i++)
            func_0201AB28(p, i);
    }
}

void func_021D7E18(u32 sys, int *state, struct Obj *obj)
{
    struct Buf16 buf;
    char *rec38;
    u32 mask;
    u32 out;
    u8 b28[8];
    u8 b20[8];
    void *str;
    struct W *w18;
    int flag;
    int fresh;
    int bad;
    int s;
    int res;
    int i;
    int trig = 0;
    u8 *r;
    void *msg;

    w18 = obj->f104;
    flag = 0;
    s = *state;
    if (s >= 0xc && s < 0x1b)
        trig = 1;
    res = func_021D9C34((char *)obj, trig,
                        !((s >= 0x19 && s <= 0x1a) || (s >= 0x11 && s <= 0x12)));
    if (res == 3) {
        *state = 0x28;
        return;
    }

    switch (*state) {
    case 0:
        func_021E8738((int *)obj->f2c, obj->f14, 0x18, 2);
        func_021E8AB4(sys, 1);
        *state = 0x35;
        break;
    case 1:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C((char *)obj, func_021D9090);
            *state = 2;
            break;
        }
        break;
    case 2:
        i = func_021D9A30((char *)obj);
        if (i == 0)
            *state = 4;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            func_021E8AA0((int *)sys, (int)func_021D9064);
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 3:
        func_021E8AA0((int *)sys, (int)func_021D8EC8);
        break;
    case 4:
        if (*obj->f104->f20 == 0) {
            func_021DB3A4(obj->f34, -1, 1, (u32)obj->f104->f34);
            *state = 5;
        }
        break;
    case 5:
        i = func_021DB478(obj->f34);
        if (i == 1) {
            r = w18->f14;
            *obj->f104->f20 = 0;
            func_021D9A9C((char *)r, (char *)obj);
            *obj->f104->f28 = obj->f104->f34->f14;
            if (func_021D9D50((char *)obj, (u32 *)obj->f104->f34) != 0)
                *state = 6;
            else
                *state = 0xa;
        }
        if (i != 0) {
            switch (func_021D9F04(obj->f34, 0, 0)) {
            case 1:
                func_021E8AA0((int *)sys, (int)func_021D7BE4);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (func_021D97C4((char *)obj) != 0) {
            func_021D97A4((char *)obj);
            *state = 8;
        }
        break;
    case 8:
        func_021D965C(obj);
        *state = 9;
        break;
    case 9:
        if (func_021D97B8((char *)obj) != 0)
            *state = 0xa;
        break;
    case 0xa:
        obj->fec = 0;
        func_021E7E0C((void **)obj->f28, 1);
        func_021E8738((int *)obj->f2c, obj->f14, 0x55, 0);
        *state = 0x35;
        func_021E8AB4(sys, 0xb);
        break;
    case 0xb:
        i = obj->f108;
        MI_CpuFill8(&buf, 0, sizeof(buf));
        buf.a = obj->f104->f34->f10;
        buf.b = obj->f104->f34->f04;
        buf.c = func_0200B078((struct Reg2 *)i, 2);
        buf.d = obj->f104->f34->f08 + obj->f104->f34->f0c;
        func_021DA0D4(obj->f34, 0, 0, w18->f08[1], (int *)(&buf));
        obj->fe4 = 0;
        obj->fe8 = 0;
        *state = 0xc;
        break;
    case 0xc:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        i = func_021DA1E4(obj->f34);
        if (i == 1)
            *state = 0xd;
        else if (i == 2)
            *state = 0xb;
        break;
    case 0xd:
        if (res == 0) {
            if (func_021DC1A0(obj->f34, (u32)w18->f14) != 0) {
                *state = 0xe;
                obj->ff0 = 0;
            }
        } else {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0xe:
        if (func_021DC1E4(obj->f34, &rec38) != 0) {
            MI_CpuCopy8(rec38, w18->f18, func_0201A918() + 0xd4);
            r = w18->f18;
            bad = 0;
            fresh = 1;
            for (i = 0; i < 8; i++) {
                if (((u16 *)r)[i] == func_02045A98())
                    fresh = 0;
            }
            if (fresh) {
                bad++;
                msg = func_02045B38(0, 2, 0xd2, 0x8057);
                str = func_02045EC0(msg, 0x8057);
                func_02045A38(str, (u16 *)r, 8);
                func_02045808(str);
                func_02045C04(msg);
            }
            if (r[0x1d] != 0 && r[0x1d] != 1) {
                r[0x1d] = 0;
                bad++;
            }
            if ((u8)r[0x1c] >= 0x10) {
                r[0x1c] = r[0x1d] == 0 ? 0 : 8;
                bad++;
            }
            if (func_02025BEC(r[0x18], r[0x19], r[0x1a]) == 0) {
                r[0x18] = 0;
                r[0x19] = 0;
                bad++;
            }
            if (func_020245D4((struct T *)(r + 0x38), 0x8057) == 0) {
                func_020242A4(r + 0x38, 1);
                bad++;
            }
            if (bad == 0)
                func_02009EC8(func_02012EBC((struct Big *)(*w18->f08)));
            *state = 0xf;
        }
        flag = 1;
        break;
    case 0xf:
        TouchParty(w18->f14, b28);
        TouchParty(w18->f18, b20);
        if (((struct Obj24253 *)(w18->f14))->f40 == ((struct Obj24254 *)(w18->f18))->f40
            && ((struct Obj24255 *)(w18->f14))->f50 == ((struct Obj24256 *)(w18->f18))->f50)
            *state = 0x10;
        else
            *state = 0x33;
        break;
    case 0x10:
        mask = 0;
        if (func_0201A090((void *)func_0200AE14(obj->f108), w18->f18 + 0xd4, &mask) == 0) {
            *state = 0x11;
        } else {
            obj->fe4++;
            *state = 0x16;
        }
        break;
    case 0x11:
        if (*obj->f104->f20 == 0) {
            func_021DB3A4(obj->f34, ((struct Obj24260 *)(obj->f104->f18))->f4C, 3, obj->ffc);
            *state = 0x12;
        }
        break;
    case 0x12:
        i = func_021DB478(obj->f34);
        if (i == 1) {
            *obj->f104->f20 = 0xe10;
            *state = 0x13;
        }
        if (i != 0) {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x13:
        func_021D9ED4(obj->f34, 0x17);
        *state = 0x14;
        break;
    case 0x14:
        if (func_021D9EEC(obj->f34) != 0)
            *state = 0x15;
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x15:
        if (func_021D9BC4(obj->ffc, (u32)(obj->f104->f18 + 0xd4)) == 0)
            obj->fe4++;
        if (func_021D9B2C((char *)obj->f104->f18, obj->f104->f18 + 0xd4, 0x57) == 0)
            obj->fe4++;
        *state = 0x16;
        break;
    case 0x16:
        if (res == 0) {
            if (func_021DC268(obj->f34, &obj->fe4) != 0) {
                *state = 0x17;
                obj->ff0 = 0;
            }
        } else {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
            case 4:
                obj->fec = 0;
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D8CF0);
                func_021D9D40((char *)obj);
                break;
            case 2:
                func_021D99F4((char *)obj);
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x17:
        if (func_021DC2A0(obj->f34, (u32)(&obj->fe8)) != 0)
            *state = 0x18;
        else
            flag = 1;
        break;
    case 0x18:
        if (obj->fe8 == 0 && obj->fe4 == 0)
            *state = 0x19;
        else
            *state = 0x33;
        break;
    case 0x19:
        func_021DCA28(obj->f34, (u32)w18->f18, 0x57);
        *state = 0x1a;
        break;
    case 0x1a:
        if (func_021DCAEC(obj->f34, (int *)(&out)) != 0) {
            *obj->f104->f40 = out;
            *state = 0x1b;
        }
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x1b:
        if (res == 0) {
            func_021D9ED4(obj->f34, 0x15);
            obj->ff0 = 0;
            *state = 0x1c;
        }
        break;
    case 0x1c:
        if (func_021DA45C(obj->f34) == 0 && func_021D9EEC(obj->f34) != 0)
            *state = 0x1d;
        flag = 1;
        break;
    case 0x1d:
        func_021D9ED4(obj->f34, 0x16);
        *state = 0x1e;
        obj->ff0 = 0;
        break;
    case 0x1e:
        if (func_021D9EEC(obj->f34) != 0)
            *state = 0x1f;
        flag = 1;
        break;
    case 0x1f:
        func_021E7E0C((void **)obj->f28, 0);
        func_020061E4(0x63a);
        func_021E8738((int *)obj->f2c, obj->f14, 0x57, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x20);
        obj->fe0 = 0;
        break;
    case 0x20:
        if (obj->fe0++ > 0x78) {
            obj->fe0 = 0;
            func_02040588(0, 0);
            func_021D9804((u32 *)obj, (u32)w18->f18);
            *state = 0x21;
        }
        break;
    case 0x21:
        if (func_021D9868((char *)obj) != 0)
            *state = 0x22;
        break;
    case 0x22:
        if (obj->fe0++ != 0) {
            obj->fe0 = 0;
            *state = 0x23;
        }
        break;
    case 0x23:
        func_0203064C(1, 0x86, 0x60000);
        func_02156E30(9, 0x60000, 1000, 0x86);
        func_02156F50(0x86);
        func_021DA5B0(obj->f34, 0, 0, 0, 0, 0);
        obj->ff4 = 0;
        *state = 0x24;
        obj->ff8 = 0;
        break;
    case 0x24:
        if (obj->ff8 == 0)
            obj->ff8 = func_021DA6B8(obj->f34, &obj->ff4);
        if (obj->ff8 == 1)
            *state = 0x25;
        if (obj->ff8 != 0) {
            switch (func_021D9F04(obj->f34, 0, (void *)1)) {
            case 1:
                func_021DA36C(obj->f34);
            case 2:
            case 4:
                func_02156ED0();
                func_021E7E0C((void **)obj->f28, 0);
                func_021E8AA0((int *)sys, (int)func_021D9064);
                break;
            }
        }
        break;
    case 0x25:
        func_02156ED0();
        func_02040588(0, 1);
        func_021E8738((int *)obj->f2c, obj->f14, 0x24, 2);
        *state = 0x35;
        func_021E8AB4(sys, 0x26);
        break;
    case 0x26:
        if (obj->fe0++ > 0x3c) {
            obj->fe0 = 0;
            w18->f04 = 1;
            func_021E8AA8(sys);
        }
        break;
    case 0x27:
        func_021DA36C(obj->f34);
        func_021E7E0C((void **)obj->f28, 0);
        w18->f0c = 2;
        obj->f100 = 1;
        if (obj->ff4 != 0)
            func_021E8AA0((int *)sys, (int)func_021D8904);
        else
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
        break;
    case 0x28:
        func_021E8738((int *)obj->f2c, obj->f14, 0x4e, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x29);
        break;
    case 0x29:
        func_021D98E4((u32 *)obj, 0);
        *state = 0x2a;
        break;
    case 0x2a:
        i = func_021D9A08((char *)obj);
        if (i != -1) {
            func_021D99F4((char *)obj);
            switch (i) {
            case 0:
                func_021E8AA0((int *)sys, (int)func_021D8FA8);
                break;
            case 1:
                *state = 0x2b;
                break;
            }
        }
        break;
    case 0x2b:
        func_021E8738((int *)obj->f2c, obj->f14, 0x26, 1);
        *state = 0x35;
        func_021E8AB4(sys, 0x2c);
        break;
    case 0x2c:
        func_021D98E4((u32 *)obj, 0);
        *state = 0x2d;
        break;
    case 0x2d:
        i = func_021D9A08((char *)obj);
        if (i != -1) {
            func_021D99F4((char *)obj);
            switch (i) {
            case 0:
                *state = 0x2e;
                break;
            case 1:
                *state = 0x28;
                break;
            }
        }
        break;
    case 0x2e:
        *state = 0x2f;
        break;
    case 0x2f:
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        case 0:
            func_021D9A1C((char *)obj, func_021D9090);
            *state = 0x30;
            break;
        }
        break;
    case 0x30:
        i = func_021D9A30((char *)obj);
        if (i == 0)
            *state = 0xa;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            func_021E8AA0((int *)sys, (int)func_021D9064);
        switch (func_021D9F04(obj->f34, 0, 0)) {
        case 1:
            func_021E8AA0((int *)sys, (int)func_021D7BE4);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
        break;
    case 0x31:
        if (func_021DA434(obj->f34) != 0)
            *state = 0x32;
        break;
    case 0x32:
        func_021DA36C(obj->f34);
        *state = 0xa;
        break;
    case 0x33:
        func_021DA384(obj->f34);
        *state = 0x34;
        obj->ff0 = 0;
        break;
    case 0x34:
        flag = 1;
        if (func_021DA390(obj->f34) != 0)
            *state = 0xb;
        break;
    case 0x35:
        if (func_021E8844((const int *)obj->f2c) != 0)
            func_021E8AB8(sys);
        break;
    }

    if (flag) {
        i = 0;
        if (obj->ff0++ > 0x4b0) {
            obj->ff0 = 0;
            i = 1;
        }
        if (func_021DA45C(obj->f34) != 0)
            i = 1;
        if (i) {
            func_021DA36C(obj->f34);
            if (func_0200FB24() == 0 && func_0203CD98() != 0)
                DWC_CloseAllConnectionsHard();
            *state = 0xa;
        }
        switch (func_021D9F04(obj->f34, 0, (void *)1)) {
        case 1:
        case 4:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D8CF0);
            func_021D9D40((char *)obj);
            break;
        case 2:
            func_021E7E0C((void **)obj->f28, 0);
            func_021E8AA0((int *)sys, (int)func_021D9064);
            break;
        }
    }
}
