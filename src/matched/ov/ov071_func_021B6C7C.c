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
 * sites to PALANM_GetColor stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 PALANM_GetColor(Slot *s, int idx, int which, u16 pos)
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
 *   PALANM_GetColor  0x02021F3C  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   func_021B6DB4  0x021B6DB4  thumb  ov071
 *   d_021BABE0     0x021BABE0  data  a1
  * note 2026-10-05 (D8 lane16): witness PALANM_GetColor filed as src/matched/arm9/PALANM_GetColor.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
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

typedef unsigned int   u32;
struct Chan02021FD8;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021B6E00(unsigned int x);
extern int func_021B6E0C(unsigned int x);
extern int func_021B6E18(int);
extern u16 PALANM_GetColor(int base, int idx, int which, u16 pos);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_021B6DB4(int *p, int a, int idx);

void func_021B6C7C(int *p, int idx)
{
    Ent *e;
    int a, b, n;
    int i;
    int v;

    e = (Ent *)((u8 *)p + 0xC + idx * 8);
    if (idx >= 4) {
        func_02034714(d_021BABE0, (int)0, d_021BABE0);
    }
    a = func_021B6E00((int)idx);
    b = func_021B6E0C((int)idx);
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
            PALANM_BlendChannel((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, v >> 8,
                          PALANM_GetColor(*(int *)p[1], idx, 1, b + i));
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
                PALANM_BlendChannel((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, e->v >> 8,
                              PALANM_GetColor(*(int *)p[1], idx, 1, b + i));
            }
        } else {
            e->timer--;
        }
        break;
    }
}
