/*
 * function: func_022033F4
 * address: 0x022033F4
 * packet: pkt_ov094_022033F4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x02021728 at +0072 has no admissible outside witness.
 * Verified C copied from ov029_func_021F0DB4.c's EXACT 8-byte scratch proof:
 * int func_02021728(char *p, int i) { return *(int *)(p + i * 0x14); }
 * ARM9 belongs to Ilias. Caller sets r0 to the palette object, r1 to 1.
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_02021728 0x02021728 thumb
 *   func_02082A60 0x02082A60 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Main {
    unsigned char pad00[0x48];
    u32 f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;
    unsigned char pad68[0x104 - 0x68];
    int h104;
    int h108;
    int h10c;
    int h110;
    int h114;
    int h118;
    unsigned char pad11c[0x1e0 - 0x11c];
    int h1e0[4];
    int h1f0;
    int h1f4;
    unsigned char pad1f8[0x23c - 0x1f8];
    int f23c;
    u16 heap;
    unsigned char pad242[0x284 - 0x242];
    unsigned char buf284[0x20];
} Main;
extern void func_02049658(u32, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(u32, u32, u32, u32, u32, u32, u16);
extern void func_020216B4(void *, u32, u32, u32, u32, u32, u16);
extern void *func_021F86E0(void);
extern char *func_02021728(void *, u32);
extern void func_02082A60(const void *, void *, u32);
extern int func_0204A6C8(u32, u32, u32, u32, u16);
extern int func_0204AF28(u32, u32, u32, u32);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern u32 func_0204AEF4(int, int);
extern void func_020216D4(void *, u32, u32, u32);
extern u32 func_020275E4(void);
extern u32 func_020490F4(u32, u32);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u32 func_020275E8(void);
extern u32 func_020275F8(u32);
extern void func_02049238(u32);
void func_022033F4(Main *m)
{
    u32 arc;
    u32 file;
    int i;

    func_02049658(m->f48, 0x5b, 4, 0, 0, 0, m->heap);
    func_02049658(m->f48, 0x71, 7, 0, 0x8000, 0, m->heap);
    func_020498F4(m->f48, 0x72, 7, 0, 0, 0, m->heap);
    func_020216B4(m->pal, m->f48, 0x5c, m->heap, 1, 0x1e0, 0);
    if (m->f23c == 1)
        func_02082A60(func_02021728(func_021F86E0(), 1) + 0x40, m->buf284, 0x20);
    m->h104 = func_0204A6C8(m->f48, 0x73, 0, 1, m->heap);
    m->h10c = func_0204AF28(m->f48, 0x75, 0x76, m->heap);
    m->h108 = func_0204ABF0(m->f48, 0x74, 1, 0, m->heap);
    func_020216D4(m->pal, 3, (u16)(func_0204AEF4(m->h108, 1) >> 1), 0x100);
    m->h110 = func_0204A6C8(m->f48, 0x77, 0, 1, m->heap);
    m->h114 = func_0204AF28(m->f48, 0x78, 0x79, m->heap);
    arc = func_020490F4(func_020275E4(), (u16)((m->heap & 0x7fff) | 0x8000));
    file = func_020275FC(0);
    m->h1f4 = func_0204AF28(arc, file, func_02027600(0), m->heap);
    m->h1f0 = func_0204ABF0(arc, func_020275E8(), 1, 0x100, m->heap);
    func_020216D4(m->pal, 3, (u16)(func_0204AEF4(m->h1f0, 1) >> 1), 0x60);
    for (i = 0; i < 4; i++)
        m->h1e0[i] = func_0204A6C8(arc, func_020275F8(0), 0, 1, m->heap);
    func_02049238(arc);
}
