/*
 * function: func_02174514
 * address:  0x02174514
 * packet:   pkt_ov011_02174514
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (D8 lane19): re-verified, MATCH; only unresolved relocations are arm9 leaves 0x0202E7E0 and 0x0202E7C4 (no witness outside range). Needs labels seeded. Source is byte-correct; no C change possible.
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (Ilias's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0202E7E0  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0202E7C4  0x0202E7C4  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
u32 func_02026478(void *obj);
int func_02012F20(int a);
void *func_02012B38(const struct BigObj *p);
u8 func_02014484(struct Sub02014444Obj *o);
int func_0202E7E0(int a);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0202E7C4(int a, int b, int c);

void func_02174514(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = func_02026478((void *)(((int *)d)[1]));
    q = func_02012F20(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        if (func_02014484(func_02012B38((const struct BigObj *)p)) == 1) {
            t = func_0202E7E0(q);
            if (t == 0 || t == 3) {
                func_0202E7C4(q, *c, (int)func_02012950((struct Sub24 *)p, a));
            }
        }
    }
}
