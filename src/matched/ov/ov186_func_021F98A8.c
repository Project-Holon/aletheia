/*
 * function: func_021F98A8
 * address: 0x021F98A8
 * packet: pkt_ov186_021F98A8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov186/br_proc_sys.c and filed here.
 */

typedef struct { int w0, w4, w8, wc, w10, w14, w18; } A_021F98A8;
typedef struct { int w0, w4, w8, wc, w10, w14; struct { int pad[3]; struct { int pad; int v; } *q; } *w18; } B_021F98A8;
void func_021F98A8(A_021F98A8 *a, B_021F98A8 *b);

void func_021F98A8(A_021F98A8 *a, B_021F98A8 *b) { a->wc = b->w4; a->w0 = b->wc; a->w10 = b->w8; a->w8 = b->w0; a->w14 = b->w14; a->w4 = b->w10; a->w18 = b->w18->q->v; }
