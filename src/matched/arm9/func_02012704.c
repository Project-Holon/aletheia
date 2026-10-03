/*
 * function: func_02012704
 * address:  0x02012704
 * packet:   pkt_020124F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: promoted.  0x0215E334 and 0x02159BBC are unlabelled ov010
 *           ENV_SetResourceSet thunks matched in src/matched/func_0215E334.c and
 *           func_02159BBC.c (`matched, overlay`); 0x021647D8, 0x0216CCB0 and
 *           0x021623BC resolve as sole-ref/code (overlay).
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *   func_021647D8   0x021647D8  thumb  ov010
 *   func_02027584   0x02027584  thumb
 *   func_0202E794   0x0202E794  thumb
 *   func_0215E334   0x0215E334  thumb  ov010
 *   func_02006E64   0x02006E64  thumb
 *   func_02007AC8   0x02007AC8  thumb
 *   func_0216CCB0   0x0216CCB0  thumb  ov010
 *   func_02159BBC   0x02159BBC  thumb  ov010
 *   func_021623BC   0x021623BC  thumb  ov010
 *   func_02014444   0x02014444  thumb
 *   func_0202889C   0x0202889C  thumb
 *
 * A destructor: fifteen pointer fields of one big object handed to fifteen
 * different release functions, then the object itself to the base deleter
 * 0x020307B0 (the ARM `blx` target, called three times).
 *
 * The literal 0x6AC is pooled once and every other offset is derived from it
 * with `adds`/`subs` (0x690, 0x68C, 0x684, 0x5E4), which is why the second
 * group starts from 0x69 << 2: the offsets are the source's array indices
 * scaled by four, and the field reads are `p[0x1AB]`, `p[0x1A4]`, ... in a
 * `u32 *`.  Writing the fields as byte offsets through a `u8 *` reproduces
 * the same derived-constant chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012704.c \
 *       --func func_02012704 --addr 0x02012704 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020307B0(u32 p);
extern int func_021647D8(int a0);
extern void func_02027584(u32 p);
extern void func_0202E794(u32 p);
extern void func_0215E334(u32 p);
extern void func_02006E64(u32 p);
extern void func_02007AC8(u32 p);
extern int func_0216CCB0(int a0);
extern void func_02159BBC(u32 p);
extern int func_021623BC(int a0);
extern void func_02014444(u32 p);
extern void func_0202889C(u32 p);

void func_02012704(u8 *p)
{
    func_020307B0(*(u32 *)(p + 0x6AC));
    func_021647D8(*(u32 *)(p + 0x690));
    func_02027584(*(u32 *)(p + 0x68C));
    func_0202E794(*(u32 *)(p + 0x684));
    func_0215E334(*(u32 *)(p + 0x5E4));
    func_02006E64(*(u32 *)(p + 0x1A4));
    func_020307B0(*(u32 *)(p + 0x1A0));
    func_02007AC8(*(u32 *)(p + 0x19C));
    func_020307B0(*(u32 *)(p + 0x18C));
    func_0216CCB0(*(u32 *)(p + 0x1A8));
    func_02159BBC(*(u32 *)(p + 0x1B0));
    func_021623BC(*(u32 *)(p + 0x158));
    func_02014444(*(u32 *)(p + 0x1B8));
    func_0202889C(*(u32 *)(p + 0x1B4));
    func_020307B0((u32)p);
}
