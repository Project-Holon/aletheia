/*
 * file:     net_state_p28.c
 * unit:     yes
 * function: func_02039C68, func_02039CA0, func_02039CB4, func_02039CD8, func_02039D94, func_0203A020
 * address:  0x02039C68
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020395EC  0x020395EC  arm
 *   func_0203A2F0  0x0203A2F0  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203A28C  0x0203A28C  arm
 *   g_021469D4     0x021469D4  data
 *   file_020A7A68  0x020A7A68  data
 *   msg_020A7A94   0x020A7A94  data
 *   func_020395E0  0x020395E0  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02039160  0x02039160  arm
 *   func_020399B8  0x020399B8  arm
 *   func_02039A5C  0x02039A5C  arm
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CD8  0x02039CD8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0203D394  0x0203D394  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   func_02087C6C  0x02087C6C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 */
#include "../../matched/include/Obj15949.h"
#include "../../matched/include/Obj04750.h"
#include "../../matched/include/Obj08835.h"

struct Entry;
struct NetEntry;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Link {
    u8 pad_00[0x44];
    u16 unk44;
    u16 unk46;
    u8 unk48;
    u8 unk49;
};

struct Obj {
    u8   pad_00[8];
    void *slot[8];
    u8   pad_28[0x16];
    u16  key;
};

typedef signed int     s32;

extern int func_020395EC(struct Entry *a);
extern u32 func_0203A2F0(u32 a0, u32 a1);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);
extern int func_020395E0(int slot);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_02039160(u16 mode);
extern u32 func_020399B8(u8 *e);
extern void func_02039A5C(void);
extern u16 func_02039338(void);
extern struct Entry *func_020399A8(void);
extern int func_02039CD8(struct Obj *p);
extern u32 func_0203D378(void);
extern u32 func_0203D394(struct NetEntry *e);
extern u32 func_0203D4D0(u8 *e, u32 a, u32 b, u32 c, void *d, u32 e2, u32 f, u32 g2);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D650(void);
extern void *func_0203D798(void);
extern void func_02034714(const char *file, u32 line, const char *msg);
void func_02039D94(void);
extern void func_02087C6C(u8 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base);
extern u8 *g_021469D4;
extern const char file_020A7A68[];
extern const char msg_020A7A94[];



/*
 * A whole translation unit, matched as one byte range.
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * sub_02039CA0 has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside sub_02039C68's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */
void sub_02039C68(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return;
    }

    p->unk46 = lo + (hi << 8);
    p->unk48 = 0xff;

    if (func_020395EC((struct Entry *)p) == 0xff) {
        p->unk49 = 0;
    } else {
        p->unk49 = 1;
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * sub_02039CA0 has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside sub_02039C68's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */
u32 sub_02039CA0(struct Link *p, u32 key)
{
    return p->unk44 == key;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * sub_02039CA0 has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside sub_02039C68's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */
u32 sub_02039CB4(struct Link *p, u32 lo, u32 hi)
{
    if (p == 0) {
        return 1;
    }
    return p->unk44 == lo + (hi << 8);
}


/*
 * Sweep the eight slot pointers at +0x8.  A slot that is still marked in use
 * (+0xd non-zero) and whose bit is not set in the key word at +0x3e is torn
 * down through the eight-argument delegate; a delegate failure aborts the
 * whole sweep with 0, otherwise the key's bit is set.  Falling off the end
 * clears the key word and reports success.
 *
 * The eight-argument call's first stack slot is the slot pointer itself and
 * the remaining three are the constants 1, 0, 1 (r5 is the object, 0xff/4/
 * 0x10 are the register arguments).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039CD8.c \
 *       --func func_02039CD8 --addr 0x02039CD8 --cc 1.1p1 --arm
 */
int func_02039CD8(struct Obj *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((struct Obj15949 *)((char *)p->slot[i]))->fD == 0)
            continue;
        if (func_0203A2F0(p->key, i) != 0)
            continue;
        if (func_0203D3F8((u32)p, 0xff, 4, 0x10, (u32)p->slot[i], 1, 0, 1) != 0)
            func_0203A28C(p->key, i, 1);
        else
            return 0;
    }
    p->key = 0;
    return 1;
}


/*
 * The net_handle.c tick (docs/families/net_handle.h).  Closed from the
 * 652-byte / 14-out source of docs/notes/pkt_02039D94.c.txt with two
 * changes:
 *   1. The two owner callbacks at g+0x14 / g+0x10 each TAKE func_0203D650's
 *      result as their argument: `a = g->get_a(func_0203D650())`.  That is
 *      why the image calls through r1 (`ldr r1, [r4, #0x14]; blx r1`):
 *      r0 is holding the argument.  Called with no argument the compile
 *      goes through r0 (4 bytes out).
 *   2. Phases 2 and 4 reuse the entry pointer `e` for the own entry
 *      (func_0203996C(0xff)); there is no separate `own` local.  With a
 *      separate local the own pointer and the loop index swap sb/sl in
 *      phase 2 (or r6/r7 in phase 4).
 */
