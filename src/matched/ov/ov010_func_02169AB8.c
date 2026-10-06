/*
 * function: func_02169AB8
 * address:  0x02169AB8
 * packet:   pkt_ov010_02169AB8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 21-state setup and teardown machine of the ov010 program. First
 * draft; the call at 0x021A153C reaches an ov021 Thumb thunk
 * (`ldr r0, [r0, #0x20]; ldr r3, =target; bx r3`), declared `thumb ov021`
 * (the ISA evidence honours the ovNNN hint since tooling_3).
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A1518  0x021A1518  thumb  ov021
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1554  0x021A1554  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A0FB4  0x021A0FB4  thumb  ov021
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02006254  0x02006254  thumb
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02169E0C  0x02169E0C  thumb  ov010
 *   func_02169E4C  0x02169E4C  thumb  ov010
 *   func_02169EA4  0x02169EA4  thumb  ov010
 *   func_02169EBC  0x02169EBC  thumb  ov010
 *   func_02169FB8  0x02169FB8  thumb  ov010
 *   func_02169FFC  0x02169FFC  thumb  ov010
 *   func_0216A07C  0x0216A07C  thumb  ov010
 *   func_0216A0BC  0x0216A0BC  thumb  ov010
 *   func_0216A148  0x0216A148  thumb  ov010
 *   func_0216A184  0x0216A184  thumb  ov010
 *   func_0216A1C0  0x0216A1C0  thumb  ov010
 *   func_0216A1F8  0x0216A1F8  thumb  ov010
 *   func_0216A21C  0x0216A21C  thumb  ov010
 *   func_0216A244  0x0216A244  thumb  ov010
 *   func_0216A264  0x0216A264  thumb  ov010
 *   func_0216A280  0x0216A280  thumb  ov010
 *   d_02172A50     0x02172A50  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u8 pad20[0x44 - 0x20];
    u8 *f44;            /* 0x44 */
    u8 pad48[0x4C - 0x48];
    u32 f4C;            /* 0x4C */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

extern int func_02169E0C(int a0);
extern void func_02169E4C(Work *w);
extern void func_02169EA4(Work *w, u32 n);
extern void func_02169EBC(Work *w);
extern int func_02169FB8(Work *w);
extern void func_02169FFC(Work *w, u32 n);
extern int func_0216A07C(Work *w);
extern void func_0216A0BC(Work *w);
extern void func_0216A148(Work *w);
extern int func_0216A184(int a0);
extern int func_0216A1C0(int a0);
extern void func_0216A1F8(int a0);
extern int func_0216A21C(int a0);
struct Ctx;
struct MsgBank;
struct Sub020071E4Ctrl;
struct Sub02008C20Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern int func_0216A244(void *a0);
extern void func_0216A264(Work *w);
extern int func_0216A280(int a0);

