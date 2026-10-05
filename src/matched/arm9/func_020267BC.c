/*
 * function: func_020267BC
 * address:  0x020267BC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02026D88 label
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *g_02146940;

struct Rec;
extern void func_02026D88(struct Rec *o, void *sys);
extern int func_02012FCC(int p0);
struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);

void func_020267BC(u32 a0)
{
    u32 *p = g_02146940;

    *p++ = a0;
    func_02026D88((struct Rec *)p, (void *)a0);
    *(u16 *)((char *)g_02146940 + 0xbb0) =
        func_0200864C((const struct PlayTime *)func_02012FCC((int)((void *)a0)));
}
