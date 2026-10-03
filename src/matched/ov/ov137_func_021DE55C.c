/*
 * function: func_021DE55C
 * address: 0x021DE55C
 * packet: pkt_ov137_021DE55C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);
int func_021DE55C(char *p) {
    int state;
    if (*(void **)(p+0xf0) == 0) return 1;
    state = func_0201CE30(*(void **)(p+0xf0));
    if (state == 0) {
        if (func_0203630C() & 1)
            func_0201CE5C(*(void **)(p+0xf0), 0);
    } else if (state == 1) {
        if (func_020362DC() & 1)
            func_0201CE38(*(void **)(p+0xf0));
    } else if (state == 2) {
        func_0201CE48(*(void **)(p+0xf0));
        *(void **)(p+0xf0) = 0;
        return 1;
    }
    return 0;
}
