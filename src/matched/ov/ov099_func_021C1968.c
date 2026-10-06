/*
 * function: func_021C1968
 * address:  0x021C1968
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE6E4  0x021BE6E4  thumb  ov099
 *   func_021C27E0  0x021C27E0  thumb  ov099
 *   func_021C27E8  0x021C27E8  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x46];
    u8 f46;                 /* 0x46 */
} Sub;

typedef struct {
    char pad[8];
    void *f8;               /* 0x008 */
    char pad0c[0x23c];
    Sub *f248;              /* 0x248 */
} Work;

extern void func_021C27E8(void *a, int v);
extern void func_021C2864(void *a, int v);
extern void func_021BE6E4(char *s);
extern void func_021C27E0(void *a);

void func_021C1968(Work *w)
{
    w->f248->f46 = 1 - w->f248->f46;
    func_021C27E8(w->f8, w->f248->f46);
    func_021C2864(w->f8, w->f248->f46);
    func_021BE6E4((char *)w);
    func_021C27E0(w->f8);
}
