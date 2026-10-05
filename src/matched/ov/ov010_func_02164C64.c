/*
 * function: func_02164C64
 * address:  0x02164C64
 * packet:   pkt_ov010_02164C64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll of the wireless exchange while the field runs: stops the
 * field when a shutdown is pending, pulls the next received record
 * (func_02164D6C) and, for a new kind-2 record on an open lid with a free
 * field, starts the func_02164FD0 event with a 12-byte hand-off; any
 * other kind-2 record is dropped and its sender answered.
 *
 * MATCH (2026-09-28 tree_ov010_4): bytes exact with the kind-2 path as
 * nested ifs and a goto past the drop (the && chain puts the last-id
 * compare as `cmp r1, r0`). The one wildcard is the bl to ov011
 * 0x02177BF4, which has no label.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_020267FC  0x020267FC  thumb
 *   func_02164D6C  0x02164D6C  thumb  ov010
 *   func_020264AC  0x020264AC  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02158570  0x02158570  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0202640C  0x0202640C  thumb
 *   func_02164FD0  0x02164FD0  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02177BF4  0x02177BF4  thumb  ov014
 *   func_02010498  0x02010498  thumb
 *   d_021729BC     0x021729BC  data  a1
 
 * 2026-10-05 (D8 lane 15): the ov011 hint on func_02177BF4 was wrong; the label is in ov014, so the symbols line now says ov014 and every relocation resolves.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile u16 vu16;

typedef struct LinkRec {
    u8 kind;            /* 0x00 */
    u8 f01;
    u8 f02;
    u8 data[6];         /* 0x03 */
} LinkRec;

typedef struct PollWork {
    u8 pad00[0xA];
    u16 last;           /* 0x0A */
    u32 cooldown;       /* 0x0C */
    u8 pad10[0x64];
    LinkRec rec;        /* 0x74 */
} PollWork;

typedef struct Handoff12 {
    void *sys;          /* 0x00 */
    u8 data[6];         /* 0x04 */
    u8 pad[2];
} Handoff12;

extern void *func_02012138(void *sys);
extern void *func_020120F4(void *sys);
extern int func_02012E40(void *p);
extern int func_0200FB24(void);
extern void func_02026400(void *field);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void func_020267FC(void);
extern LinkRec *func_02164D6C(PollWork *w, u32 *id);
extern int func_020264AC(void *field);
extern int func_02012B70(void *p);
extern void *func_020127A4(void *p);
extern u16 func_02012AC8(void *p);
extern int func_02158570(u16 v);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0202640C(void *field, void (*fn)(void *), void *arg);
extern void func_02164FD0(void *arg);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02177BF4(u32 id);
extern void func_02010498(void);
extern const char d_021729BC[];

static inline int PAD_DetectFold(void)
{
    return (*(vu16 *)0x02FFFFA8 & 0x8000) >> 15;
}

void func_02164C64(void *unused, void *sys, PollWork *w)
{
    void *field;
    void *p;
    u32 id;
    LinkRec *rec;
    Handoff12 *h;
    u16 v;

    field = func_02012138(sys);
    p = func_020120F4(sys);
    id = 0;
    if (func_02012E40(p) == 1)
        return;
    if (func_0200FB24()) {
        func_02026400(field);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1) {
        func_02026400(field);
        return;
    }
    if (w->cooldown != 0)
        w->cooldown--;
    func_020267FC();
    rec = func_02164D6C(w, &id);
    if (rec != 0) {
        if (rec->kind == 2) {
            if (!PAD_DetectFold() && !func_020264AC(field) && !func_02012B70(p)) {
                v = func_02012AC8(func_020127A4(p));
                if (v != w->last) {
                    w->last = v;
                    if (func_02158570(v) == 1) {
                        h = func_02030734(0x8005, sizeof(Handoff12), 1, d_021729BC, 0x154);
                        h->sys = sys;
                        MI_CpuCopy8(rec->data, h->data, 6);
                        func_0202640C(field, func_02164FD0, h);
                        goto end;
                    }
                }
            }
            MI_CpuFill8(&w->rec, 0, sizeof(LinkRec));
            func_02177BF4(id);
        } else {
            rec->kind = 0;
        }
    }
end:
    func_02010498();
}
