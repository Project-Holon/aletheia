/*
 * function: func_02038DF0
 * address:  0x02038DF0
 * packet:   pkt_02038DF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A50   0x020A7A50  data
 *   func_0203D798  0x0203D798  arm
 *   func_020365E8  0x020365E8  arm
 *   func_02036540  0x02036540  arm
 *   func_02036500  0x02036500  arm
 *   func_020364D4  0x020364D4  arm
 *   func_0203A804  0x0203A804  arm
 *   func_0203A7EC  0x0203A7EC  arm
 *   func_0203A634  0x0203A634  arm
 *   func_0203A81C  0x0203A81C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02038D68  0x02038D68  arm
 *   func_02034714  0x02034714  arm
 *
 * net_system.c packet reassembly: drain a slot's receive ring (src, the
 * 0x10-byte slot header func_0203640C builds; +0x0C is its read cursor)
 * into the reassembly record st, one chunk per turn, asserting at line
 * 0x6E3 on a zero header.  Written fresh from the image: the old note
 * (docs/notes/pkt_02038DF0.c.txt) kept no recoverable source.
 *
 * What closed it:
 *   - func_020364D4 is written in BOTH arms of the func_0203A804 test,
 *       if (!func_0203A804(h)) len = f(src, buf, left, left);
 *       else                   len = f(src, buf, left, n - 7);
 *     The compiler hoists the shared argument setup above the branch and
 *     sinks the call below it, which is the image's `mov r3, r2 / b /
 *     ldr r3, [sp, #4]` diamond.  A ternary argument (any spelling) is
 *     if-converted to moveq/ldrne and is 8 bytes short.
 *   - n is u32 (with it s32 the stack parameter is loaded after the guard
 *     instead of in the prologue); `int lim = n - 7` assigned inside the
 *     loop is an equivalent EXACT spelling.
 *   - h is u32 and declared after len/sv/p (permuter decl-order);
 *     func_02036540's result is narrowed through a u16 local at the 0xFFFF
 *     re-seed (the lsl/lsr pair), so it is declared returning u32 here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Src {
    u8  pad00[0x0c];
    s16 pos;
};

struct St {
    s32 done;
    u8 *dst;
    u16 left;
    u16 total;
    u16 h;
    u8  f0E;
    u8  f0F;
};

extern const u8 str_020A7A24[];
extern const u8 str_020A7A50[];
extern void *func_0203D798(void);
extern int  func_020365E8(struct Src *s);
extern u32  func_02036540(struct Src *s);
extern u8   func_02036500(struct Src *s);
extern int  func_020364D4(struct Src *s, u8 *buf, u32 n, u32 max);
extern int  func_0203A804(u32 h);
extern int  func_0203A7EC(u32 h);
extern int  func_0203A634(u32 a);
extern u8  *func_0203A81C(u32 h, u32 a, u32 b);
extern void func_02082D44(void *dst, const void *src, int n);
extern void func_02038D68(u32 h, u32 total, u8 *dst, struct St *st);
extern void func_02034714(const u8 *file, int line, const u8 *msg);

void func_02038DF0(struct Src *src, u32 a1, u8 *buf, struct St *st, u32 n)
{
    int len;
    s16 sv;
    u8 *p;
    u32 h;
    int cnt;

    func_0203D798();
    while (func_020365E8(src) != 0) {
        h = st->h;
        if (h == 0) {
            h = func_02036540(src);
            if (h == 0) {
                func_02034714(str_020A7A24, 0x6E3, str_020A7A50);
                continue;
            }
        }
        sv = src->pos;
        st->h = h;
        if (st->total == 0xFFFF) {
            if (func_020365E8(src) < 3) {
                src->pos = sv;
                return;
            }
            {
                u16 v = func_02036540(src);
                st->left = v;
                st->total = v;
            }
            st->f0E = a1;
            st->f0F = func_02036500(src);
        }
        sv = src->pos;
        if (func_0203A804(h) && func_0203A634(st->f0F)) {
            if (st->dst == 0)
                st->dst = func_0203A81C(h, st->f0E, st->total);
            p = st->dst + st->done;
        } else {
            p = buf;
            st->dst = buf;
        }
        if (!func_0203A634(st->f0F))
            p = 0;
        if (!func_0203A804(h))
            len = func_020364D4(src, buf, st->left, st->left);
        else
            len = func_020364D4(src, buf, st->left, n - 7);
        st->left = st->left - (u16)len;
        cnt = len;
        if (st->total > st->done) {
            cnt = st->total - st->done;
            if (cnt > len)
                cnt = len;
            if (p != 0)
                func_02082D44(buf, p, cnt);
        }
        st->done += cnt;
        if (st->left == 0) {
            func_02038D68(h, st->total, st->dst, st);
            continue;
        }
        if (!func_0203A7EC(h))
            return;
        if (func_0203A804(h))
            return;
        if (!func_0203A634(st->f0F))
            return;
        st->left += (u16)len;
        src->pos = sv;
        return;
    }
}
