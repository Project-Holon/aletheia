/*
 * function: func_02164A2C
 * address:  0x02164A2C
 * packet:   pkt_ov010_02164A2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sub-process sequence of the ov010 program: eight steps, each starting
 * one child process (two from ov021, the ov216 one through
 * func_020120B4 with a 12-byte hand-off), then done. Step 2 falls
 * through into step 3.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is the
 * pooled 0x021BDB40, the ov216 process template, which has no other
 * reference in the image (ov216_id itself resolves by the overlay_id
 * class).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020297AC  0x020297AC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02029690  0x02029690  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02029CC0  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 
 * 2026-10-05 (D8 lane 15): the process template d_021BDB40 lives in ov216; the data line now carries the ov216 token and the relocation resolves.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SubArgs {
    void *sys;          /* 0x0C */
    u32 f04;            /* 0x10 */
    u8 f08;             /* 0x14 */
    u8 flag;            /* 0x15 */
    u8 pad[2];
} SubArgs;

typedef struct SeqWork2 {
    void *sys;          /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    SubArgs sub;        /* 0x0C */
    u8 f18;             /* 0x18 */
} SeqWork2;

extern void *func_020120F4(void *sys);
extern void *func_0201210C(void *sys);
extern void *func_021BE8D4(void *sys, void *p, u32 a, u32 b);
extern void func_02012374(void *evt, void *proc);
extern void *func_020144DC(void *sys, void *p);
extern void *func_020297AC(void *sys, u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_020120B4(void *sys, u32 ovId, const void *proc, void *arg);
extern int func_020120F0(void *sys);
extern void *func_02029690(void *sys, u32 a, u32 b);
extern void *func_020145CC(void *sys);
extern void *func_02188CCC(void *p);
extern void func_021A0F40(void *p, u32 v);
extern void *func_021BE92C(void *sys, void *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_02029CC0(void *sys);
extern u8 ov216_id[];
extern const u8 d_021BDB40[];

int func_02164A2C(void *evt, u32 *seq, SeqWork2 *w)
{
    void *sys;
    void *p;

    sys = w->sys;
    func_020120F4(sys);
    p = func_0201210C(sys);
    switch (*seq) {
    case 0:
        func_02012374(evt, func_021BE8D4(sys, p, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, func_020144DC(sys, p));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_020297AC(sys, 0x483, 6, 0));
        (*seq)++;
    case 3:
        MI_CpuFill8(&w->sub, 0, sizeof(SubArgs));
        w->sub.sys = w->sys;
        w->sub.f04 = w->f04;
        w->sub.f08 = w->f18;
        func_020120B4(sys, (u32)ov216_id, d_021BDB40, &w->sub);
        (*seq)++;
        break;
    case 4:
        if (func_020120F0(sys) == 0) {
            func_02012374(evt, func_02029690(sys, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        func_02012374(evt, func_020145CC(sys));
        (*seq)++;
        break;
    case 6:
        if (w->sub.flag != 0)
            func_021A0F40(func_02188CCC(p), 0);
        func_02012374(evt, func_021BE92C(sys, p, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        func_02012374(evt, func_02029CC0(sys));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
