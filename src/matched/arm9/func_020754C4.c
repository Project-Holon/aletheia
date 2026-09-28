/*
 * function: func_020754C4
 * address:  0x020754C4
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * Walk the 32 slots of the current archive (func_020742FC is called for its
 * side effect only): for every slot record func_020744B4 hands back, apply
 * its count byte and +2 halfword (func_02072DB0 / func_02072DD0), and when
 * both the record's +4 payload and the argument are non-null, register the
 * payload count times with func_02072DE8, failing out on the first refusal.
 *
 * Levers (permuter hill found the first, the second is a prototype read):
 *   - declaration order i, e, j (register r6 / r7 / r8);
 *   - the slot index is `int` in the CALLEE PROTOTYPES as well as the loop
 *     (func_02072DE8's first parameter above all).  With the callee declared
 *     u32 the implicit conversion reshuffles r4-r7 (14 bytes out); the loop
 *     compare is `blt`, so the index itself is signed.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020754C4.c \
 *       --func func_020754C4 --addr 0x020754C4 --arm --cc ../2.0/sp2
 *   EXACT, 156 bytes, 5 of 5 relocation sites resolved (sp2p2 the same,
 *   dsi/1.1p1 152 bytes DIFF).
 *
 * symbols:
 *   func_020742FC  0x020742FC  arm
 *   func_020744B4  0x020744B4  arm
 *   func_02072DB0  0x02072DB0  arm
 *   func_02072DD0  0x02072DD0  arm
 *   func_02072DE8  0x02072DE8  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  count;
    u8  pad01;
    u16 h2;
    void *data;
} Ent;

extern void *func_020742FC(void);
extern Ent  *func_020744B4(int index);
extern void  func_02072DB0(int idx, int v);
extern void  func_02072DD0(int idx, u32 val);
extern u32   func_02072DE8(int idx, u32 a, void *src);

u32 func_020754C4(u32 a)
{
    int i;
    Ent *e;
    int j;

    func_020742FC();
    for (i = 0; i < 32; i++) {
        e = func_020744B4(i);
        if (e == 0)
            continue;
        func_02072DB0(i, e->count);
        func_02072DD0(i, e->h2);
        if (e->data != 0 && a != 0) {
            for (j = 0; j < e->count; j++) {
                if (func_02072DE8(i, a, e->data) == 0)
                    return 0;
            }
        }
    }
    return 1;
}
