/*
 * function: func_021B9AB8
 * address: 0x021B9AB8
 * packet: pkt_ov172_021B9AB8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-05, wD4 lane17): DIFF, 186 -> 131 bytes. Lever: y0 is read in the loop pre-header as `yb = *(u8 *)&y0;` (stack u8 argument re-read from its home, address-taking is fine for stack args). The prologue now matches except x0/p: original stores r3,r2 to [sp,#4],[sp] first and reloads x0 for every use (ours copies x0 to r1), and holds y0 in r5 across the float calls. Slot order of stepx, stepy, yb also differs (original yb lowest). Tried yb declared first, stepy before stepx (132-133 bytes).
 * note 2026-10-04 wD2 lane01: still 186 bytes. Original spills r3 (x0) and r2 (p) first at entry and re-reads x0 from [sp,#4] at every use; ours copies x0 to r1. Tried `*(int *)&x0` at each use: forces a `push {r0-r3}` prologue (107 bytes diff, 214 bytes), so x0 is an allocator spill, not address-taken. Also `*(u8 **)&p` (worse).
 * note (2026-10-04): draft is logic-correct (186 byte diff, 206 vs 208 bytes). Residue: original keeps x0 and p
 *   purely on the stack (str r3,[sp,#4] first; x0 reloaded each use) and holds y1,y0 in r4,r5 across the
 *   float-round calls, re-reading y0 from the stack arg in the loop pre-header; mine copies x0 to r1 and
 *   spills y0 to [sp,#8] early. Tried: u8 vs one-field struct stack params, struct x0, ternary max,
 *   declaration order of accumulators, u8 callee params. None changed the allocation.
 * 2026-10-05 (wD5 lane20): 131 -> 27 bytes. Levers: y0 and y1 copied into locals `by = y1; ay = y0;` assigned AFTER the dx abs (original keeps y1 in r4, y0 in r5 across the float calls; declare ay before by, assign by first), and the loop-invariant read of the stack u8 `*(u8 *)&y0` written inline in the loop call so it hoists after the n>0 guard. Declaring stepy before stepx gives 27. Residue: (1) x0 is a pure memory spill in the original (str r3,[sp,#4] first, x0 reloaded at every use: `ldr r0,[sp,#4]` before `subs r2,r0,r1`); ours copies r3 to r1 first, so dx and d use r1/r0 swapped; (2) spill slot order of stepx/stepy/hoisted y temp (original 0x10/0xc/8, ours 8/0xc/0x10). Not tried: anything that forces x0 into memory without an address-taking cast.
 * symbols:
 *   func_021B9B88 0x021B9B88 thumb ov172
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C0A4(int a, int b);
extern void func_021B9B88(u8 *p, u8 x, u8 y, int value);

void func_021B9AB8(int a0, int a1, u8 *p, int x0, u8 y0, u8 x1, u8 y1, int value)
{
    int dx = x0 - x1;
    int dy;
    int n, i;
    int stepy, stepx;
    int accx, accy;
    int d, r;
    int yb; int ay; int by;
    if (dx < 0)
        dx = -dx;
    by = y1; ay = y0; dy = ay - by;
    if (dy < 0)
        dy = -dy;
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C0A4(func_0209C494(r), n);
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C0A4(func_0209C494(r), n);
    accx = 0;
    accy = 0;
    for (i = 0; i < n; i++) {
        yb = *(u8 *)&y0;
        func_021B9B88(p, x0 + (accx >> 12), yb + (accy >> 12), value);
        accx += stepx;
        accy += stepy;
    }
}
