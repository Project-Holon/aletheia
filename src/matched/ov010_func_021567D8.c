/*
 * function: func_021567D8
 * address:  0x021567D8
 * packet:   pkt_ov010_021567D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   d_0216FEFC  0x0216FEFC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Seq {
    void *f00;          /* 0x00 */
    u8 pad04[0x10 - 0x04];
    u8 state;           /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    u8 pad18[0x4C - 0x18];
    u8 f4C;             /* 0x4C */
} Seq;

extern void *func_020120F4(void *p);
extern u32 func_02012A30(void *p);
extern void *func_0201210C(void *p);
extern void *func_02012374(void *evt, void *sub);
typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;

extern void *func_021854B0(void *p, void *q, u32 id, Pos *pos, u32 flag);
extern const Pos d_0216FEFC;

void func_021567D8(void *evt, Seq *s)
{
    void *x;
    Pos pos;

    x = func_0201210C(s->f00);
    pos = d_0216FEFC;
    pos.x += s->f4C << 17;
    func_02012374(evt, func_021854B0(s->f00, x, 0x4E, &pos, 0));
}
