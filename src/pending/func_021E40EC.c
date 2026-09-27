/*
 * function: func_021E40EC
 * address:  0x021E40EC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: codegen, 128/136 bytes.  Logic and byte order of the stack args
 * match, but register allocation differs (image keeps p in r5, a1 in r4,
 * a2 in r6 and the copied 2-word table at sp+0x10; ours uses r6/r7 for the
 * arguments and places the table at sp+0x14) and the a1 conditional's arms
 * are laid out differently.  Blocker: codegen, not evidence.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   func_02040618  0x02040618  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 */

typedef unsigned int u32;

extern void *func_020490F4(u32 a, u32 b);
extern void func_02049990(int a, u32 b, int c, int d, int e, int f, int g,
                          int h);
extern void func_02040618(int a, int b, int c);
extern void func_0204B3DC(int a, int b);
extern void func_02049238(void *a);
extern void func_02040588(int a, int b);

void func_021E40EC(void *p, int a1, int a2)
{
    u32 tbl[2];
    int v;

    tbl[0] = *(u32 *)0x021E7DD0;
    tbl[1] = *(u32 *)(0x021E7DD0 + 4);
    v = (int)func_020490F4(0x66, *(unsigned short *)((char *)p + 0x5f4));
    func_02049990(v, tbl[a2], 4, 0,
                  (unsigned short)*(unsigned int *)((char *)p + 0x870), 0, 0,
                  *(unsigned short *)((char *)p + 0x5f4));
    func_02040618(4, 0, a1 != 0 ? 0x80 : 0);
    func_0204B3DC(*(int *)((char *)p + 0xf04), 0);
    func_02049238((void *)v);
    func_02040588(4, 1);
}
