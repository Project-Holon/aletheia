/*
 * function: func_021BE6EC
 * address: 0x021BE6EC
 * packet: pkt_ov093_021BE6EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: shared fail label keeps one zero-return epilogue; id, chosen,
 * best declaration order fixes the spilled local slots.
 * symbols:
 *   d_021EFDB8 0x021EFDB8 data a2
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D6E74 0x021D6E74 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021BCB14 0x021BCB14 thumb ov093
 *   func_021BCB68 0x021BCB68 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6E40 0x021D6E40 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BD148 0x021BD148 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 *a; u32 b, c; u8 d0, flag; u16 pad; } E;
extern const u16 d_021EFDB8[3];
extern int func_021D5BB0(u8 *, u32);
extern int func_021D6E74(u8 *);
extern u8 func_021D5440(u8 *);
extern E *func_021BCB14(u8 *, u16, u8, u32);
extern u32 func_021BCB68(u8 *, E *);
extern void func_021D5FC0(u8 *, u32);
extern void func_021D6E40(u8 *, u8, u16);
extern void func_021CD64C(void *, u8, ...);
extern void func_021BD148(u8 *, u8);
int func_021BE6EC(u8 *p, u8 *a, u16 key, u32 x)
{
    u32 i;
    u32 n;
    u8 id;
    u8 *chosen;
    u32 best;
    u8 chosen_id;
    E *cur;
    E *found[2];
    u32 v;
    for (i = 0; i < 3; i++) {
        if (key == d_021EFDB8[i]) break;
    }
    if (i == 3) goto fail;
    if (func_021D5BB0(a, 10) != 0) goto fail;
    if (func_021D6E74(a) != 0) goto fail;
    n = 0;
    id = func_021D5440(a);
    for (i = 0; i < 3; i++) {
        if (key != d_021EFDB8[i]) {
            found[n] = func_021BCB14(p, d_021EFDB8[i], id, x);
            if (found[n] != 0) {
                n++;
                if (n >= 2) break;
            }
        }
    }
    if (n == 0) goto fail;
    best = 6;
    chosen = found[0]->a;
    for (i = 0; i < n; i++) {
        cur = found[i];
        v = func_021BCB68(p, cur);
        if (v < best) {
            best = v;
            chosen = cur->a;
        }
    }
    chosen_id = func_021D5440(chosen);
    func_021D5FC0(a, 10);
    func_021D6E40(chosen, id, key);
    func_021CD64C(*(void **)(p + 12), 91, 0x47a, id, chosen_id, 0xffff0000);
    func_021BD148(p, chosen_id);
    return 1;
fail:
    return 0;
}
