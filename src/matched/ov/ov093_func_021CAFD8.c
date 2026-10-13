/*
 * function: func_021CAFD8
 * address: 0x021CAFD8
 * packet: pkt_ov093_021CAFD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P6 lane U6. The older draft (docs/notes) differed by a
 *   count/index register swap (14 B). Declaring count before i closes it (the
 *   first declared long-lived local takes r4). The kind local (11, then
 *   kind + 0xF5) is plain literals 0xB and 0x100; the Clear helper and the tmp
 *   local are plain loop and direct argument. unsigned long n is u32.
 * symbols:
 *   func_021D7F00 0x021D7F00 thumb ov093
 *   func_021CB134 0x021CB134 thumb ov093
 *   func_021CB144 0x021CB144 thumb ov093
 *   func_021CB154 0x021CB154 thumb ov093
 *   func_021CB164 0x021CB164 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   func_021B8778 0x021B8778 thumb ov093
 *   func_021B98A4 0x021B98A4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021D7F00(u32);
extern u32 func_021CB134(void *);
extern void *func_021CB144(void *, int);
extern void func_021CB154(void *, void *);
extern void func_021CB164(void *, void *);
extern int func_021D5B68(void *);
struct Unk021B8CB0;
extern u8 func_021D5440(u8 *p);
extern int func_021B9A24(u32, u32);
extern int func_021B8D8C(void *, void *, u32);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char * const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D78AC(u32);
int func_021CAFD8(u8 *p, u32 mode, void *m, const u16 *item, u8 self, void *out)
{
    int count;
    u8 j;
    void *previous;
    int position;
    u16 target;
    u8 indices[6];
    int members[3];
    int d1;
    u8 i;
    u8 choice;
    int d0;
    u32 n;
    if (func_021D7F00(mode) <= 1 || func_021CB134(out) != 1) goto fail;
    previous = func_021CB144(out, 0);
    if (!func_021D5B68(previous)) goto fail;
    if (func_021B9A24(func_021D5440(m), func_021D5440(previous))) goto fail;
    position = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(m));
    func_021CB154(out, previous);
    if (WAZA_TOOL_GetFlag(*item, 0xb)) target = 0x600 | position;
    else target = 0x100 | position;
    n = func_021B8778(*(void **)(p + 4), target, indices);
    for (j = 0; j < 3; j++) members[j] = 0;
    count = 0;
    for (i = count; i < n; i++) {
        members[count] = (int)func_021B98A4(*(void **)(p + 8), indices[i]);
        if (!func_021D5B68((void *)members[count])) {
            indices[count] = indices[i];
            count = (u8)(count + 1);
        }
    }
    if (!count) return 0;
    if (count != 2) choice = 0;
    else {
        d0 = indices[0] - self;
        if (d0 < 0) d0 *= -1;
        d1 = indices[1] - self;
        if (d1 < 0) d1 *= -1;
        if (d0 == d1) {
            d0 = func_021D59B4((void *)members[0], 13);
            d1 = func_021D59B4((void *)members[1], 13);
        }
        if (d0 < d1) choice = 0;
        else if (d1 < d0) choice = 1;
        else choice = func_021D78AC(2);
    }
    if (members[choice]) { func_021CB164(out, (void *)members[choice]); return 1; }
fail:
    return 0;
}
