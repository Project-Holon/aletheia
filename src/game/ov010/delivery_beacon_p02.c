/*
 * file:     delivery_beacon_p02.c
 * unit:     yes
 * function: func_021576D0, func_02157700, func_02157724, func_02157760
 * address:  0x021576D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021727F4  0x021727F4  data
 *   func_02034714 0x02034714 arm
 *   d_021727F0 0x021727F0 data a4
 *   func_02177B2C  0x02177B2C  thumb  ov014
 *   func_02177BAC  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021780C4  0x021780C4  thumb  ov014
 *   func_02177BCC  0x02177BCC  thumb  ov014
 */
#include "../../matched/include/Obj04145.h"
#include "../../matched/include/Obj04913.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { INDEX_ZERO = 0 } Index;

typedef struct P {
    u8 pad00[0x31B8];
    u8 sel;
} P;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *, void *, u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u8 *func_02177B2C(int);
extern void func_02177BAC(u32 idx);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_021780C4(u32 i);
extern void func_02177BCC(void);
void *func_021576D0(u8 *p);
void func_02157700(int *p);
int func_02157724(u8 *p);
void func_02157760(u8 *q);
extern const char d_021727F4[];
extern char d_021727F0[];


void *func_021576D0(u8 *p)
{
    void *buf;

    buf = func_02030734(*(u16 *)(p + 6), 0x31C0, 1, d_021727F4, 0x127);
    func_02082D44(p, buf, 0x7C);
    return buf;
}

void func_02157700(int *p) { if (p[2] != 0 && p[2] >= 0x5e8) func_02034714(d_021727F0, 0, d_021727F0); }

/*
 * extent: 58-byte body followed by 2-byte alignment padding.
 * lever: enum bound preserves the entry guard; declare index before bound.
 */
int func_02157724(u8 *p) { int i; Index n; n = p[0xd9]; if (n == 0) return 0; for (i = 0; i < n; i++) { if (n != p[i * 100 + 0xd9]) return 0; } return 1; }


/*
 * Wave 75: ov014 leaves 0x021780C4 and 0x02177BCC filed and verified;
 *   all six relocations resolve. 0x02177BAC was already matched.
 * levers (lane R1): the old 3-slot frame miss was the `sel`/`sel2` locals, which
 *   copy-propagate into one; the original writes p->sel directly and the two stack
 *   slots are the loop-hoisted 0x31B8 address. `(e+0x60) & (q+0x14)` operand order,
 *   and the CRC result in a named local for `cmp r0, r1`.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = q;` before `base = q + 0x7C;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02157760(u8 *q)
{
    P *p = (P *)q;
    u8 *base;

    int i;
    u8 *e;
    int idx;
    u32 crc;

    base = q + 0x7C;

    for (i = 0; i < 16; i++) {
        e = func_02177B2C(i);
        if (e == 0)
            continue;
        if (e[0x5F] != ((struct Obj04145 *)q)->f10) {
            func_02177BAC(i);
        } else if ((((struct Obj04913 *)e)->f60 & ((struct Obj04145 *)q)->f14) == 0) {
            func_02177BAC(i);
        } else if (e[0x5E] != p->sel && p->sel != 0xFF) {
            func_02177BAC(i);
        } else {
            idx = e[0x5C] - 1;
            if (idx >= 0x12)
                continue;
            if (q[idx * 100 + 0xD8] != 0)
                continue;
            crc = func_0203F1FC(e + 8, 0x54);
            if (crc != ((struct Obj04913 *)e)->f0) {
                func_02177BAC(i);
            } else {
                if (p->sel == 0xFF)
                    p->sel = e[0x5E];
                func_021780C4(i);
                func_02082D44(e, base + idx * 100, 100);
                func_02177BCC();
            }
        }
    }
}
