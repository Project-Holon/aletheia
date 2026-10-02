/*
 * unit: yes
 * function: func_02155338, func_0215534C, func_02155354, func_0215535C, func_02155364
 * address: 0x02155338
 * packet: pkt_ov009_02155338
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower func_0215535C resolves through the verified existing 02156CF4
 * unit after its function inventory was corrected to include 02156D70.
 * symbols:
 *   func_02156874 0x02156874 thumb ov009
 *   func_02156B70 0x02156B70 thumb ov009
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_02156D70 0x02156D70 thumb ov009
 *   func_02156CD0 0x02156CD0 thumb ov009
 */
extern unsigned char func_02156874(int);
typedef signed short s16;
typedef unsigned int u32;
extern s16 func_02156B70(void);
extern int func_02156B8C(void);
extern void func_02156D70(u32);
extern int func_02156CD0(void);
int func_02155338(int n)
{
    if (func_02156874(n) == 6) return 1;
    return 0;
}
s16 func_0215534C(void)
{
    return func_02156B70();
}
int func_02155354(void)
{
    return func_02156B8C();
}
void func_0215535C(u32 v)
{
    func_02156D70(v);
}
int func_02155364(void)
{
    return func_02156CD0();
}
