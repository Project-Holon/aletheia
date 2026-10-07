/*
 * file:     btl_server_p18.c
 * unit:     yes
 * function: func_021BC55C, func_021BC568
 * address:  0x021BC55C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021C6394  0x021C6394  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 kind : 4; u32 pad : 3; u32 id : 16; u32 rest : 9; } B;

typedef struct { u8 *a; B b; u32 c; u32 d; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; } S;

extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021C6394(u8 *p, u8 *a, unsigned int n);
extern void func_021E0394(u8 *a, int b);
u8 func_021BC55C(u8 *p);
void func_021BC568(S *p);

u8 func_021BC55C(u8 *p)
{
    return p[0x784];
}


void func_021BC568(S *p)
{
    u32 lk = func_021CC8D8((u8 *)p + 0x1d74, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        E *e;
        e = &p->e[i];
        if (e->b.kind == 1)
            id = e->b.id;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                func_021C6394((u8 *)p, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C((u32 *)((u8 *)p + 0x1d74), lk, 0x5a0);
}
