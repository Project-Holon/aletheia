/*
 * function: func_02023D40
 * address:  0x02023D40
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
 *   sub_02023DC4  0x02023DC4  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_020056A0(void *cb, void *param, u32 flag);
struct Args3;
extern u32 sub_02023DC4(void *obj, struct Args3 *args);

struct Item_02023D40 {
    void *val;
    u32 field_4;
    u32 field_8;
};

void func_02023D40(void *obj, void *val, u32 f4, u32 f8)
{
    struct Item_02023D40 *entry = (struct Item_02023D40 *)((u8 *)obj + 0x68 + f8 * 12);

    entry->val = val;
    entry->field_4 = f4;
    entry->field_8 = f8;
    sub_020056A0(sub_02023DC4, entry, 1);
}
