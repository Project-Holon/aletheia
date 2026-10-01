/*
 * function: func_021BD668
 * address: 0x021BD668
 * packet: pkt_ov216_021BD668
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 * symbols:
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD6BC 0x021BD6BC thumb ov216
 *   func_021BCD00 0x021BCD00 thumb ov216
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *sub_020311B8(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void func_021BD6BC(struct TcblNode *, void *);
extern void func_021BCD00(int);
void func_021BD668(char *owner, int direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl **)(owner + 24), func_021BD6BC, 12, 0));
    MI_CpuFill8(work, 0, 12);
    *(u8 *)work = direction;
    if (*(u8 *)work == 0) {
        *(u8 *)(work + 3) = 0;
        *(s8 *)(work + 4) = 8;
    } else {
        *(u8 *)(work + 3) = 64;
        *(s8 *)(work + 4) = -8;
    }
    *(u8 *)(work + 1) = 8;
    func_021BCD00(1357);
    *(int **)(work + 8) = counter;
    ++*counter;
}
