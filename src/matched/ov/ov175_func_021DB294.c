/*
 * function: func_021DB294
 * address: 0x021DB294
 * packet: pkt_ov175_021DB294
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012950 0x02012950 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned int   u32;
struct Rec44;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern int func_02008468(void);
extern void func_02082D44(const void *, void *, int);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_021DB294(int index, int unused, void *dest, char *ctx, int owner)
{
    void *record;
    record = func_02012950(*(void **)(ctx + 8), index);
    func_02082D44(dest, record, func_02008468());
    if (owner == (int)func_020399A8()) {
        if (index != func_0203D1A4((struct Link *)((int)func_020399A8())))
            *(int *)(ctx + 0x13c) = 1;
    }
}
