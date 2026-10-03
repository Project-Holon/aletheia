/*
 * function: func_021F1060
 * address:  0x021F1060
 * packet:   pkt_ov029_021F1060
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 2 needs the entry's col and row in named locals (col first) for the
 * row in r7 and col spilled to [sp,#8]; the stack Pair copy follows
 * a-two-word-const-table-copied-to-the-stack-is-a-pair-assignment.md.
 *
 * symbols:
 *   func_021F1060  0x021F1060  thumb  ov029
 *   func_021F0B00  0x021F0B00  thumb  ov029
 *   func_021F0A68  0x021F0A68  thumb  ov029
 *   func_021F0A38  0x021F0A38  thumb  ov029
 *   func_021F2B9C  0x021F2B9C  thumb  ov029
 *   func_021F0FB0  0x021F0FB0  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 *   func_021F1000  0x021F1000  thumb  ov029
 *   d_021F331C     0x021F331C  data  a4
 *   d_021F3410     0x021F3410  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int a, b; } Pair;
typedef struct { u8 key, row, col, v; } Ent;

extern const Pair d_021F331C;
extern const Ent d_021F3410[];
extern const u16 d_021F31D4[];
extern void func_021F0B00(void *q, void *p, u8 a, int b, int c, u16 d);
extern int func_021F0A68(void *p);
typedef unsigned int   u32;
extern void func_021F0A38(unsigned char *p);
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern void func_021F0FB0(void *p);
extern void func_021F1A44(void *p, int a);
extern int func_021F1000(void *p);

int func_021F1060(u8 *p)
{
    Pair t = d_021F331C;
    int i, j, n;
    unsigned int k;
    const Ent *e;
    int v;
    int col;
    int row;

    switch (p[0x455]) {
    case 0:
        for (i = 0; i < 9; i++) {
            n = ((int *)&t)[i % 2];
            for (j = 0; j < n; j++)
                func_021F0B00(p + 0x2D0 + i * 0x20 + j * 8, p, 4, 1, 4, 2);
        }
        p[0x455]++;
        break;
    case 1:
        if (func_021F0A68(p) == 0)
            p[0x455]++;
        break;
    case 2:
        for (k = 0; k < 0x1F; k++) {
            e = &d_021F3410[k];
            if (p[0x456] == d_021F3410[k].key) {
                col = e->col;
                row = e->row;
                v = func_021F2B9C(p, row, col);
                func_021F0B00(p + 0x2D0 + row * 0x20 + col * 8, p, d_021F31D4[v], 2, v, e->v);
            }
        }
        if (p[0x456] >= 4) {
            func_021F0FB0(p);
            func_021F1A44(p, 1);
            p[0x455]++;
        }
        p[0x456]++;
        break;
    case 3:
        if (func_021F0A68(p) == 0 && func_021F1000(p) == 0)
            return 1;
        break;
    }
    func_021F0A38(p);
    return 0;
}
