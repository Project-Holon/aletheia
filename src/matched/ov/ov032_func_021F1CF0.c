/*
 * function: func_021F1CF0
 * address:  0x021F1CF0
 * packet:   pkt_ov032_021F1CF0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1CF0 0x021F1CF0 thumb
 *   func_021F0A98 0x021F0A98 thumb ov032
 *   func_021F0B80 0x021F0B80 thumb ov032
 *   func_021F178C 0x021F178C thumb ov032
 *   func_021F0C04 0x021F0C04 thumb ov032
 *   func_021F0B64 0x021F0B64 thumb ov032
 *   func_021F0E04 0x021F0E04 thumb ov032
 *   func_021F0C70 0x021F0C70 thumb ov032
 *   func_021F253C 0x021F253C thumb ov032
 *   func_021F0D9C 0x021F0D9C thumb ov032
 *   func_021F0D5C 0x021F0D5C thumb ov032
 *   func_021F0B10 0x021F0B10 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_02031194 0x02031194 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F0A98(char *p, u8 b);
extern void func_021F0B80(char *p, u32 a, int *s);
extern void func_021F178C(char *p, u8 a, int *s);
extern void func_021F0C04(char *p, int flag);
extern void func_021F0B64(char *p);
extern void func_021F0E04(char *p, int a);
extern int func_021F0C70(char *p, int flag);
extern void func_021F253C(char *p, u16 v);
extern void func_021F0D9C(char *p);
extern int func_021F0D5C(char *p, int i);
extern void func_021F0B10(char *p, int a, int *b);
extern void func_021F05E8(char *p, int a, int b);
extern void func_02031194(void *h);

void func_021F1CF0(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char **)(t + 0x1c);
    if (*(int *)(t + 8) > 0)
        return;
    switch (t[0]) {
    case 0:
        if (*(u16 *)(t + 0x14) != 0)
            func_021F0A98(p, (*(u16 *)(t + 0x16) != 0 ? 1 : 0) + 9);
        else if (*(u16 *)(t + 0x10) < *(u16 *)(t + 0x12))
            func_021F0A98(p, 8);
        func_021F0B80(p, *(u32 *)(p + 0x11c), (int *)(t + 8));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        func_021F0C04(p, 1);
        func_021F0B64(p);
        t[0]++;
        break;
    case 4:
        r = func_021F0C70(p, 1);
        if (r < 0)
            break;
        t[5] = r;
        if (t[5] == 0) {
            func_021F253C(p, 7);
            p[0x79] = 1;
            t[0] = 5;
        } else {
            t[0] = 6;
        }
        break;
    case 5:
        if (*(u8 *)(p + 0x79) != 0) {
            t[0] = 4;
            break;
        }
        func_021F0D9C(p);
        t[0] = 7;
        break;
    case 6:
        if (func_021F0D5C(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 7:
        func_021F0B10(p, 1, (int *)(t + 8));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8(p, 4, 0);
        (**(int **)(t + 0x20))--;
        func_02031194(h);
        break;
    }
}
