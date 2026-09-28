/*
 * function: func_0216EB98
 * address:  0x0216EB98
 * packet:   pkt_ov010_0216EB98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Proc main of the ov010 result screen: a 12-state sequence that pushes the
 * child tasks, loads overlays 93/92/230 for the sub-screens, and folds three
 * code-range checksums (ov021 helpers over 0x0216E680..) into a running sum
 * whose residue mod 0x1933 arms a trap callback.
 *
 * DIFF, 4 bytes short: every instruction is right except the register of
 * the func_0201210C result. The image copies it to r2 and loads the state
 * into r1 (then `adds r1, r2, #0` in states 2 and 10); this C coalesces it
 * with r1 and loads the state into r0. Declaration order of sys/p04/proc/
 * sum, proc as u32, the state through a u32 local or an int pointer, and
 * the state-10 call through a local are flat; permuter seed 8701, budget
 * 400, no gain. See docs/notes/pkt_ov010_0216EB98.c.txt.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029B28  0x02029B28  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_0202E79C  0x0202E79C  thumb
 *   func_0202E80C  0x0202E80C  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02011D34  0x02011D34  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_02168D30  0x02168D30  thumb  ov010
 *   func_0216EFDC  0x0216EFDC  thumb  ov010
 *   func_0216EFF0  0x0216EFF0  thumb  ov010
 *   func_0216F054  0x0216F054  thumb  ov010
 *   func_0216E680  0x0216E680  thumb  ov010
 *   func_0216F064  0x0216F064  thumb  ov010
 *   func_0216F070  0x0216F070  thumb  ov010
 *   func_0216F07C  0x0216F07C  thumb  ov010
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021882DC  0x021882DC  arm  ov021
 *   func_02188354  0x02188354  arm  ov021
 *   func_02188390  0x02188390  arm  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov093_id       0x0000005D  data
 *   ov092_id       0x0000005C  data
 *   ov230_id       0x000000E6  data
 *   d_021EFDAC     0x021EFDAC  data
 *   d_021B9D94     0x021B9D94  data
 *   g_0214624C     0x0214624C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Info {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Info;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    Info *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Info *f10;          /* 0x10 */
    u32 f14;            /* 0x14 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
    u8 pad20[4];
    void *f24;          /* 0x24 */
} Work;

extern u8 ov093_id[];
extern u8 ov092_id[];
extern u8 ov230_id[];
extern u8 d_021EFDAC[];
extern u8 d_021B9D94[];
extern u32 g_0214624C;

extern void *func_0201210C(void *sys);
extern void func_02012374(void *evt, void *task);
extern void func_0201235C(void *evt, void *task);
extern void func_02012444(void *evt, u32 id, void *data, void *arg);
extern void *func_02012B38(void *p);
extern void *func_02012F20(void *p);
extern void **func_02012F50(void *p);
extern void func_0201447C(void *p, u32 on);
extern void *func_020144DC(void *sys, void *proc);
extern void *func_020145CC(void *sys);
extern void *func_02029B28(void *sys, u32 n);
extern void *func_02029BCC(void *sys, u16 v);
extern void *func_02029C00(void *sys);
extern void *func_02029CC0(void *sys);
extern void func_0202E79C(void *p);
extern void func_0202E80C(void *p);
extern void func_02034AC4(u32 id);
extern void func_02034A5C(u32 id);
extern void func_020056A0(void (*fn)(void), void *arg, u32 pri);
extern void func_02011D34(void);
extern void *func_0215F6E8(void *sys);
extern void func_02168D30(void *p, Info *info);
extern int func_0216EFDC(Work *w);
extern void func_0216EFF0(Work *w, void *p);
extern void func_0216F054(Work *w);
extern void func_0216E680(void);
extern void func_0216F064(void);
extern void func_0216F070(void);
extern void func_0216F07C(void);
extern void *func_02189A08(void);
extern u32 func_021882DC(void (*start)(void), void (*end)(void), u32 seed);
extern u32 func_02188354(void (*start)(void), void (*end)(void), u32 seed);
extern u32 func_02188390(void (*start)(void), void (*end)(void), u32 seed);
extern void func_021CF498(void *p, void *evt, void *arg);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);

int func_0216EB98(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *p04 = w->f04;
    void *proc = func_0201210C(sys);
    u32 sum = 0x013A1AB5;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(sys, w->f08->f18));
        (*state)++;
        break;
    case 1:
        func_021CF498(func_02189A08(), evt, w->f24);
        (*state)++;
        break;
    case 2:
        func_02012374(evt, func_020144DC(sys, proc));
        (*state)++;
        break;
    case 3:
        func_0201447C(func_02012B38(p04), 1);
        func_0202E79C(func_02012F20(p04));
        func_02012444(evt, (u32)ov093_id, d_021EFDAC, w->f08);
        (*state)++;
        break;
    case 4:
        w->f10 = w->f08;
        w->f0c = p04;
        func_02012444(evt, (u32)ov092_id, d_021B9D94, &w->f0c);
        (*state)++;
        break;
    case 5:
        func_02034AC4((u32)ov230_id);
        func_0201447C(func_02012B38(p04), 0);
        func_0202E80C(func_02012F20(p04));
        (*state)++;
        break;
    case 6: {
        int ok = 0;

        if (func_021882DC(func_0216E680, func_0216F064, 0) == ~(u32)func_0216F064)
            ok = 1;
        sum += ok ? 0 : 0x3D1;
        func_0216EFF0(w, p04);
        if (w->f1c != 0)
            func_02168D30(*func_02012F50(p04), w->f08);
        (*state)++;
        ok = 0;
        if (func_02188354(func_0216E680, func_0216F070, 0) == ~(u32)func_0216F070)
            ok = 1;
        sum += ok ? 0 : 0x5D1;
        break;
    }
    case 7: {
        int ok = 0;

        if (func_02188390(func_0216E680, func_0216F07C, 0) == ~(u32)func_0216F07C)
            ok = 1;
        sum += ok * 0x9D;
        if (w->f18 == 0 && func_0216EFDC(w) == 1)
            func_02012374(evt, func_02029B28(sys, 0x1E));
        else
            func_02012374(evt, func_02029C00(sys));
        func_02034A5C((u32)ov230_id);
        (*state)++;
        break;
    }
    case 8:
        if (w->f18 == 0 && func_0216EFDC(w) == 1) {
            if (w->f14 == 1) {
                func_0216F054(w);
                return 1;
            }
            func_0216F054(w);
            func_0201235C(evt, func_0215F6E8(sys));
            return 0;
        }
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 9:
        func_02012374(evt, func_02029CC0(sys));
        (*state)++;
        break;
    case 10:
        if (w->f14 == 0)
            func_02012374(evt, func_021BE92C(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 11:
        func_0216F054(w);
        return 1;
    }
    if (sum % 0x1933 != 0) {
        func_020056A0(func_02011D34, 0, 0x7F);
        g_0214624C++;
    }
    return 0;
}
