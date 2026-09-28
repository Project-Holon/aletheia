/*
 * function: func_021F6CDC
 * address:  0x021F6CDC
 * packet:   pkt_021F6CDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
 * symbols:
 *   func_021F6C80  0x021F6C80  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02018438(void *p);
extern int func_021F6C80(void *pa, void *pb);

int func_021F6CDC(void *mon, void *want)
{
    MonTag t;

    t.species = func_02017E88(mon, 5, 0);
    t.form = func_02017E88(mon, 0x6E, 0) + 1;
    t.gender = func_02018438(mon);
    return func_021F6C80(&t, want);
}
