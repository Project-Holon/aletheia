/*
 * function: func_021C0A4C
 * address: 0x021C0A4C
 * packet: pkt_ov093_021C0A4C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor q hoists its halfword load before the record store.
 * symbols:
 *   func_021C0C04 0x021C0C04 thumb ov093
 *   func_021C0C14 0x021C0C14 thumb ov093
 *   func_021C0C24 0x021C0C24 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C6BF8 0x021C6BF8 thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C1E74 0x021C1E74 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021C15D4 0x021C15D4 thumb ov093
 *   func_021C1678 0x021C1678 thumb ov093
 *   func_021C7C24 0x021C7C24 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { u16 value; u16 id:5; u16 mode:4; u16 type:4; u16 marked:1; u16 special:1; u16 error:1; };
struct List { u8 good, bad, count, pad; struct Entry entries[1]; };
extern void func_021C0C04(u8 *);
extern u8 *func_021C0C14(u8 *);
extern u8 *func_021C0C24(u8 *);
extern u8 func_021D5440(u8 *p);
extern int func_021C6BF8(u8 *, u8 *, u8 *, u32);
extern int func_021CC8B8(const u32 *, u8);
extern int func_021C1E74(u8 *, u8 *, u8 *, const u8 *, u32, u16, u32, u32, u16 *);
extern u32 func_021D6D7C(u8 *p);
extern u32 func_021C15D4(void *p, u32 n);
extern int func_021C1678(u8 *, u8 *, u8 *, u32, u16 *);
extern void func_021C7C24(u16 *, int, u8 *, u8 *, int);
void func_021C0A4C(u8 *p, u8 *a, u8 *b, const u8 *q, const u32 *c, u16 k, struct List *out)
{
    int i = 0;
    u8 *r;
    struct { u16 x, y; } temp;
    out->good = 0;
    out->bad = 0;
    func_021C0C04(b);
    r = func_021C0C14(b);
    if (r != 0) {
        do {
            out->entries[i].id = func_021D5440(r);
            out->entries[i].marked = (u16)func_021C6BF8(p, a, r, *(u16 *)q);
            out->entries[i].mode = (u16)func_021CC8B8(c, out->entries[i].id);
            out->entries[i].special = (u16)func_021C1E74(p, a, r, q, out->entries[i].mode, k, out->entries[i].marked, 0, &temp.y);
            out->entries[i].value = temp.y;
            if (out->entries[i].special) {
                out->entries[i].marked = 0;
                out->entries[i].mode = 3;
            }
            out->entries[i].error = (u16)func_021D6D7C(r);
            if (!out->entries[i].error) {
                temp.x = func_021C15D4(r, out->entries[i].value);
                out->entries[i].type = (u16)func_021C1678(p, a, r, 1, &temp.x);
                out->entries[i].value = temp.x;
                out->good++;
            } else {
                out->entries[i].value = temp.y;
                out->entries[i].type = 0;
                out->bad++;
            }
            func_021C7C24((u16 *)(p + 0x1f7c), (int)p, a, r, out->entries[i].mode);
            i++;
            r = func_021C0C24(b);
        } while (r != 0);
    }
    out->count = i;
}
