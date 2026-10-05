/*
 * function: func_021B6C7C
 * address:  0x021B6C7C
 * packet:   pkt_ov071_021B6C7C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker: every concrete byte matches (312 of 312); the two THM_CALL
 * sites to func_02021F3C stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 func_02021F3C(Slot *s, int idx, int which, u16 pos)
 *   {
 *       if (which == 1) {
 *           return s[idx].a[pos];
 *       }
 *       if (which == 0) {
 *           return s[idx].b[pos];
 *       }
 *       return 0;
 *   }
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_021B6E00  0x021B6E00  thumb  ov071
 *   func_021B6E0C  0x021B6E0C  thumb  ov071
 *   func_021B6E18  0x021B6E18  thumb  ov071
 *   func_02021F3C  0x02021F3C  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_021B6DB4  0x021B6DB4  thumb  ov071
 *   d_021BABE0     0x021BABE0  data  a1
  * note 2026-10-05 (D8 lane16): witness func_02021F3C filed as src/matched/arm9/func_02021F3C.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

extern char d_021BABE0[];

extern void func_02034714(char *a, int b, char *c);
extern int func_021B6E00(int);
extern int func_021B6E0C(int);
extern int func_021B6E18(int);
extern u16 func_02021F3C(int base, int idx, int which, u16 pos);
extern void func_02021FD8(int, int, u16, u16, u8, u16);
extern void func_021B6DB4(int *p, int a, int idx);

void func_021B6C7C(int *p, int idx)
{
    Ent *e;
    int a, b, n;
    int i;
    int v;

    e = (Ent *)((u8 *)p + 0xC + idx * 8);
    if (idx >= 4) {
        func_02034714(d_021BABE0, 0, d_021BABE0);
    }
    a = func_021B6E00(idx);
    b = func_021B6E0C(idx);
    n = func_021B6E18(idx);
    switch (e->state) {
    case 1:
        v = e->v;
        if (e->dir == 0) {
            v += 0x80;
            if (v >= 0x1100) {
                v = 0x1000;
                e->dir ^= 1;
            }
        } else {
            v -= 0x80;
            if (v <= 0) {
                v = 0x100;
                e->dir ^= 1;
            }
        }
        e->v = v;
        for (i = 0; i < n; i++) {
            func_02021FD8(*(int *)p[1], idx, a + i, 1, v >> 8,
                          func_02021F3C(*(int *)p[1], idx, 1, b + i));
        }
        break;
    case 2:
        if (e->timer == 0) {
            e->timer = 3;
            if (e->v == 0) {
                e->v = 0x1000;
            } else {
                e->v = 0;
                e->cnt++;
                if (e->cnt > 1) {
                    func_021B6DB4(p, 0, idx);
                }
            }
            for (i = 0; i < n; i++) {
                func_02021FD8(*(int *)p[1], idx, a + i, 1, e->v >> 8,
                              func_02021F3C(*(int *)p[1], idx, 1, b + i));
            }
        } else {
            e->timer--;
        }
        break;
    }
}
