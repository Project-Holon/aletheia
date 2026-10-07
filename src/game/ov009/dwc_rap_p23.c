/*
 * file:     dwc_rap_p23.c
 * unit:     yes
 * function: func_02156DC4, func_02156DE0, func_02156DFC
 * address:  0x02156DC4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 *   abs_id_11  0x00000011  data
 *   func_02157108  0x02157108  thumb  ov009
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021B6100  0x021B6100  thumb  ov017
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_02157108(u16 a);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int id);
extern void func_021B6100(void);
void func_02156DC4(int a0, int a1);
void func_02156DE0(int a, int b);
void func_02156DFC(int a);
extern int *g_021A8264;
extern unsigned char abs_id_11[];


/*
 * Recursive MATCH unblocker: callee of func_021DA5D0 (ov123) +004A. Coherent
 * Thumb code in ov009 (ov010 holds the tail of another function), so the ov009
 * shard makes that site attest as `matched`.
 */
void func_02156DC4(int a0, int a1)
{
    *(int *)((char *)g_021A8264 + 0x28C) = a0;
    *(int *)((char *)g_021A8264 + 0x290) = a1;
}

/*
 * leaf: sole blocker of owned ov123 021D920C; parent ownership audit passed.
 * extent: next labelled function 02156DFC follows the 28-byte leaf.
 */
void func_02156DE0(int a, int b)
{
    *(int *)((char *)g_021A8264+0x294)=a;
    *(int *)((char *)g_021A8264+0x298)=b;
}


/*
 * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load
 * ov017, run func_021B6100 there, unload it.
 */
void func_02156DFC(int a)
{
    if (func_02157108(a) == 3) {
        func_02034AC4((int)abs_id_11);
        func_021B6100();
        func_02034A5C((int)abs_id_11);
    }
}
