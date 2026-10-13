/*
 * function: INTRUDE_COMM_ScanCallback
 * address:  0x02173368
 * packet:   pkt_ov011_02173368
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   WIH_IsMatchingParent  0x0217873C  thumb  ov014
 *   func_02177494  0x02177494  thumb  ov014
 *   func_02177BFC  0x02177BFC  thumb  ov014
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02158570  0x02158570  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C50  0x02165C50  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 f3_0 : 1;
    u8 f3_1 : 1;
    u8 f3_rest : 6;
    u32 id;
    u32 w8;
    u32 lo : 17;
    u32 mon : 10;
    u32 hi : 5;
} Rec;

typedef struct Obj {
    u8 pad0[0x925];
    u8 count;
    u8 f926;
    u8 pad927;
    u32 a928[2];
    u32 ids[2];
    u8 b938[2];
    u8 b93a[2];
    u8 pad93c[3];
    u8 f93f_0 : 1;
    u8 f93f_1 : 1;
    u8 f93f_rest : 6;
} Obj;

extern int func_0203D1B4(void);
extern u32 func_0200FB24(void);
extern int WIH_IsMatchingParent(u8 *p);
extern int func_02177494(u8 *obj, u32 flags);
extern Rec *func_02177BFC(void *, u8 *);
extern u32 func_02013D5C(u32 id);
extern int func_02158570(u16);
extern void func_02165C34(struct Rec *r, void *buf);
extern u8 func_02165D08(struct Rec *r);
extern u8 func_02165C50(u32 *);

void INTRUDE_COMM_ScanCallback(void *a0, Obj *s)
{
    u8 kind;
    Rec *rec;
    int i;

    if (s->count >= 2) {
        return;
    }
    if (func_0203D1B4() > 1) {
        return;
    }
    if (s->f93f_1 == 1) {
        return;
    }
    if (func_0200FB24() != 0) {
        return;
    }
    if (WIH_IsMatchingParent(a0) == 0) {
        return;
    }
    if (func_02177494(a0, ~0x10) == 0) {
        return;
    }
    rec = func_02177BFC(a0, &kind);
    if (kind != 3) {
        return;
    }
    if (rec->f3_1) {
        return;
    }
    for (i = 0; i < s->count; i++) {
        if (rec->id == s->ids[i]) {
            return;
        }
    }
    if ((int)func_02013D5C((u16)rec->mon) == 1) {
        return;
    }
    if (func_02158570(rec->mon) == 0) {
        return;
    }
    func_02165C34((struct Rec *)(&rec->w8), (void *)s->a928[s->count]);
    s->b938[s->count] = func_02165D08((struct Rec *)(&rec->w8));
    s->b93a[s->count] = func_02165C50(&rec->w8);
    s->ids[s->count] = rec->id;
    s->f926 = 0;
    s->count++;
}
