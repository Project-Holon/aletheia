/*
 * file:     worldtrade_box_p14.c
 * unit:     yes
 * function: func_021F6B34, func_021F6B40, func_021F6B80, func_021F6BA4, func_021F6BC4
 * address:  0x021F6B34
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_02202C58  0x02202C58  data  a4
 */
struct Sub020079BCEntry;
struct Sav;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_0201AA18(void *party);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *a);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern int func_020078C4(void *save, u32 box);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);
int func_021F6B34(int v);
void *func_021F6B40(void *party, void *save, int box, int slot);
u32 func_021F6B80(u8 *p, u32 b, u32 c);
int func_021F6BA4(void *party, void *save, int box, int slot);
u32 func_021F6BC4(void *sav);
extern const u32 tbl_02202C58[];

/*
 * True only for the 0xff sentinel.
 */
int func_021F6B34(int v)
{
    if (v == 0xff) {
        return 1;
    }
    return 0;
}


void *func_021F6B40(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0) {
        if (slot > (int)func_0201AA18(party) - 1) {
            return 0;
        }
        return func_020185F4(func_0201AB28(party, slot));
    }
    return func_02007A18(save, box, slot);
}


u32 func_021F6B80(u8 *p, u32 b, u32 c)
{
    if (func_021F6B34(c) != 0) {
        return func_0201AA18(p);
    }
    return func_020078C4((void *)b, c);
}


int func_021F6BA4(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0 && (int)func_0201AA18(party) < 2) {
        return 0;
    }
    return 1;
}


u32 func_021F6BC4(void *sav)
{
    u32 f = func_02017DBC(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = func_02017E88(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    func_02017DE4(sav, f);
    return r;
}
