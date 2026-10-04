/*
 * function: func_021BA8C0
 * address:  0x021BA8C0
 * packet:   pkt_ov070_021BA8C0
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 *
 * symbols:
 *   d_021BBA74     0x021BBA74  data  a1
 *   d_021BBBCC     0x021BBBCC  data  a2
 *   d_021BBA81     0x021BBA81  data  a1
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef struct {
    short x, y;
    unsigned short z;
    unsigned char d, e;
} Rect;

typedef struct {
    unsigned char pad0[0x544];
    unsigned short heap;
    unsigned char pad546[0x590 - 0x546];
    int res[3];
    unsigned char pad59C[0x69C - 0x59C];
    int owner;
    unsigned char pad6A0[0x6AC - 0x6A0];
    int obj[5];
} W;

extern unsigned char d_021BBA74[];
extern short d_021BBBCC[][2];
extern unsigned char d_021BBA81[];
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, unsigned int);

void func_021BA8C0(W *p)
{
    unsigned i;
    Rect r;
    for (i = 0; i < 5; i++) {
        r.d = d_021BBA74[i];
        r.e = 1;
        r.x = d_021BBBCC[i][0] - 0x10;
        r.y = d_021BBBCC[i][1];
        r.z = d_021BBA81[i * 2 + 1];
        p->obj[i] = (int)func_0204B294((void *)p->owner, p->res[1], p->res[0], p->res[2], &r, 0, p->heap);
        func_0204B92C((struct Obj *)p->obj[i], 1);
    }
}
