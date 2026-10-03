/*
 * function: func_021BD7D4
 * address: 0x021BD7D4
 * packet: pkt_ov216_021BD7D4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 * symbols:
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD854 0x021BD854 thumb ov216
 *   func_021BD13C 0x021BD13C thumb ov216
 *   func_021BD0E4 0x021BD0E4 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *sub_020311B8(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void func_021BD854(struct TcblNode *, char *);
extern void func_021BD13C(u8 *p, int a);
extern void func_021BD0E4(char *, u32, u32);
void func_021BD7D4(char *owner, int index, int position, u8 direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl **)(owner + 24), (void (*)(struct TcblNode *, void *))func_021BD854, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(char **)(work + 12) = owner + 0x15c + index * 128;
    *(u8 *)work = index;
    *(s16 *)(work + 4) = (1 - position) * -192;
    if (direction == 0)
        *(s16 *)(work + 6) -= 8;
    else
        *(s16 *)(work + 6) += 8;
    *(u8 *)(work + 1) = 24;
    func_021BD13C(*(void **)(work + 12), *(s16 *)(work + 4));
    if (position != 1)
        func_021BD0E4(owner, *(u8 *)work, 1);
    *(char **)(work + 16) = owner;
    *(int **)(work + 20) = counter;
    ++*counter;
}
