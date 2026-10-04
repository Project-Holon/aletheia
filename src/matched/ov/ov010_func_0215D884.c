/*
 * function: func_0215D884
 * address:  0x0215D884
 * packet:   pkt_ov010_0215D884
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into
 * the slot (player name, message-bank entries, link member names, or the
 * three placement labels of a four-way ranking).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02156914  0x02156914  thumb  ov010
 *   func_02156A3C  0x02156A3C  thumb  ov010
 *   func_02156AD4  0x02156AD4  thumb  ov010
 *   func_02012F44  0x02012F44  thumb
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5E4(void *vm);
struct Big;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Work;
extern u16 func_0215A5CC(void *a0);
extern void *func_02158F74(void *p);
extern u16 func_02159B10(Ctx *c, void *vm);
extern void *func_02156914(void *w, u32 heap);
extern void func_02156A3C(struct Work *w, u8 j, void *ws, u32 slot);
extern void func_02156AD4(struct Work *w, u8 j, void *ws, u32 slot);
extern void *func_02012F44(void *h);
extern void **func_02012F80(void *h);
extern u8 func_0200A7A0(struct Big *p, u32 index);
extern u8 *func_0200A7F8(struct Big *p);
extern void func_0201EE0C(void *win, u32 slot, void *str, u32 a, u32 b, u32 c);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);

int func_0215D884(Ctx *c, void *vm)
{
    void *wsx = func_0215A5F4(vm);
    void *h = func_0215A5E4(vm);
    u32 heap = func_0215A5CC(vm);
    void *ws = func_02158F74(wsx);
    u8 op;
    u8 slot;
    u16 arg;
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
        str = func_02156914(*func_02012F80(h), heap);
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
        func_02156A3C(*func_02012F80(h), arg, ws, slot);
        break;
    case 6:
        func_02156AD4(*func_02012F80(h), arg, ws, slot);
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
