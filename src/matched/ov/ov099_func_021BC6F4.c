/*
 * function: func_021BC6F4
 * address:  0x021BC6F4
 * packet:   pkt_ov099_021BC6F4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *
 * Levers: the word index 0x73 of the first arm is an enum-typed local set
 * before the call (it keeps r6 = 0x73 live across it); the stores are written
 * out per arm.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef enum { K73 = 0x73 } Idx;

extern u32 func_0203D378(void);
extern void func_021BAAB8(char *p, int a, int b);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, unsigned int a, unsigned int b);

int func_021BC6F4(char *p, int v)
{
    u32 *a = (u32 *)p;
    Idx k;

    if (func_0203D378() != 0) {
        k = K73;
        func_021BAAB8(p, 0x73, 0);
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 0xa);
        a[k] = 0x49;
    } else {
        func_021BAAB8(p, 0x72, 0);
        a[0x78] = 0x78;
        a[0x73] = 0x8f;
    }
    return v;
}
