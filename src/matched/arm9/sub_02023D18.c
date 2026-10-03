/*
 * function: func_02023D18
 * address:  0x02023D18
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020056A0  0x020056A0  thumb
 *   sub_02023DA8  0x02023DA8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_020056A0(void *cb, void *param, u32 flag);
struct Args4;
extern u32 sub_02023DA8(void *obj, struct Args4 *args);

struct Item_02023D18 {
    void *val;
    u32 field_4;
    u32 field_8;
    u32 field_C;
};

struct Big_02023D18 {
    u8 pad[0x10];
    struct Item_02023D18 items[1][1];
};

void func_02023D18(void *obj, void *val, u32 f4, u32 f8, u32 fC)
{
    struct Item_02023D18 *entry = (struct Item_02023D18 *)((u8 *)obj + 0x10 + (fC << 5) + (f8 << 4));

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    entry->field_C = fC;
    sub_020056A0(sub_02023DA8, entry, 1);
}
