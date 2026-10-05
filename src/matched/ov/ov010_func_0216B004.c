/*
 * function: func_0216B004
 * address:  0x0216B004
 * packet:   pkt_ov010_0216B004
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * Proc main of an ov010 sub-sequence: a 9-state machine that registers the
 * party member's species/form key with the save (clearing the form to 12
 * when it is not yet seen), runs the ov098 screen and then the ov227 one,
 * and frees both work buffers when it runs past the last state.
 *
 * Byte-correct. Evidence gaps, not C: 0x02189A08 (ov021), 0x021B6158
 * (ov098) and 0x021B95C8 (ov227) carry no func_ label in their overlay
 * and have no second caller; d_021B6D74 and d_021B98A4 are the ov098 and
 * ov227 proc tables. Levers: `ok` at function scope (its slot sits above
 * the case-1 locals), heap declared before mon in both key blocks, and
 * the u16 flag stored in both arms of an if/else.
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02012944  0x02012944  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021B6100  0x021B6100  thumb  ov098
 *   func_021B6158  0x021B6158  thumb  ov098
 *   func_021B95A0  0x021B95A0  thumb  ov227
 *   func_021B95C8  0x021B95C8  thumb  ov227
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   d_021B6D74     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Key {
    u32 species : 11;
    u32 pad0 : 12;
    u32 form : 6;
    u32 pad1 : 3;
} Key;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 f10[0x10];       /* 0x10 */
    Key f20;            /* 0x20 */
    u16 f24;            /* 0x24 */
    u8 pad26[2];
    u16 *f28;           /* 0x28 */
} Work;

extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 d_021B6D74[];
extern u8 d_021B98A4[];

extern void *func_020124E4(void *evt);
extern void *func_020120F4(void *h);
extern void *func_02029BCC(void *h, u16 v);
extern void func_02012374(void *evt, void *task);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void *func_02012EBC(void *sys);
extern u32 func_0200E2BC(void *sv, Key *key, u32 heap, u32 mode);
extern void *func_020144DC(void *h, void *proc);
extern void *func_0201292C(void *sys);
extern void func_02007E50(void *p, u32 a, u32 b, u32 heap);
extern void func_02034AC4(u32 id);
extern void func_02034A5C(u32 id);
extern void *func_02012944(void *sys);
extern void *func_0200873C(void *sv);
extern void *func_0200CA10(void *sv);
extern void func_02012444(void *evt, u32 id, void *data, void *arg);
extern void func_02007F1C(void *p, u32 a, u32 b, u32 heap);
extern void *func_02029C00(void *h);
extern void *func_020145CC(void *h);
extern void *func_02029CC0(void *h);
extern void func_020307B0(void *p);
extern void *func_02189A08(void *p);
extern void func_021CF498(void *p, void *evt, void *arg);
extern void *func_021B6100(void *sys, void *mon, void *out, void *a, void *b, void *c, void *d, u32 heap);
extern int func_021B6158(void *p);
extern void *func_021B95A0(void *sys, int ok, void *mon, u32 heap);
extern void func_021B95C8(void *p);

int func_0216B004(void *evt, u32 *state, Work *w)
{
    void *h = func_020124E4(evt);
    void *sys = func_020120F4(h);
    int ok;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(h, 0x468));
        (*state)++;
        break;
    case 1: {
        u32 heap;
        void *mon;
        Key key;

        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), &key, heap, 1) == 0)
            w->f20.form = 12;
        func_021CF498(func_02189A08(w->f00), evt, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        func_02012374(evt, func_020144DC(h, w->f00));
        (*state)++;
        break;
    case 4: {
        void *sv = func_02012EBC(sys);

        func_02007E50(func_0201292C(sys), 0x240, 1, w->f24);
        func_02034AC4((u32)ov098_id);
        w->f04 = func_021B6100(sys, w->f0c, w->f10, func_02012944(sys), func_0201292C(sys),
                               func_0200873C(sv), func_0200CA10(sv), w->f24);
        func_02012444(evt, -1, d_021B6D74, w->f04);
        (*state)++;
        break;
    }
    case 5: {
        u32 heap;
        void *mon;
        Key key;

        ok = func_021B6158(w->f04);
        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), &key, heap, 1) == 0
            || func_0200E2BC(func_02012EBC(sys), &w->f20, w->f24, 0) == 0)
            ok = 0;
        if (ok == 1)
            *w->f28 = 1;
        else
            *w->f28 = 0;
        func_02034A5C((u32)ov098_id);
        func_02034AC4((u32)ov227_id);
        w->f08 = func_021B95A0(sys, ok, w->f0c, w->f24);
        func_02012444(evt, -1, d_021B98A4, w->f08);
        func_02007F1C(func_0201292C(sys), 0x240, 1, w->f24);
        (*state)++;
        break;
    }
    case 6:
        func_021B95C8(w->f08);
        func_02034A5C((u32)ov227_id);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    default:
        func_020307B0(w->f0c);
        func_020307B0(w->f04);
        return 1;
    }
    return 0;
}
