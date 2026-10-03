/*
 * function: func_021D2030
 * address: 0x021D2030
 * packet: pkt_ov093_021D2030
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: word locals with casts at the four descriptor loads, t2 before v
 * in declaration order, and a named nested-call result keep v in r7 and
 * t1/t2 in the original spill slots. The u8 b in the callee's own source
 * is widened here: the original caller has no second truncation after v.
 * symbols:
 *   func_021CD9E0 0x021CD9E0 thumb ov093
 *   func_021B8590 0x021B8590 thumb ov093
 *   func_021D2000 0x021D2000 thumb ov093
 *   func_021EA0A0 0x021EA0A0 thumb ov093
 *   func_021EA0E4 0x021EA0E4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 unk00;
    u8 unk04[0x50];
    void *win;
} Seq;
extern u32 func_021CD9E0(void *s);
extern int func_021B8590(u32 v);
extern u32 func_021D2000(Seq *s, u32 k, u32 b);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(void *win);
int func_021D2030(Seq *s, int *state, const u32 *a)
{
    u32 t2;
    u32 v;
    u32 t1;
    u32 t3;
    u32 result;
    switch (*state) {
    case 0:
        if (func_021CD9E0(s)) {
            return 1;
        }
        if (func_021B8590(s->unk00)) {
            v = (u8)a[0];
            t1 = (u8)a[1];
            t2 = (u16)a[2];
            t3 = (u8)a[3];
            result = func_021D2000(s, t2, v);
            func_021EA0A0(s->win, v, t1, t2, result, t3, 0);
            *state = *state + 1;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
