/*
 * function: func_021F3264
 * address:  0x021F3264
 * packet:   pkt_ov032_021F3264
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note:     the object array at +0x2BC must be a struct array member: raw
 *           (p + i * 4) arithmetic schedules p+i*4 ahead of &d[i] (2-byte DIFF).
 * symbols:
 *   func_021F3214 0x021F3214 thumb ov032
 *   func_0204B3DC 0x0204B3DC arm
 *   d_021F35F0 0x021F35F0 data ov032 a2
 */

typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    char pad[0x138];
    unsigned *a;        /* 0x138 */
    int pad2;
    unsigned *b;        /* 0x140 */
    int pad3;
    unsigned *c;        /* 0x148 */
    char pad4[0x2BC - 0x14C];
    void *o[6];         /* 0x2BC */
} S;

extern Pt d_021F35F0[];
extern void *func_021F3214(char *p, unsigned a, unsigned b, unsigned c, short x, short y, unsigned char w, unsigned char h, unsigned char z);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021F3264(S *p)
{
    int i;
    for (i = 0; i < 6; i++) {
        p->o[i] = func_021F3214((char *)p, *p->b, *p->a, *p->c, d_021F35F0[i].x, d_021F35F0[i].y, i * 3 + 1, 1, 1);
        func_0204B3DC(p->o[i], 1);
    }
}