void func_02039D94(void)
{
    u8 *e;
    u8 *g;
    int i;

    for (i = 0; i < 8; i++) {
        u32 s = func_020395E0(i);
        e = (u8 *)func_0203996C(s);
        if (func_02039160((u16)s) == 0)
            func_020399B8(e);
    }

    func_02039A5C();

    if (func_0203D378() != 0) {
        e = (u8 *)func_0203996C(0xff);
        for (i = 0; i < 9; i++) {
            u8 *r = g_021469D4 + i;
            if (r[0x18] != 1)
                continue;
            if (func_0203D4D0(e, r[0x10], 8, 2,
                              g_021469D4 + i * 2, 0, 0, 0) == 0)
                continue;
            if ((g_021469D4 + i)[0x10] == 0)
                func_02034714(file_020A7A68, 0x29a, msg_020A7A94);
            (g_021469D4 + i)[0x18] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        u8 *p;
        p = (u8 *)func_0203996C(func_020395E0(i));
        if (func_0203D394((struct NetEntry *)p) == 0)
            continue;
        if (p[0x49] == 0)
            continue;
        if (func_020395EC((struct Entry *)p) == 0xff)
            continue;
        if (func_0203D3A8((struct Entry *)p, (u16)7, (u16)4, (u32)(p + 0x46)) != 0)
            p[0x49] = 0;
    }

    if (func_02039338() == 0) {
        e = (u8 *)func_0203996C(0xff);
        if (e != 0) {
            for (i = 0; i < 8; i++) {
                u8 *s = *(u8 **)(e + i * 4 + 8);
                if (s == 0 || s[0xd] == 0)
                    continue;
                if (func_0203A2F0(((struct Obj04750 *)e)->f40, i) != 0)
                    continue;
                if (func_02039CD8((struct Obj *)e) != 0)
                    ((struct Obj04750 *)e)->f40 =
                        func_0203A28C(((struct Obj04750 *)e)->f40, i, 1);
            }
        }
    }

    g = func_0203D798();
    if (g[0x65] == 4)
        return;

    e = (u8 *)func_020399A8();
    if (e[0x4e] != 1)
        return;

    if (((struct Obj08835 *)g)->f10 != 0 && ((struct Obj08835 *)g)->f14 != 0) {
        u32 a;
        u32 b;
        a = (*(u32 (**)(u32))(g + 0x14))(func_0203D650());
        b = (*(u32 (**)(u32))(g + 0x10))(func_0203D650());
        if (func_0203D3A8((struct Entry *)e, (u16)0xa, (u16)a, (u32)((void *)b)) != 0)
            e[0x4e] = 0;
    } else {
        e[0x4e] = 0;
    }
}

/*
 * net_handle.c: claim a connection slot for the message a2 (MAC copy,
 * id bytes, OS_GetMacAddress) when this machine owns the table, else mark
 * the table dirty.
 *
 * The 11-byte residue of docs/notes/pkt_02039CD8.c.txt and
 * pkt_02039D94.c.txt (the in-use `strb` scheduled after the MI_CpuCopy8
 * argument setup, the `1` in r3) was the message parameter's pointee
 * qualifier: `const u8 *a2`.  With a2 const-qualified the store to p[0xd]
 * no longer has to be ordered against the reads of a2 that feed the call.
 * A top-level `u8 * const a2` does nothing.  `volatile` on the owner
 * record stays load-bearing (the zero arm's load order).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A020.c  *       --func func_0203A020 --addr 0x0203A020 --arm --cc 1.1p1
 */
void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base)
{
  volatile u8 *r4 = func_0203D798();
  u8 *p;
  u8 *own;
  own = (u8 *) func_0203996C(0xff);
  if (own != base)
    goto mismatch;
  p = *((u8 **) ((base + (idx * 4)) + 8));
  if (p[0xd] != 0)
    return;
  p[0xd] = 1;
  MI_CpuCopy8(a2, p + 6, 6);
  p[0xc] = a2[6];
  func_02087C6C(p);
  if (a2[8] == 0)
    goto zero;
  if ((a2[6] != 0) && (a2[7] != r4[0x67]))
  {
    if ((*((u16 *) (r4 + 0x6e))) == a2[8])
    {
      p[0xf] = *((u16 *) (r4 + 0x6e));
      p[0xe] = *((u16 *) (r4 + 0x6e));
      return;
    }
  }
  if (((a2[6] == 0) && (a2[7] == r4[0x67])) && ((*((u16 *) (r4 + 0x6e))) == a2[8]))
  {
    p[0xf] = *((u16 *) (r4 + 0x6e));
    p[0xe] = *((u16 *) (r4 + 0x6e));
  }
  else
  {
    p[0xf] = 0xff;
    p[0xe] = 0;
  }
  return;
  zero:
  {
    u8 hi = r4[0x67];
    u8 lo = a2[7];
    p[0xf] = hi;
    p[0xe] = lo;
  }

  return;
  mismatch:
  base[0x4e] = 1;

}
