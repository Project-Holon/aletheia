/*
 * function: func_02205E80
 * address:  0x02205E80
 * packet:   pkt_ov094_02205E80
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220A580     0x0220A580  data   ov094  a4
 *   d_0220A392     0x0220A392  data   ov094  a2
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int v[6];
} Q;

extern const Q d_0220A580;
extern const u16 d_0220A392[];
struct Obj;
extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, u16 f, u16 heap);
extern void func_0204B92C(struct Obj *h, u32 f);
extern void func_0204B878(int h, u16 f);
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_02205E80(char *m)
{
    Q q = d_0220A580;
    int o0;
    int o1;
    int o2;
    int o3;
    int o4;
    int o5;
    char *p;
    int j;

    o0 = 0x240;
    o0 = 0x17c;
    o1 = 0x110;
    o1 = 0x108;
    o2 = 0x114;
    o3 = 0x110;
    o3 = 0x180;
    o4 = 0x110;
    o4 = 0x180;
    o5 = 0x110;
    o5 = 0x180;
    for (j = 0; j < 6; j++) {
        p = m + j * 8;
        *(u32 *)(p + o3) = (u32)func_0204B294((void *)*(u32 *)(m + o0), *(u32 *)(m + 0x110), *(u32 *)(m + o1),
                                         *(u32 *)(m + o2), d_0220A392, 1, *(u16 *)(m + 0x240));
        func_0204B92C((struct Obj *)*(int *)(p + o4), 1);
        func_0204B878(*(int *)(p + o5), q.v[j]);
        func_0204B3DC((struct Obj *)*(int *)(p + 0x180), 0);
    }
}
