/*
 * function: func_021BD8A8
 * address: 0x021BD8A8
 * packet: pkt_ov216_021BD8A8
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD948 0x021BD948 thumb ov216
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_021BD174 0x021BD174 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct Queue;
struct Rec;
extern struct TcblNode *sub_020311B8(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void func_021BD948(struct TcblNode *, void *);
extern void func_021B6548(void *, int, int);
extern int func_02165AC4(struct Queue *, struct Rec *, u16 *, int);
extern void func_021BD174(void *, void *, u16, u8);
void func_021BD8A8(char *owner, int direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl **)(owner + 24), func_021BD948, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(u8 *)(work + 4) = direction;
    if (direction == 0) {
        *(u8 *)(work + 3) = *(u8 *)(owner + 0x30) + 1;
        func_021B6548(*(void **)(owner + 0x124), 3, 0);
    } else {
        *(u8 *)(work + 3) = *(u8 *)(owner + 0x30) - 1;
        func_021B6548(*(void **)(owner + 0x124), 2, 0);
    }
    func_021B6548(*(void **)(owner + 0x124), 1, 0);
    func_02165AC4(*(struct Queue **)(owner + 0x24), *(struct Rec **)(owner + 0x28), (u16 *)(owner + 0x2c), *(u8 *)(owner + 0x31 + *(u8 *)(work + 3)));
    func_021BD174(owner, *(void **)(owner + 0x28), *(u16 *)(owner + 0x2c), *(u8 *)(owner + 0x2e) ^ 1);
    *(char **)(work + 16) = owner;
    *(int **)(work + 20) = counter;
    ++*counter;
}
