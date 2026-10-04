/*
 * function: func_021C0D08
 * address:  0x021C0D08
 * packet:   pkt_ov021_021C0D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB2DC  0x021AB2DC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *obj, struct VecFx32 *out);
extern void func_02164208(u32 dir, Vec *pos, int step);
extern u8 func_0216D91C(void *obj);
extern u8 func_0216D924(void *obj);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB11C(u32 attr);
extern int func_021AB2DC(u16 id);

int func_021C0D08(void *obj, u32 dir, void *map)
{
    Vec pos;
    Vec cur;
    int flagB;
    int flagA;
    u8 i;
    u8 m;
    u8 n;
    u8 j;
    u32 attr;
    u16 id;

    func_0216D88C(obj, (struct VecFx32 *)&pos);
    func_02164208(dir, &pos, 0x10000);
    n = func_0216D91C(obj);
    m = func_0216D924(obj);
    flagB = 0;
    flagA = 0;
    for (i = 0; i < m; i++, pos.z -= 0x10000) {
        cur = pos;
        for (j = 0; j < n; j++, cur.x += 0x10000) {
            attr = func_021AB0D4(map, &cur);
            id = func_021AB0F0(attr);
            if (func_021AB11C(attr)) {
                if (func_021AB2DC(id) == 0)
                    return 1;
                flagA = 1;
            } else {
                flagB = 1;
            }
        }
    }
    if (flagA == 1) {
        if (flagB == 0)
            return 3;
        return 2;
    }
    return 0;
}
