/*
 * file:     wih_p12.c
 * unit:     yes
 * function: func_02178F1C, func_02178F8C
 * address:  0x02178F1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02179010  0x02179010  thumb  ov014
 *   func_0208EE60  0x0208EE60  arm
 *   g_021797A8 0x021797A8 data ov014 a4
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u16 f0, err, f4, f6, channel, level; } Msg;

void func_02178138(int a);
void func_0217814C(int a);
int func_02179010(void *cb, int n);
u16 func_0208EE60(void);
int func_02178F1C(u16 n);
void func_02178F8C(const Msg *m);
extern u8 *g_021797A8;


int func_02178F1C(u16 n)
{
    u32 m = func_0208EE60();

    if (m == 0x8000) {
        func_0217814C(3);
        func_02178138(9);
        return 3;
    }
    if (m == 0) {
        func_0217814C(0x16);
        func_02178138(9);
        return 0x18;
    }
    if (!((1 << (n - 1)) & m)) {
        do {
            n = n + 1;
            if (n > 0x10)
                return 0x18;
        } while (!((1 << (n - 1)) & m));
    }
    return (u16)func_02179010((void *)func_02178F8C, n);
}

#pragma opt_dead_assignments off

/*
 * note: 2026-10-05 wave P16 lane E8: older draft was DIFF 101 B / 136 B because the
 *   two arms kept separate copies of the u16 store. Per-function pragma
 *   opt_dead_assignments off gives 132 B EXACT (also with plain literal offsets).
 *   Without the pragma the same source stays 136 B. Callee types from matched
 *   definitions: func_0217814C and func_02178138 void(int), func_02178F1C int(u16).
 */
void func_02178F8C(const Msg *m)
{
    u32 a;
    u32 b;
    u32 t;
    int r;
    if (m->err != 0) {
        func_0217814C(m->err);
        func_02178138(9);
        return;
    }
    a = m->channel;
    b = m->level;
    t = *(u16 *)(g_021797A8 + 0x1EAE);
    if (t > b) {
        *(u16 *)(g_021797A8 + 0x1EAE) = b;
        t = 1 << (a - 1);
        *(u16 *)(g_021797A8 + 0x1EB0) = t;
    } else if (t == b) {
        t = (u16)(1 << (a - 1)) | *(u16 *)(g_021797A8 + 0x1EB0);
        *(u16 *)(g_021797A8 + 0x1EB0) = t;
    }
    r = func_02178F1C(a + 1);
    if (r == 0x18 && *(u32 *)(g_021797A8 + 0x1E70) != 9) {
        func_02178138(7);
        return;
    }
    if (r != 2) func_02178138(9);
}


#pragma opt_dead_assignments reset