extern u32 func_02188CCC(u8 *p);
extern int func_021A0F30(u32 a, u32 b);
extern int func_021A0ED4(u32 a);
extern int func_021A1518(u32 *p);
extern void func_021A1524(u32 *p);
extern int func_021A1554(u32 *p);
extern void func_021A1530(u32 *p);
extern void func_021A1548(u32 *p);
extern int func_021A153C(u32 *p);
extern void func_021A0FB4(u32 *p, u32 a);

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);
extern u32 func_0201C440(void *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern void func_0201F7A8(void *p, u32 kind);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_020061E4(u32 a);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern int func_02006254(u32 a);
extern u32 func_020362DC(void);

extern const char d_02172A50[];

int func_02169AB8(Work *w, u32 *state)
{
    void *ws;
    void *str;

    switch (*state) {
    case 0:
        func_021A0F30(func_02188CCC(w->f08), 7);
        *state = 1;
        break;
    case 1:
        if (func_021A0ED4(func_02188CCC(w->f08)) == 1
            && func_021A1518((u32 *)func_02188CCC(w->f08)) == 1) {
            w->f18 = func_02030734(w->f10, 0x50, 0, d_02172A50, 0x9F);
            w->f18->f04 = func_02045B38(0, 3, 0x9E, w->f10);
            w->f18->f18 = func_020457B0(0x200, w->f10);
            w->f18->f00 = func_0203101C(w->f10, w->f10, 1, 4);
            w->f18->f1C = func_02028590(0xF, 1, 1, w->f10);
            w->f18->f14 = func_0201C440((void *)w->f10);
            w->f18->f4C = 0;
            func_02169E4C(w);
            func_0216A0BC(w);
            *state = 2;
        }
        break;
    case 2:
        func_02169EA4(w, 2);
        *state = 3;
        break;
    case 3:
        if (func_02169FB8(w) == 0) {
            func_0216A148(w);
            *state = 4;
        }
        break;
    case 4:
        switch (func_0216A184((int)w)) {
        case 0:
            if (func_020071F0(w->f00) == 1) {
                func_02169EA4(w, 8);
                *state = 0xE;
            } else {
                func_0201F7A8(w->f18->f08, 1);
                *state = 5;
            }
            break;
        case 1:
            *state = 0x11;
            break;
        }
        break;
    case 5:
        func_02008DF0(func_02012F2C(func_020120F4(w->f04)), 1);
        func_021A1524((u32 *)func_02188CCC(w->f08));
        if (func_021A1554((u32 *)func_02188CCC(w->f08)) == 1)
            func_02169FFC(w, 10);
        else
            func_02169FFC(w, 4);
        *state = 6;
        break;
    case 6:
        if (func_0216A07C(w) == 1) {
            func_0216A1C0((int)w);
            *state = 7;
        }
        break;
    case 7:
        if (func_0216A21C((int)w) == 1)
            *state = 8;
        break;
    case 8:
        if (func_0216A244(w) != 0) {
            w->f18->f44 = func_0202EE30(func_020056BC(), w->f18->f08, 0xF, 0x10, w->f10);
            func_021A1530((u32 *)func_02188CCC(w->f08));
            func_0216A264(w);
            func_02012DAC((int)func_020120F4(w->f04));
            *state = 9;
        }
        break;
    case 9:
        switch (func_02012DD0(func_020120F4(w->f04))) {
        case 0:
        case 1:
            break;
        case 2:
            *state = 10;
            break;
        case 3:
            func_021A1548((u32 *)func_02188CCC(w->f08));
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            func_02169EA4(w, 7);
            func_0202F038(w->f18->f44);
            *state = 0xD;
            break;
        }
        break;
    case 10:
        if (func_021A153C((u32 *)func_02188CCC(w->f08)) == 1) {
            func_020061E4(0x558);
            func_0216A280((int)w);
            func_0216A1F8((int)w);
            ws = func_0201EC64(w->f10);
            str = func_02045EC0(w->f18->f04, 5);
            func_0201F02C(ws, 0, func_02012944(func_020120F4(w->f04)));
            func_0201F250(ws, w->f18->f18, str);
            func_02045808(str);
            func_0201ED04(ws);
            func_02169EBC(w);
            func_0202F038(w->f18->f44);
            *state = 0xB;
        }
        break;
    case 11:
        if (func_0216A21C((int)w) == 1 && func_0216A244(w) != 0 && func_02169FB8(w) == 0)
            *state = 0xC;
        break;
    case 12:
        if (func_02006254(0x558) == 0)
            *state = 0x10;
        break;
    case 13:
        if (func_0216A21C((int)w) != 1 || func_0216A244(w) == 0)
            break;
        *state = 0xE;
    case 14:
        if (func_02169FB8(w) == 0)
            *state = 0xF;
        break;
    case 15:
        if (func_020362DC() & 3)
            *state = 0x13;
        break;
    case 16:
        if (func_020362DC() & 3)
            *state = 0x13;
        if (w->f18->f4C >= 150)
            *state = 0x13;
        else
            w->f18->f4C++;
        break;
    case 17:
        func_02169E0C((int)w);
        func_021A0F30(func_02188CCC(w->f08), 1);
        *state = 0x12;
        break;
    case 18:
        return 1;
    case 19:
        func_02169E0C((int)w);
        func_021A0F30(func_02188CCC(w->f08), 0);
        *state = 0x14;
        break;
    case 20:
        func_021A0FB4((u32 *)func_02188CCC(w->f08), w->f10);
        return 0;
    }
    return 2;
}
