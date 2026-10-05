/*
 * function: func_0215F734
 * address:  0x0215F734
 * packet:   pkt_ov010_0215F734
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Step machine of an ov010 sub-sequence: the step comes from w->seq[*i]
 * through func_0215F9DC, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of func_02012444, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * func_0215FA54.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02012158  0x02012158  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_0215F9C4  0x0215F9C4  thumb  ov010
 *   func_0215F9DC  0x0215F9DC  thumb  ov010
 *   func_0215F9EC  0x0215F9EC  thumb  ov010
 *   func_02158A20  0x02158A20  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    void *sys;          /* 0x00 */
    void *f04;          /* 0x04 */
    u32 f08;            /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u8 f14[8];          /* 0x14 */
    u8 f1c[0x28 - 0x1C];/* 0x1C */
    u8 f28[8];          /* 0x28 */
    u8 f30[4];          /* 0x30 */
    u32 step;           /* 0x34 */
    u32 seq[16];        /* 0x38 */
    int timer;          /* 0x78 */
} Work;

extern void *func_02012EBC(void *p);
extern void *func_0201210C(void *sys);
extern void *func_02012138(void *sys);
extern void func_02012374(void *evt, void *task);
extern void func_020120B4(void *sys, u32 id, void *data, void *arg);
extern int func_020120F0(void *sys);
extern void func_02012444(void *evt, u32 id, void *data, void *arg);
extern void func_02012158(void *sys, u32 v);
extern void *func_02014554(void *sys, void *proc);
extern void func_02005E30(u32 v);
extern void func_02026400(void *p);
extern int func_02026454(void *p);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern u32 func_0215F9C4(void);
extern void func_0215F9DC(Work *w, u32 *i);
extern void func_0215F9EC(Work *w);
extern void func_02158A20(void *sys, u32 v);
extern void *func_02161B90(void *sys, void *evt, u32 a, u32 b, u32 c);
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];

int func_0215F734(void *evt, u32 *i, Work *w)
{
    void *sys = w->sys;
    void *save;
    void *proc;

    func_02012EBC(w->f04);
    proc = func_0201210C(w->sys);
    save = func_02012138(w->sys);
    switch (w->step) {
    case 0:
        if (w->f08 == 1)
            func_0215F9EC(w);
        func_02005E30(30);
        func_0215F9DC(w, i);
        break;
    case 1:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        func_0215F9DC(w, i);
        break;
    case 2:
        if (func_02026454(save))
            func_02026400(save);
        func_0215F9DC(w, i);
        break;
    case 3:
        if (func_02026454(save) == 0)
            func_0215F9DC(w, i);
        break;
    case 4:
        func_02012374(evt, func_02014554(sys, proc));
        func_0215F9DC(w, i);
        break;
    case 5:
        func_020120B4(sys, (u32)ov180_id, d_021B800C, w->f1c);
        func_0215F9DC(w, i);
        break;
    case 6:
        if (func_020120F0(sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 7:
        func_020120B4(sys, (u32)ov181_id, d_021BAB24, w->f28);
        func_0215F9DC(w, i);
        break;
    case 8:
        if (func_020120F0(sys) == 0)
            func_0215F9DC(w, i);
        break;
    case 9:
        func_02012374(evt, func_02161B90(sys, evt, func_0215F9C4(), 0, 0));
        func_0215F9DC(w, i);
        break;
    case 10:
        func_02158A20(sys, 4);
        func_0215F9DC(w, i);
        break;
    case 11:
        func_02012444(evt, (u32)ov205_id, d_021B9E54, w->f14);
        func_0215F9DC(w, i);
        break;
    case 12:
        if (w->timer > 60) {
            w->timer = 0;
            func_0215F9DC(w, i);
        }
        w->timer++;
        break;
    case 13:
        func_02012444(evt, (u32)ov182_id, d_021B9BA0, w->f30);
        func_02012158(sys, 0);
        func_0215F9DC(w, i);
        break;
    case 14:
        return 1;
    case 15:
        return 0;
    }
    return 0;
}
