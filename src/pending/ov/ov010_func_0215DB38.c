/*
 * function: func_0215DB38
 * address:  0x0215DB38
 * packet:   pkt_ov010_0215DB38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result slot, then opens or closes the link work (0, 1), starts the
 * ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the slot (19..21).
 *
 * Byte-correct (first draft plus ov100_id for the pooled 0x64). Evidence
 * gaps, not C: 0x021FDA6C (ov132) has no func_ label; ov100_id is passed to
 * func_02014808 (r2), which is not in the overlay_id consumer list;
 * d_021BB6A4 is another overlay's proc data (same gap as func_02155478).
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 *
 * 2026-10-05 (wave D8): Only d_021BB6A4 (ov100 process data) is unresolved; not fixable in C. Source unchanged.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_0215DDC8  0x0215DDC8  thumb  ov010
 *   func_0215DE0C  0x0215DE0C  thumb  ov010
 *   func_0215DE38  0x0215DE38  thumb  ov010
 *   func_0215DE44  0x0215DE44  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215DF78  0x0215DF78  thumb  ov010
 *   func_0215DFB4  0x0215DFB4  thumb  ov010
 *   func_0215E010  0x0215E010  thumb  ov010
 *   func_0215E068  0x0215E068  thumb  ov010
 *   func_0215E0B0  0x0215E0B0  thumb  ov010
 *   func_0215E0EC  0x0215E0EC  thumb  ov010
 *   func_0215E130  0x0215E130  thumb  ov010
 *   func_0215E184  0x0215E184  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02014808  0x02014808  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02030734  0x02030734  arm
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021FCDEC  0x021FCDEC  thumb  ov132
 *   func_021FDA6C  0x021FDA6C  thumb  ov132
 *   d_02172914     0x02172914  data  a1
 *   d_021BB6A4     0x021BB6A4  data
 *   ov100_id       0x00000064  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Link {
    void *f00;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
    u16 *f30;           /* 0x30 */
    u16 f34;            /* 0x34 */
} Link;

typedef struct Wait {
    void *vm;
    Link *link;
} Wait;

extern const char d_02172914[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern void func_02156BAC(void *p);
extern u32 func_02156BCC(void *p);
extern void func_0215DDC8(void *evt, void *h);
extern void func_0215DE0C(Link *l, void *h);
extern void func_0215DE38(Link *l, void *proc, void *a, u16 arg);
extern void func_0215DE44(Link *l);
extern void func_0215897C(void *evt, void *task);
extern int func_0215DF78();
extern int func_0215DFB4();
extern int func_0215E010();
extern int func_0215E068();
extern int func_0215E0B0();
extern int func_0215E0EC();
extern int func_0215E130();
extern int func_0215E184();
extern void *func_0201210C(void *proc);
extern void func_02012124(void *proc, u32 v);
extern void *func_02012138(void *proc);
extern void *func_02012944(void *h);
extern Link *func_02012F80(void *h);
extern void func_020113D0(void *c, int (*fn)());
extern void *func_02014808(void *proc, void *sys, u32 a, void *data, void *out, int (*fn)(), void *arg);
extern int func_0200FB24(void);
extern Wait *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_021CD48C(void *a, void *sys, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021FCDEC(void *sess, u8 v);
extern u32 func_021FDA6C(void *h);

int func_0215DB38(void *c, void *vm)
{
    void *evt;
    void *proc;
    void *h;
    void *sys;
    u16 cmd;
    u16 arg;
    u16 *dst;
    int busy;
    Link *l;

    evt = func_0215A5F4(vm);
    proc = func_0215A5DC(vm);
    h = func_0215A5E4(vm);
    sys = func_0201210C(proc);
    cmd = func_02159B10(c, vm);
    arg = func_02159B10(c, vm);
    func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    busy = 0;
    l = 0;
    if (cmd != 0 && cmd != 0x15) {
        l = func_02012F80(h);
        if (l->f00 != 0) {
            func_02156BAC(l->f00);
            if (func_02156BCC(l->f00) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        func_0215DDC8(evt, h);
        break;
    case 1:
        func_0215DE0C(l, h);
        break;
    case 10:
        func_0215DE38(l, proc, func_02012138(proc), arg);
        break;
    case 11:
        func_0215DE44(l);
        func_020113D0(c, func_0215E130);
        return 1;
    case 12:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 0, 1, 0);
        func_020113D0(c, func_0215DFB4);
        return 1;
    case 13:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 1, 1, 0);
        func_020113D0(c, func_0215E010);
        return 1;
    case 14:
        if (l->sess == 0 || busy != 0)
            break;
        l->f34 = arg;
        func_021FCDEC(l->sess, l->f34);
        func_020113D0(c, func_0215E068);
        return 1;
    case 15:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, func_0215E0B0);
        return 1;
    case 16:
        func_020113D0(c, func_0215E0EC);
        return 1;
    case 17:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, func_0215E184);
        return 1;
    case 18: {
        Wait *w = func_02030734(0x8004, 8, 1, d_02172914, 0x3C8);

        w->vm = vm;
        w->link = l;
        l->f30 = dst;
        l->f0c = h;
        l->f2c = func_021FDA6C(h);
        l->f28 = arg == 0 ? 9 : 10;
        func_0215897C(evt, func_02014808(proc, sys, (u32)ov100_id, d_021BB6A4, &l->f0c, func_0215DF78, w));
        return 1;
    }
    case 19:
        if (l->sess != 0 && busy == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 20:
        if (l->sess != 0)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 21:
        if (func_0200FB24() != 0) {
            func_02012124(proc, 1);
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}
