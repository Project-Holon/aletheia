/*
 * function: func_021F2F60
 * address:  0x021F2F60
 * packet:   pkt_ov029_021F2F60
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * 2026-10-04 (wD2 lane 09): bytes are identical; only ABS32 +0124 (func_02154668) is open.
 * 02154668 is a Thumb veneer (ldr r3,[pc]; bx r3) and 3 overlays overlap it (ov000, ov001, ov006).
 * Tried ov000 and ov010 on the symbols line: still no outside witness.
 *
 * Byte-correct; two sites stay wildcarded:
 *   +0130 ABS32 abs_id_124 (0x7C): a pooled overlay id (ov124, whose
 *     0x021D4D40 table is the next argument) passed as func_02014808's
 *     third argument; func_02014808 is not in OVERLAY_ID_CONSUMERS and no
 *     other pool word holds 0x7C, so no evidence class resolves it.
 *   +0124 ABS32 func_02154668 (ov000): an unlabelled tail-call stub
 *     (`ldr r3,[pc,#0]; bx r3` -> func_02154670, 00 4b 18 47 at 0x02154668
 *     in ov000.s).  Not filed, since it is not the only blocker: C
 *     `void *func_02154668(void *p) { return func_02154670(p); }`.
 *   abs_id_0 resolves through the func_020124AC overlay-id consumer.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021F009C  0x021F009C  thumb  ov029
 *   func_021F2C78  0x021F2C78  thumb  ov029
 *   func_021F2C10  0x021F2C10  thumb  ov029
 *   func_020124AC  0x020124AC  thumb
 *   func_02154668  0x02154668  thumb  ov000
 *   abs_id_0       0x00000000  data
 *   func_021559E4  0x021559E4  thumb  ov010
 *   func_0215FBF4  0x0215FBF4  thumb  ov010
 *   func_02167044  0x02167044  thumb  ov010
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02014808  0x02014808  thumb
 *   abs_id_124     0x0000007C  data
 *   d_021D4D40     0x021D4D40  data  ov124  a4
 *   func_021D297C  0x021D297C  thumb  ov021
 *   func_0201235C  0x0201235C  thumb
 *   d_021F3554     0x021F3554  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    char *p;
    int kind;
} Req;

extern u8 abs_id_0[];
extern u8 abs_id_124[];
extern int d_021D4D40;
extern int d_021F3554;

extern int func_0201210C(int a);
extern int func_021F009C(char *p);
extern int func_021F2C78(char *p);
extern int func_021F2C10(char *p);
extern void *func_020124AC(int a, const void *id, void *fn, int b);
extern void *func_02154668(void *p);
extern void *func_021559E4(int a, int b, int c, int d);
extern void *func_0215FBF4(int a, int b, int c, int d);
extern void *func_02167044(int a, int b);
extern void *func_021945A4(int a, int b, int c);
extern void *func_02030734(u32 heap, u32 size, u32 flag, void *file, u32 line);
extern int func_020120F4(int a);
extern int func_02012944(int a);
extern void *func_02014808(int a0, int a1, const void *a2, void *a3, void *a4, int a5, void *a6);
extern void *func_021D297C(int a);
extern void func_0201235C(void *a, void *b);

int func_021F2F60(void *a, int unused, Req *q)
{
    char *p;
    int h;
    int ok;
    void *x;
    int *buf;

    p = q->p;
    ok = 0;
    h = func_0201210C(*(int *)(p + 0x1c));
    switch (q->kind) {
    case 1:
    case 5:
    case 6:
        ok = func_021F009C(q->p);
        break;
    case 7:
    case 11:
        ok = func_021F2C78(q->p);
        break;
    case 12:
    case 13:
        ok = func_021F2C10(q->p);
        break;
    }
    if (ok == 0)
        return 0;

    switch (q->kind) {
    case 6:
        x = func_020124AC(*(int *)(p + 0x1c), abs_id_0, (void *)func_02154668, h);
        break;
    case 1:
        x = func_021559E4(*(int *)(p + 0x1c), h, 0, 1);
        break;
    case 5:
        x = func_0215FBF4(*(int *)(p + 0x1c), h, 0, 1);
        break;
    case 11:
        x = func_02167044(*(int *)(p + 0x1c), h);
        break;
    case 7:
        x = func_021945A4(*(int *)(p + 0x1c), h, 4);
        break;
    case 12:
        buf = func_02030734(4, 8, 1, &d_021F3554, 0x14B7);
        buf[0] = func_02012944(func_020120F4(*(int *)(p + 0x1c)));
        buf[1] = *(int *)(p + 0x1c);
        x = func_02014808(*(int *)(p + 0x1c), h, abs_id_124, &d_021D4D40, buf, 0, buf);
        break;
    case 13:
        x = func_021D297C(*(int *)(p + 0x1c));
        break;
    }
    func_0201235C(a, x);
    return 0;
}
