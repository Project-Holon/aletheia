/*
 * function: func_02204DE0
 * address:  0x02204DE0
 * packet:   pkt_02204DE0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E50 0x02005E50 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_020063B4 0x020063B4 thumb
 *   func_02204F40 0x02204F40 thumb ov195
 */

extern int func_02005E50(void);
extern int func_02005F38(void);
extern void func_02005DE4(int);
extern void func_02005E64(void);
extern void func_02005D28(void);
extern int func_020063B4(int, void *, int);
extern void func_02204F40(char *, char *);

void func_02204DE0(char *a, char *b)
{
    switch (*(int *)(b + 0x30)) {
    case 0:
        break;
    case 1:
        if (func_02005E50() == 0) {
            if (*(int *)(a + 0xc) != 0) {
                func_02005DE4(1);
                func_02005E64();
            }
            *(int *)(b + 0x30) = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            *(int *)(b + 0x30) = 0;
        break;
    case 3:
        if (func_020063B4(0x3f3, b + 0x34, 0) != 0)
            *(int *)(b + 0x30) = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (func_02005E50() == 0) {
            func_02005D28();
            *(int *)(b + 0x30) = 0;
        }
        break;
    case 7:
        if (func_020063B4(0x519, b + 0x34, 0) != 0)
            *(int *)(b + 0x30) = 8;
        break;
    case 8:
        if (func_02005F38() == 0)
            func_02204F40(a, b);
        break;
    case 9:
        if (func_02005F38() == 0)
            func_02204F40(a, b);
        break;
    }
}
