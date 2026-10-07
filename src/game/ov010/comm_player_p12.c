/*
 * file:     comm_player_p12.c
 * unit:     yes
 * function: func_0216880C, func_02168824, func_0216883C
 * address:  0x0216880C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 */
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020056EC(u32 range);
extern int func_0209C2B0();
void *func_0216880C(u32 group, u32 heap);
int func_02168824(void);
u8 func_0216883C(u32 n);


/*
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * func_0204A1BC(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer func_02168924 takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * func_02168800, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216880C.c \
 *       --func func_0216880C --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void *func_0216880C(u32 group, u32 heap)
{
    return (void *)func_0204A1BC(215, (u16)(group + 1), 0, heap);
}


int func_02168824(void)
{
    int a0;
    int a1;
    int t4;

t4 = 0;
t4 = ~t4;
a0 = t4 + 0;
    a0 = func_020056EC(a0);
loc_02168830:
a1 = (unsigned)t4 >> 0x10;
    a0 = func_0209C2B0(a0, a1);
loc_02168836:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    return a0;}


/*
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: func_02168924
 * stores the result to its u8 local without an extension.
 */
u8 func_0216883C(u32 n)
{
    if (n < 50)
        return 3;
    if (n < 70)
        return 6;
    if (n < 90)
        return 9;
    if (n < 110)
        return 12;
    if (n < 160)
        return 15;
    if (n < 180)
        return 18;
    if (n < 200)
        return 21;
    return 31;
}
