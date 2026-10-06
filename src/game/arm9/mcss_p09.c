/*
 * file:     mcss_p09.c
 * unit:     yes
 * function: func_02017CC8, func_02017D30, func_02017D70, func_02017DBC, func_02017DE4
 * address:  0x02017CC8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_02017F50  0x02017F50  thumb
 *   func_02017E64  0x02017E64  thumb
 *   func_02019A50  0x02019A50  thumb
 *   func_02019A9C  0x02019A9C  thumb
 */
struct Personal;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sav {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 14;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

extern u32  func_02017E88(void *a0, u32 a1, u32 a2);
extern u32  func_02019C54(void *a0, u16 a1);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32  func_0201AF6C(u32 a0);
extern u8 func_02017F50(u32 a, u16 b, u32 c);
extern void func_02017E64(void *a0, u32 a1, u32 a2);
extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern u16 func_02019A9C(const u16 *p, u32 size);
void sub_02017CC8(void *a0, void *a1, void *a2);


/*
 * verdict:  EXACT* (match.py: compiled 102, listing extent 104).  The two
 *           trailing bytes at 0x02017D2E are `00 00` padding after the `pop`
 *           and the follower at 0x02017D30 carries no label, so the inferred
 *           extent runs two bytes long.  Never a byte difference; the follower
 *           is reported for the integrator rather than seeded here
 *           (layout/function_starts.txt is not this lane's file).
 */
void sub_02017CC8(void *a0, void *a1, void *a2)
{
    u32 v = func_02017E88(a0, 0x6f, 0);
    u32 t = func_0201AE1C((const struct Personal *)func_02019C54(a1, v), 0x14);
    u32 w = func_0201AE1C((const struct Personal *)func_02019C54(a2, v), 0x14);

    if (func_0201AF6C(t) == 1 && w != 0xff) {
        return;
    }
    func_02017E64(a0, 0x6e, func_02017F50((u32)a1, v, func_02017E88(a0, 0, 0)));
}


u32 func_02017D30(struct Sav *p)
{
    u32 r = 0;

    if (p->b0 == 0) {
        r = 1;
        p->b0 = 1;
        p->b1 = 1;
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 func_02017D70(struct Sav *p, u32 f)
{
    u32 r = 0;

    if (p->b0 == 1 && f == 1) {
        p->b0 = 0;
        p->b1 = 0;
        r = 1;
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 func_02017DBC(struct Sav *p)
{
    u32 r = 0;

    if (p->b1 == 0) {
        p->b1 = 1;
        r = 1;
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}

u32 func_02017DE4(struct Sav *p, u32 f)
{
    u32 r = 0;

    if (p->b1 == 1 && f == 1) {
        r = 1;
        p->b1 = 0;
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
    return r;
}
