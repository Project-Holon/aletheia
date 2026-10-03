/*
 * function: func_022051A8
 * address: 0x022051A8
 * packet: pkt_ov195_022051A8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 82 code bytes followed by two zero alignment bytes at 0x022051FA.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02021D50 0x02021D50 thumb
 */
typedef unsigned int   u32;
struct S02021D50;
extern void func_02040588(u32 which, u32 enable);
extern void func_02021D50(struct S02021D50 *p);
void func_022051A8(int task, char *p)
{
    switch (*(int *)(p + 0x88)) {
    case 1:
        func_02040588(1, 1);
        *(int *)(p + 0x8c) = 1;
        *(int *)(p + 0x88) = 0;
        break;
    case 2:
        func_02040588(1, 0);
        *(int *)(p + 0x8c) = 0;
        *(int *)(p + 0x88) = 0;
        break;
    }
    if (*(void **)(p + 0xa8))
        func_02021D50(*(void **)(p + 0xa8));
}
