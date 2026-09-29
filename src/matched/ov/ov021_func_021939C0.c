/*
 * function: func_021939C0
 * address:  0x021939C0
 * packet:   pkt_ov021_021939C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020493D4  0x020493D4  arm
 *   func_02049250  0x02049250  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02194044  0x02194044  thumb  ov021
 *   func_0216245C  0x0216245C  thumb  ov010
 *   d_021D3F60     0x021D3F60  data  a4
 *   d_021DDA60     0x021DDA60  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a; u16 b; u32 c; } Ent;

extern int d_021D3F60[];
extern int d_021DDA60;
extern u32 func_020493D4(int h, int a);
extern Ent *func_02049250(int h, int a, u16 heap);
extern void *func_02030734(u16 heap, u32 size, u32 clear, void *file, u32 line);
extern void func_020307B0(void *p);
extern int func_02194044(u8 *p, u16 a, u16 b);
extern void func_0216245C(void *o, u16 idx);

void func_021939C0(u8 *o, void *dst, int skip, u32 heap)
{
    u32 n;
    Ent *e;
    u32 *seen;
    u32 cnt;
    u32 i;
    u32 j;
    Ent *cur;

    if (skip != 0)
        return;
    n = func_020493D4(*(int *)(o + 0x10), d_021D3F60[*o]);
    heap = (heap & 0x7FFF) | 0x8000;
    e = func_02049250(*(int *)(o + 0x10), d_021D3F60[*o], (u16)heap);
    n >>= 3;
    seen = func_02030734((u16)heap, n * 4, 1, &d_021DDA60, 0x208);
    cnt = 0;
    for (i = 0; i < n; i++) {
        cur = &e[i];
        if (func_02194044(o + 0x18, e[i].a, cur->b)) {
            seen[cnt] = cur->c;
            cnt++;
        } else {
            for (j = 0; j < cnt; j++) {
                if (seen[j] == e[i].c)
                    break;
            }
            if (j >= cnt) {
                for (j = i + 1; j < n; j++) {
                    if (cur->c == e[j].c)
                        break;
                }
                if (j >= n)
                    func_0216245C(dst, (u16)cur->c);
            }
        }
    }
    func_020307B0(seen);
    func_020307B0(e);
}
