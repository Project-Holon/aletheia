/*
 * function: func_02200E1C
 * address: 0x02200E1C
 * packet: pkt_ov094_02200E1C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_02015C78 0x02015C78 thumb
 *   _ll_mul 0x0209C054 arm
 *   d_020A1B38 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef long long s64;
typedef struct Vec { int x, y, z; } Vec;
extern int func_022019F4(char *, int);
extern void func_021F89BC(void *);
extern const s16 d_020A1B38[];
extern void func_02015C78(void *, u32 *);
#define MUL(a, b) ((int)(((s64)(a) * (b) + 0x800) >> 12))
void func_02200E1C(void *task, char *q)
{
    char *p = *(char **)q;
    Vec v = {0, 0, 0};
    int i = func_022019F4(p, *(int *)(q + 4));
    char *e;
    int off;
    int x, y;
    int j;
    if (i == -1) {
        func_021F89BC(task);
        return;
    }
    e = p + 8;
    off = i * 0x5c;
    if (*(void **)(e + off) == 0) {
        func_021F89BC(task);
        return;
    }
    if (*(int *)(q + 0x38) != *(u8 *)(p + *(int *)(q + 4) + 0x542)) {
        func_021F89BC(task);
        return;
    }
    if (*(int *)(q + 0x34) == 0) {
        if (*(int *)(q + 0x30) == *(int *)(q + 0x1c)) {
        *(int *)(q + 0x30) = 0;
        if (*(int *)(q + 8) & 1)
            *(int *)(q + 0x28) -= *(int *)(q + 0x2c);
        else
            *(int *)(q + 0x28) += *(int *)(q + 0x2c);
        if (*(int *)(q + 0x28) & 0xffff0000) {
            *(int *)(q + 0x28) = (u16)*(int *)(q + 0x28);
            *(int *)(q + 0x20) -= 1;
            *(int *)(q + 0x34) = *(int *)(q + 0x24);
        }
        if (*(int *)(q + 0x20) != 0) {
            switch (*(int *)(q + 0xc)) {
            case 0:
                j = ((u16)(*(int *)(q + 0x28) + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, *(int *)(q + 0x10));
                y = d_020A1B38[j + 1];
                y = -MUL(y, *(int *)(q + 0x14));
                x += *(int *)(q + 0x10);
                break;
            case 1:
                j = ((u16)(*(int *)(q + 0x28) + 0x4000) >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, *(int *)(q + 0x10)) - *(int *)(q + 0x10);
                y = d_020A1B38[j + 1];
                y = MUL(y, *(int *)(q + 0x14));
                break;
            case 2:
                j = (*(int *)(q + 0x28) >> 4) * 2;
                x = d_020A1B38[j];
                x = -MUL(x, *(int *)(q + 0x10));
                y = d_020A1B38[j + 1];
                y = -MUL(y, *(int *)(q + 0x14));
                y += *(int *)(q + 0x14);
                break;
            case 3:
                j = (*(int *)(q + 0x28) >> 4) * 2;
                x = d_020A1B38[j];
                x = MUL(x, *(int *)(q + 0x10));
                y = d_020A1B38[j + 1];
                y = MUL(y, *(int *)(q + 0x14)) - *(int *)(q + 0x14);
                break;
            }
            switch ((*(int *)(q + 8) & 7) >> 1) {
            default:
            case 0:
                v.z = x;
                v.y = y;
                break;
            case 1:
                v.x = x;
                v.z = y;
                break;
            case 2:
                v.x = x;
                v.y = y;
                break;
            }
        }
        func_02015C78(*(void **)(e + off), (u32 *)&v);
        } else {
            *(int *)(q + 0x30) += 1;
        }
    } else {
        *(int *)(q + 0x34) -= 1;
    }
    if (*(int *)(q + 0x20) == 0)
        func_021F89BC(task);
}
