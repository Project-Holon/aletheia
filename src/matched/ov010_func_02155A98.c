/*
 * function: func_02155A98
 * address:  0x02155A98
 * packet:   pkt_ov010_02155A98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the ov010 link sequence task (func_02155C0C over a Seq) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 *
 * symbols:
 *   func_02155C0C  0x02155C0C  thumb  ov010
 *   func_0216576C  0x0216576C  thumb  ov010
 *   func_02157028  0x02157028  thumb  ov010
 *   func_021F685C  0x021F685C  thumb  ov112
 *   func_021F68BC  0x021F68BC  thumb  ov112
 *   func_021FD904  0x021FD904  thumb  ov132
 *   func_021FC848  0x021FC848  thumb  ov132
 *   func_0203064C  0x0203064C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02012F44  0x02012F44  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0200A81C  0x0200A81C  thumb
 *   func_02005728  0x02005728  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Seq;

struct Link {
    struct Seq *owner;  /* 0x00 */
    void *sess;         /* 0x04 */
};

typedef struct Seq {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    struct Link *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1c;          /* 0x1C */
    void *f20;          /* 0x20 */
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    void *f2c;          /* 0x2C */
    void *f30;          /* 0x30 */
    void *f34;          /* 0x34 */
    void *f38;          /* 0x38 */
    u32 f3c;
    void *f40;          /* 0x40 */
    u8 f44[4];          /* 0x44 */
    u32 f48;
    u8 f4c;             /* 0x4C */
    u8 pad4d[3];
    u32 f50;            /* 0x50 */
} Seq;

typedef u32 (*TaskFn)(void *task, u32 *state, Seq *work);

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern Seq *func_020124E8(void *task);
extern void *func_02012EBC(void *sys);
extern void *func_02012138(void *p);
extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02012934(void *p);
extern void *func_0201AB28(void *list, u32 i);
extern u32 func_02017E1C(void *p, u32 id, void *v);
extern void func_0216576C(void *p);
extern void func_02045808(void *p);
extern void *func_02012F44(void *h);
extern void *func_021F685C(u32 heap);
extern int func_021FD904(void *sess);
extern u16 func_0200A7C8(void *sv);
extern void func_021F68BC(void *p, void *a, void *b, u16 c, u32 d);
extern void *func_02012944(void *p);
extern void *func_020185F0(void *p);
extern void func_021FC848(void *sess, void *a, void *b, void *c, void *d, u32 heap);
extern u16 func_0200A81C(void *p);
extern u32 func_02005728(u32 n);
extern void *func_02157028(u32 heap, void *src, u16 lim);
extern u32 func_02155C0C(void *task, u32 *state, Seq *work);

void *func_02155A98(void *a, void *b, u32 c, u32 d, struct Link *link)
{
    void *task;
    Seq *s;
    void *tmp;

    func_0203064C(1, 0x802C, 0x42000);
    task = func_020122C0(a, 0, func_02155C0C, sizeof(Seq));
    s = func_020124E8(task);
    s->f00 = a;
    s->f04 = b;
    s->f14 = d;
    s->f1c = func_02012EBC(b);
    s->f20 = func_02012138(a);
    s->link = link;
    s->link->owner = s;
    s->f28 = link->sess;
    s->f50 = 0;
    s->f38 = 0;
    tmp = func_020457B0(11, 4);
    s->f18 = func_0201AB28(func_02012934(s->f04), c);
    func_02017E1C(s->f18, 0x73, tmp);
    func_0216576C(tmp);
    func_02045808(tmp);
    s->f2c = 0;
    s->f30 = 0;
    s->f34 = 0;
    s->f40 = func_02012F44(b);
    s->f24 = func_021F685C(4);
    if (s->f14 == 0 || func_021FD904(s->link->sess) == 1)
        func_021F68BC(s->f24, s->f1c, s->f04, func_0200A7C8(s->f40), 0x2C);
    if (s->f14 == 1) {
        s->state = 11;
        s->f10 = 0;
        func_021FC848(s->f28, func_02012944(s->f04), func_020185F0(s->f18), s->f20, s->f24, 4);
    } else {
        u16 lim = func_0200A81C(s->f40);
        u8 i;
        u8 j;
        u8 k;
        u8 t;

        for (i = 0; i < 4; i++)
            s->f44[i] = i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                k = func_02005728(4);
                t = s->f44[j];
                s->f44[j] = s->f44[k];
                s->f44[k] = t;
            }
        }
        s->f4c = s->f44[0];
        s->f38 = func_02157028(4, s->f24, lim);
        s->state = 13;
        s->f10 = 0;
    }
    return task;
}
