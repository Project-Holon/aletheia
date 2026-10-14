/*
 * function: WORLDTRADE_ADAPTER_DeletePrintStream
 * address: 0x02202940
 * packet: pkt_ov135_02202940
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 P22L9: array base reached through a static inline accessor p->e (the bare field, a local pointer and u32 arithmetic all kept the base in r1, DIFF16/13). The zero stored is the counter's initial copy (idiom a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero).
 *
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 */
typedef unsigned int u32;
struct Ent { u32 a; u32 b; u32 c; };
struct Obj { u32 w0; u32 w1; u32 w2; u32 w3; void *h; u32 n; struct Ent e[24]; };
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p) {
    int i;
    for (i = 0; i < 24; i++) {
        struct Ent *e = p->e + i;
        if (e->c != 0) e->c = 0;
    }
    if (p->h != 0) {
        PRINTSYS_PrintStreamDelete(p->h);
        p->h = 0;
        p->n = 0;
    }
}
