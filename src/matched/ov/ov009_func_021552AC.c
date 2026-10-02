/*
 * unit: yes
 * function: func_021552AC, func_021552C4, func_021552CC, func_021552D4
 * address: 0x021552AC
 * packet: pkt_ov009_021552AC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower func_021552C4 resolves through the verified ov009 02156CAC leaf;
 * ov010's same-address allocator is a different function.
 * symbols:
 *   func_02156D84 0x02156D84 thumb ov009
 *   func_02155388 0x02155388 thumb ov009
 *   func_02156CAC 0x02156CAC thumb ov009
 *   func_0216B908 0x0216B908 arm ov009
 *   func_021562EC 0x021562EC thumb ov009
 */
extern int func_02156D84(void);
extern int func_02155388(void);
extern int func_02156CAC(void);
extern int func_0216B908(void);
extern int func_021562EC(void);
int func_021552AC(void)
{
    int r;
    r = func_02156D84();
    if (!func_02155388()) r |= 1;
    return r;
}
int func_021552C4(void)
{
    return func_02156CAC();
}
int func_021552CC(void)
{
    return func_0216B908();
}
int func_021552D4(void)
{
    return func_021562EC();
}
