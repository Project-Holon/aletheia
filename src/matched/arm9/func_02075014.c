/*
 * function: func_02075014
 * address:  0x02075014
 * packet:   pkt_02075014
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  the pool word naming func_02075274 (0x0207507C) is this function's
 *           own, so the ABS32 site has no outside witness; 0x02075274 in turn
 *           cannot be filed because SND_InvalidateBankData (0x020896CC) and
 *           SND_DestroyBank (0x0208A38C) each have their only caller inside it
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern u32 func_0207466C(u32);
struct Global;
extern struct Global *func_020742FC(void);
extern void func_02074694(u32, u32);
extern void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void func_02075274(u8 *p, u32 len, u32 b, u32 c);
u32 func_02075014(u32 a, u32 b, u32 c) {
    u32 sz;
    u32 r = func_0207466C(a);
    if (r == 0) {
        if (c == 0) sz = 0;
        else sz = (u32)func_020742FC();
        r = (u32)func_02074E9C(a, (u32)func_02075274, sz, a, (u32 *)b);
        if (c != 0 && r != 0) func_02074694(a, r);
    }
    return r;
}
