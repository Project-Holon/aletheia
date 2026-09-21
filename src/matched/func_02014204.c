/*
 * function: func_02014204
 * address:  0x02014204
 * packet:   pkt_020141A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  matched - 0x02013C70's only call site image-wide is the one
 *           inside this function, and src/pending/func_02013C70.c is itself
 *           only MATCH (its pool word for tbl_0209E010 has no outside
 *           witness), so no `matched` entry can attest the site.  Every
 *           concrete byte here is correct; --suggest-split reports no
 *           viable cut.
 * symbols:
 *   sub_02013B90   0x02013B90  thumb
 *   sub_02013B74   0x02013B74  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct t {
    u32 a;      /* 0x00 */
    u16 b;      /* 0x04 */
    s16 c;      /* 0x06 */
    u16 d;      /* 0x08 */
    u16 e;      /* 0x0a */
    u32 f;      /* 0x0c */
    u16 g;      /* 0x10 */
    u8  pad[2];
    u16 h;      /* 0x14 */
    u16 i;      /* 0x16 */
};

struct v3 { u32 x, y, z; };

extern void func_020140F8(struct t *p);
extern int  func_02013C70(int id);
extern void sub_02013B90(int id, struct v3 *out);
extern void sub_02013B74(int id, struct v3 *out);

void func_02014204(struct t *p, int id)
{
    struct v3 v;

    func_020140F8(p);
    p->a = 1;
    p->b = id;
    p->c = -1;
    p->d = 2;
    p->e = 0;
    if (func_02013C70(id) != 0) {
        sub_02013B90(id, &v);
        p->f = 1;
        *((u8 *)p + 0x12) = 1;
        p->g = v.x;
        p->i = v.y;
        p->h = v.z;
    } else {
        sub_02013B74(id, &v);
        p->f = 0;
        *(struct v3 *)((u8 *)p + 0x10) = v;
    }
}
