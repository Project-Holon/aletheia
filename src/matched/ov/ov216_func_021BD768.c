/*
 * function: func_021BD768
 * address: 0x021BD768
 * packet: pkt_ov216_021BD768
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD668 0x021BD668 thumb ov216
 *   func_021BD73C 0x021BD73C thumb ov216
 *   sub_02031194 0x02031194 arm
 */
typedef unsigned char u8;
struct TcblNode;
extern void func_021BD668(void *, int, int *);
extern int func_021BD73C(char *);
extern void sub_02031194(struct TcblNode *);
void func_021BD768(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (*(u8 *)p) {
    case 0:
        func_021BD668(*(void **)(p + 8), 0, (int *)(p + 4));
        ++*(u8 *)p;
        break;
    case 1:
        if (*(int *)(p + 4) == 0)
            ++*(u8 *)p;
        break;
    case 2:
        if (func_021BD73C(p) == 0) {
            func_021BD668(*(void **)(p + 8), 1, (int *)(p + 4));
            ++*(u8 *)p;
        }
        break;
    case 3:
        if (*(int *)(p + 4) != 0)
            break;
    default:
        --**(int **)(p + 12);
        sub_02031194(task);
        break;
    }
}
