/*
 * file:     scrcmd_musical_p02.c
 * unit:     yes
 * function: func_0215D7D4, func_0215D864, func_0215D884, func_0215DADC
 * address:  0x0215D7D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F44  0x02012F44  thumb
 *   func_0200A750  0x0200A750  thumb
 *   func_0200A6BC   0x0200A6BC  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   func_02156A3C  0x02156A3C  thumb  ov010
 *   func_02156AD4  0x02156AD4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_0200A7A0  0x0200A7A0  thumb
 *   func_0200A7F8  0x0200A7F8  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 */
struct Big;
struct BigSub4;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Work;
struct WordSet;
struct Strbuf;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u8 pad[0x14];
    u8 *f14;
} Cur;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
} Rec;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012F44(void *);
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);
extern void func_0200A6BC(struct Big *p, u32 index);
extern void *func_0215A5F4(void *vm);
extern u16 func_0215A5CC(void *a0);
extern void *func_02158F74(void *p);
extern void *func_02156914(int a0, int a1);
extern void func_02156A3C(struct Work *w, u8 j, void *ws, u32 slot);
extern void func_02156AD4(struct Work *w, u8 j, void *ws, u32 slot);
extern int func_02012F80(char *base);
extern u8 func_0200A7A0(struct Big *p, u32 index);
extern u8 *func_0200A7F8(struct Big *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
int func_0215D7D4(Cur *a, void *b);
int func_0215D864(void *a0, void *a1);
int func_0215D884(Ctx *c, void *vm);
int func_0215DADC(void *a,void *b);


int func_0215D7D4(Cur *a, void *b)
{
    int f;
    u32 k;
    u16 *out;
    Rec *r;
    f = func_02159B10(a, b);
    k = *a->f14;
    a->f14++;
    out = func_02159AE8(a, b);
    r = (Rec *)func_0200A750(func_02012F44(func_0215A5E4(b)), (u8)f);
    switch (k) {
    case 0:
        switch (r->b0) {
        case 0: *out = 0x18; break;
        case 1: *out = 0xf; break;
        case 2: *out = 0x2d; break;
        case 3: *out = 0xc; break;
        case 4: *out = 0; break;
        }
        break;
    case 1:
        *out = f + 5;
        break;
    case 2:
        f += 0xf;
        *out = f;
        break;
    case 3:
        *out = r->b1;
        break;
    case 4:
        *out = r->h2;
        break;
    }
    return 0;
}


/*
 * blocked:   wild=4
 *
 * The slot index is truncated to a byte before the arm9 pair call.
 */
int func_0215D864(void *a0, void *a1)
{
    int v = func_02159B10(a0, a1);

    func_0200A6BC((struct Big *)func_02012F44(func_0215A5E4(a1)), (u8)v);

    return 0;
}


/*
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into
 * the slot (player name, message-bank entries, link member names, or the
 * three placement labels of a four-way ranking).
 */
int func_0215D884(Ctx *c, void *vm)
{
    void *wsx = func_0215A5F4(vm);
    void *h = func_0215A5E4(vm);
    u32 heap = func_0215A5CC(vm);
    void *ws = func_02158F74(wsx);
    u8 op;
    u8 slot;
    u32 arg;
    void *bank;
    void *str;

    op = *c->pc;
    c->pc++;
    slot = *c->pc;
    c->pc++;
    arg = func_02159B10(c, vm);

    switch (op) {
    case 0: {
        void *sv = func_02012F44(func_0215A5E4(vm));

        str = func_020457B0(0x26, heap);
        func_02045994(str, (const u16 *)func_0200A7F8(sv), 0x26);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    }
    case 1:
    case 8:
        if (op == 1)
            bank = func_02045B38(0, 2, 0x4F, heap);
        else
            bank = func_02045B38(0, 2, 0x11A, heap);
        str = func_02045EC0(bank, arg + 3);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 2:
        str = func_02156914((int)(*((void **)func_02012F80(h))), heap);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        break;
    case 3:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 4:
        bank = func_02045B38(0, 2, 0x4B, heap);
        str = func_02045EC0(bank, arg + 4);
        func_0201EE0C(ws, slot, str, 0, 1, 2);
        func_02045808(str);
        func_02045C04(bank);
        break;
    case 5:
        func_02156A3C(*((void **)func_02012F80(h)), arg, ws, slot);
        break;
    case 6:
        func_02156AD4(*((void **)func_02012F80(h)), arg, ws, slot);
        break;
    case 7: {
        void *sv = func_02012F44(func_0215A5E4(vm));
        u16 ids[3];
        u8 idx[4];
        u8 val[4];
        u8 i;
        u8 j;

        for (i = 0; i < 4; i++) {
            idx[i] = i;
            val[i] = func_0200A7A0(sv, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 n = j + 1;

                if (val[j] < val[n]) {
                    u8 t = val[j];

                    val[j] = val[n];
                    val[n] = t;
                    t = idx[j];
                    idx[j] = idx[n];
                    idx[n] = t;
                }
            }
        }
        if (val[0] == val[1] && val[0] == val[2]) {
            ids[0] = 9;
            ids[1] = 8;
        } else {
            ids[0] = idx[0] + 4;
            if (val[1] == val[2])
                ids[1] = 8;
            else
                ids[1] = idx[1] + 4;
        }
        if (val[1] == val[3])
            ids[2] = idx[1] + 4;
        else if (val[2] == val[3])
            ids[2] = idx[2] + 4;
        else
            ids[2] = idx[3] + 4;
        bank = func_02045B38(0, 2, 0x4B, heap);
        for (i = 0; i < 3; i++) {
            str = func_02045EC0(bank, ids[i]);
            func_0201EE0C(ws, i, str, 0, 1, 2);
            func_02045808(str);
        }
        func_02045C04(bank);
        break;
    }
    }
    return 0;
}

int func_0215DADC(void *a,void *b)
{
 int i = func_02159B10(a,b);
 u8 *p = (u8 *)func_0200A750(func_02012F44(func_0215A5E4(b)), (u8)i);
 p[1] = 0;
 return 0;
}
