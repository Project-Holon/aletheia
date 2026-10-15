/*
 * function: IRC_RANKING_InputGetFlick
 * address: 0x021B8E90
 * packet: pkt_ov106_021B8E90
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Evidence: state words from ov106_func_021B8DA8; pair outputs are
 * aggregate copies. The ARM9 0203630C unit proves its pointer return;
 * SDK 0207CA00 proves the three-word vector subtraction signature.
 * Unsigned shifts retain wrapping before signed float conversion.
 * Nested success tests retain the shared failure exit; EXACT* ends
 * at 021B8FA6, followed solely by two zero alignment bytes.
 *
 * symbols:
 *   KEY_GetCont 0x0203630C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 */
typedef unsigned int u32;
typedef struct { int x, y; } Pair;
typedef struct { long x, y, z; } Vec;
typedef struct {
    Pair start, end;
    int x, y, dx, dy, count;
    u32 consumed;
    int flags;
} State;
extern unsigned int KEY_GetCont(void);
extern void VEC_Subtract(const Vec *, const Vec *, Vec *);
extern float _fflt(int);
extern int _ffix(float);
extern float _fadd(float, float), _fsub(float, float);
static inline int convert(int v)
{
    float f;
    if (v > 0)
        f = _fadd(0.5f, _fflt((int)((u32)v << 12)));
    else
        f = _fsub(_fflt((int)((u32)v << 12)), 0.5f);
    return _ffix(f);
}
int IRC_RANKING_InputGetFlick(State *p, Pair *start, Pair *end, Vec *delta, int *count)
{
    Vec a, b;
    int y;
    if (!KEY_GetCont()) {
        if (p->consumed < 1) {
            p->consumed = 1;
            if (start)
                *start = p->start;
            if (end)
                *end = p->end;
            if (delta) {
                y = convert(p->start.y);
                a.x = convert(p->start.x);
                a.y = y;
                a.z = 0;
                y = convert(p->end.y);
                b.x = convert(p->end.x);
                b.z = 0;
                b.y = y;
                VEC_Subtract(&a, &b, delta);
            }
            if (count)
                *count = p->count;
            return 1;
        }
    }
    return 0;
}
