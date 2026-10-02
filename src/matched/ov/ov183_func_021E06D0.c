/*
 * unit: yes
 * function: func_021E06D0, func_021E0754, func_021E075C, func_021E0764
 * address: 0x021E06D0
 * packet: pkt_ov183_021E06D0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_020490F4 0x020490F4 arm
 *   func_021E1244 0x021E1244 thumb ov183
 *   func_021E1910 0x021E1910 thumb ov183
 *   func_020056A0 0x020056A0 thumb
 *   func_021E083C 0x021E083C thumb ov183
 *   func_021E16E4 0x021E16E4 thumb ov183
 *   d_021E3968 0x021E3968 data ov183
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Source { int words[10]; };
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void func_02082BCC(void *, int, u32);
extern int func_021FC20C(int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021E1244(char *);
extern void func_021E1910(char *);
extern void *func_020056A0(void (*)(void), void *, int);
extern void func_021E083C(void);
extern void func_021E16E4(char *);
extern char d_021E3968[];
char *func_021E06D0(const struct Source *src, u16 heap)
{
    char *p;
    p = func_02030734(heap, 0x368, 0, d_021E3968, 56);
    func_02082BCC(p, 0, 0x368);
    *(struct Source *)(p + 0x324) = *src;
    *(u16 *)(p + 0x34c) = heap;
    *(int *)(p + 0x25c) = src->words[7];
    *(int *)(p + 0x310) = func_021FC20C(src->words[8]);
    *(void **)(p + 0x258) = func_020490F4(59, *(u16 *)(p + 0x34c));
    func_021E1244(p);
    func_021E1910(p);
    *(void **)(p + 0x314) = func_020056A0(func_021E083C, p, 16);
    return p;
}
void func_021E0754(char *p)
{
    func_021E16E4(p);
}
int func_021E075C(char *p)
{
    return *(int *)(p + 0x350);
}
u64 func_021E0764(char *p)
{
    return *(u64 *)(p + 0x360);
}
